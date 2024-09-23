#include <stdio.h>

unsigned long long memo[95];

unsigned long long fib_iterative_wrapper(int num)
{
   if (num == 1 || num == 2)
   {
      return memo[num];
   }
   if (memo[num] != 0)
   {
      return memo[num];
   }

   unsigned long long num_prev = 0;
   unsigned long long num_current = 1;
   unsigned long long num_next;

   for (int ix = 2; ix < num; ix++)
   {
      num_next = num_prev + num_current;
      num_prev = num_current;
      num_current = num_next;
   }

   return num_current;
}

unsigned long long fib_recursive_wrapper(int num)
{
   if (num == 1 || num == 2)
   {
      return memo[num];
   }
   if (memo[num] != 0)
   {
      return memo[num];
   }

   memo[num] = fib_recursive_wrapper(num - 1) + fib_recursive_wrapper(num - 2);
   return memo[num];
}

unsigned long long fib_i(int num)
{
   if (num > 2 && memo[num] != 0)
   {
      return memo[num];
   }

   unsigned long long result = fib_iterative_wrapper(num);
   memo[num] = result;
   return result;
}

unsigned long long fib_r(int num)
{
   if (num > 2 && memo[num] != 0)
   {
      return memo[num];
   }

   unsigned long long result = fib_recursive_wrapper(num);
   memo[num] = result;
   return result;
}

int main(int argc, char *argv[])
{
   int num_arg;
   int num_file;
   unsigned long long num_total;
   unsigned long long num_final;
   char option;

   sscanf(argv[1], "%d", &num_arg);
   option = argv[2][0];

   if (argc >= 4)
   {
      FILE *file = fopen(argv[3], "r");
      if (file == NULL)
      {
         printf("Error opening file: %s\n", argv[3]);
         return 1;
      }
      fscanf(file, "%d", &num_file);
      fclose(file);
   }
   else
   {
      num_file = 0;
   }

   num_total = num_arg + num_file;

   memo[1] = 0;
   memo[2] = 1;

   if (option == 'i')
   {
      num_final = fib_i(num_total);
      printf("%llu\n", num_final);
   }
   else if (option == 'r')
   {
      num_final = fib_r(num_total);
      printf("%llu\n", num_final);
   }

   return 0;
}
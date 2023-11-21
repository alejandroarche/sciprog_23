#include <stdio.h>


int main(void) {
/* Declare variables */
   int i;
   float sum1, sum2, diff;
   

/* First sum */
// Initialising sum1 to zero to start accumulation
   sum1 = 0.0;
// Looping from 1 to 1000, adding the reciprocal of i to sum1
   for (i=1; i<=1000; i++) {
      sum1 += 1.0 / i; // Adding 1/i to sum1
   }


/* Second sum */
// Initialising sum2 to zero to start accumulation
   sum2 = 0.0;
// Looping from 1000 down to 1, adding the reciprocal of i to sum2
   for (i=1000; i>0; i--) {
      sum2 += 1.0 / i; // Adding 1/i to sum2
   }
// Printing the result of the first sum
   printf(" Sum1=%f\n",sum1);
// Printing the result of the second sum
   printf(" Sum2=%f\n",sum2);

/* Find the difference */
// Calculating the difference between sum1 and sum2
   diff = sum1 - sum2;
// Printing the difference between the two sums
   printf(" Difference between the two is %f\n",diff);

return 0;
}

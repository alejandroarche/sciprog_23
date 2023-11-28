/* Include the standard input-output library header */
#include <stdio.h>

/* Function to calculate the greatest common divisor (GCD) using iteration */
int gcd_iteration(int a, int b) {
    int temp;
    /* Loop until b is not equal to 0 */
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    /* Return the GCD, which is now stored in a */
    return a;
}

/* Function to calculate the greatest common divisor (GCD) using recursion */
int gcd_recursive(int a, int b) {
    /* Base case: if b is 0, a is the GCD */
    if (b == 0) {
        return a;
    }
    /* Recursive case: call gcd_recursive with b and the remainder of a divided by b */
    else {
        return gcd_recursive(b, a % b);
    }
}

/* Main function */
int main(void) {
    /* Initialize two integers a and b */
    int a = 5;
    int b = 25;

    /* Calculate GCD of a and b using recursive and iterative functions */
    int ans_r = gcd_recursive(a, b);
    int ans_i = gcd_iteration(a, b);

    /* Print the results from both methods */
    printf("Using iteration, we get the answer: %d\n", ans_i);
    printf("Using recursion, we get the answer: %d\n", ans_r);

    /* Return 0 to indicate successful completion of the program */
    return 0;
}


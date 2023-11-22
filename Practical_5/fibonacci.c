#include <stdio.h>
#include <stdlib.h>

/* Function declaration/prototype
 *    Input arguments: Fn-1 and Fn-2
 *       On exit: Fn and Fn-1 */
void fibonacci(int *a, int *b);

int main() {
    int n, i;
    int f0 = 0, f1 = 1;

    printf("Enter a positive integer\n");
    scanf("%d", &n);

    if (n < 1) {
        printf("The number is not positive.\n");
        exit(1);
    }

    printf("The fibonacci sequence is: \n");
    printf("%d, %d, ", f0, f1);

    /* Calculating fibonacci sequence from 2 */
    for (i = 2; i <= n; i++) {
        fibonacci(&f1, &f0);
        printf("%d, ", f1);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    return 0;
}

void fibonacci(int *a, int *b) {
    /* *a = Fn-1, *b = Fn-2  next = Fn */
    int next;
    next = *a + *b; /* Fn = Fn-1 + Fn-2 */
    *b = *a; /* Update Fn-2 to Fn-1 */
    *a = next; /* Update Fn-1 to Fn */
}


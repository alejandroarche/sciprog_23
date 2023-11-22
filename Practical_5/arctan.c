#include <stdio.h>
#include <math.h>

/* Function declarations */
double arctan1(const double x, const double delta);
double arctan2(const double x);

int main() {
    double delta, x;

    printf("Enter the precision for the Maclaurin series:\n");
    scanf("%lf", &delta);

    /* Declare arrays to store results of arctan1 and arctan2 */
    int length = 1000;
    double tan1[length]; /* Storing the result of arctan1 */
    double tan2[length]; /* Storing the result of arctan2 */

    /* Loop through x values to calculate arctan using two methods */
    int j = 0; /* Array index */
    x = -0.9;
    while (x <= 0.9 && j < length) {
        tan1[j] = arctan1(x, delta);
        tan2[j] = arctan2(x);
        printf("The difference at x=%lf between them is %.10lf.\n", x, fabs(tan1[j] - tan2[j]));
        j++;
        x += 0.1; /* Try with 0.01 as well */
    }

    return 0;
}

/* Function to calculate arctan using Maclaurin series */
double arctan1(const double x, const double delta) {
    double arcTan = 0; /* Approximation */
    double elem, val; /* Element in the series */
    int n = 0; /* Sum parameter */

    do {
        val = 2 * n + 1;
        elem = pow(x, val) / val;
        arcTan += elem;
        n++;
    } while (fabs(elem) >= delta);

    return arcTan;
}

/* Function to calculate arctan using logarithm properties */
double arctan2(const double x) {
    return (log(1 + x) - log(1 - x)) / 2;
}


#include <stdio.h>
#include <math.h>

/* Global variables */
int N = 12;
double TanValues[13];

/* Function prototypes */
double degtorad(double deg);
double traprule(int N);

int main() {
    int i;
    double deg, rad;

    /* Calculate tan(x) for x in [0,60] degrees, every 5 degrees, and store in TanValues */
    for (i = 0; i <= N; i++) {
        deg = i * 5.0; /* Current degree */
        rad = degtorad(deg); /* Convert degree to radians */
        TanValues[i] = tan(rad); /* Compute tan(x) and store */
        /* Uncomment the following line to print TanValues for each degree */
        /* printf("TanValues[%d] = %f at x=%2.2f degrees\n", i, TanValues[i], deg); */
    }

    /* Calculate the area under the curve using the Trapezoidal Rule */
    double integral_approx = traprule(N);
    /* The exact value of the integral from 0 to pi/3 for tan(x) */
    double integral_exact = log(2.0);

    /* Print the results */
    printf("Your approximation of the integral from x=0 degrees to x=60 degrees of the function tan(x) with respect to x is:%.5f\nThe exact solution is:%.5f\n", integral_approx, integral_exact);

    return 0;
}

/* Function to convert degrees to radians */
double degtorad(double deg) {
    return (deg * M_PI) / 180.0;
}

/* Function to compute the area under a curve using the Trapezoidal Rule */
double traprule(int N) {
    int i;
    double width, area = TanValues[0] + TanValues[N]; /* Initialize area with first and last terms */
    
    /* Sum the middle terms with a weight of 2 */
    for (i = 1; i < N; i++) {
        area += 2.0 * TanValues[i];
    }

    /* Calculate the width of each trapezoid */
    width = degtorad(60.0) / (double)N;
    /* Complete the area calculation */
    area = width * area * 0.5;

    return area;
}


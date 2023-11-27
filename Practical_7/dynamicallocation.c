/* Include standard I/O and standard library headers */
#include <stdio.h>
#include <stdlib.h>

/* Function to allocate memory for an array of integers */
int *allocateArray(int n) {
    int *p;
    p = (int *) malloc(n*sizeof(int));
    return p;
}

/* Function to fill an array with ones */
void fillWithOnes(int *array, int n) {
    int i;
    for(i=0; i<n; i++) {
        array[i] = 1;
    }
}

/* Function to print the array */
void printArray(int *array, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d: %d\n", i, array[i]);
    }
}

/* Function to deallocate the memory allocated for the array */
void freeArray(int *array) {
    free(array);
}

/* Main function */
int main() {
    int n, *a;

    /* Prompt user for the size of the array */
    printf("Size of the array:\n");
    scanf("%d", &n);

    /* Allocate array, fill it with ones, print it, and then deallocate it */
    a = allocateArray(n);
    fillWithOnes(a, n);
    printArray(a, n);
    freeArray(a);

    /* Ensure the pointer is not left dangling */
    a = NULL;

    return 0;
}


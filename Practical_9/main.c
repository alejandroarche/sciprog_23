/* Include standard libraries */
#include <stdio.h>
#include <stdlib.h>

/* Include magic_square header */
#include "magic_square.h"

/* Define the maximum length for a file name */
#define MAX_FILE_NAME 100

/* Function declaration */
int getlines(char filename[MAX_FILE_NAME]);

/* Main program function */
int main() {
    /* Define file pointer and filename variable */
    FILE *f;
    char filename[MAX_FILE_NAME];
    
    /* Prompt user to enter the file name */
    printf("Enter file name: ");
    scanf("%s", filename);

    /* Get the number of lines in the file */
    int n = getlines(filename);

    /* TODO: Open the file */
    f = fopen(filename, "r");
    if(f == NULL) {
        printf("!!! can't open file !!!\n");
        exit(1);
    }

    int i;
    /* TODO: Allocating a matrix for storing the magic square
 *        as an array of pointers, where each pointer is a row */
    int **magicSquare = malloc(n * sizeof(int*));
    for(i=0; i<n; ++i) {
        magicSquare[i] = malloc(n * sizeof(int));
    }

    /* TODO: Inputting integer data into the matrix */
    int j;
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            fscanf(f, "%d", &magicSquare[i][j]);
            printf("%d\t", magicSquare[i][j]);
        }
        printf("\n");
    }

    /* Check if the square is a magic square and print result */
    printf("This square %s magic\n", isMagicSquare(magicSquare, n) ? "is" : "is NOT");

    /* TODO: Freeing each row separately before freeing the array of pointers */
    for(i=0; i<n; ++i) {
        free(magicSquare[i]);
    }
    free(magicSquare);

    /* TODO: Close the file */
    fclose(f);

    /* End of main function */
    return 0;
}

/* Function to get the number of lines in a file */
int getlines(char filename[MAX_FILE_NAME]) {
    /* Open the file for reading */
    FILE *fp = fopen(filename, "r");

    int ch_read;
    int count = 0;

    /* Read characters from the file one at a time */
    while((ch_read = fgetc(fp)) != EOF) {
        /* Increment count if a newline character is found */
        if(ch_read == '\n') {
            count++;
        }
    }

    /* Print the number of lines found */
    printf("No. lines, %d\n", count);

    /* Close the file */
    fclose(fp);

    /* Return the line count */
    return count;
}


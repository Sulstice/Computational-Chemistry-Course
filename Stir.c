#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ELEMENTS 99

double * natural_log (); // Obtain the natural log from 1 to 100
double * approximation(); // Obtain the approximation from 1 to 100
double * percentage (); // Calculate the percentage difference
void * file_output (); // File to store data

int main () {
    double * log = natural_log ();
    double * approx = approximation ();
    double * percent = percentage(log, approx);
    file_output (log, approx, percent);
    return 0;
}

double * natural_log () {
    static double natural_array[ELEMENTS]; // Set up the array, no need for malloc since we know the size
    int i;

    natural_array[0] = log(1.0);
    natural_array[1] = log(2.0);
    
    double x;
    x = natural_array[1];
    
    for (i = 2; i <= ELEMENTS; i++) {
        natural_array[i] = x + log(1 + i);
        x = natural_array[i];
        // Check printf ("Element[%d] = %f\n", i, x)
    }
    return natural_array;
}

double * approximation () {

    static double approximation_array[ELEMENTS];
    int i;
 
    for (i = 0; i <= ELEMENTS; i++) {
        approximation_array[i] = (i + 1) * log (i + 1) - (i + 1);
        // Check printf ("Element[%d] = %f\n", i, approximation_array[i])
    }

    return approximation_array;
}

double * percentage (double * natural_array, double * approximation_array) {

    static double percentage_array[ELEMENTS];
    int i;
    for (i = 0; i <= ELEMENTS; i++) {
        percentage_array[i] = ((fabs(natural_array[i] - approximation_array[i])/natural_array[i])*100);
    // Check printf ("Element[%d] = %f\n", i, percentage_array[i])
    }
    return percentage_array;
}

void * file_output (double * natural_array, double * approximation_array, double * percentage_array) {
    int i;

   FILE * outfile = fopen("StirData.txt", "w");
   if (outfile == NULL) {
      printf ("Error file does not exist!");
      exit (-1);
   }
   for (i = 0; i <= ELEMENTS; i++) {
       fprintf (outfile, "%7f%11f%10f\n", natural_array[i], approximation_array[i], percentage_array[i]);
   }

   return outfile;
}

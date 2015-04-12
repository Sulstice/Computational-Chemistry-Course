#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ELEMENTS 99

double * natural_log ();
/* Obtain the natural log of 0 to 100 and then store each value in an array */
double * approximation ();
/* Use the sterling approximation caluculate the numbers from 0 - 100 and then store it in an array */
double * difference ();
/* Calculate the difference between the arrays (Not Neeeded) */
double * percentage ();
/* Calculate the percentage of the difference and return the array */

void * file_output () ;
/* Create a function to store the data */

int main () {
   double * log = natural_log();
   double * approx = approximation();
   double * percent = percentage(log, approx);
   file_output (log, approx, percent);
   return 0;
}

double * natural_log () {

    static double natural_array[ELEMENTS]; /* set up the array */
    int i; /* set up the integer to increase the array by a value */
    

    natural_array[0] = log(1.0); /* set up the first value in the array */
    natural_array[1] = log(2.0);
    
    double x;
    x = natural_array [1];
    for (i = 2; i <=99; i++) { /* set up the for loop to increment the i */
        natural_array[i] = x + log(1 + i);
        x = natural_array[i];
// Check        printf ("Element[%d] = %f\n", i, x); 
     }
    return  natural_array;
}    
    
double * approximation () {

    static double approximation_array[ELEMENTS]; /* set up the array */ 
    int i;  /* set up the integer to increase the array by a value */ 
    
    for (i = 0; i <=99; i++) {
        approximation_array[i] = (i + 1) * log(i + 1) - (i + 1);
// Check       printf ("Elements[%d] = %f\n", i, approximation_array[i]); 
    }
    return approximation_array;
}
/*    Check
double * difference (double * natural_array, double * approximation_array) {

    static double difference_array[ELEMENTS];
    int i;  
    for (i = 0; i <= 99; i++) {
        difference_array[i] = fabs(natural_array[i] - approximation_array[i]);
// Check       printf ("Elements[%d] = %f\n", i, difference_array[i]); 
    }
    return difference_array;
}
*/
double * percentage (double * natural_array, double * approximation_array) {
    static double percentage_array[ELEMENTS];
    int i;
    for (i = 0; i <= 99; i++) {
        percentage_array[i] = ((fabs(natural_array[i] - approximation_array[i])/natural_array[i]) * 100);
// Check     printf ("Elements[%d] = %f\n", i, percentage_array[i]);
     }
    return percentage_array;

}
void * file_output (double * natural_array, double * approximation_array, double * percentage_array) {
 int i;
 FILE * out_file = fopen("approximation.txt", "w");
  if (out_file == NULL) {
     printf ("Error: file does not exist!");
     exit (-1);
  }
  for (i = 0; i <= ELEMENTS; i++) { 
       fprintf (out_file, "%f\n", approximation_array[i]);
  }
  FILE * out_file1 = fopen("exact.txt", "w");
  if (out_file1 == NULL) {
      printf ("Error: file does not exist!");
      exit(-1);
  }
  for (i = 0; i <= ELEMENTS; i++) {
       fprintf (out_file1, "%f\n", natural_array[i]);
  }

  FILE * out_file2 = fopen("percentage_array.txt", "w");
  if (out_file2 == NULL) {
      printf ("Error: file does not exist!");
      exit(-1);
  }
  for (i = 0; i <= ELEMENTS; i++) {
       fprintf (out_file2, "%f\n", percentage_array[i]);
  }
  return out_file, out_file1, out_file2;
 
}




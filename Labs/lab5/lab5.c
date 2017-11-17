/*
 * Lab4.c
 * COMP 2160 Programming Practices
 *
 * Using gprof to profile a program
 *
 * to compile: gcc -lm -pg lab4.c
 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long ulong;

// prototypes
double machin(double tolerance);
double nilakantha(double tolerance);
double gregory(double tolerance);

int main(int argc, char *argv[]){
  int decplaces;
  // argument checking
  if(argc < 2){
    printf("usage: %s <dec places>\n", argv[0]);
    exit(0);
  }else{
    decplaces = atoi(argv[1]);
  }

  int i;
  double tol;
  /* char *fmt = "%5d\t%15.12f\t%15.12f\t%15.12f\n";
  printf("Some series for estimating pi\n");
  printf("Accuracy\n");
  printf("Decimals     Machin         Nilakantha      Gregory\n");
  for(i = 2; i < decplaces; i++){
    tol = pow(10, -i);
    printf(fmt, i, machin(tol), nilakantha(tol), gregory(tol));
  }// for */
  char *fmt = "%5d\t%15.12f\t\n";
  printf("Some series for estimating pi\n");
  printf("Accuracy\n");
  printf("Decimals     Machin\n");
  for(i = 2; i < decplaces; i++){
    tol = pow(10, -i);
    printf(fmt, i, machin(tol));
  }// for
  printf("\nEnd of processing.\n");
  return 0;
}// main

// Calculate pi using Machin's formula
double machin(double tolerance){
  double x1 = 1./5;
  double x2 = 1./239;
  double powerx1 = x1; 
  double powerx2 = x2; 
  double atanx1 = x1;
  double atanx2 = x2;
  double oldpi = 0;
  double newpi = 16 * atanx1 - 4 * atanx2;
  double diff;
  ulong i = 0;
  do{
    i++;
    oldpi = newpi;
    powerx1 *= x1 * x1;
    powerx2 *= x2 * x2;
    if(i % 2 == 0){
      atanx1 += powerx1/(2*i+1);
      atanx2 += powerx2/(2*i+1);
    }else{
      atanx1 -= powerx1/(2*i+1);
      atanx2 -= powerx2/(2*i+1);
    }
    newpi = 16 * atanx1 - 4 * atanx2;
    diff = fabs(newpi - oldpi);
  } while (diff > tolerance);
  return newpi;
}// fastpi

// Calculate pi using the Nilakantha series
double nilakantha(double tolerance){
  double sum = 3;
  double term = 4./24;
  int count = 1;
  while (fabs(term) > tolerance){
    sum += term;
    term = term * (2 * count) * (2 * count + 1);
    count++;
    term = -term / (2 * count + 1) / (2 * count + 2);
  }
  return sum;
}// fastpi

// Calculate pi using the Gregory-Leibniz series
double gregory(double tolerance){
  double pi = 0;
  double term = 4;
  ulong i = 0;
  while(term > tolerance){
    if(i % 4 == 0)
       pi += term;
    else
       pi -= term;
    i += 2;
    term = 4./(i+1);
  }// while
  return pi;
}// slowpi


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]) {
  double x,y;
  if(argc != 3){
  	printf("Number of parameters should be 2\n");
  	exit(1);
  }
  
  x = atof(argv[1]);
  y = atof(argv[2]);

  printf("%f\n", pow(x,y));
  return 0;
}


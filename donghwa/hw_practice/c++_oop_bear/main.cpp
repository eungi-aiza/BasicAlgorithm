#include <stdio.h>
#include <stdlib.h>
#include "NewBear.h"

int main() {
  Bear* b1 = new Polar(450);
  Bear* b2 = new Grizzly(300);
  Black_Momma * b3 = new Black_Momma(100);

  Black * cub1 = new Black(50);
  Black * cub2 = new Black(20);
  
  b3->AddCub(cub1);
  b3->AddCub(cub2);
  
  b1->PrintSelf();
  b2->PrintSelf();
  b3->PrintSelf();
  

  delete b1;
  delete b2;
  delete b3;
  delete cub1;
  delete cub2;

  return EXIT_SUCCESS;
}

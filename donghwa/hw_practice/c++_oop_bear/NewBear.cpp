#include <stdio.h>
#include "NewBear.h"


// Bear
Bear::Bear(float aWeight){
    weight = aWeight;
}
void Bear::SetWeight(float aWeight){
    weight = aWeight;
}
float Bear::GetWeight(void){
    return(weight);
}

// Polar, Grizzly, Black Black
float Polar::Aggressiveness(void){
    return(1.0 * weight);
}
void Polar::PrintSelf(void){
    printf("I am Polar bear, Weight=%g, Aggressiveness=%g\n", weight, Aggressiveness());
}

float Grizzly::Aggressiveness(void){
    return(0.9 * weight);
}
void Grizzly::PrintSelf(void){
    printf("I am Grizzly bear, Weight=%g, Aggressiveness=%g\n", weight, Aggressiveness());
}

float Black::Aggressiveness(void){
    return(0.7 * weight);
}
void Black::PrintSelf(void){
    printf("I am Black bear, Weight=%g, Aggressiveness=%g\n", weight, Aggressiveness());
}


// Black_Momma
Black_Momma::Black_Momma(float aWeight):Black(aWeight){
    count = 0;
    cub1 = NULL;
    cub2 = NULL;
}
void Black_Momma::AddCub(Black *aCub){
    if (count == 0){
        cub1 = aCub;
    } else if (count == 1){
        cub2 = aCub;
    } else {
        printf("Error : cannot add cubs. MAX_CUBS_NUM=2");
    }; 
    count++;
}
float Black_Momma::Aggressiveness(void){
    if (count != 0)
        return(Black::Aggressiveness()*2);
    else
        return (Black::Aggressiveness());
}
float Black_Momma::TotalAggressiveness(void){
    float cubAggressiveness;
    if (count == 0){
        cubAggressiveness = 0.0;
    } else if (count == 1){
        cubAggressiveness = cub1->Aggressiveness();
    } else if (count == 2){
        cubAggressiveness = cub1->Aggressiveness() + cub2->Aggressiveness();
    }
    return (Aggressiveness() + cubAggressiveness);
}
void Black_Momma::PrintSelf(void){
    printf("I am Black Mommabear, with %d of cub(s), Weight=%g, Aggressiveness=%g, Total Aggressiveness=%g\n", count, weight, Aggressiveness(), TotalAggressiveness());
}



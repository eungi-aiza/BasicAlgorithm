#include "NewBear.h"
#include <stdio.h>

/*** Bear ***/
Bear::Bear(float aWeight) {
    Weight = aWeight;
}

void Bear::SetWeight(float aWeight) {
    Weight = aWeight;
}
float Bear::GetWeight(void) {
    return(Weight);
}

/*** Polar ***/
Polar::Polar(float aWeight) : Bear(aWeight) {
    
}

float Polar::Aggressiveness(void) {
    return (GetWeight()*1);
} 

void Polar::PrintSelf(void) {
    printf("I am Polar Bear, Weight=%f, Aggressiveness=%f\n", GetWeight(), Aggressiveness());
}

/*** Grizzly ***/
Grizzly::Grizzly(float aWeight) : Bear(aWeight) {
    
}

float Grizzly::Aggressiveness(void) {
    return (GetWeight()*0.9);
} 

void Grizzly::PrintSelf(void) {
    printf("I am Grizzly Bear, Weight=%f, Aggressiveness=%f\n", GetWeight(), Aggressiveness());
}

/*** Black ***/
Black::Black(float aWeight) : Bear(aWeight) {
    
}

float Black::Aggressiveness(void) {
    return (GetWeight()*0.7);
} 

void Black::PrintSelf(void) {
    printf("I am Black Bear, Weight=%f, Aggressiveness=%f\n", GetWeight(), Aggressiveness());
}

/*** Black_Momma ***/
Black_Momma::Black_Momma(float aWeight) : Black(aWeight) {
    cub1 = NULL;
    cub2 = NULL;
}

float Black_Momma::Aggressiveness(void) {
    if ((cub1 == NULL) && (cub2 == NULL)) {
        return (GetWeight()*0.7);
    }
    else {
        return (GetWeight()*0.7) * 2;
    }
} 

void Black_Momma::PrintSelf(void) {
    if ((cub1 == NULL) && (cub2 == NULL)) {
        printf("I am Black Mommabear with 0 cub(s), Weight=%f, Aggressiveness=%f, Total Aggressiveness=%f\n", 
        GetWeight(), Aggressiveness(), Aggressiveness());
    }

    else if ((cub1 != NULL) && (cub2 != NULL)) {
        printf("I am Black Mommabear with 2 cub(s), Weight=%f, Aggressiveness=%f, Total Aggressiveness=%f\n", 
        GetWeight(), Aggressiveness(), Aggressiveness() + cub1->Aggressiveness() + cub2->Aggressiveness());
    }

    else if ((cub1 != NULL) && (cub2 == NULL)) {
        printf("I am Black Mommabear with 1 cub(s), Weight=%f, Aggressiveness=%f, Total Aggressiveness=%f\n", 
        GetWeight(), Aggressiveness(), Aggressiveness() + cub1->Aggressiveness());
    }
    else if ((cub1 == NULL) && (cub2 != NULL)) {
        printf("I am Black Mommabear with 1 cub(s), Weight=%f, Aggressiveness=%f, Total Aggressiveness=%f\n",
        GetWeight(), Aggressiveness(), Aggressiveness() + cub2->Aggressiveness());
    }
}   

void Black_Momma::AddCub(Bear *aCub) {
    if (cub1 == NULL) {
        cub1 = aCub;
    }
    else if ((cub1 != NULL) && (cub2 == NULL)) {
        cub2 = aCub;
    }
}
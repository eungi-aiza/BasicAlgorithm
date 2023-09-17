#include "NewBear.h"


/* Constructor */
Bear::Bear(float aWeight){
    weight = aWeight;
}

Polar::Polar(float aWeight):Bear(aWeight){
    aggressiveness = aWeight;
}

/* Accessors*/
float Bear::GetWeight(void){ return weight; }
void Bear::SetWeight(float aWeight){
    weight = aWeight;
}
void Bear::PrintSelf(void){ };


void Polar::SetAggressiveness(void){ aggressiveness = weight; }
float Polar::GetAggressiveness(void){ return aggressiveness; }
void Polar::PrintSelf(void){
    printf("I am Polar bear, Weight={%d}, Aggressiveness={%d}", GetWeight(), GetAggressiveness());
}

void Grizzly::SetAggressiveness(void){ aggressiveness = 0.9 * weight; }
float Grizzly::GetAggressiveness(void){ return aggressiveness; }
void Grizzly::PrintSelf(void){
    printf("I am Grizzly bear, Weight={%d}, Aggressiveness={%d}", GetWeight(), GetAggressiveness());
}


void Black::SetAggressiveness(void){ aggressiveness = 0.7 * weight; }
float Black::GetAggressiveness(void){ return aggressiveness; }
void Black::PrintSelf(void){
    printf("I am Black bear, Weight={%d}, Aggressiveness={%d}", GetWeight(), GetAggressiveness());
}

/*** Constructor ***/
Black_Momma::Black_Momma(float aWeight)
              : Black(aWeight) // pass along to the Black constructor
{ num_cubs = 0; }

/*** Accessors ***/
// Black* BlackMomma::GetCub(void) {
//     return(cub);
// }
void Black_Momma::AddCub(Black *aCub) {
    if (num_cubs < 2){
        cubs.push_back(aCub);
        num_cubs += 1;
    }       
}
/*** Meannness ***/
/* Use the inherited meanness and then multiply by 2. */
float Black_Momma::GetAggressivness(void) {
    if (num_cubs > 0){
        return(Black::GetAggressiveness() * 2);
    } else {
        return(Black::GetAggressiveness());
    }
}

float Black_Momma::TotalAggressiveness(void) {
    float cubAggressiveness = 0;
    for (auto cub : cubs){
        cubAggressiveness += cub->GetAggressiveness();
    }
    return( GetAggressiveness() + cubAggressiveness);
}

float Black_Momma::GetNumCubs(void){
    return num_cubs;
}

void Black_Momma::PrintSelf(void){
    printf("I am Black with {%d} cub(s), Weight={%d}, Aggressiveness={%d}, Total Aggressiveness={%d}", GetNumCubs(), GetWeight(), GetAggressiveness());
}
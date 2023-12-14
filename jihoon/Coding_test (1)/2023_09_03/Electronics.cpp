#include "Electronics.h"
#include <stdio.h>
// Fill in here

Electronics::Electronics(float aSize) {
    Size = aSize;
}

float Electronics::GetSize(void) {
    return(Size);
}

void Electronics::SetSize(float aSize) {
    Size = aSize;
}

TV::TV(float aSize) : Electronics(aSize) {

}

void TV::PrintSelf(void){
    printf("It is a TV, Size=%.f, Price=%.f\n", Size, Size*1.8);
} 

Computer::Computer(float aSize) : Electronics(aSize) {

}

void Computer::PrintSelf(void){
    printf("It is a Computer, Size=%.f, Price=%.f\n", Size, Size*0.6);
} 

Cellphone::Cellphone(float aSize) : Electronics(aSize) {

}

void Cellphone::PrintSelf(void){
    printf("It is a Cellphone, Size=%.f, Price=%.f\n", Size, Size*0.7);
} 

Laptop::Laptop(float aSize) : Computer(aSize) {

}

void Laptop::AddGPU(Electronics *aGPU) {
    GPUs.push_back(aGPU);
    num_of_gpu += 1;
}


void Laptop::PrintSelf(void){
    int gpu_price = 0;
    for (int i = 0; i < num_of_gpu; i++) {
        gpu_price += GPUs[i]->GetSize()*0.6;
    }
    printf("It is a Laptop with %d of GPU(s), Size=%.f, Price=%.f, Total Price=%.f\n", num_of_gpu, GetSize(), GetSize()*0.6*2, GetSize()*0.6*2 + gpu_price);
} 

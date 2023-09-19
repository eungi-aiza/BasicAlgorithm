```cpp
#include "Electronics.h"
#include <iostream>
#include <vector>
using namespace std;

// Fill in here
void TV::SetSize(){
    Price = 1.8 * Size;
}

void Computer::SetSize(){
    Price = 0.6 * Size;
}

void Cellphone::SetSize(){
    Price = 0.7 * Size;
}

void Laptop::SetSize(){
    Price = 0.6 * Size;
    if (GPUs.size() != 0) Price *= 2;
    TotalPrice += Price;
    for (Electronics* gpu: GPUs){
        gpu -> SetSize();
        TotalPrice += gpu->Price; // 
    }
}

void TV::PrintSelf(){
    SetSize();
    printf("It is a TV, Size=%d, Price=%d\n", GetSize(), Price);
}

void Computer::PrintSelf(){
    SetSize();
    printf("It is a Computer, Size=%d, Price=%d\n", GetSize(), Price);
}

void Cellphone::PrintSelf(){
    SetSize();
    printf("It is a Cellphone, Size=%d, Price=%d\n", GetSize(), Price);
}

void Laptop::PrintSelf(){
    SetSize();
    printf("It is a Laptop with %d of GPU(s), Size=%d, Price=%d, Total Price=%d\n", 
        GetNumGPU(), GetSize(), Price, TotalPrice);
}

void Laptop::AddGPU(Electronics *aGPU) {
    GPUs.push_back(aGPU);
}
```
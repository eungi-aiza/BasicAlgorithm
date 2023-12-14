#include "Electronics.h"
#include <stdio.h>
// Fill in here


/* Electornics */
Electronics::Electronics(int Size_) {Size = Size_;}
int Electronics::GetSize(){return Size;};
void Electronics::SetSize(int Size_){Size = Size_;};

/* TV */
TV::TV(int Size_) : Electronics(Size_){}
void TV::PrintSelf(){
    printf("It is a TV, Size=%d, Price=%.f\n", Size, Size*1.8);
}

/* Computer */
Computer::Computer(int Size_) : Electronics(Size_){}
void Computer::PrintSelf(){
    printf("It is a Computer, Size=%d, Price=%.f\n", Size, Size*0.6);
}

/* Cellphone */
Cellphone::Cellphone(int Size_) : Electronics(Size_){}
void Cellphone::PrintSelf(){
    printf("It is a Cellphone, Size=%d, Price=%.f\n", Size, Size*0.7);
}

/* Laptop */
Laptop::Laptop(int Size_) : Computer(Size_), numGPU(0){} // 생성자에 numGPU도 0으로 초기화 해줘야함
void Laptop::PrintSelf(){
    if (numGPU)
        printf("It is a Laptop with %d GPU(s), Size=%d, Price=%.f, Total Price=%.f\n", numGPU, Size, Size*0.7, Size*1.4);
    else
        printf("It is a Laptop with 0 GPU(s), Size=%d, Price=%.f, Total Price=%.f\n", Size, Size*0.7, Size*0.7);
}

void Laptop::AddGPU(Electronics *aGPU){
    if (numGPU<2){
        numGPU++;
    }
}
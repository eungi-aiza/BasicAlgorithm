#pragma once
#include <vector>
using namespace std;

class Electronics {
    public:
    Electronics(float aSize); // Constructor
    virtual void SetSize(float aSize); // Set the Size
    virtual float GetSize(void); // accessors
    virtual void PrintSelf(void) = 0; // Pure virtual

    protected:
    float Size; // We could make this private
};

class TV : public Electronics {
    public:
    TV(float aSize);
    void PrintSelf(void);
};

class Computer : public Electronics {
    public:
    Computer(float aSize);
    void PrintSelf(void);
};

class Cellphone : public Electronics {
    public:
    Cellphone(float aSize);
    void PrintSelf(void);
};

class Laptop : public Computer {
    public:
    Laptop(float aSize);
    void PrintSelf(void);
    void AddGPU(Electronics *aGPU);
    
    int num_of_gpu = 0;
    vector<Electronics *> GPUs;
};
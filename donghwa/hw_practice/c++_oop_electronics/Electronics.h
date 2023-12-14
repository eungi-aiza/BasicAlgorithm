#pragma once

// Fill in here
class Electronics{
protected:
    int Size;
public:
    Electronics(int Size_); // constructor
    int GetSize();
    void SetSize(int Size_);
    virtual void PrintSelf(void) = 0; // pure virtual function
};

class TV : public Electronics{
public:
    TV(int Size);
    virtual void PrintSelf(void);
};

class Computer : public Electronics{
public:
    Computer(int Size);
    virtual void PrintSelf(void);
};

class Cellphone : public Electronics{
public:
    Cellphone(int Size);
    virtual void PrintSelf(void);
};

class Laptop : public Computer{
private:
    int numGPU;
public:
    Laptop(int Size);
    virtual void PrintSelf(void);
    void AddGPU(Electronics *aGPU);
};
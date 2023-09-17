#pragma once
#include <stdio.h>
#include <vector>
using namespace std;

// Fill in here
class Bear {
    public :
    Bear(float aWeight);
    float GetWeight(void);
    void SetWeight(float aWeight);
    virtual void PrintSelf(void)=0;

    protected :
    float weight;
};

class Polar : public Bear{
    public :
    Polar(float aWeight);
    void SetAggressiveness(void);
    float GetAggressiveness(void);
    virtual void PrintSelf(void) = 0;

    protected :
    float weight;
    float aggressiveness;
};


class Grizzly : public Bear{
    public :
    Grizzly(float aWeight);
    void SetAggressiveness(void);
    float GetAggressiveness(void);
    virtual void PrintSelf(void) = 0;

    protected :
    float weight;
    float aggressiveness;
};

class Black : public Bear{
    public :
    Black(float aWeight);
    void SetAggressiveness(void);
    float GetAggressiveness(void);
    virtual void PrintSelf(void) = 0;

    protected :
    float weight;
    float aggressiveness;
};

class Black_Momma : public Black{
    public :
    Black_Momma(float aWeight);
    
    void AddCub(Black *aCub);
    // Black *getCub(void);

    void SetAggressiveness(void);
    virtual float GetAggressivness(void) = 0;
    float TotalAggressiveness(void);
    virtual void PrintSelf(void) = 0;
    float GetNumCubs(void);

    protected:
    int num_cubs;
    vector<Black *> cubs;
};
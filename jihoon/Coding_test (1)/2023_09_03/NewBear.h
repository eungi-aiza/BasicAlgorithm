#pragma once

class Bear {
    public:
    Bear(float aWeight); // Constructor
    virtual void SetWeight(float aWeight); // Weight
    virtual float GetWeight(void); // accessors
    virtual float Aggressiveness(void) = 0; // Pure virtual
    virtual void PrintSelf(void) = 0; // Pure virtual

    protected:
    float Weight; // We could make this private
};

class Polar : public Bear {
    public:
    Polar(float aWeight);
    float Aggressiveness(void);
    void PrintSelf(void);
};


class Grizzly : public Bear {
    public:
    Grizzly(float aWeight);
    float Aggressiveness(void);
    void PrintSelf(void);
};

class Black : public Bear {
    public:
    Black(float aWeight);
    float Aggressiveness(void);
    void PrintSelf(void);
};

class Black_Momma : public Black {
    public:
    Black_Momma(float aWeight);
    float Aggressiveness(void);
    void PrintSelf(void);
    void AddCub(Bear *aCub);

    protected:
    Bear *cub1; 
    Bear *cub2; 
};
#pragma once

// Fill in here
class Bear{
    public:
        Bear(float aWeight);  
        void SetWeight(float aWeight);
        float GetWeight(void);
        
        virtual void PrintSelf(void) = 0;
        virtual float Aggressiveness(void) = 0;

    protected:
        float weight;
};


class Polar:public Bear{
    public :
        Polar(float _aWeight) : Bear(_aWeight){};
        virtual float Aggressiveness(void);
        virtual void PrintSelf(void);   
};
class Grizzly:public Bear{
    public :
        Grizzly(float _aWeight) : Bear(_aWeight){};
        virtual float Aggressiveness(void);
        virtual void PrintSelf(void);  
};
class Black:public Bear{
    public :
        Black(float _aWeight) : Bear(_aWeight){};
        virtual float Aggressiveness(void);
        virtual void PrintSelf(void);   
};

class Black_Momma:public Black{
    public:
        Black_Momma(float aWeight);

        void AddCub(Black *aCub);
        virtual void PrintSelf(void);
        virtual float Aggressiveness(void);
        virtual float TotalAggressiveness(void);

    protected:
        int count;
        Black *cub1;
        Black *cub2;
};
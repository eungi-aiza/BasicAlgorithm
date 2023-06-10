#include<iostream>
using namespace std;

// Encapsulation
class Encapsulation{
private:
    int x;
public:
    void set(int a){
        x = a;
    }
    int get(){
        return x;
    }
};

// Inheritance
class Parent{
public:
    void parentFunction(){
        cout << "This is a function in the parent class." << endl;
    }
};

class Child : public Parent {
public:
    void childFunction(){
        cout << "This is a function in the child class." << endl;
    }
};

// Polymorphism
class Base{
public:
    virtual void show(){
        cout << "Base class\n";
    }
};

class Derived : public Base{
public:
    void show(){
        cout << "Derived class\n";
    }
};

class AbstractClass{
public:
    virtual void pureVirtualFunction() = 0;
};

class ConcreteClass : public AbstractClass{
public:
    void pureVirtualFunction(){
        cout << "Implemented Virtual Function" << endl;
    }
};

int main(){
    // Encapsulation
    Encapsulation obj;
    obj.set(5);
    cout << "Encapsulation: " << obj.get() << endl;
    // Inheritance
    Child child;
    child.parentFunction();
    child.childFunction();
    // Polymorphism
    Base *base;
    Derived derived;
    base = &derived;
    base->show();

    // Abstraction
    ConcreteClass concrete;
    concrete.pureVirtualFunction();
}
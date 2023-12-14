/*
4. (40 pts) Consider the following code:
(a) Implement deep copy constructors for both IntArray and ArrayOfArrays. In these constructors, you chase pointers as deep as possible. (25 pts)
(b) Implement destructors for both IntArray and ArrayOfArrays. The destructors reclaim the spaces allocated to the integer arrays and the array of IntArray pointers. (15 pts)
*/

#include <iostream>

class IntArray {
public:
    IntArray(int size);
    IntArray(const IntArray &other);
    IntArray();
    ~IntArray();
    void initialize(int size);
    void set(int index, int value);
    void print() const;
private:
    int *myarray;
    int used;
    int max_size;
};

IntArray::IntArray(int size) : myarray(new int[size]), used(0), max_size(size) {}

IntArray::IntArray(const IntArray &other) 
    : myarray(new int[other.max_size]), used(other.used), max_size(other.max_size) {
    for (int i = 0; i < used; ++i) {
        myarray[i] = other.myarray[i];
    }
}
IntArray::IntArray() : myarray(nullptr), used(0), max_size(0) {}
IntArray::~IntArray() {
    delete[] myarray;
}

void IntArray::initialize(int size) {
    delete[] myarray; // delete the existing array
    myarray = new int[size];
    used = 0;
    max_size = size;
}

void IntArray::set(int index, int value) {
    if(index >= 0 && index < max_size) {
        myarray[index] = value;
        used = std::max(used, index + 1);
    }
}

void IntArray::print() const {
    for(int i = 0; i < used; ++i) {
        std::cout << myarray[i] << (i == used - 1 ? "" : ", ");
    }
    std::cout << '\n';
}

class ArrayOfArrays {
public:
    ArrayOfArrays(int size);
    ArrayOfArrays(const ArrayOfArrays &other);
    ArrayOfArrays();
    ~ArrayOfArrays();
    void initialize(int size);
    void set(int index, const IntArray &value);
    void print() const;
private:
    IntArray **myarray;
    int used;
    int max_size;
};

ArrayOfArrays::ArrayOfArrays(int size) 
    : myarray(new IntArray*[size]), used(0), max_size(size) {
    std::fill_n(myarray, size, nullptr);
}
ArrayOfArrays::ArrayOfArrays(const ArrayOfArrays &other) {
    used = other.used;
    max_size = other.max_size;
    myarray = new IntArray*[max_size];
    for (int i = 0; i < used; ++i) {
        myarray[i] = new IntArray(*(other.myarray[i]));
    }
}

ArrayOfArrays::ArrayOfArrays() : myarray(nullptr), used(0), max_size(0) {}
ArrayOfArrays::~ArrayOfArrays() {
    for(int i = 0; i < used; ++i) {
        delete myarray[i];
    }
    delete[] myarray;
}

void ArrayOfArrays::initialize(int size) {
    for(int i = 0; i < used; ++i) {
        delete myarray[i];
    }
    delete[] myarray;

    myarray = new IntArray*[size];
    std::fill_n(myarray, size, nullptr);
    used = 0;
    max_size = size;
}

void ArrayOfArrays::set(int index, const IntArray &value) {
    if(index >= 0 && index < max_size) {
        delete myarray[index];
        myarray[index] = new IntArray(value);
        used = std::max(used, index + 1);
    }
}

void ArrayOfArrays::print() const {
    for(int i = 0; i < used; ++i) {
        myarray[i]->print();
    }
}

int main() {
    // Test Case 1: Testing the deep copy functionality of IntArray
    IntArray arr1;
    // Assume a constructor that initializes an array with a given size
    arr1.initialize(5); 
    arr1.set(0, 1);
    arr1.set(1, 2);
    arr1.set(2, 3);
    arr1.set(3, 4);
    arr1.set(4, 5);

    IntArray arr2 = arr1; // This should call the copy constructor
		// IntArray arr2(arr1);

    arr1.set(0, 10); // Modify arr1, should not affect arr2

    // Assuming a method to print the array
    arr1.print(); // Output: 10, 2, 3, 4, 5
    arr2.print(); // Output: 1, 2, 3, 4, 5 (unchanged, proving deep copy)

    // Test Case 2: Testing the deep copy functionality of ArrayOfArrays
    ArrayOfArrays aoa1;
    // Assume a constructor that initializes an array with a given size
    aoa1.initialize(2); 

    aoa1.set(0, arr1);
    aoa1.set(1, arr2);

    ArrayOfArrays aoa2 = aoa1; // This should call the copy constructor

    IntArray arr3(5); // Create a new array with size 5
    arr3.set(0, 10); // Set the first value to 20
    arr3.set(1, 20); // Set the first value to 20
    arr3.set(2, 30); // Set the first value to 20
    arr3.set(3, 40); // Set the first value to 20
    arr3.set(4, 50); // Set the first value to 20
    aoa1.set(0, arr3); 

    // Assuming a method to print the ArrayOfArrays
    aoa1.print(); // Output: [10, 20, 30, 40, 50], [1, 2, 3, 4, 5]
    aoa2.print(); // Output: [10, 2, 3, 4, 5], [1, 2, 3, 4, 5] (unchanged, proving deep copy)

    return 0;
}
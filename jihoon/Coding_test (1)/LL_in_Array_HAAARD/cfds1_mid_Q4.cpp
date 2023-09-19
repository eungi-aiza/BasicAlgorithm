/*
4. (40 pts) Consider the following code:
(a) Implement deep copy constructors for both IntArray and ArrayOfArrays. In these constructors, you chase pointers as deep as possible. (25 pts)
(b) Implement destructors for both IntArray and ArrayOfArrays. The destructors reclaim the spaces allocated to the integer arrays and the array of IntArray pointers. (15 pts)
*/

class IntArray {
public:
    IntArray(const IntArray &other);
    ~IntArray();
private:
    int *myarray; // Data
    int used; // The number of valid elements in myarray
    int max_size; // The maximum number of elements in myarray
    // Unused indices have garbage values
};
class ArrayOfArrays {
public:
    ArrayOfArrays(const ArrayOfArrays &other);
    ~ArrayOfArrays();
private:
    IntArray **myarray; // An array of IntArray pointers
    int used; // the number of valid arrays in myarray
    int max_size; // the maximum number of arrays in myarray
    // Unused indices have garbage values
};

IntArray::IntArray(const IntArray &other) {
    used = other.used;
    max_size = other.max_size;
    myarray = new int[max_size];

    for (int i = 0; i < used; ++i) {
        myarray[i] = other.myarray[i];
    }
}

ArrayOfArrays::ArrayOfArrays(const ArrayOfArrays &other) {
    used = other.used;
    max_size = other.max_size;
    myarray = new IntArray*[max_size];
    for (int i = 0; i < used; ++i) {
        myarray[i] = new IntArray(*(other.myarray[i]));
    }
}

IntArray::~IntArray() {
    delete[] myarray;
}

ArrayOfArrays::~ArrayOfArrays() {
    for (int i = 0; i < used; ++i) {
        delete myarray[i];
    }
    delete[] myarray;
}
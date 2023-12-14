// Destructor for IntArray
IntArray::~IntArray() {
    // Deallocate the dynamically allocated memory
    delete[] myarray;
    myarray = nullptr;
}

// Destructor for ArrayOfArrays
ArrayOfArrays::~ArrayOfArrays() {
    // Deallocate the dynamically allocated memory for each IntArray
    for (int i = 0; i < used; ++i) {
        delete myarray[i];
    }

    // Deallocate the array of IntArray pointers
    delete[] myarray;
    myarray = nullptr;
}

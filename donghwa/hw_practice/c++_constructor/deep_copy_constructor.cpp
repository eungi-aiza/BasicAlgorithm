// Deep copy constructor for IntArray
IntArray::IntArray(const IntArray &other) {
    // Allocate memory for myarray
    myarray = new int[other.max_size];
    
    // Copy the contents from other
    for (int i = 0; i < other.used; ++i) {
        myarray[i] = other.myarray[i];
    }
    
    // Copy other attributes
    used = other.used;
    max_size = other.max_size;
}

// Deep copy constructor for ArrayOfArrays
ArrayOfArrays::ArrayOfArrays(const ArrayOfArrays &other) {
    // Allocate memory for myarray (array of IntArray pointers)
    myarray = new IntArray*[other.max_size];
    
    // Copy the contents from other
    for (int i = 0; i < other.used; ++i) {
        myarray[i] = new IntArray(*other.myarray[i]); // Create a deep copy of IntArray
    }
    
    // Copy other attributes
    used = other.used;
    max_size = other.max_size;
}

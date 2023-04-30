
#include <iostream>
#include <list>

int main() {
    std::list<int> L = {1, 2};
    // t is pointing to the position where 1 is located
    std::list<int>::iterator t = L.begin();
    L.push_front(10); // 10, 1, 2
    
    // prints the value pointed by t, which is 1
    std::cout << *t << std::endl; 
    L.push_back(5); // 10, 1, 2, 5
    
    // insert before the position pointed to by t, which is 1, so the list becomes 10, 6, 1, 2, 5
    L.insert(t, 6);
    // move t to the next position, which is where 2 is located
    t++; 
    
    // remove the element pointed to by t, which is 2, and move t to the next element, which is 5
    t = L.erase(t); 
    
    std::cout << *t << std::endl;
    for (auto i : L) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    for (std::list<int>::iterator it = L.begin(); it != L.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}

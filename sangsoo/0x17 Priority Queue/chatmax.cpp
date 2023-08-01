#include<iostream>
using namespace std;

const int MAX_ELEMENT = 20;

class Element {
public:
    int key;
    Element(int value = 0) : key(value) {}
};

class HeapType {
private:
    Element heap[MAX_ELEMENT];
    int heap_size;

public:
    HeapType() : heap_size(0) {}

    void insert_max_heap(const Element& item) {
        int i = ++heap_size;
        while (i != 1 && item.key > heap[i / 2].key) {
            heap[i] = heap[i / 2];
            i /= 2;
        }
        heap[i] = item;
    }

    Element delete_max_heap() {
        Element item = heap[1];
        Element temp = heap[heap_size--];

        int parent = 1, child = 2;
        while (child <= heap_size) {
            if (child < heap_size && heap[child].key < heap[child + 1].key)
                child++;
            if (temp.key >= heap[child].key)
                break;
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        return item;
    }

    void print_heap() {
        for (int k = 1; k <= heap_size; k++)
            cout << heap[k].key << " ";
        cout << endl;
    }
};

int main() {
    Element e1(3), e2(5), e3(1), e4(7), e5(4);
    Element a1;

    HeapType heap;

    heap.insert_max_heap(e1);
    heap.insert_max_heap(e2);
    heap.insert_max_heap(e3);
    heap.insert_max_heap(e4);
    heap.insert_max_heap(e5);

    heap.print_heap();

    a1 = heap.delete_max_heap();
    cout << "\n\nmax value deleted: " << a1.key << "\n\n";

    heap.print_heap();
    
    return 0;
}

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// A functor that compares two pairs by their second element (priority) in reverse order
struct reverse_second {
  bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  }
};

// A priority queue class with min-heap using std::pair
template <typename T, typename Compare = reverse_second>
class min_heap {
  private:
    vector<pair<T, int>> data; // the underlying container
    Compare comp; // the comparison function or functor

    // Swap two elements in the vector
    void swap(int i, int j) {
      pair<T, int> temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }

    // Move an element up the heap until it satisfies the heap property
    void siftup(int i) {
      while (i > 0 && comp(data[i], data[(i - 1) / 2])) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
      }
    }

    // Move an element down the heap until it satisfies the heap property
    void siftdown(int i) {
      while (2 * i + 1 < data.size()) {
        int min_child = 2 * i + 1;
        if (2 * i + 2 < data.size() && comp(data[2 * i + 2], data[min_child])) {
          min_child = 2 * i + 2;
        }
        if (comp(data[min_child], data[i])) {
          swap(i, min_child);
          i = min_child;
        } else {
          break;
        }
      }
    }

  public:
    // Create an empty priority queue
    min_heap() {}

    // Create a priority queue with a custom comparison function or functor
    min_heap(Compare c) : comp(c) {}

    // Check if the priority queue is empty
    bool empty() {
      return data.empty();
    }

    // Return the size of the priority queue
    int size() {
      return data.size();
    }

    // Insert a new element with a given priority into the priority queue
    void push(T x, int priority) {
      data.push_back(make_pair(x, priority)); // add the new element at the end of the vector
      siftup(data.size() - 1); // move it up to its proper position
    }

    // Remove and return the element with the highest priority from the priority queue
    pair<T, int> pop() {
      if (data.empty()) {
        throw runtime_error("Cannot pop from an empty heap.");
      }
      pair<T, int> top = data[0]; // save the element at the root
      swap(0, data.size() - 1); // replace it with the last element in the vector
      data.pop_back(); // remove the last element from the vector
      siftdown(0); // move the root element down to its proper position
      return top; // return the saved element
    }

    // Return the element with the highest priority from the priority queue
    pair<T, int> peek() {
      if (data.empty()) {
        throw runtime_error("Cannot peek into an empty heap.");
      }
      return data[0]; // return the element at the root
    }
};

int main() {

   // Create a priority queue of int with reverse_second as the comparison functor
   min_heap<int> pq;

   // Insert some elements with different priorities
   pq.push('A', 3);
   pq.push('B', 1);
   pq.push('C', 2);

   // Remove and print the elements in order of priority
   while (!pq.empty()) {
     cout << char(pq.pop().first) << endl; // B, C, A
   }

   return 0;
}

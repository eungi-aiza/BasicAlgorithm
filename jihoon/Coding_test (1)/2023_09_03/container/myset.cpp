#include "myset.h"

void MySet::Insert(int data) {
  // TODO: insert 'data' into set
  // Check if data exists in RBT, if not insert, if yes do not insert
  if (!(set.Search(set.GetRoot(), data))) {
    set.Insert(data);
    size += 1;
  }
}

void MySet::Erase(int data) {
  // TODO: erase 'data' from set
  // If data exists in RBT
  if (set.Search(set.GetRoot(), data)) {
    set.Delete(set.Search(set.GetRoot(), data));
    size -= 1;
  }
}

bool MySet::Find(int data) {
  // TODO: return true if 'data' exists in the set
  if (set.Search(set.GetRoot(), data)) {
    return true;
  }
  return false;
}

size_t MySet::Size() {
  // TODO: return number of elements in the set
  return size;
}

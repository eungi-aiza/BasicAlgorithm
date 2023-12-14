#include "myset.h"

void MySet::Insert(int data) {
  // TODO: insert 'data' into set
  if (!myRBT.Search(myRBT.GetRoot(), data)){
    myRBT.Insert(data);
    num++;
  }
}

void MySet::Erase(int data) {
  // TODO: erase 'data' from set
  if (myRBT.Search(myRBT.GetRoot(), data)){
    RBT::Node* target = myRBT.Search(myRBT.GetRoot(), data);
    myRBT.Delete(target);
    num--;
  }
}

bool MySet::Find(int data) {
  // TODO: return true if 'data' exists in the set
  if (!myRBT.Search(myRBT.GetRoot(), data)){
    return false; 
  }
  return true;
}

size_t MySet::Size() {
  // TODO: return number of elements in the set
  return num;
}
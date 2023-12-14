#pragma once

#include "bst.h"
#include "rbt.h"

class MySet {
  public:
  void Insert(int data);
  void Erase(int data);
  
  bool Find(int data);
  size_t Size();

  RBT set;
  int size = 0;
};

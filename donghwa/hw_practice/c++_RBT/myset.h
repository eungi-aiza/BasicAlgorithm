#pragma once

#include "bst.h"
#include "rbt.h"

class MySet {
public:
  void Insert(int data);
  void Erase(int data);
  bool Find(int data);
  size_t Size();
  size_t num;
  RBT myRBT;
  MySet(size_t num) : num(0){}
  MySet() : num(0){}
};
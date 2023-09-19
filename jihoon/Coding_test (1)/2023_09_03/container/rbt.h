#pragma once

#include <string>

enum Color {
  COLOR_BLACK,
  COLOR_RED
};

class RBT {
public:
  class Node {
  public:
    Node(int key, Node* parent, Node* left, Node* right,
        enum Color color) {
      this->key = key;
      this->parent = parent;
      this->left = left;
      this->right = right;
      this->color = color;
    }
  
    int key;
    Node* parent;
    Node* left;
    Node* right;
    enum Color color;
  };

  RBT();

  void Insert(int key);
  void Delete(Node* z);

	void Preorder(Node* node);
	void Inorder(Node* node);
	void Postorder(Node* node);

  Node* Search(Node* node, int key);

  Node* Maximum(Node* node);
  Node* Minimum(Node* node);

  Node* Successor(Node* x);
  Node* Predecessor(Node* x);

  Node* GetRoot() { return this->root; }

  void Print();

private:
  Node* root;
  Node* Tnil;

  void InsertFixUp(Node* k);
  void LeftRotate(Node* x);
  void RightRotate(Node* x);
  void DeleteFixUp(Node* x);
  void Transplant(Node* u, Node* v);

  void _print(Node* root, std::string indent, bool last);
};


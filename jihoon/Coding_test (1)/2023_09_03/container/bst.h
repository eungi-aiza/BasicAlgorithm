#pragma once

#include <string>

class BST {
public:
  class Node {
  public:
    Node(int key) {
      this->key = key;
      this->parent = NULL;
      this->left = NULL;
      this->right = NULL;
    }
  
    int key;
    Node* parent;
    Node* left;
    Node* right;
  };

	BST() : root(NULL) {};

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

	Node* GetRoot() { return root; }

	void Print();

private:
  void transplant(Node* u, Node* v);
	void _print(Node* root, std::string indent, bool last);

	Node* root;
};

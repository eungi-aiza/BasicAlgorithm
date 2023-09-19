#include <iostream>
#include "rbt.h"

using namespace std;

RBT::RBT() {
  Tnil = new Node(0, NULL, NULL, NULL, COLOR_BLACK);
  root = Tnil;
}

void RBT::Insert(int key) {
  Node* z = new Node(key, NULL, Tnil, Tnil, COLOR_RED);

  Node* x = this->root;
  Node* y = NULL;

  while (x != Tnil) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  // found the location - insert z with parent y
  z->parent = y;

  if (y == NULL) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }

  // if new node is a root node, simply return
  if (z->parent == NULL){
    z->color = COLOR_BLACK;
    return;
  }

  // if the grandparent is null, simply return
  if (z->parent->parent == NULL) {
    return;
  }

  InsertFixUp(z);
}

void RBT::Delete(Node* z) {
  Node* x;

  Node* y = z;
  int y_original_color = y->color;
  if (z->left == Tnil) {
    x = z->right;
    Transplant(z, z->right);
  } else if (z->right == Tnil) {
    x = z->left;
    Transplant(z, z->left);
  } else {
    y = Minimum(z->right);
    y_original_color = y->color;
    x = y->right;
    if (y->parent == z) {
      x->parent = y;
    } else {
      Transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }

    Transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  delete z;

  if (y_original_color == COLOR_BLACK){
    DeleteFixUp(x);
  }
}

void RBT::Preorder(Node* node) {
  if (node != Tnil) {
    cout << node->key << " ";
    Preorder(node->left);
    Preorder(node->right);
  } 
}

void RBT::Inorder(Node* node) {
  if (node != Tnil) {
    Inorder(node->left);
    cout << node->key << " ";
    Inorder(node->right);
  } 
}

void RBT::Postorder(Node* node) {
  if (node != Tnil) {
    Postorder(node->left);
    Postorder(node->right);
    cout << node->key << " ";
  } 
}

RBT::Node* RBT::Search(Node* node, int key) {
  if (key == node->key) {
    return node;
  }
  else if (node == Tnil) {
    return NULL;
  }

  if (key < node->key)
    return Search(node->left, key);
  else
    return Search(node->right, key);
}

RBT::Node* RBT::Maximum(Node* node) {
  while (node->right != Tnil) {
    node = node->right;
  }
  return node;
}

RBT::Node* RBT::Minimum(Node* node) {
  while (node->left != Tnil) {
    node = node->left;
  }
  return node;
}

RBT::Node* RBT::Successor(Node* x) {
  if (x->right != Tnil) {
    return Minimum(x->right);
  }

  Node* y = x->parent;
  while (y != Tnil && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

RBT::Node* RBT::Predecessor(Node* x) {
  if (x->left != Tnil) {
    return Maximum(x->left);
  }

  Node* y = x->parent;
  while (y != Tnil && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

void RBT::InsertFixUp(Node* z) {
  Node* y;
  while (z->parent->color == COLOR_RED) {
    if (z->parent == z->parent->parent->right) {
      y = z->parent->parent->left;
      if (y->color == COLOR_RED) {
        // case 1
        y->color = COLOR_BLACK;
        z->parent->color = COLOR_BLACK;
        z->parent->parent->color = COLOR_RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          // case 2
          z = z->parent;
          RightRotate(z);
        }
        // case 3
        z->parent->color = COLOR_BLACK;
        z->parent->parent->color = COLOR_RED;
        LeftRotate(z->parent->parent);
      }
    } else {
      y = z->parent->parent->right;

      if (y->color == COLOR_RED) {
        y->color = COLOR_BLACK;
        z->parent->color = COLOR_BLACK;
        z->parent->parent->color = COLOR_RED;
        z = z->parent->parent;	
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          LeftRotate(z);
        }
        z->parent->color = COLOR_BLACK;
        z->parent->parent->color = COLOR_RED;
        RightRotate(z->parent->parent);
      }
    }
    if (z == root) {
      break;
    }
  }
  root->color = COLOR_BLACK;
}

void RBT::LeftRotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (y->left != Tnil) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    this->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void RBT::RightRotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (y->right != Tnil) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    this->root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

void RBT::DeleteFixUp(Node* x) {
  Node* w;
  while (x != root && x->color == COLOR_BLACK) {
    if (x == x->parent->left) {
      w = x->parent->right;
      if (w->color == COLOR_RED) {
        w->color = COLOR_BLACK;
        x->parent->color = COLOR_RED;
        LeftRotate(x->parent);
        w = x->parent->right;
      }

      if (w->left->color == COLOR_BLACK && w->right->color == COLOR_BLACK) {
        w->color = COLOR_RED;
        x = x->parent;
      } else {
        if (w->right->color == COLOR_BLACK) {
          w->left->color = COLOR_BLACK;
          w->color = COLOR_RED;
          RightRotate(w);
          w = x->parent->right;
        } 

        w->color = x->parent->color;
        x->parent->color = COLOR_BLACK;
        w->right->color = COLOR_BLACK;
        LeftRotate(x->parent);
        x = root;
      }
    } else {
      w = x->parent->left;
      if (w->color == COLOR_RED) {
        w->color = COLOR_BLACK;
        x->parent->color = COLOR_RED;
        RightRotate(x->parent);
        w = x->parent->left;
      }

      if (w->left->color == COLOR_BLACK && w->right->color == COLOR_BLACK) {
        w->color = COLOR_RED;
        x = x->parent;
      } else {
        if (w->left->color == COLOR_BLACK) {
          w->right->color = COLOR_BLACK;
          w->color = COLOR_RED;
          LeftRotate(w);
          w = x->parent->left;
        } 

        w->color = x->parent->color;
        x->parent->color = COLOR_BLACK;
        w->left->color = COLOR_BLACK;
        RightRotate(x->parent);
        x = root;
      }
    } 
  }
  x->color = COLOR_BLACK;
}

void RBT::Transplant(Node* u, Node* v){
  if (u->parent == NULL) {
    root = v;
  }
  else if (u == u->parent->left){
    u->parent->left = v;
  }
  else {
    u->parent->right = v;
  }
  v->parent = u->parent;
}

void RBT::_print(Node* root, string indent, bool last) {
  if (root != Tnil) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "     ";
    } else {
      cout << "L----";
      indent += "|    ";
    }

    string sColor =
      (root->color == COLOR_BLACK) ? "BLACK" : "RED";
    cout << root->key << " (" << sColor << ")" << endl;
    _print(root->left, indent, false);
    _print(root->right, indent, true);
  }
}

void RBT::Print() {
  if (GetRoot() != NULL)
    _print(GetRoot(), "", true);
}

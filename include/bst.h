// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
#include <algorithm>

template < typename T >
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };

 private:
  Node* root;
  Node* addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->left = root->right = nullptr;
    } else if (root->value > value) {
      root->left = addNode(root->left, value);
    } else if (root->value < value) {
      root->right = addNode(root->right, value);
    } else {
      root->count++;
    }
    return root;
  }
  int depthTree(Node* root) {
    if (root == nullptr) {
      return 0;
    } else {
      int leftDepth = depthTree(root->left);
      int rightDepth = depthTree(root->right);
      return std::max(leftDepth, rightDepth) + 1;
    }
  }
  int searchNode(Node* root, T value) {
    if (root == nullptr)
      return 0;
    else if (root->value == value)
      return root->count;
    else if (root->value > value)
      return searchNode(root->left, value);
    else
    return searchNode(root->right, value);
  }

 public:
  BST() : root(nullptr) {}
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return depthTree(root) - 1;
  }
  int search(T value) {
    return searchNode(root, value);
  }
};
#endif  // INCLUDE_BST_H_

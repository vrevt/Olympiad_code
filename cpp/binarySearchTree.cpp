#include <algorithm>
#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <vector>
#include <set>
 
using namespace std;
 
class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr), size_(0) {}
 
  ~BinarySearchTree() {
    delete root_;
  }
 
  bool Contains(int value) const;
 
  void Add(int value);
 
  void Erase(int value);
 
  int Size() const;
 
  vector<int> ToSortedArray() const;
 
 protected:
  struct Node {
    int value;
    Node *parent;
    Node *left;
    Node *right;
 
    Node(int value, Node *parent) : value(value),
                                    parent(parent),
                                    left(nullptr),
                                    right(nullptr) {}
    ~Node() {
      delete left;
      delete right;
    }
  };
 
  Node *root_;
  int size_;
 
  Node *Find(int value) const;
 
  void Detach(Node *target_node);
  void Swap(Node *parentik, Node *son);
 
  Node *GetLeftmostNode(Node *node) const;
  Node *GetRightmostNode(Node *node) const;
 
  void AppendToSortedArray(Node *node, std::vector<int> *res) const;
};
 
bool BinarySearchTree::Contains(int value) const {
  return (Find(value));
}
 
void BinarySearchTree::Add(int value) {
  size_++;
 
  if (root_ == nullptr) {
    root_ = new Node(value, nullptr);
    return;
  }
 
  Node *temp = root_;
  while (1) {
    if (temp->value > value) {
      if (temp->left != nullptr) {
        temp = temp->left;
      } else {
        temp->left = new Node(value, temp);
        return;
      }
    } else {
      if (temp->right != nullptr) {
        temp = temp->right;
      } else {
        temp->right = new Node(value, temp);
        return;
      }
    }
  }
}
 
void BinarySearchTree::Erase(int value) {
  Node *temp = Find(value);
  Detach(temp);
  delete temp;
}
 
int BinarySearchTree::Size() const {
  return size_;
}
 
vector<int> BinarySearchTree::ToSortedArray() const {
  vector<int> elements;
  AppendToSortedArray(root_, &elements);
  return elements;
}
 
BinarySearchTree::Node *BinarySearchTree::Find(int value) const {
  Node *temp = root_;
  while (temp != nullptr) {
    if (temp->value == value) break;
    if (temp->value < value) {
      temp = temp->right;
    } else {
      temp = temp->left;
    }
  }
  return temp;
}
 
void BinarySearchTree::Detach(BinarySearchTree::Node *target_node) {
  Node *temp = target_node;
 
  if (temp == nullptr) return;
  size_--;
 
   if (temp->left == nullptr) {
    Swap(temp, temp->right);
  } else if (temp->right == nullptr) {
    Swap(temp, temp->left);
  } else {
    Node *rightNode = GetLeftmostNode(temp->right);
    if (rightNode->parent != temp) {
      Swap(rightNode, rightNode->right);
      rightNode->right = temp->right;
      rightNode->right->parent = rightNode;
    }
    Swap(temp, rightNode);
    rightNode->left = temp->left;
    rightNode->left->parent = rightNode;
  }
  temp->left = nullptr;
  temp->right = nullptr;
  temp->parent = nullptr;
}
 
void BinarySearchTree::Swap(Node *parentik, Node *son) {
  if (parentik->parent == nullptr) {
    root_ = son;
  } else if (parentik->parent->left == parentik) {
    parentik->parent->left = son;
  } else {
    parentik->parent->right = son;
  }
  if (son != nullptr) {
    son->parent = parentik->parent;
  }
}
 
BinarySearchTree::Node *BinarySearchTree::GetLeftmostNode(Node *node) const {
  while (node->left != nullptr) node = node->left;
  return node;
}
 
BinarySearchTree::Node *BinarySearchTree::GetRightmostNode(Node *node) const {
  while (node->right != nullptr) node = node->right;
  return node;
}
 
void BinarySearchTree::AppendToSortedArray(Node *node, vector<int> *res) const {
  if (node == nullptr) return;
  AppendToSortedArray(node->left, res);
  res->push_back(node->value);
  AppendToSortedArray(node->right, res);
}
 
#ifndef IGNORE_MAIN
int main() {
  const int kQueriesCount = 50'000;
  const std::vector<int>
      kElementsMaxValues({1, 2, 5, 13, 42, 1024, 1'000'000'000});
 
  mt19937_64 random_generator(2018);
  for (const int max_element_value : kElementsMaxValues) {
    vector<int> elements;
    BinarySearchTree tree;
 
    for (int i = 0; i < kQueriesCount; ++i) {
      int query_type = random_generator() % 3;
 
      switch (query_type) {
        case 0: {
          int value;
          if (elements.empty() || random_generator() % 100 < 75) {
            value = random_generator() % max_element_value;
            value -= max_element_value / 2;
          } else {
            value = elements[random_generator() % elements.size()];
          }
 
          elements.push_back(value);
          sort(elements.begin(), elements.end());
          tree.Add(value);
          break;
        }
        case 1: {
          int value;
          if (elements.empty() || random_generator() % 100 < 40) {
            value = random_generator() % max_element_value;
            value -= max_element_value / 2;
          } else {
            value = elements[random_generator() % elements.size()];
          }
 
          bool result = tree.Contains(value);
          bool expected_result =
              std::find(elements.begin(), elements.end(), value)
                  != elements.end();
          assert(result == expected_result);
          break;
        }
        case 2: {
          int value;
          if (elements.empty() || random_generator() % 100 < 25) {
            value = random_generator() % max_element_value;
            value -= max_element_value / 2;
          } else {
            value = elements[random_generator() % elements.size()];
          }
 
          auto element_it = std::find(elements.begin(), elements.end(), value);
          if (element_it != elements.end()) {
            elements.erase(element_it);
          }
          tree.Erase(value);
          break;
        }
        default: {
          break;
        }
      }
 
      assert(elements.size() == tree.Size());
      assert(elements == tree.ToSortedArray());
    }
 
    cout << "Passed: max_element_value = " << max_element_value << endl;
  }
 
  return 0;
}
#endif

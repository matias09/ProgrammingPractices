#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <initializer_list>
#include <iostream>

#include <stdlib.h>
#include <stdint.h>

template <typename T>
class DoubleList
{
  struct Node
  {
    T     value;
    Node* next;
    Node* prev;
  };

public:
  explicit DoubleList()
    : head(nullptr), length_(0) {}

  explicit DoubleList(std::initializer_list<T> elements)
    : head(nullptr), length_(0)
  {
    for (auto const & e : elements)
      Insert(e);
  }

  ~DoubleList()
  {
    if (length_ == 0)
      return;

    Node* tmp = nullptr;

    while (head != nullptr) {
      tmp = head;
      head = head->next;

      free(tmp);
      tmp = nullptr;
    }
  }

  bool Insert(T const & e)
  {
    if (length_ == 0) {
      head = MakeNode();
      head->value = e;
    } else {
      Node* new_node = MakeNode();
      new_node->value = e;

      new_node->next = head;
      head->prev = new_node;

      head = new_node;
    }

    ++length_;
    return true;
  }

  bool Erase()
  {
    if (length_ == 0)
      return false;

    Node* tmp = head;
    head = head->next;

    free(tmp);
    tmp = nullptr;

    --length_;
    return true;
  }

  void Print()
  {
    Node* tmp = head;

    for (size_t i = 0; i < length_; ++i, tmp = tmp->next)
      std::cout << tmp->value << ' ';
  }

  std::size_t length() const { return length_; }

private:
  Node* MakeNode() const
  {
     Node* new_node = static_cast<Node*>( malloc( sizeof(Node) ) );
     new_node->next = nullptr;
     new_node->prev = nullptr;
     new_node->value = 0;

     return new_node;
  }

  Node* head;
  std::size_t length_;
};

#endif // DOUBLE_LIST_H
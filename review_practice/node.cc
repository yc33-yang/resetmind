// Copyright 2018 yc33-yang

#include "node.h"

Node::Node(char data) : data(data), prev(nullptr), next(nullptr) {
 // nothing to do more
}

char Node::GetData() {
 return data;
}

Node* Node::GetPreviousNode() {
  return prev;
}

Node* Node::GetNextNode() {
  return next;
}

Node* Node::InsertPreviousNode(char data) {
 Node * newNode = new Node(data, prev, this);
 if (newNode)
 {
  if (prev) {
   prev->next = newNode;
  }
  prev = newNode;
 }
 return newNode;
}

Node* Node::InsertNextNode(char data) {
 Node * newNode = new Node(data, this, next);
 if (newNode)
 {
  if (next) {
   next->prev = newNode;
  }
  next = newNode;

 }
 return newNode;
}

bool Node::ErasePreviousNode() {
 if (prev)
 {
  Node *toRemove = prev;
  prev = prev->prev;
  if (prev)
  {
   prev->next = this;
  }
  delete toRemove;
  return true;
 }
 return false;
}

bool Node::EraseNextNode() {
 if (next)
 {
  Node *toRemove = next;
  next = next->next;
  if (next)
  {
   next->prev = this;
  }
  delete toRemove;
  return true;
 }
 return false;
}

// Copyright 2018 yc33-yang

#ifndef NODE_H_
#define NODE_H_

class Node {
 char data;
 Node *prev, *next;

 Node(char _data, Node *_prev, Node *_next) : data(_data), prev(_prev), next(_next) {
  // nothing to do more
 }

 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();
};

#endif  // NODE_H_

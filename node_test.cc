// Copyright 2018 yc33-yang
#if 0
2 Implementation
2.1 class Node
We will implement Node type denoting each node of linked list.
    +----------+---------Node-Type---------+----------+
    | Previous |                           |    Next  |
<---+--        |  Internal char type data  |        --+--->
    |  Node    |                           |    Node  |
    +----------+---------------------------+----------+

One public constructor and five public functions should be implemented.

 explicit Node(char data) : 
		This constructor should make Node storing data as internal data.
 char GetData() : 
		This function should return internal data.
 Node* InsertPreviousNode(char data) : 
		This function should make new Node with given data and Insert between 
		previous node and this node. (with new keyword of C++)
		This function should return pointer of inserted node.
 Node* InsertNextNode(char data) : 
		This function should make new Node with given
		data and Insert between next node and this node. (with new keyword of C++) This
		function should return pointer of inserted node.
 Node* GetPreviousNode() : 
		This function should return set previous node with Insert -
		PreviousNode method.If not set, this function should return nullptr.
 Node* GetNextNode() : 
		This function should return set next node with InsertNextNode.
		If not set, this function should return nullptr.
 bool ErasePreviousNode() : 
		This function should erase previous node and deallocate.
		(with delete keyword of C++) If previous node does not exist so erase was unsuccessful,
		you should return false.Otherwise, you should return true.
 bool EraseNextNode() : 
		This function should erase previous node and deallocate. (with
		delete keyword of C++) If next node does not exist so erase was unsuccessful, you should
		return false.Otherwise, you should return true.

Making another private functions or members are free.It is NOT recommended to use
global variables.

You can verify correctness of this class Node with judging system.


#endif

#include "node.h"
#include "node_test.h"
#include "test.h"
#include <stdlib.h>
#include <time.h>

class NodeConstructorTestSuite
{
private:
  template <class T> static void _swap(T&a, T&b) { T t = a; a = b; b = t; }

  static void _fill_from_to(Node &node, char from, char to, bool forward=true)
  {
	  if (from > to) { _swap(from, to); }
	  for (char c = from; c <= to; c++)
	  {
		  forward ? node.InsertPreviousNode(c) : node.InsertNextNode(c);
	  }
  }

  static void _fill_forward_AZ(Node &node) {  _fill_from_to(node, 'A', 'Z');  }
  static void _fill_backward_AZ(Node &node) { _fill_from_to(node, 'A', 'Z', false); }
  static Node* _FirstNode(Node &node)
  {
	  Node *cur = &node;
	  while (cur)
	  {
		  Node *prev = cur->GetPreviousNode();
		  if (prev == &node)
		  {
			  // cannot revisit
			  return NULL;
		  }
		  if (prev)
		  {
			  cur = prev;
		  }
		  else
			  break;
	  }
	  return cur;
  }
  static Node* _LastNode(Node &node)
  {
	  Node *cur = &node;
	  while (cur)
	  {
		  Node *next = cur->GetNextNode();
		  if (next == &node)
		  {
			  // cannot revisit
			  return NULL;
		  }
		  if (next)
		  {
			  cur = next;
		  }
		  else
			  break;
	  }
	  return cur;
  }

  static bool _canNavigate(Node &node)
  {
	  Node *first = _FirstNode(node);
	  Node *last = _LastNode(*first);
	  return first == _FirstNode(*last);
  }
  
  static void SingleNodeTest() {
	  Node node('A');
	  EXPECT_EQ(node.GetData(), 'A');
  }

  static void AtoZTest()
  {
	  Node *node = new Node(' ');
	  _fill_forward_AZ(*node);
	  _fill_backward_AZ(*node);
	  EXPECT_TRUE(_canNavigate(*node));

	  node->EraseNextNode();
	  node->ErasePreviousNode();
	  EXPECT_TRUE(_canNavigate(*node));

	  Node *leftNode = _FirstNode(*node);
	  Node *rightNode = _LastNode(*node);

	  leftNode->EraseNextNode();
	  leftNode->ErasePreviousNode();
	  rightNode->EraseNextNode();
	  rightNode->ErasePreviousNode();
	  EXPECT_TRUE(_canNavigate(*node));

	  // destructing
	  leftNode = _FirstNode(*node);
	  while (leftNode->EraseNextNode()) ; //do nothing

  }

  inline static char randData() { return rand() % 256; }
  inline static int  randOperation() { return rand() % 10; }

  static void doRandom()
  {
	  int operation;
	  char data;
	  
	  int doCount = 500 + (rand() % 9999);

	  Node *seedNode = new Node(randData());
	  Node *cur = seedNode, *moveTo = seedNode;

	  for (int i = 0; i < doCount; i++)
	  {
		  if (moveTo) {
			  cur = moveTo;
		  }

		  operation = randOperation();
		  data = randData();

		  switch (operation)
		  {
		  case 0: case 6:
			  moveTo = cur->InsertPreviousNode(data);
			  break;
		  case 1: case 7:
			  moveTo = cur->InsertNextNode(data);
			  break;
		  case 2: case 8:
			  moveTo = cur->GetPreviousNode();
			  break;
		  case 3: case 9:
			  moveTo = cur->GetNextNode();
			  break;
		  case 4:
			  cur->ErasePreviousNode();
			  break;
		  case 5:
			   cur->EraseNextNode();
			  break;
		  }
		  ASSERT_TRUE(_canNavigate(*cur));
		  printf("%c", cur->GetData());
	  }
	  printf("\ncongrat! %d\n", doCount);
	  cur = _FirstNode(*seedNode);
	  while (cur->EraseNextNode())
		  ASSERT_TRUE(_canNavigate(*cur));
	  delete cur;
  }

public:
  static void RunTest() {
    SingleNodeTest();
	AtoZTest();
	doRandom();
    // add more..
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void NodeTest() {
	srand((unsigned int)time(nullptr) + clock());

  NodeConstructorTestSuite::RunTest();
  // add more..
}


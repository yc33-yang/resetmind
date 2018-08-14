// Copyright 2018 yc33-yang

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
  Node *home, *end, *cursor;
  int  countChar;
 
 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_

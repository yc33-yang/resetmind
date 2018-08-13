// Copyright 2018 yc33-yang

#include "typing_machine.h"

const int MAX_CHAR_PER_LINE = 100;

TypingMachine::TypingMachine() {
	const char SOL = '\0', EOL = '\n';
	home = new Node(SOL);
	end = home->InsertNextNode(EOL);
	cursor = end;
	countChar = 0;
}

void TypingMachine::HomeKey() {
	cursor = home->GetNextNode();
}

void TypingMachine::EndKey() {
	cursor = end;
}

void TypingMachine::LeftKey() {
	Node *prev = cursor->GetPreviousNode();
	if (prev != home)
	{
		cursor = prev;
	}
}

void TypingMachine::RightKey() {
	Node *next = cursor->GetNextNode();
	if (next != nullptr)
	{
		cursor = next;
	}
}

inline bool isValidChar(char c) {
	return (' ' <= c) && (c <= '~');
}

bool TypingMachine::TypeKey(char key) {
	if (! isValidChar(key)) {
		return false;
	}
	if (countChar >= MAX_CHAR_PER_LINE)
	{
		return false;
	}
	Node *prev = cursor->InsertPreviousNode(key);
	if (prev == nullptr)
	{
		return false;
	}
	countChar++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (cursor->GetPreviousNode() == home)
	{
		return false;
	}
	bool ret = cursor->ErasePreviousNode();
	if (ret)
	{
		countChar--;
	}
	return ret;
}

std::string TypingMachine::Print(char separator) {
	std::string line;
	Node *iter;
	for (iter = home->GetNextNode(); iter; iter = iter->GetNextNode())
	{
		if (iter == cursor && separator != 0) {
			line += separator;
		}
		if (iter == end)
		{
			break;
		}
		line += iter->GetData();
	}
	return line;
}

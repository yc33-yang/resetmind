// Copyright 2018 yc33-yang

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"
#include <stdlib.h>
//#include <time.h>

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	ASSERT_EQ(tm.Print(0), std::string(""));
  }

#if 0
   bool TypeKey(char key) : Insert key at the left of the cursor.This typing machine only
	  accept key in ASCII range 32 (0x20, ' ') through 126 (0x7E, '~'), inclusive.If element
	  is out of range, you should do nothing.

#endif

  static void validCharTest()
  {
	  TypingMachine tm;
	  EXPECT_FALSE(tm.TypeKey(10));
	  EXPECT_FALSE(tm.TypeKey(' '-1));
	  EXPECT_TRUE(tm.TypeKey(' '));
	  EXPECT_TRUE(tm.TypeKey('~'));
	  EXPECT_FALSE(tm.TypeKey(1+'~'));
	  ASSERT_EQ(tm.Print('|'), std::string(" ~|"));
  }
  static char **maxCharTestExpect;
  static void MaxCharTest()
  {
	  TypingMachine tm;
	  char key;
	  for (int i = 0; i < 212; i++)
	  {
		  key = ' ' + i % ('~' - ' '+1);
		  tm.TypeKey(key);
		  tm.Print('1');
		  tm.TypeKey(key);
		  tm.Print('1');
		  tm.EndKey(); tm.Print('1');
		  tm.EraseKey(); tm.Print('1');
		  tm.TypeKey(key); tm.Print('1');
		  tm.RightKey(); tm.Print('1');
		  tm.LeftKey(); tm.Print('1');
		  tm.HomeKey(); tm.Print('1');
		  tm.EraseKey(); tm.Print('1');
		  tm.TypeKey(key); tm.Print('1');
		  tm.LeftKey(); tm.Print('1');
		  for (int j = 0; j <= i / 2; j++)
		  {
			  tm.RightKey(); tm.Print('1');
		  }
		  tm.TypeKey(key); tm.Print('1');
		  tm.EraseKey(); 
		  //printf("%s\n", tm.Print(0  ).c_str());
		  //printf("%s\n", tm.Print('|').c_str());
	  }
	  std::string expected = "@?>=<;:987654321BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~!#%')+-/13579;=?ACEGIKMOQSUWY[]_acegikmoqsuwy{} \"$&(| ";
	  //EXPECT_EQ(expected, tm.Print('|'));
  }


  inline static char randData() { return rand() % 256; }
  inline static int  randOperation() { return rand() % 10; }

  static void doRandom()
  {
	  int operation;
	  char data;

	  int doCount = 500 + (rand() % 9999);
	  TypingMachine tm;


	  for (int i = 0; i < doCount; i++)
	  {
		  operation = randOperation();
		  data = randData();

		  switch (operation)
		  {
		  case 0: case 6:
			  tm.LeftKey();
			  break;
		  case 1: case 7:
			  tm.RightKey();
			  break;
		  case 2:
			  tm.HomeKey();
			  break;
		  case 3: 
			  tm.EndKey();
			  break;
		  case 4:
			  tm.EraseKey();
			  break;
		  case 5: case 8: case 9:
			  tm.TypeKey(data);
			  break;
		  }
		  printf("%s", tm.Print(data).c_str());
	  }
	  printf("\ncongrat! %d\n", doCount);

  }

public:
  static void RunTest() {
    BarSeparatorTest();
	validCharTest();
	MaxCharTest();
	// doRandom();
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

void TypingMachineTest() {
	//srand((unsigned int)time(nullptr) + clock());
	TmConstructorTestSuite::RunTest();
  // add more..
}


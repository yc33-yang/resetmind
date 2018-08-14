// Copyright 2018 yc33-yang

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

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
  static void MaxCharTest()
  {
	  TypingMachine tm;
	  for (int i = 0; i < 212; i++)
	  {
		  tm.TypeKey(' ' + i % ('~' - ' '));
		  tm.Print('1');
		  tm.TypeKey(' ' + i % ('~' - ' '));
		  tm.Print('1');
		  tm.EndKey(); tm.Print('1');
		  tm.EraseKey(); tm.Print('1');
		  tm.TypeKey(' ' + i % ('~' - ' ')); tm.Print('1');
		  tm.RightKey(); tm.Print('1');
		  tm.LeftKey(); tm.Print('1');
		  tm.HomeKey(); tm.Print('1');
		  tm.EraseKey(); tm.Print('1');
		  tm.TypeKey(' ' + i % ('~' - ' ')); tm.Print('1');
		  tm.LeftKey(); tm.Print('1');
		  for (int j = 0; j <= i / 2; j++)
		  {
			  tm.RightKey(); tm.Print('1');
		  }
		  tm.TypeKey(' ' + i % ('~' - ' ')); tm.Print('1');
		  tm.EraseKey(); tm.Print('1');
	  }
  }
public:
  static void RunTest() {
    BarSeparatorTest();
	validCharTest();
	MaxCharTest();
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
  TmConstructorTestSuite::RunTest();
  // add more..
}


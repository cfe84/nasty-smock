#include "UnitTest++/UnitTest++.h"
#include <iostream>

using namespace std;

TEST(Sanity) 
{
   CHECK_EQUAL(1, 1);
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}

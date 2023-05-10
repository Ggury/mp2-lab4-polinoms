
#include "../gtest/gtest.h"
#include "../include/Polynoms.h"	

using namespace std;

TEST(Polynom, can_create_polynom)
{
	Polynom pol;
	ASSERT_NO_THROW(Polynom pol);
}
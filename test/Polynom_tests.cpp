
#include "../gtest/gtest.h"
#include "../include/Polynom.h"	

using namespace std;

TEST(Polynom, can_create_polynom)
{
	Polynom pol;
	ASSERT_NO_THROW(Polynom pol);
}

TEST(Polynom, throw_if_deree_more_999)
{
	Polynom pol;
	ASSERT_ANY_THROW(pol._Push(1000, 1000));
}

TEST(Polynom, can_push)
{
	Polynom pol;
	pol._Push(1, 333);
	EXPECT_EQ(pol.getlist().Head->data.degree, 333);
}

TEST(Polynom, can_get_list)
{
	Polynom pol;
	ASSERT_NO_THROW(pol.getlist());
}

TEST(Polynom, can_print_polynom)
{
	Polynom pol;
	pol._Push(1, 111);
	pol._Push(2, 222);
	ASSERT_NO_THROW(pol.Printpolynom());
}

TEST(Polynom, create_poynom_is_right)
{
	Polynom pol;
	bool isr = false;
	if (pol.getlist().Head == NULL)
	{
		isr = true;
	}
	EXPECT_EQ(isr, true);
}

TEST(Polynom, can_summ_with_equal_degrees)
{
	Polynom pol1;
	pol1._Push(1, 111);
	pol1._Push(2, 222);
	Polynom pol2;
	pol2._Push(2, 222);
	Polynom res;
	res = pol1 + pol2;
	Node* hd = res.getlist().Head;
	int i = 0;
	while (hd != NULL)
	{
		if (i == 0)
		{
			EXPECT_EQ(hd->data.modif, 1);
			EXPECT_EQ(hd->data.degree, 111);
		}
		if (i == 1)
		{
			EXPECT_EQ(hd->data.modif, 4);
			EXPECT_EQ(hd->data.degree, 222);
		}
		hd = hd->next;
		i++;
	}
}

TEST(Polynom, can_summ_with_not_equal_degrees)
{
	Polynom pol1;
	pol1._Push(1, 111);
	pol1._Push(2, 222);
	Polynom pol2;
	pol2._Push(3, 333);
	Polynom res;
	res = pol1 + pol2;
	Node* hd = res.getlist().Head;
	int i = 0;
	while (hd != NULL)
	{
		if (i == 0)
		{
			EXPECT_EQ(hd->data.modif, 1);
			EXPECT_EQ(hd->data.degree, 111);
		}
		if (i == 1)
		{
			EXPECT_EQ(hd->data.modif, 2);
			EXPECT_EQ(hd->data.degree, 222);
		}
		if (i == 2)
		{
			EXPECT_EQ(hd->data.modif, 3);
			EXPECT_EQ(hd->data.degree, 333);
		}
		hd = hd->next;
		i++;
	}
}

TEST(Polynom, can_mult)
{
	Polynom pol1;
	pol1._Push(1, 111);
	pol1._Push(2, 222);
	Polynom pol2;
	pol2._Push(2, 222);
	Polynom res;
	res = pol1 * pol2;
	Node* hd = res.getlist().Head;
	int i = 0;
	while (hd != NULL)
	{
		if (i == 0)
		{
			EXPECT_EQ(hd->data.modif, 2);
			EXPECT_EQ(hd->data.degree, 333);
		}
		if (i == 1)
		{
			EXPECT_EQ(hd->data.modif, 4);
			EXPECT_EQ(hd->data.degree, 444);
		}
		hd = hd->next;
		i++;
	}
}

TEST(Polynom, can_multiply_on_value)
{
	Polynom pol;
	pol._Push(2, 222);
	Polynom res = pol * 3;
	EXPECT_EQ(res.getlist().Head->data.modif, 6);
	EXPECT_EQ(res.getlist().Head->data.degree, 222);
}

TEST(Polynom, throw_if_invalid_degrees)
{
	Polynom pol;
	pol._Push(9, 999);
	Polynom pol2;
	pol2._Push(9, 999);
	ASSERT_ANY_THROW(pol * pol2);
}



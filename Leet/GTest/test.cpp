#include "pch.h"
#include "..\Leet\CUtils.h"

namespace CUtilsTestSuite
{
	TEST(SquareCheck, sqr4) {
		EXPECT_EQ(16, square(4));
	}


	TEST(SquareCheck, sqr3) {
		EXPECT_TRUE(9, square(3));
	}

	class RangeChecker : public testing::TestWithParam<std::tuple<int, bool>>
	{
	public:

	protected:
		InRange irInstance{ 0, INT16_MAX };
	};

	TEST_P(RangeChecker, TCInrangeVectors)
	{
		std::tuple<int, bool> tuple = GetParam();

		int param = std::get<0>(tuple);
		bool expectedValue = std::get<1>(tuple);

		std::cout << "param = " << param << " expected value = " << expectedValue << '\n';

		bool isInside = irInstance.checkRange(param);

		ASSERT_EQ(expectedValue, isInside);
	}

	INSTANTIATE_TEST_CASE_P(InRangeTrue, RangeChecker, testing::Values(
		std::make_tuple(-50, false),
		std::make_tuple(4, true),
		std::make_tuple(5, true),
		std::make_tuple(-6, false),
		std::make_tuple(7, true),
		std::make_tuple(9, true),
		std::make_tuple(10, true),
		std::make_tuple(11, true),
		std::make_tuple(-100, false)
	));
}

/*
TEST(TestSuiteName, TestCaseName) 
{
	//Arrange
	declare necessary datatypes for input

	//Act
	res = myfun(inp);

	//Assert
	EXPECT_TRUE(9, square(3));

//-------------------------------------------------
	//ASSERT_* - Fatal 
	//EXPECT_* - Non fatal

	//ASSERT_STREQ - to chk contents of the str - else pointers only be chkd

}

//Testfixture is for common instantiation & destruction of objects but test cases are coded

//TestParams are for call one generic test cases with a range of input & output pairs

*/
#include <iostream>
#include <gtest/gtest.h>
//#include "../src/ArrayLib/ArrayLib.h"
#include <ArrayLib.h>

class ArrayAlgoTests : public ::testing::Test {
public:

protected:
	int LA[5] = {1,3,5,7,8};	//array with 5 elements
	size_t n = 5;			//num of elements in array
};

TEST_F(ArrayAlgoTests, printingOriginalArray)
{
	testing::internal::CaptureStdout();

	//we list the original elements
	list_values(LA, n);

	EXPECT_EQ(
		"LA[0] = 1 \n"
		"LA[1] = 3 \n"
		"LA[2] = 5 \n"
		"LA[3] = 7 \n"
		"LA[4] = 8 \n",
		testing::internal::GetCapturedStdout()
	);
}

TEST_F(ArrayAlgoTests, updateArrayElement)
{
	//we update the item 3 with the value 10
	update_array(LA, &n, 3, 10);

	testing::internal::CaptureStdout();

	//now we list all the elements again
	list_values(LA, n);

	EXPECT_EQ(
		"LA[0] = 1 \n"
		"LA[1] = 3 \n"
		"LA[2] = 5 \n"
		"LA[3] = 10 \n"
		"LA[4] = 7 \n"
		"LA[5] = 8 \n",
		testing::internal::GetCapturedStdout()
	);
}

TEST_F(ArrayAlgoTests, searchForElement)
{
	update_array(LA, &n, 3, 10);

	EXPECT_EQ(3ULL, search_element(LA, n, 10));
}

TEST_F(ArrayAlgoTests, deleteElement)
{
	update_array(LA, &n, 3, 10);

	//we update the item 3 with the value 10
	delete_element(LA, &n, 3);

	testing::internal::CaptureStdout();

	//now we list all the elements again
	list_values(LA, n);

	EXPECT_EQ(
		"LA[0] = 1 \n"
		"LA[1] = 3 \n"
		"LA[2] = 5 \n"
		"LA[3] = 7 \n"
		"LA[4] = 8 \n",
		testing::internal::GetCapturedStdout()
	);
}

#include <iostream>
#include <gtest/gtest.h>
#include "../src/ArrayLib/ArrayLib.h"

class ArrayAlgoTests : public ::testing::Test {
public:

protected:
	int LA[5] = {1,3,5,7,8};	//array with 5 elements
	size_t n = 5;			//num of elements in array
};

TEST_F(ArrayAlgoTests, PrintingOriginalArray){

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

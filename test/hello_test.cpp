#include <gtest/gtest.h>
#include "../incl/dynamic_array.hpp"

class DynamicArrayTest : public testing::Test {
	protected:
		void SetUp() override{
		}
		DynamicArray empty_array;
		DynamicArray once_increased_array;
};

TEST_F(DynamicArrayTest, ArrayIsEmpty){
	EXPECT_EQ(empty_array.size(), 0);

}



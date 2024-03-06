#include <gtest/gtest.h>
#include "../incl/dynamic_array.hpp"

class DynamicArrayTest : public testing::Test {
	protected:
		void SetUp() override{
			once_increased_array.append(1);
			twice_increased_array.append(1);
			twice_increased_array.append(2);
			thrice_increased_array.append(1);
			thrice_increased_array.append(2);
			thrice_increased_array.append(3);
		}
		DynamicArray<int> empty_array;
		DynamicArray<int> once_increased_array;
		DynamicArray<int> twice_increased_array;
		DynamicArray<int> thrice_increased_array;
};

TEST_F(DynamicArrayTest, ArrayInstantiation){
	EXPECT_EQ(empty_array.getCapacity()	, 0		);
	EXPECT_EQ(empty_array.getSize()		, 0		);
	EXPECT_EQ(empty_array.toString()	, "[]"	);
}

TEST_F(DynamicArrayTest, OnceAppendedArray){
	EXPECT_EQ(once_increased_array.getCapacity()	, 1);
	EXPECT_EQ(once_increased_array.getSize()		, 1);
	EXPECT_EQ(once_increased_array.toString()		, "[ 1 ]");
	EXPECT_EQ(once_increased_array[0]				, 1);
	once_increased_array[0] = 20;
	EXPECT_EQ(once_increased_array[0]				, 20);
	EXPECT_THROW(once_increased_array[1], 			std::out_of_range);
}

TEST_F(DynamicArrayTest, TwiceAppendedArray){
	EXPECT_EQ(twice_increased_array.getCapacity()	, 2);
	EXPECT_EQ(twice_increased_array.getSize()		, 2);
	EXPECT_EQ(twice_increased_array.toString()		, "[ 1 | 2 ]");
	EXPECT_EQ(twice_increased_array[1]				, 2);
	twice_increased_array[0] = 20;
	twice_increased_array[1] = 30;
	EXPECT_EQ(twice_increased_array[0]				, 20);
	EXPECT_EQ(twice_increased_array[1]				, 30);
	EXPECT_THROW(once_increased_array[2], 			std::out_of_range);
}

TEST_F(DynamicArrayTest, ThriceAppendedArray){
	EXPECT_EQ(thrice_increased_array.getCapacity()	, 4);
	EXPECT_EQ(thrice_increased_array.getSize()		, 3);
	EXPECT_EQ(thrice_increased_array.toString()		, "[ 1 | 2 | 3 ]");
	EXPECT_EQ(thrice_increased_array[1]				, 2);
	thrice_increased_array[0] = 20;
	thrice_increased_array[2] = 30;
	EXPECT_EQ(thrice_increased_array[0]				, 20);
	EXPECT_EQ(thrice_increased_array[2]				, 30);
	EXPECT_THROW(once_increased_array[4], 			std::out_of_range);
}


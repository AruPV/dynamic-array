#include <gtest/gtest.h>
#include "../incl/dynamic_array.hpp"

class IntDynamicArrayTest : public testing::Test {
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

TEST_F(IntDynamicArrayTest, IntArrayInstantiation){
	EXPECT_EQ(empty_array.getCapacity()	, 0		);
	EXPECT_EQ(empty_array.getSize()		, 0		);
	EXPECT_EQ(empty_array.toString()	, "[]"	);
}

TEST_F(IntDynamicArrayTest, IntOnceAppendedArray){
	EXPECT_EQ(once_increased_array.getCapacity()	, 1);
	EXPECT_EQ(once_increased_array.getSize()		, 1);
	EXPECT_EQ(once_increased_array.toString()		, "[ 1 ]");
	EXPECT_EQ(once_increased_array[0]				, 1);
	once_increased_array[0] = 20;
	EXPECT_EQ(once_increased_array[0]				, 20);
	EXPECT_THROW(once_increased_array[1], 			std::out_of_range);
}

TEST_F(IntDynamicArrayTest, IntTwiceAppendedArray){
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

TEST_F(IntDynamicArrayTest, IntThriceAppendedArray){
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

class BoolDynamicArrayTest : public testing::Test {
	protected:
		void SetUp() override{
			once_increased_array.append(1);
			twice_increased_array.append(0);
			twice_increased_array.append(1);
			thrice_increased_array.append(1);
			thrice_increased_array.append(0);
			thrice_increased_array.append(1);
		}
		DynamicArray<bool> empty_array;
		DynamicArray<bool> once_increased_array;
		DynamicArray<bool> twice_increased_array;
		DynamicArray<bool> thrice_increased_array;
};

TEST_F(BoolDynamicArrayTest, BoolArrayInstantiation){
	EXPECT_EQ(empty_array.getCapacity()	, 0		);
	EXPECT_EQ(empty_array.getSize()		, 0		);
	EXPECT_EQ(empty_array.toString()	, "[]"	);
}

TEST_F(BoolDynamicArrayTest, BoolOnceAppendedArray){
	EXPECT_EQ(once_increased_array.getCapacity()	, 1);
	EXPECT_EQ(once_increased_array.getSize()		, 1);
	EXPECT_EQ(once_increased_array.toString()		, "[ 1 ]");
	EXPECT_EQ(once_increased_array[0]				, true);
	once_increased_array[0] = false;
	EXPECT_EQ(once_increased_array[0]				, false);
	EXPECT_THROW(once_increased_array[1], 			std::out_of_range);
}

TEST_F(BoolDynamicArrayTest, BoolTwiceAppendedArray){
	EXPECT_EQ(twice_increased_array.getCapacity()	, 2);
	EXPECT_EQ(twice_increased_array.getSize()		, 2);
	EXPECT_EQ(twice_increased_array.toString()		, "[ 0 | 1 ]");
	EXPECT_EQ(twice_increased_array[1]				, true);
	twice_increased_array[0] = true;
	twice_increased_array[1] = false;
	EXPECT_EQ(twice_increased_array[0]				, true);
	EXPECT_EQ(twice_increased_array[1]				, false);
	EXPECT_THROW(once_increased_array[2], 			std::out_of_range);
}

TEST_F(BoolDynamicArrayTest, BoolThriceAppendedArray){
	EXPECT_EQ(thrice_increased_array.getCapacity()	, 4);
	EXPECT_EQ(thrice_increased_array.getSize()		, 3);
	EXPECT_EQ(thrice_increased_array.toString()		, "[ 1 | 0 | 1 ]");
	EXPECT_EQ(thrice_increased_array[1]				, false);
	thrice_increased_array[0] = false;
	thrice_increased_array[2] = false;
	EXPECT_EQ(thrice_increased_array[0]				, false);
	EXPECT_EQ(thrice_increased_array[2]				, false);
	EXPECT_THROW(once_increased_array[4], 			std::out_of_range);
}

class StringDynamicArrayTest : public testing::Test {
	protected:
		void SetUp() override{
			once_increased_array.append("first item");
			twice_increased_array.append("first item");
			twice_increased_array.append("second item");
			thrice_increased_array.append("first item");
			thrice_increased_array.append("second item");
			thrice_increased_array.append("third item");
		}
		DynamicArray<std::string> empty_array;
		DynamicArray<std::string> once_increased_array;
		DynamicArray<std::string> twice_increased_array;
		DynamicArray<std::string> thrice_increased_array;
};

TEST_F(StringDynamicArrayTest, StringArrayInstantiation){
	EXPECT_EQ(empty_array.getCapacity()	, 0		);
	EXPECT_EQ(empty_array.getSize()		, 0		);
	EXPECT_EQ(empty_array.toString()	, "[]"	);
}

TEST_F(StringDynamicArrayTest, StringOnceAppendedArray){
	EXPECT_EQ(once_increased_array.getCapacity()	, 1);
	EXPECT_EQ(once_increased_array.getSize()		, 1);
	EXPECT_EQ(once_increased_array.toString()		, "[ first item ]");
	EXPECT_EQ(once_increased_array[0]				, "first item");
	once_increased_array[0] = "new item";
	EXPECT_EQ(once_increased_array[0]				, "new item");
	EXPECT_THROW(once_increased_array[1], 			std::out_of_range);
}

TEST_F(StringDynamicArrayTest, StringTwiceAppendedArray){
	EXPECT_EQ(twice_increased_array.getCapacity()	, 2);
	EXPECT_EQ(twice_increased_array.getSize()		, 2);
	EXPECT_EQ(twice_increased_array.toString()		, "[ first item | second item ]");
	EXPECT_EQ(twice_increased_array[1]				, "second item");
	twice_increased_array[0] = "first new item";
	twice_increased_array[1] = "second new item";
	EXPECT_EQ(twice_increased_array[0]				, "first new item");
	EXPECT_EQ(twice_increased_array[1]				, "second new item");
	EXPECT_THROW(once_increased_array[2], 			std::out_of_range);
}

TEST_F(StringDynamicArrayTest, StringThriceAppendedArray){
	EXPECT_EQ(thrice_increased_array.getCapacity()	, 4);
	EXPECT_EQ(thrice_increased_array.getSize()		, 3);
	EXPECT_EQ(thrice_increased_array.toString()		, "[ first item | second item | third item ]");
	EXPECT_EQ(thrice_increased_array[1]				, "second item");
	thrice_increased_array[0] = "first new item";
	thrice_increased_array[2] = "second new item";
	EXPECT_EQ(thrice_increased_array[0]				, "first new item");
	EXPECT_EQ(thrice_increased_array[2]				, "second new item");
	EXPECT_THROW(once_increased_array[4], 			std::out_of_range);
}

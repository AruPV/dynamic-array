// SOURCES:
// CPython's List implementation: https://github.com/python/cpython/blob/main/Include/listobject.h
// 								  https://github.com/python/cpython/blob/main/Include/listobject.c
// NOTES:
//
// I made the decision to zero-initialize the array if no values are passed. I 
// could have (and for a second thought about) using options instead (a datatype
// included in c++17), but I decided against it because I decided to not let 
// users interact with the uninitialized elements of the array.
//
//
// I also decided to implement this with keywords similar to those that the
// vector class uses, but I did not copy its implementation (or, like, I 
// didn't look at it so if it's similar it's not intentional!!).
//
// One final thing, I decided to hold the array like a c-style array instead
// of an std::array because i wanted to force myself to work with pointers thought
// I know it is probably a better idea to just use std::array in an actual implementation
// of dynamic arrays!

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstddef>					// For size_t
#include <array>
#include <string>
#include <map>
#include <functional>

class DynamicArray{

	private:
		static int resize_count;
		static int copies;
		
		static std::map<std::string,int> get_stats_map();
		static void reset_stats();

		static int add(int);
		static int mult(int);
		static int (*resize_operation)(int);
		static float resize_factor;

		// Because of how C handles arrays, i declare ptr to first value here. The pointer here
		// is uninitialized. It's undefined behavior if I attempt to dereference. I should also
		// not dereference this directly, really, but instead use the syntax for 
		// accessing array elements, the compiler then does the pointer arithmetic and dereferencing
		// for me (yay!).
		int* array;			
		int next_i;
		size_t capacity;
		void resize();

	public:
		DynamicArray();
		template<int array_length>
		DynamicArray(std::array<int, array_length> i_array);
		~DynamicArray();
		int size();
		int& operator[](size_t index);
		int append(int new_int, bool log = false);
		std::string toString();
		void modify_resize();

};

#endif

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
		static int 		resize_count;
		static int 		copies;
		static int 		(*resize_operation)(int);
		static float 	resize_factor;
		static bool		logs;

		static int 		add(int);
		static int 		mult(int);
		static void 	resetStats();
		
		int* 	array;			
		int 	next_i;
		size_t 	capacity;
		void 	resize();

	public:
		static std::map<std::string,int> getStatsMap();
		static void						 toggleLogs();

		DynamicArray();
		template<int array_length>
		DynamicArray(std::array<int, array_length> i_array);
		~DynamicArray();

		int 		getSize();
		int			getCapacity();
		void 		append(int new_value);
		int& 		operator[](size_t index);
		std::string toString();
		void 		modifyResize(int (*)(int), float factor = resize_factor);
};

#endif

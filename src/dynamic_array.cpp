#include "../incl/dynamic_array.hpp"
#include <iostream>
#include <ranges>

// INITIALIZE STATIC MEMBERS
int (*DynamicArray::resize_operation)(int) = DynamicArray::mult;
float DynamicArray::resize_factor = 2;

// CONSTRUCTORS
DynamicArray::DynamicArray(): 
	capacity {1}{
	// Default constructor.
	array = new int[1];
	next_i = 0;
}

template<int array_length>
DynamicArray::DynamicArray(std::array<int, array_length> i_array)
	: capacity {array_length}{
	array = new int[array_length];
	next_i = 0;
}

// DESTRUCTOR
DynamicArray::~DynamicArray(){
	delete[] array;
}

// OTHER METHODS

int DynamicArray::mult(int capacity){
	return (capacity * resize_factor);
}

int DynamicArray::add(int capacity){
	return (capacity + resize_factor);
}

void DynamicArray::resize(){		
	// Allocate new memory in heap
	int* new_array = new int[resize_operation(capacity)];
	for (int i : std::views::iota(0, int(capacity))){
		new_array[i] = array[i];
	}
	delete[] array; 	// ptr is now dangling
	array = new_array;  // ptr reassigned to new array location 
	capacity = resize_operation(capacity);
}

int DynamicArray::size(){
	return (next_i);
}

int DynamicArray::append(int new_int, bool log){
	if (capacity <= next_i){
		if (log) {std::cout << "array exceded capacity and will resize";}
		this->resize();
	}
	array[next_i] = new_int;
	next_i += 1;
	return 1;
}

int& DynamicArray::operator[](size_t index){
	if (index >= next_i){
		throw std::out_of_range("Index out of bounds");
	}
	return array[index];

}

std::string DynamicArray::toString(){
	if (next_i == 0){
		return "[]";
	}
	std::string return_str = "[ ";
	// Range object implemented in c++20.
	for (int i : std::views::iota(0, (next_i - 1))){
		return_str.append(std::to_string(array[i]) + " | ");
	}
	return_str.resize(return_str.size() - 2);
	return_str += "]";
	return return_str;
}




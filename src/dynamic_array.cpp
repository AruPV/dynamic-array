#include "../incl/dynamic_array.hpp"
#include <iostream>
#include <ranges>

// INITIALIZE STATIC MEMBERS
int 	DynamicArray::resize_count = 0;
int 	DynamicArray::copies = 0;
int 	(*DynamicArray::resize_operation)(int) = DynamicArray::mult;
float 	DynamicArray::resize_factor = 2;
bool 	DynamicArray::logs = false;

int DynamicArray::mult(int capacity){
	return (capacity * resize_factor);
}

int DynamicArray::add(int capacity){
	return (capacity + resize_factor);
}

void DynamicArray::resetStats(){
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

std::map<std::string,int> DynamicArray::getStatsMap(){
	std::map<std::string,int> return_map;
	return_map["Resizes"] = resize_count;
	return_map["Copies"] = copies;
	return return_map;
}

void DynamicArray::toggleLogs(){
	logs = !logs;
}

DynamicArray::DynamicArray(): 
	capacity {0}{
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

DynamicArray::~DynamicArray(){
	delete[] array;
}

int DynamicArray::getSize(){
	return (next_i);
}

int DynamicArray::getCapacity(){
	return (capacity);
}

void DynamicArray::append(int new_value){
	if (capacity == 0 ){
		capacity = 1;
	} else if (capacity <= next_i){
		this->resize();
		if (logs) {std::cout << "array resized to: " << capacity << "\n";}
		resize_count++;
	}
	array[next_i] = new_value;
	next_i += 1;
	return;
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
	for (int i : std::views::iota(0, (next_i))){
		return_str.append(std::to_string(array[i]) + " | ");
		copies ++;
	}
	return_str.resize(return_str.size() - 2);
	return_str += "]";
	return return_str;
}

void DynamicArray::modifyResize(int (*new_func)(int), float new_factor){
	resize_operation = new_func; 
	resize_factor = new_factor;
}




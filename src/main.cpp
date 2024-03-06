#include "../incl/dynamic_array.hpp"
#include <iostream>
#include <ranges>

int main(){
	
	DynamicArray<int>::toggleLogs();
	DynamicArray<int> d_a;
	for (int i = 0; i <12; i++){
		d_a.append(i);
	};

	DynamicArray<int> d_b;
	d_b.append(1);


	std::cout << d_a.toString();
	std::cout << d_b.toString();
	

}

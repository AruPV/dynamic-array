#include "../incl/dynamic_array.hpp"
#include <iostream>
#include <ranges>

int main(){

	DynamicArray d_a;
	for (int i = 0; i <12; i++){
		d_a.append(i);
	};

	for (int i = 0; i <10; i++){
		std::cout << d_a[i] << "\n";
	};

	std::cout << d_a.toString();
	
	std::cout << d_a.size();

}

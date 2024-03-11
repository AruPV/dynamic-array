#include "../incl/dynamic_array.hpp"
#include <iostream>
#include <ranges>
#include <array>
#include <chrono>


std::array<float, 4> oneExperiment(
	int min_list_size, 
	int max_list_size, 
	int (*new_func)(int), 
	float resize_value )
{
	DynamicArray<int>::modifyResize(new_func, resize_value);

	std::array<float,4> return_array;			//[length of list, resizes, copies, time]
	DynamicArray<int> working_array;
	int min_max_dif = max_list_size - min_list_size;

	// For timing
	decltype(std::chrono::high_resolution_clock::now()) start, end;
	std::chrono::duration<float> duration;
	start = std::chrono::high_resolution_clock::now();

	for (int i: std::views::iota(0, rand() % min_max_dif + min_list_size))
	{
		int random_int = rand() % 1000 + 1;
		working_array.push(random_int);
	}
	
	// Timer stop
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	// Construct return std::array
	return_array[0] = working_array.getSize();
	return_array[1] = working_array.getStatsMap()["Copies"];
	return_array[2] = working_array.getStatsMap()["Resizes"];
	return_array[3] = duration.count();
	
	return return_array;
}

int main()
{
	std::cout << "Started experiments\n";
	srand(1312);
	int num_experiments = 30;
	std::array<float,4> two_mult_array = {0.0,0.0,0.0,0.0};

	std::cout << "Started 2 mult\n";
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::mult, 2);
		for (int i = 0; i < 4; i++)
		{
			two_mult_array[i] += return_array[i];
		}
	}

	std::cout << "Started 1.5 mult\n";
	std::array<float,4> onefive_mult_array = {0.0,0.0,0.0,0.0};
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::mult, 1.5);
		for (int i = 0; i < 4; i++)
		{
			onefive_mult_array[i] += return_array[i];
		}
	}

	std::cout << "Started 1.25 mult\n";
	std::array<float,4> onetwofive_mult_array = {0.0,0.0,0.0,0.0};
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::mult, 1.25);
		for (int i = 0; i < 4; i++)
		{
			onetwofive_mult_array[i] += return_array[i];
		}
	}

	std::cout << "Started 16k add\n";
	std::array<float,4> sixteen_add_array = {0.0,0.0,0.0,0.0};
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::add, 16384);
		for (int i = 0; i < 4; i++)
		{
			sixteen_add_array[i] += return_array[i];
		}
	}

	std::cout << "Started 4k add\n";
	std::array<float,4> four_add_array = {0.0,0.0,0.0,0.0};
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::add, 4096);
		for (int i = 0; i < 4; i++)
		{
			four_add_array[i] += return_array[i];
		}
	}

	std::cout << "Started 1k add\n";
	std::array<float,4> one_add_array = {0.0,0.0,0.0,0.0};
	for (int i: std::views::iota(0, num_experiments))
	{
		DynamicArray<int>::resetStats();
		auto return_array = oneExperiment(100000, 999999, DynamicArray<int>::add, 1024);
		for (int i = 0; i < 4; i++)
		{
			one_add_array[i] += return_array[i];
		}
	}

	for (int i = 0; i < 4; i++)					//Average out
	{
		one_add_array[i] 			= one_add_array[i]			/num_experiments;
		four_add_array[i] 			= four_add_array[i]			/num_experiments;
		sixteen_add_array[i] 		= sixteen_add_array[i]		/num_experiments;

		two_mult_array[i] 			= two_mult_array[i]			/num_experiments;
		onefive_mult_array[i] 		= onefive_mult_array[i]		/num_experiments;
		onetwofive_mult_array[i] 	= onetwofive_mult_array[i]	/num_experiments;
	}

	std::cout << "\n=== Results for Multiplication resize ===\n";
	std::cout << "~ By factor of 2 ~\n";
	std::cout << "List length: " 	<< 	two_mult_array[0]			<< "\n";
	std::cout << "Resize number: " 	<< 	two_mult_array[2]			<< "\n";
	std::cout << "Copies number: " 	<< 	two_mult_array[1]			<< "\n";
	std::cout << "Time: " 			<< 	two_mult_array[3]			<< "\n";
	std::cout << "~ By factor of 1.5 ~\n";
	std::cout << "List length: " 	<< 	onefive_mult_array[0]		<< "\n";
	std::cout << "Resize number: " 	<< 	onefive_mult_array[2]		<< "\n";
	std::cout << "Copies number: " 	<< 	onefive_mult_array[1]		<< "\n";
	std::cout << "Time: " 			<< 	onefive_mult_array[3]		<< "\n";
	std::cout << "~ By factor of 1.25 ~\n";
	std::cout << "List length: " 	<< 	onetwofive_mult_array[0]	<< "\n";
	std::cout << "Resize number: " 	<< 	onetwofive_mult_array[2]	<< "\n";
	std::cout << "Copies number: " 	<< 	onetwofive_mult_array[1]	<< "\n";
	std::cout << "Time: " 			<< 	onetwofive_mult_array[3]	<< "\n";
	std::cout << "\n=== Results for Addition resize ===\n";
	std::cout << "~ By increase of 16384 ~\n";
	std::cout << "List length: " 	<< 	sixteen_add_array[0]		<< "\n";
	std::cout << "Resize number: " 	<< 	sixteen_add_array[2]		<< "\n";
	std::cout << "Copies number: " 	<< 	sixteen_add_array[1]		<< "\n";
	std::cout << "Time: " 			<< 	sixteen_add_array[3]		<< "\n";
	std::cout << "~ By increase of 4096 ~\n";
	std::cout << "List length: " 	<< 	four_add_array[0]			<< "\n";
	std::cout << "Resize number: " 	<< 	four_add_array[2]			<< "\n";
	std::cout << "Copies number: " 	<< 	four_add_array[1]			<< "\n";
	std::cout << "Time: " 			<< 	four_add_array[3]			<< "\n";
	std::cout << "~ By increase of 1024 ~\n";
	std::cout << "List length: " 	<< 	one_add_array[0]			<< "\n";
	std::cout << "Resize number: " 	<< 	one_add_array[2]			<< "\n";
	std::cout << "Copies number: " 	<< 	one_add_array[1]			<< "\n";
	std::cout << "Time: " 			<< 	one_add_array[3]			<< "\n";

}

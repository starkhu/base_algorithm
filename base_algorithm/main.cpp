#include<iostream>
#include"time.h"
#include"recursive_test.h"
#include"sort.h"
#include"binary_search.h"

void CountTime(int t,void (*base_function)(int t)) {
	clock_t start, end;  
	double duration; 
	start = clock();
	(*base_function)(t);
	end = clock();
	duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "duration is: " << duration << " seconds." << std::endl;
}

void PrintOptions() {
	std::cout << "1: recursive test" << std::endl;
	std::cout << "2: sort test" << std::endl;
	std::cout << "3: binary search test" << std::endl;
}

int main() {
	PrintOptions();
	char options;
	std::cout << "please input your options: ";
	std::cin >> options;
	int arr[8] = {4, 5, 6, 7, 8, 1, 2, 3};
	while (options != 'q') {
		switch (options) {
		case '1':
			CountTime(1, RecursiveTest);
			CountTime(2, RecursiveTest);
			break;
		case '2':	
			BubbleSort(CreateArray_10(), 10);
			InsertionSort(CreateArray_10(), 10);
			ShellSort(CreateArray_10(), 10);
			QuickSort(CreateArray_10(), 0, 9);
			break;
		case '3':
			BinarySearch<int>(arr, 7);
			//BinarySearch<int>(arr, 7);
			break;
		case 'q':
			break;
		}
		std::cout << "please input your options: ";
		std::cin >> options;
	}

	system("pause");
	return 0;
}
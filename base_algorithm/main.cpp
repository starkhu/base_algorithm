#include<iostream>
#include"time.h"
#include"recursive_test.h"
#include"sort.h"

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
}

int main() {
	PrintOptions();
	char options;
	std::cout << "please input your options: ";
	std::cin >> options;
	int arr[5] = { 2, 34, 54, 3, 1 };
	while (options != 'q') {
		switch (options) {
		case '1':
			CountTime(1, RecursiveTest);
			CountTime(2, RecursiveTest);
			break;
		case '2':	
			std::cout << "aa" << std::endl;
			//BubbleSort(arr, 5);
			BubbleSort(CreateArray_10(), 10);
			InsertionSort(CreateArray_10(), 10);
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
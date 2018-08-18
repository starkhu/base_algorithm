#include<iostream>
#include"time.h"
#include"recursive_test.h"

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
}

int main() {
	PrintOptions();
	char options;
	std::cout << "please input your options: ";
	std::cin >> options;
	while (options != 'q') {
		switch (options) {
		case '1':
			CountTime(1, RecursiveTest);
			CountTime(2, RecursiveTest);
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
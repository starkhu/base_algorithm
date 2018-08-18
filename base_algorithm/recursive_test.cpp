#include<iostream>

int Fibonacci_1(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	else {
		return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
	}
}

int Fibonacci_2(int n) {
	if (n == 0 || n == 1)
		return 0;
	int fabonacci_first = 0;
	int fabonacci_second = 1;
	int fabonacci_n = 0;
	int i = 2;
	while (i <= n) {
		fabonacci_n = fabonacci_first + fabonacci_second;
		fabonacci_first = fabonacci_second;
		fabonacci_second = fabonacci_n;
		i++;
	}
	return fabonacci_n;
}

void RecursiveTest(int i) {
	std::cout << "i is: " << i << std::endl;
	switch (i){
	case 1:
		std::cout << Fibonacci_1(30) << std::endl;
		break;
	case 2:
		std::cout << Fibonacci_2(30) << std::endl;
		break;
	default:
		break;
	}
}
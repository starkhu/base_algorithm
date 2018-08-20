#include<iostream>

//求base的exponent次方，不得使用库函数，不需要考虑大数问题。
// Find the exponent power of the base
// you must not use the library function
// do not need to consider the big number problem.
double Power(double base, int exponent) {
	double result = 1.0;
	bool exp_is_positive = true;
	if (base == 0 && exponent < 0) {
		throw new std::exception("Invalid Input");
		return 0.0;
	}
	if (exponent == 0)
		return 1.0;
	else if (exponent < 0) {
		exponent *= (-1);
		exp_is_positive = false;
	}

	for (int i = 0; i < exponent; i++) {
		result *= base;
		// std::cout << result << std::endl;
	}
	if (exp_is_positive)
		return result;
	else
		return 1 / result;
}

// better way: bit movement
double Power_1(double base, int exponent) {
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)
		return base;
	double result = Power_1(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;
	return result;
}
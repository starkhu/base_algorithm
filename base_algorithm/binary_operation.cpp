#include<iostream>

// 输入一个整数
//输出该数二进制表示中1的个数


//can not solve the case where the input is negative.
void NumberOfOne_0(int num) {
	//int num;
	//std::cout << "please input a num: ";
	//std::cin >> num;
	if (num == 0) {
		std::cout << "0" << std::endl;
		return;
	}
	if (num == 1) {
		std::cout << "1" << std::endl;
		return;
	}
	int times = 0;
	while (num != 0 && num != 1) {
		times += (num % 2);
		num = num / 2;
	}
	times += num;
	std::cout << "number of one is: " << times << std::endl;
}

void BinaryOperation() {
	int num = 3;
	std::cout << (num & 1) << std::endl;
	std::cout << ((num-1) & 1) << std::endl;
}

void NumberOfOne_1(int num) {
	//int num;
	//std::cout << "please input a num: ";
	//std::cin >> num;
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (num & flag)
			count++;
		flag = flag << 1;
	}
	std::cout << "number of one is: " << count << std::endl;
}

//把一个整数减去1再和原来的数做与运算，
//相当于把原来整数的二进制表示中最右边的1变成0.
//Subtracting an integer by 1 and doing the AND operation with the original number 
// is equivalent to changing the rightmost 1 of the binary representation of the original integer to 0.
void NumberOfOne_2(int num) {
	//int num;
	//std::cout << "please input a num: ";
	//std::cin >> num;
	int count = 0;
	while (num) {
		num = (num - 1) & num;
		count++;
	}
	std::cout << "number of one is: " << count << std::endl;
}
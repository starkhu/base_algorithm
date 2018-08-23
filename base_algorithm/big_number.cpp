#include<iostream>

void PrintNumber(char* num) {
	int len = strlen(num);
	std::cout << "len is: " << len << std::endl;
	int index = 0;
	while (index <= len - 2) {
		if (num[index] == '0') {
			index++;
		}
		else
		{
			break;
		}
	}
	std::cout << "index is: " << index << std::endl;
	for (int i = index; i <= len - 1; i++)
		std::cout << num[i];
	std::cout << std::endl;
}

void Print1ToMaxOfDigitsRecursively(char* num, int len, int index) {
	if (index == len - 1) {
		PrintNumber(num);
		return;
	}
	for (int i = 0; i < 10; i++) {
		num[index + 1] = i + '0';
		Print1ToMaxOfDigitsRecursively(num, len, index+1);
	}
}

void Print1ToMaxOfDigits(int n) {
	if (n == 0)
		return;
	char* num = new char[n + 1];
	num[n] = '\0';
	for (int i = 0; i < 10; i++) {
		num[0] = i + '0';
		Print1ToMaxOfDigitsRecursively(num, n, 0);
	}
	delete[] num;
}


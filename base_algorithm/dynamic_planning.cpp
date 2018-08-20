#include<iostream>

//给你一根长度为n的绳子，请把绳子剪成m段（n>1,m>1）,每段绳子的长度记为k[0],k[1]…,k[m].
//请问k[0]*k[1]…*k[m]可能的最大乘积是多少？
// Give you a rope of length n, please cut the rope into m segments (n>1, m>1), 
// the length of each rope is recorded as k[0], k[1]...,k[m ].
// What is the maximum possible product of k[0]*k[1]...*k[m]?

int CutRope() {
	int len;
	std::cout << "please input a number:";
	std::cin >> len;
	if (len < 2)
		return 0;
	if (len == 2)
		return 1;
	if (len == 3)
		return 2;
	int* products = new int[len + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	
	int max = 0;
	for (int i = 4; i <= len; i++) {
		max = 0;
		for (int j = 1; j <= i / 2; j++) {
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}
		products[i] = max;
	}
	max = products[len];
	delete[] products;
	return max;
}
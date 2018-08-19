#pragma once
#include<iostream>

template<typename T>
	void BinarySearch(T arr[], int len);

//find the smallest number in the rotated array.
template<typename T>
void BinarySearch(T arr[], int len) {
	std::cout << "b s t" << std::endl;
	if (arr == nullptr || len <= 0)
		throw new std::exception("Invalid Array");
	//T* head = &arr[0];
	//T* tail = &arr[len - 1];
	T head = 0;
	T tail = len - 1;
	T mid = (head + tail) / 2;
	while (head + 1 != tail) {
		std::cout << "head is:" << head << std::endl;
		std::cout << "tail is:" << tail << std::endl;
		std::cout << "mid is:" << mid << std::endl;
		if (arr[mid] < arr[head]) {
			tail = mid;
		}
		else if (arr[mid] > arr[head]) {
			head = mid;
		}
		mid = (head + tail) / 2;
		//system("pause");
	}
	std::cout << "the smallest number is: " << arr[tail] << std::endl;
}

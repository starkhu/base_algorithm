#pragma once
#include<iostream>

template<typename T>
	void BinarySearch(T arr[], int len);
template<typename T>
	int MinInOrder(T arr[], int head, int tail);

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
	T mid = head;
	while (arr[head] < arr[mid]) {
		if (tail - head == 1) {
			mid = tail;
			break;
		}
		if (arr[head] == arr[tail] && arr[head] == arr[mid])
			mid = MinInOrder(arr, head, tail);
		if (arr[mid] <= arr[head]) {
			tail = mid;
		}
		else if (arr[mid] >= arr[head]) {
			head = mid;
		}
		mid = (head + tail) / 2;
		//system("pause");
	}
	std::cout << "the smallest number is: " << arr[mid] << std::endl;
}
template<typename T>
int MinInOrder(T arr[], int head, int tail) {
	T flag = arr[head];
	for (int i = head; i < tail; i++) {
		if (arr[i] < flag)
			return i;
	}
	return head;
}

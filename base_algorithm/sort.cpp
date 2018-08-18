#include<iostream>
#include<vector>
#include<string>

//std::vector<int> arr;
int arr[10];

void PrintArray(std::string str, int data[], int len) {
	std::cout << str << std::endl;
	for (int i = 0; i < len; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

void Swap(int data[], int a, int b) {
	int temp;
	temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

int* CreateArray_10() {
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100;
	return arr;

}

//average time complexity: O(n^2)
//average space complexity: O(1)
void BubbleSort(int data[], int len) {
	std::cout << "bubble sort" << std::endl;
	PrintArray("berore Bubble sort,array is:",data, len);
	if (data == nullptr || len <= 0)
		return;
	for (int i = 0; i < len; i++) {
		int flag = 0;
		for (int j = 0; j < len - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				Swap(data, j, j + 1);
				flag++;
			}
		}
		if (flag == 0)
			break;
	}
	PrintArray("after Bubble sort, array is:", data, len);
}

void InsertionSort(int data[], int len) {
	PrintArray("before insertion sort, array is:", data, len);
	if (data == nullptr || len <= 0) {
		return;
	}
	for (int i = 1; i < len; i++) {
		int j = i;
		while (j >= 1 && data[j - 1] > data[j]) {
			Swap(data, j - 1, j);
			j--;
		}
	}
	PrintArray("after insertion sort, array is:", data, len);
}
#include<iostream>
#include<vector>

//std::vector<int> arr;
int arr[10];

void PrintArray(int data[], int len) {
	std::cout << "Array is:" << std::endl;
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
int* BubbleSort(int data[], int len) {
	PrintArray(data, len);
	if (data == nullptr || len <= 0)
		return nullptr;
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
	PrintArray(data, len);
	return data;

}
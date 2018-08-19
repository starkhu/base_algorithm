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

//average time complexity: O(n^2)
//average space complexity: O(1)
void InsertionSort(int data[], int len) {
	PrintArray("before insertion sort, array is:", data, len);
	if (data == nullptr || len <= 0) {
		std::cout << "Invalid array" << std::endl;
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

//average time complexity: not certain
//average space complexity: O(1)
void ShellSort(int A[], int n){
	int h = 0;
	PrintArray("before shell sort, array is:", A, n);
	while (h <= n) 
	{
		h = 3 * h + 1;
	}
	std::cout << "1 h is: " << h << std::endl;
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			std::cout << "h is: " << h << std::endl;
			PrintArray("array is:", A, n);
			int j = i - h;
			int get = A[i];
			while (j >= 0 && A[j] > get)
			{
				A[j + h] = A[j];
				j = j - h;
			}
			A[j + h] = get;
			//PrintArray("array is:", A, n);
		}
		h = (h - 1) / 3; 
	}
	PrintArray("after shell sort, array is:", A, n);
}

//average time complexity: O(nlogn)
//average space complexity: O(1)
void QuickSort(int data[], int low, int high) {
	if (data == nullptr || low > high) {
		throw new std::exception("Invalid Array");
		//std::cout << "Invalid array" << std::endl;
		return;
	}
	PrintArray("before quick sort, array is:", data, high - low + 1);
	int left = low;
	int right = high;
	int key = data[left];
	while (left != right) {
		while (left < right && data[right] >= key)
			right--;
		data[left] = data[right];
		while (left < right && data[left] <= key)
			left++;
		data[right] = data[left];
	}
	data[left] = key;
	QuickSort(data, low, left - 1);
	QuickSort(data, left + 1, high);
	PrintArray("after quick sort, array is:", data, high - low + 1);
}
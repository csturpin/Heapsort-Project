#include<iostream>
#include<string>
using namespace std;

template <class T>
void max_heapify(T *array, size_t arraylength, int i) {
	size_t max = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left > arraylength || right > arraylength)
		return;
	
	if (array[left] > array[i] && array[left] > array[right])
		max = left;
	else if (array[right] > array[i] && array[right] > array[left])
		max = right;
	else
		max = i;

	if (max != i && arraylength > 1) {
		swap(array[max], array[i]);
		max_heapify(array, arraylength, max);
	}
}

template <class T>
void heapsort(T *array, size_t arraylength) {
	for (int i = arraylength - 1; i >= 0; i--)
		max_heapify(array, arraylength, i);

	for (int i = arraylength - 1; i > 0; i--) {
		swap(array[0], array[i]);
		max_heapify(array, i - 1, 0);
		if (i == 1 && array[0] > array[1])
			swap(array[0], array[i]);
	}
}

int main() {
	string str_array[] = { "Luke", "Chewbacca", "Han", "Vader", "Leia", "Lando", "Obiwan", "Greedo", "Jabba" };
	int int_array[] = { 45, 106, 17, 2, 30, 21, 378, 290, 75, 8, 14, 80, 64, 9, 3, 111 };
	float fl_array[] = { 9.3f, 6.77f, 4.01f, 15.0f, 52.86f, 60.9f, 16.99f, 3.23f, 3.22f, 15.1f, 45.7f, 2.0f };
	
	size_t str_length = sizeof(str_array) / sizeof(str_array[0]);
	size_t int_length = sizeof(int_array) / sizeof(int_array[0]);
	size_t fl_length = sizeof(fl_array) / sizeof(fl_array[0]);
	
	cout << "Unsorted String Array: ";
	for (size_t i = 0; i < str_length; i++)
		cout << str_array[i] << "\t";
	
	heapsort(str_array, str_length);
	
	cout << "\n\nSorted String Array: \t";
	for (size_t i = 0; i < str_length; i++)
		cout << str_array[i] << "\t";
	
	
	cout << "\n\nUnsorted Integer Array: ";
	for (size_t i = 0; i < int_length; i++)
		cout << int_array[i] << "\t";

	heapsort(int_array, int_length);

	cout << "\n\nSorted Integer Array: \t";
	for (size_t i = 0; i < int_length; i++)
		cout << int_array[i] << "\t";

	cout << "\n\nUnsorted Float Array: \t";
	for (size_t i = 0; i < fl_length; i++)
		cout << fl_array[i] << "\t";

	heapsort(fl_array, fl_length);

	cout << "\n\nSorted Float Array: \t";
	for (size_t i = 0; i < fl_length; i++)
		cout << fl_array[i] << "\t";
	cout << "\n\n";
	
	system("pause");
	return 0;
}
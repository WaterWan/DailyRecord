#include <iostream>

using namespace std;

void quick_sort(int a[], int s, int e);

void swap(int &a, int &b);

int a[10] = { 93, 27, 30, 2, 8, 12, 2, 8, 30, 89};

int main() {
	quick_sort(a, 0, 9);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void quick_sort(int a[], int s, int e) {
	if(s >= e) {
		return;
	}
	int k = a[s];
	int i = s;
	int j = e;
	while(i != j) {
		while(i < j && a[j] >= k) {
			j--;
		}
		swap(a[i], a[j]);
		while(i < j && a[i] <= k) {
			i++;
		}
		swap(a[i], a[j]);
	}
	quick_sort(a, s, i - 1);
	quick_sort(a, i + 1, e);
}

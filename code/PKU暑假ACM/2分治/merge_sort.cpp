#include <iostream>

using namespace std;

void merge_sort(int a[], int s, int e, int temp[]);

void merge(int a[], int s, int m, int e, int temp[]);

int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
int b[10];

int main() {
	// 这里的9是数组的最后一位下标 
	merge_sort(a, 0, 9, b);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
} 

void merge_sort(int a[], int s, int e, int temp[]) {
	if(s < e) {
		int m = s + (e - s) / 2;
		merge_sort(a, s, m, temp);
		merge_sort(a, m + 1, e, temp);
		merge(a, s, m, e, temp);
	}
}

void merge(int a[], int s, int m, int e, int temp[]) {
	int pt = 0;
	int p1 = s;
	int p2 = m + 1;
	while(p1 <= m && p2 <= e) {
		if(a[p1] < a[p2]) {
			temp[pt] = a[p1];
			p1++;
		} else {
			temp[pt] = a[p2];
			p2++;
		}
		pt++;
	}
	while(p1 <= m) {
		temp[pt] = a[p1];
		pt++;
		p1++;
	}
	while(p2 <= e) {
		temp[pt] = a[p2];
		pt++;
		p2++;
	}
	for(int i = 0; i < e - s + 1; i++) {
		a[s + i] = temp[i];
	}
}

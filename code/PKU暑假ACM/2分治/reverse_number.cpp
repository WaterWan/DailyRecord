#include <iostream>

using namespace std;

const int maxn = 1000005;

long long a[maxn];
long long t[maxn];

void merge_sort_and_count(long long a[], int s, int e, long long t[]);

void merge(long long a[], int s, int m, int e, long long t[]);

long long count = 0;

int main() {
	int times;
	cin >> times;
	for(int i = 0; i < times; i++) {
		count = 0;
		int n;
		cin >> n;
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		merge_sort_and_count(a, 0, n - 1, t);
		cout << count << endl;
	}
	return 0;
} 

void merge_sort_and_count(long long a[], int s, int e, long long t[]) {
	if(s >= e) {
		return;
	}
	int m = s + (e - s) / 2;
	merge_sort_and_count(a, s, m, t);
	merge_sort_and_count(a, m + 1, e, t);
	merge(a, s, m, e, t);
}

void merge(long long a[], int s, int m, int e, long long t[]) {
	int pt = 0;
	int pa = s;
	int pb = m + 1;
	while(pa <= m && pb <= e) {
		if(a[pa] <= a[pb]) {
			t[pt++] = a[pa++];
		} else {
			count += pb - (s + pt);
			t[pt++] = a[pb++];
		}
	}
	while(pa <= m) {
		t[pt++] = a[pa++];
	}
	while(pb <= e) {
		t[pt++] = a[pb++];
	}
	for(int i = 0; i < pt; i++) {
		a[s+i] = t[i];
	}
}

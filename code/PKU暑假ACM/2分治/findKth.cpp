#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

void findKth(int a[], int s, int e, int k);

void swap(int &a, int &b);

const int maxn = 100005;
int a[maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	findKth(a, 0, n - 1, k);
	sort(a + n - k, a + n);
	for(int i = n - 1; i >= n - k; i--) {
		cout << a[i] << endl;
	}
	return 0;
}

void findKth(int a[], int s, int e, int k) {
	if(s >= e) {
		return;
	}
	int t = a[s];
	int i = s;
	int j = e;
	while(i != j) {
		if(i < j && a[j] >= t) {
			j--;
		}
		swap(a[i], a[j]);
		if(i < j && a[i] <= t) {
			i++;
		}
		swap(a[i], a[j]);
	}
	int right = e + 1 - i;
	if(right == k) {
		return;
	} else if(right > k) {
		findKth(a, i + 1, e, k);
	} else {
		findKth(a, s, i - 1, k - right);
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


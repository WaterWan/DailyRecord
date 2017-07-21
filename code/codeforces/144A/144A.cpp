#include <iostream>

using namespace std;

const int maxn = 105;

int main() {
	int n;
	cin >> n;
	int a[maxn];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > max) {
			max = a[i];
			maxi = i;
		}
	}
	int min = a[n-1];
	int mini = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] < min) {
			min = a[i];
			mini = i;
		}
	}
	int result = n - 1 - mini + maxi;
	if(maxi >= mini) {
		result--;
	}
	cout << result << endl;
} 

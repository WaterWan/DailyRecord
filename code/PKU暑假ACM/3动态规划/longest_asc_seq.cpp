#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn];
int maxLen[maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		maxLen[i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j]) {
				maxLen[i] = max(maxLen[j] + 1, maxLen[i]);
			}
		}
	}
	cout << *max_element(maxLen, maxLen + n) << endl;
} 

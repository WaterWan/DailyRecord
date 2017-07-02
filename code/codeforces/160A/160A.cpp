#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn];

int cmp(int a, int b);

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+n, cmp);
	int take = 0;
	for(int i = 0; i < n; i++) {
		take += a[i];
		if(take > sum - take) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
} 

int cmp(int a, int b) {
	return a > b;
}

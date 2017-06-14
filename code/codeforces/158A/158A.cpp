#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 50

using namespace std;

int main() {
//	freopen("158A.in", "r", stdin);
	int number[MAXN];
	
	int n;
	int k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> number[i];
	}
	int out = 0;
	for(int i = 0; i < n; i++) {
		if(number[i] >= number[k-1] && number[i] > 0) {
			out++;
		}
	}
	cout << out << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int maxn = 35;

int a[maxn];
int b[maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i] == b[j]) {
				count++;
			}
		}
	}
	cout << count << endl;
} 

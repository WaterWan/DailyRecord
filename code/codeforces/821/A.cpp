#include <iostream>

using namespace std;

const int maxn = 55;
int n;
int a[maxn][maxn];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	} 
	bool good = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 1) {
				bool ok = false;
				for(int i1 = 0; i1 < n; i1++) {
					for(int j1 = 0; j1 < n; j1++) {
						if(a[i1][j] + a[i][j1] == a[i][j]) {
							ok = true;
							break;
						}
					}
					if(ok) {
						break;
					}
				}
				if(!ok) {
					good = false;
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
} 

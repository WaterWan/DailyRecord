#include <cstring>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
char a[51][51];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= m; j++) {
				a[i][j] = '#';
			}
		} else {
			for(int j = 1; j <= m; j++) {
				a[i][j] = '.';
			}
			if(i / 2 % 2 == 1) {
				a[i][m] = '#';
			} else {
				a[i][1] = '#';
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j]; 
		}		 
		cout << endl;
	}

}


#include <cstring>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[106];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}


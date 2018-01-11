#include <cstring>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int s[4];
	int cnt = 0;
	for(int i = 0; i < 4; i++) {
		cin >> s[i];
		bool exists = false;
		for(int j = 0; j < i; j++) {
			if(s[i] == s[j]) {
				exists = true;
				break;
			}
		}
		if(exists) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}


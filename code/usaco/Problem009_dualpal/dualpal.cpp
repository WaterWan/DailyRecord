/**
ID: njuwz151
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string baseTable = "0123456789";

string base10ToBaseN(int number, int base);

bool isPal(string str);

int main() {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int n;
	int s;
	cin >> n >> s;
	int delta = 0;
	while(n > 0) {
		delta++;
		int count = 0;
		string baseN;
		for(int j = 2; j <= 10; j++) {
			baseN = base10ToBaseN(s + delta, j);
			if(isPal(baseN)) {
				count++;
			}
		}
		if(count >= 2) {
			cout << baseN << endl;
			n--;
		}
	}
} 

string base10ToBaseN(int number, int base) {
	string result;
	while(number > 0) {
		result = baseTable[number % base] + result;
		number /= base;
	}
	return result;
}

bool isPal(string str) {
	int len = str.size();
	for(int i = 0; i < len / 2; i++) {
		if(str[i] != str[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

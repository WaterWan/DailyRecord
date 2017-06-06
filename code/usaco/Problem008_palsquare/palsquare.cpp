/**
ID: njuwz151
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std; 

string baseTable = "0123456789ABCDEFGHIJK";

string reverse(string src);

string base10ToBaseN(int number, int base);

int main() {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int base;
	cin >> base;
	for(int i = 1; i <= 300; i++) {
		string palNumber = base10ToBaseN(i, base);
		string palSquare = base10ToBaseN(i * i, base);
		string reverseSquare = reverse(palSquare);
		for(int j = 0; j < palSquare.size(); j++) {
			if(palSquare[j] != reverseSquare[j]) {
				break;
			}
			if(j == palSquare.size() - 1) {
				cout << palNumber << " " << palSquare << endl;
			}
		}
	}
	
	return 0;
} 

string reverse(string src) {
	int len = src.size();
	string result;
	for(int i = len - 1; i > -1; i--) {
		result += src[i];
	}
	return result;
}

string base10ToBaseN(int number, int base) {
	string result;
	while(number > 0) {
		result = baseTable[number % base] + result;
		number /= base;
	}
	return result;
}


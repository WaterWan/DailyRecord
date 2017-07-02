/**
ID: Wan Zhong
TASK: preface
LANG: C++
**/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
string s = "IVXLCDM";
int count[7];
int base[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

void deal(int n);
void show();

int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		deal(i);
	}
	show();
}

void show() {
	for(int i = 0; i < s.length(); i++) {
		if(count[i]) {
			cout << s[i] << " " << count[i] << endl;
		} else {
			break;
		}
	}
}

void deal(int n) {
	string roman = "";
	int i = 0;
	while(n != 0) {
		if(n >= base[i]) {
			n -= base[i];
			roman += str[i];
		} else {
			i++;
		}
	}
	for(int j = 0; j < roman.length(); j++) {
		for(int k = 0; k < s.length(); k++) {
			if(roman[j] == s[k]) {
				count[k]++;
				break;
			}
		}
	}
}

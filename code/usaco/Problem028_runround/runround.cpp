/**
ID: Wan Zhong
TASK: runround
LANG: C++
**/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string> 
#include <sstream>

using namespace std;

bool runround(int n);

string itos(int n);

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	int n;
	cin >> n;
	n++;
	while(!runround(n)) {
		n++;
	}
	cout << n << endl;
}

string itos(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

bool runround(int n) {
	string s = itos(n);
	int len = s.size();
	bool digit[10];
	for(int i = 0; i < 10; i++) {
		digit[i] = false;
	}
	for(int i = 0; i < len; i++) {
		if(digit[s[i] - '0']) {
			return false;
		}
		digit[s[i] - '0'] = true;
		if(digit[0]) {
			return false;
		}
	}
	bool visit[len];
	for(int i = 0; i < len; i++) {
		visit[i] = false;
	}
	int ptr = 0;
	while(!visit[ptr]) {
		visit[ptr] = true;
		ptr += s[ptr % len] - '0';
		ptr %= len;
	}
	for(int i = 0; i < len; i++) {
		if(!visit[i]) {
			return false;
		}
	}
	if(ptr != 0) {
		return false;
	}
	return true;
}

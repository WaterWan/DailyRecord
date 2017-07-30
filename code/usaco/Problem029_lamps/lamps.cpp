/**
ID: Wan Zhong
TASK: lamps
LANG: C++
**/ 
#include <iostream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
bool lamps[maxn];
int n, c;

void init();

void button1();
void button2();
void button3();
void button4();

void (*buttonTable[4])() = {button1, button2, button3, button4};

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; i++) {
		lamps[i] = true;
	}
	int lamp_on, lamp_off;
	vector<int> ons;
	vector<int> offs;
	vector<string> results;
	while(scanf("%d", &lamp_on)) {
		if(lamp_on == -1) {
			break;
		}
		ons.push_back(lamp_on);
	}
	while(scanf("%d", &lamp_off)) {
		if(lamp_off == -1) {
			break;
		}
		offs.push_back(lamp_off);
	}
	for(int i = 0; i < 16; i++) {
		init();
		bitset<4> status(i);
		if((status.count() % 2) != (c % 2) || (status.count() > c)) {
			continue;
		}
		for(int j = 0; j < 4; j++) {
			if(status[j]) {
				(*buttonTable[j])();
			}
		}
		bool ok = true;
		for(int on = 0; on < ons.size(); on++) {
			if(!lamps[ons[on]]) {
				ok = false;
				break;
			}
		}
		for(int off = 0; off < offs.size(); off++) {
			if(lamps[offs[off]]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			string res = "";
			for(int i = 1; i <= n; i++) {
				res += (lamps[i] ? "1" : "0"); 
			}
			results.push_back(res);
		}
	}
	sort(results.begin(), results.end());
	for(int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
	if(results.size() == 0) {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}

void init() {
	for(int i = 1; i <= n; i++) {
		lamps[i] = true;
	}
}

void button1() {
	for(int i = 1; i <= n; i++) {
		lamps[i] = !lamps[i];
	}
}

void button2() {
	for(int i = 1; i <= n; i += 2) {
		lamps[i] = !lamps[i];	
	}
}

void button3() {
	for(int i = 2; i <= n; i += 2) {
		lamps[i] = !lamps[i];
	}
}

void button4() {
	for(int i = 1; i <= n; i += 3) {
		lamps[i] = !lamps[i];
	}
}


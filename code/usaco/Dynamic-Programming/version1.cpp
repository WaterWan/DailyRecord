#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 10000;
int n;
int sequence[maxn];

int check(int start, int nmatches, int smallest);

int main() {
	freopen("test.in", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	cout << check(0, 0, 99999);
	return 0;
}

int check(int start, int nmatches, int smallest) {
//	cout << "Check!" << endl;
//	cout << start << "   " << nmatches << "     " << smallest << endl;
	int better;
	int best = nmatches;
	for(int i = start; i < n; i++) {
		if(sequence[i] < smallest) {
			better = check(i, nmatches + 1, sequence[i]);
			if(better > best) {
				best = better;
			}
		} 
	}
	return best;
}


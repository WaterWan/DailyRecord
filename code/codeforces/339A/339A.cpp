#include <iostream>
#include <string>

using namespace std;
const int maxn = 105;

int main() {
	string s;
	cin >> s;
	int number[maxn];
	int count[3] = {0, 0, 0};
	for(int i = 0; i < s.length(); i+=2) {
		count[s[i]-'0'-1]++;
	}
	int n_ptr = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < count[i]; j++) {
			number[n_ptr] = i+1;
			n_ptr++;
		}
	}
	bool first = true;
	for(int i = 0; i < n_ptr; i++) {
		if(first) {
			cout << number[i];
			first = false;
		}else {
			cout << "+" << number[i];
		}
	}
	cout << endl;
	return 0;
}

/**
ID: Wan Zhong
TASK: zerosum
LANG: C++11
**/ 
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;
int n;
vector<string> res;
char num2char(int i);
int get_last_plus(int x, int sum, int last_oper);
int get_last_minus(int x, int sum, int last_oper);
int get_last_block(int x, int sum, int last_oper);
int op_plus(int x, int sum, int last_oper);
int op_minus(int x, int sum, int last_oper);
int op_block(int x, int sum, int last_oper);

int (*func[3])(int x, int sum, int last_oper) = {op_plus, op_minus, op_block};
int (*oper[3])(int x, int sum, int last_oper) = {get_last_plus, get_last_minus, get_last_block};
char sym[3] = {'+', '-', ' '};

void dfs(int x, int sum, int last_oper, string str) {
	if(x == n + 1) {
		if(sum == 0) {
			res.push_back(str);
		}
		return;
	}
	for(int i = 0; i < 3; i++) {
		dfs(x + 1, func[i](x, sum, last_oper), oper[i](x, sum, last_oper), str + sym[i] + num2char(x));
	}
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	scanf("%d", &n);
	dfs(2, 1, 1, "1");
	sort(res.begin(), res.end(), less<string>());
	for(string s : res) {
		printf("%s\n", s.c_str());
	}
}
char num2char(int i){  
    char ch = i + '0';  
    return ch;  
} 
int get_last_plus(int x, int sum, int last_oper) {
	return x;
}
int get_last_minus(int x, int sum, int last_oper) {
	return -1 * x;
}
int get_last_block(int x, int sum, int last_oper) {
	int sgn = (last_oper > 0) ? 1 : (-1);
	return sgn * (abs(last_oper) * 10 + x);
}
int op_plus(int x, int sum, int last_oper) {
	return sum + x;
}
int op_minus(int x, int sum, int last_oper) {
	return sum - x;
}
int op_block(int x, int sum, int last_oper) {
	return sum - last_oper + get_last_block(x, sum, last_oper);
}

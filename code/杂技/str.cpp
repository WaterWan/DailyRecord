#include <iostream>
#include <bitset>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 50;



/*
Method 1
*/
//	int len = s.length();
//	for(int i = 1; i < (1 << len); i++) {
//		bitset<maxn> bs(i);
//		for(int j = 0; j < len; j++) {
//			if(bs[j]) {
//				cout << s[j];
//			}
//		}
//		cout << endl;
//	}
//	return 0;


/*
Method 2
*/
//bool visited[maxn];
//string s;
//int size;
//void sub(int depth) {
//	if(depth == size) {
//		for(int i = 0; i < size; i++) {
//			if(visited[i]) {
//				cout << s[i];
//			}
//		}
//		cout << endl;
//		return;
//	}
//	visited[depth] = false;
//	sub(depth + 1);
//	visited[depth] = true;
//	sub(depth + 1);
//}
//
//int main() {
//	cin >> s;
//	size = s.length();
//	memset(visited, 0, sizeof visited);
//	sub(0);
//}






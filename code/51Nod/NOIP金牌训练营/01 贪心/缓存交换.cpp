#include <stdio.h>
#include <set>
#include <map>
using namespace std;
int n, m;
const int maxn = 100010;
int a[maxn];
int p[maxn];// ��p[x] = y�������x�β���������һ�����棬��ô��һ�η�������������ڵ�i�β���
map<int, int> g; // g[i] = l,��ʾ���һ�η��ʵ�i���������ڵ�l�β���ִ�е� 
set<int> s; // s��ʾ��ǰ������Щ�����ǲ���Ҫ���·���cache�� 
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		p[i] = n + 1;
		p[g[a[i]]] = i;
		g[a[i]] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s.find(i) != s.end()) {
			s.erase(i);
			s.insert(p[i]);
		} else {
			cnt++;
			if(s.size() == m) {
				s.erase(--s.end());
			}
			s.insert(p[i]);
		}
	}
	printf("%d", cnt);
	return 0;
}

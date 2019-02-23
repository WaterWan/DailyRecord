#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
typedef struct People{
	int a;
	int b;

}People;
People people[maxn];
int cmp(People p1, People p2) {
	if(p1.b * p2.a != p2.b * p1.a) {
		return p1.b * p2.a < p2.b * p1.a;
	}
	if(p1.a != p2.a) {
		return p1.a < p2.a;
	}
	return p1.b > p2.b;
}
int main() {
	int n;
	scanf("%d", &n);
	int a, b;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		people[i] = {a, b};
	}
	sort(people, people + n, cmp);
	long long wt = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		wt += 1LL * people[i].b;
		sum += wt * people[i].a;
	}
	printf("%lld", sum);
	return 0;
}

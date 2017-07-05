#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5000000, mod = 1000000007;

typedef long long LL;
// not prime
bool np[N+5];
// p���м�¼���е����� 
LL p[N], tot;
LL f[N+5];

void init(){
	LL k;
	for(int i = 2; i <= N;i++){
		if(!np[i]) {
			p[++tot]=i;
			f[i] = 1LL * (i - 1) * i / 2 % mod;
		}

		// j�������е����е����� 
		for(int j = 1; j <= tot && i * p[j] <= N;j++){
			np[i*p[j]] = 1;
			// �����״̬ת�Ʒ����������ģ����x���Ա�ʾ��һ����������һ������1��������ô��ʱ��Ӧ�ð���ÿ��p[j]���ˣ��ֳ�i�� ����ô��һ�־���f[p[j]] * i,�ڶ��־��� f[i]
			f[i*p[j]] = (1LL * f[p[j]]  * i + f[i]) % mod;
			if(i % p[j] == 0) {
				break;
			} 
		}
	}
}

int main(){
	init();
	LL ans = 0;
	LL l, r , t , now = 1;
	scanf("%I64d%I64d%I64d",&t,&l,&r);
	for(int i = l;i <= r;i++){
		ans += now * f[i] % mod;
		now = now * t % mod;
	}
	cout << ans % mod << endl;
}

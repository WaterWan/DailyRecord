// 从网上找的一份答案 
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
typedef unsigned long long ulint;

/*
 * 对于x*y的字符串矩阵进行hash
 * 预处理的时候H[i][j]表示从第i行第一个字符开始长度为j的字符串hash
 * 随后处理成(0, 0)作为左上角, (i, j)作为右下角的字符矩阵的Hash值
 * x是竖着的行数, y是横着的列数
 */
#define maxx 505
#define maxy 505

ulint seedx = 233;
ulint seedy = 23333;
ulint xp[maxx];
ulint yp[maxy];
ulint H[maxx][maxy];
char s[maxx][maxy];
int x, y;

void init(int x, int y)
{
    xp[0] = yp[0] = 1;
    for(int i = 1; i <= x; i++) xp[i] = xp[i - 1]*seedx;
    for(int i = 1; i <= y; i++) yp[i] = yp[i - 1]*seedy;
    return;
}

void initHash(int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        H[i][0] = s[i][0] - 'a' + 1;
        for(int j = 1; j < y; j++)
            H[i][j] = H[i][j - 1]*seedy + s[i][j] - 'a' + 1;
    }
    for(int i = 1; i < x; i++)//从1开始, 第0行是不变的
        for(int j = 0; j < y; j++)
            H[i][j] += H[i - 1][j]*seedx;
    return;
}

ulint askHash(int x1, int y1, int x2, int y2)//询问以(x1, y1)为左上角, (x2, y2)为右上角的字符矩阵的hash值
{
    ulint ret = H[x2][y2];
    if(x1 > 0) ret -= H[x1 - 1][y2]*xp[x2 - x1 + 1];
    if(y1 > 0) ret -= H[x2][y1 - 1]*yp[y2 - y1 + 1];
    if(x1 > 0 && y1 > 0) ret += H[x1 - 1][y1 - 1]*xp[x2 - x1 + 1]*yp[y2 - y1 + 1];
    //H[x2][y2] - H[x1 - 1][y2]*xp[x2 - x1 + 1] - H[x2][y1 - 1]*yp[y2 - y1 + 1] + H[x1 - 1][y1 - 1]*xp[x2 - x1 + 1]*yp[y2 - y1 + 1];
    return ret;
}

//vector<pair<ulint, pair<int, int> > > V; vector TLE, map MLE了, 试试邻接表

struct Edge
{
    ulint data;
    int nex;
    int x, y;
};

Edge edges[maxx*maxy];

int head[100010];
int tot = 0;
const ulint maxSize = 100007;

void add(ulint u, ulint data, int x, int y)
{
    edges[tot].data = data;
    edges[tot].x = x;
    edges[tot].y = y;
    edges[tot].nex = head[u];
    head[u] = tot++;
}

int exist(ulint value)
{
    ulint u = value % maxSize;
    for(int i = head[u]; i + 1; i = edges[i].nex)
    {
        if(edges[i].data == value)
            return i + 1;
    }
    return 0;
}

bool check(int mid, int &x1, int &y1, int &x2, int &y2)
{
    memset(head, -1, sizeof(head));
    tot = 0;
    for(int i = 0; i + mid - 1 < x; i++)
        for(int j = 0; j + mid - 1 < y; j++)
        {
            ulint tmp = askHash(i, j, i + mid - 1, j + mid - 1);
            int pos;
            if(pos = exist(tmp))
            {
                x1 = edges[pos - 1].x;
                y1 = edges[pos - 1].y;
                x2 = i + 1;
                y2 = j + 1;
                return true;
            }
            add(tmp % maxSize, tmp, i + 1, j + 1);
        }
    return false;
}

int main()
{
    while(~scanf("%d %d", &x, &y))
    {
        getchar();
        for(int i = 0; i < x; i++)
            gets(s[i]);
        init(x, y);
        initHash(x, y);
        int L = 1, R = min(x, y), ans = 0;
        int ansx1, ansy1, ansx2, ansy2;
        while(L <= R)//二分正方形的边长来判断
        {
            int mid = (L + R) >> 1;
            if(check(mid, ansx1, ansy1, ansx2, ansy2))
            {
                ans = mid;
                L = mid + 1;
            }
            else R = mid - 1;
        }
        printf("%d\n", ans);
        if(ans) printf("%d %d\n%d %d\n", ansx1, ansy1, ansx2, ansy2);
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
struct Vector {
	double x, y;
	Vector(int xx, int yy):x(xx), y(yy) {}
	Vector() {}
	double operator ^ (const Vector &v) const {
		return x * v.y - v.x * y;
	}
};
#define Point Vector

Vector operator - (const Point &p1, const Point &p2) { // 从A点指向B点的矢量AB可用B-A来表示 
	return Vector(p1.x - p2.x, p1.y - p2.y); // 矢量从p2指向p1 
}

bool operator < (const Point &p1, const Point& p2) {
	// 如果p1^p2 > 0，说明p1经逆时针旋转<180度可以到p2，则p1<p2
	if((Vector(p2 - Point(0, 0)) ^ Vector(p1 - Point(0, 0))) > 0) {
		return true;
	} 
	return false;
} 

Point ps[60];
int main() {
	int x, y;
	int n = 0;
	while(cin >> ps[n].x >> ps[n].y) {
		n++;
	}
	sort(ps + 1, ps + n);
	cout << "(0,0)" << endl;
	for(int i = n - 1; i > 0; i--) {
		cout << "(" << ps[i].x << "," << ps[i].y << ")" << endl;
	} 
	return 0;
}

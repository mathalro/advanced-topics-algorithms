#include <bits/stdc++.h>
#define CW 1
#define CCW 2
#define COL 0
#define maxn 100

using namespace std;

struct point {
	int x, y;
	point() {}
	point(int _x, int _y) : x(_x), y(_y) {}
};

point P[maxn];
int n;

/*
	Calculates the orientation of 3 points, if they are counterclockwise return 2, if are clockwise return 1, or colinear returns 0
*/
int orientation(point p0, point p1, point p2) {
	int tmp = (p1.x-p0.x)*(p2.y-p1.y) - (p2.x-p1.x)*(p1.y-p0.y);
	if (tmp == COL) return COL;
	return tmp > COL ? CCW : CW;
}

/*
	Calculates the distance between two points
*/
int dist(point p1, point p2) {
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}


/*
	Operator to ordenate the vector of points with respect to the polar angle
*/
bool operator<(point p1, point p2) {
	int o = orientation(P[0], p1, p2);
	if (o == 0) return dist(p1, P[0]) < dist(p2, P[0]);
	return o == CW ? false : true;
}

point nextToTop(stack<point> S) {
	S.pop();
	return S.top();
}

/*
	Algotithm of Granhan to find the Convex Hull
*/
void grahanScan() {

	// eliminate the colinear points
	int m = 1;
	for (int i = 1; i < n; i++) {
		while (i < n-1 && orientation(P[0], P[i], P[i+1]) == 0) {
			i++;
		}
		P[m] = P[i];
		m++;
	}

	// Find de Hull
	stack<point> S;
	S.push(P[0]);
	S.push(P[1]);
	S.push(P[2]);

	for (int i = 3; i < m	; i++) {
		// verify if the last 3 points are CCW, if not, remove the middle point from the stack
		while (orientation(nextToTop(S), S.top(), P[i]) != 2) {
			S.pop();
		}
		S.push(P[i]);
	}

	while (!S.empty()) {
		printf("%d %d\n", S.top().x, S.top().y);
		S.pop();
	}
}

int main () {
	scanf("%d", &n);
	int menor = 0;

	int x, y; scanf("%d %d", &x, &y);
	P[0] = point(x, y);

	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		P[i] = point(x, y);
		if (y < P[menor].y) {
			menor = i;
		} else if (y == P[menor].y && x < P[menor].x) {
			menor = i;
		}
	}

	swap(P[menor], P[0]);
	sort(P+1, P+n);
	grahanScan();

	return 0;
} 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define Nmax 500

struct point
{
	int x, y;
	char c;
};

struct line
{
	struct point p1, p2;
};

struct point polygon[Nmax];

int ccw(struct point p0, // is it counterclockwise??
		struct point p1,
		struct point p2)
{
	int dx1, dx2, dy1, dy2;
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	if (dx1*dy2 > dy1*dy2) return +1;
	if (dx1*dy2 > dy1*dx2) return -1;
	if ((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
	if ((dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2))
										return 1;

}

int parallel(struct line l1, struct line l2){
	return (l1.p2.y - l1.p1.y)*(l2.p2.x - l2.p1.x) == (l2.p2.y - l2.p1.y)*(l1.p2.x - l1.p1.x);
}

int intersect(struct line l1, struct line l2)
{
	return ((ccw(l1.p1, l1.p2, l2.p1)
			*ccw(l1.p1, l1.p2, l2.p2)) <= 0)
		&& ((ccw(l2.p1, l2.p2, l1.p1)
			*ccw(l2.p1, l2.p2, l1.p2)) <= 0);
}

float theta(struct point p1, struct point p2)
{
	int dx, dy, ax, ay;
	float t;
	dx = p2.x - p1.x; ax = abs(dx);
	dy = p2.y - p1.y; ay = abs(dy);
	t = (ax + ay == 0) ? 0 : (float) dy/(ax + ay);
	if (dx < 0) t = 2-t;
	else if (dy < 0) t = 4+t;
	return t*90.0;
}

int inside(struct point t, struct point p[], int N)
{
	int i, count = 0, j = 0;
	struct line lt, lp;
	p[0] = p[N]; p[N+1] = p[1];
	lt.p1 = t; lt.p2 = t; lt.p2.x = INT_MAX;
	for (i = 0; i <= N; i++)
	{
		lp.p1 = p[1]; lp.p2 = p[i];
		if (!intersect(lp,lt))
		{
			lp.p2 = p[j]; j = i;
			if (intersect(lp,lt)) count++;
		}
	}
	return count & 1;
}

int perpendicular(struct line l1, struct line l2){
	return (l1.p2.y - l1.p1.y)*(l2.p2.y - l2.p1.y) == -1*(l1.p2.x - l1.p1.x)*(l2.p2.x - l2.p1.x);
}



double length_squared(struct line l){
	return (l.p2.x - l.p1.x)*(l.p2.x - l.p1.x) + (l.p2.y - l.p1.y)*(l.p2.y - l.p1.y);
}

int square(struct line l1, struct line l2, struct line l3, struct line l4){
	int i, j;
	int distances[8*7];
	struct point P[8];

	P[0] = l1.p1; 
	P[1] = l1.p2; 
	P[2] = l2.p1; 
	P[3] = l2.p2; 
	P[4] = l3.p1; 
	P[5] = l3.p2; 
	P[6] = l4.p1; 
	P[7] = l4.p2; 

	int index = 0;
	for (i = 0; i < 8; i++) { 
		for (j = i+1; j < 8; j++) {
			struct line lp;
			lp.p1 = P[i];
			lp.p2 = P[j];
			distances[index++] = length_squared(lp);
		}
	}

	if (!(sides + diagonals + points)) return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	


	return 0;
}
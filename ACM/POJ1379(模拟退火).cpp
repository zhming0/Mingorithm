#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<time.h>
using namespace std;
const static int P = 15, L = 25, INF = 1e20;
const double decay = 0.85, eps = 1e-3, pi = acos(-1.0);
struct Pint{
	double x, y, dist;
}hole[1010], cand[P];
double dis(const Pint& a, const Pint& b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main(int argc, char *argv[]) {
	int cases, X, Y, M;
	scanf("%d", &cases);
	srand((unsigned)time(NULL));
	while (cases--) {
		scanf("%d %d %d", &X, &Y, &M);
		double delta = double(max(X,Y))/(sqrt(1.0*M));
		for (int i=0; i<M; i++) {
			scanf("%lf %lf", &hole[i].x, &hole[i].y);
			hole[i].dist = INF;
		}
		for (int i=0; i<P; i++)	{
			cand[i].x = double(rand()%1000 + 1) / 1000.000 * X;
			cand[i].y = double(rand()%1000 + 1) / 1000.000 * Y;
			cand[i].dist = INF;
			for (int j=0; j<M; j++) 
				cand[i].dist = min(cand[i].dist, dis(cand[i], hole[j]));
		}		
		while (delta > eps) {
			for (int i=0; i<P; i++) {
				for (int j=0; j<L; j++) {
					Pint t;
					double tmp = double(rand()%1000 + 1) / 1000.000 * 10 * pi;
					t.x = cand[i].x + delta*cos(tmp);
					t.y = cand[i].y + delta*sin(tmp);
					if (t.x < 0 || t.y < 0 ||t.y > Y || t.x > X )
						continue;
					t.dist = INF;
					for (int k=0; k<M; k++) 
						t.dist = min(t.dist, dis(t, hole[k]));
					if (t.dist > cand[i].dist) 
						cand[i] = t;
				}
			}
			delta *= decay;
		}
		int retidx=0;
		for (int i=0; i<P; i++) 
			if (cand[i].dist > cand[retidx].dist) 
				retidx = i;
		printf("The safest point is (%.1lf, %.1lf).\n", cand[retidx].x, cand[retidx].y);
	}
	return 0;
}
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define PRE 0.00000001

double abs_double(double a)
{
	if (a>0) return a;
	else return -a;
}

int main (int argc, const char * argv[]) {
	int cases;
	//freopen("test.txt", "r", stdin);
	scanf("%d",&cases);
	while (cases--) {
		int i;
		double p1[3],v1[3],p2[3],v2[3];
		double newPos1[3];
		double newPos2[3];
		double R;
		double time,time2;
		scanf("%lf%lf%lf",&p1[0],&p1[1],&p1[2]);
		scanf("%lf%lf%lf",&v1[0],&v1[1],&v1[2]);
		scanf("%lf%lf%lf",&p2[0],&p2[1],&p2[2]);
		scanf("%lf%lf%lf",&v2[0],&v2[1],&v2[2]);
		scanf("%lf",&R);
		double dis;
		double lefttime=0;
		double righttime=100000000;
		time=(lefttime+righttime)/2;
		time2=righttime;
		while (abs_double(time-time2)>PRE) {
			time=(lefttime+righttime)/2;
			time2=(time+righttime)/2;
			for (i=0; i<3; i++) {
				newPos1[i]=p1[i]+v1[i]*time;
				newPos2[i]=p2[i]+v2[i]*time;
			}
			double newDis1=sqrt((newPos1[0]-newPos2[0])*(newPos1[0]-newPos2[0])+
							   (newPos1[1]-newPos2[1])*(newPos1[1]-newPos2[1])+
							   (newPos1[2]-newPos2[2])*(newPos1[2]-newPos2[2]));
			for (i=0; i<3; i++) {
				newPos1[i]=p1[i]+v1[i]*time2;
				newPos2[i]=p2[i]+v2[i]*time2;
			}
			double newDis2=sqrt((newPos1[0]-newPos2[0])*(newPos1[0]-newPos2[0])+
								(newPos1[1]-newPos2[1])*(newPos1[1]-newPos2[1])+
								(newPos1[2]-newPos2[2])*(newPos1[2]-newPos2[2]));
			if (newDis2>newDis1) {
				dis=newDis1;
				righttime=time2;
			}else {
				dis=newDis2;
				lefttime=time;
			}
			if (dis<=R) {
				break;
			}
		}
		//printf("time=%lf,time2=%lf,dis=%lf\n",time,time2,dis);
		if (dis<=R) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}

	}

    return 0;
}

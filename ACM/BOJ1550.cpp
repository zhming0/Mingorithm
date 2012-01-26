#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases;
	cin>>cases;
	while (cases--) {
		int G1,S1,B1,G2,S2,B2;
		int op=0;
		cin>>G1>>S1>>B1>>G2>>S2>>B2;
		if (G1<G2)
		{
			op+=(G2-G1);
			S1-=(G2-G1)*11;
			G1=G2;
		}
		if(B1<B2)
		{
			if ((B2-B1)%9==0) {
				op+=(B2-B1)/9;
				S1-=(B2-B1)/9;
				B1=B2;
			}
			else {
				op+=(B2-B1)/9+1;
				S1-=((B2-B1)/9+1);
				B1=B2;
			}
		}
		if (S1<S2) {
			int gap=S2-S1;
			int needG,needB;
			if (gap%9==0) {
				needG=gap/9;
			}else {
				needG=gap/9+1;
			}
			if (G1>G2) {
				if (needG>=(G1-G2)) {
					S1+=(G1-G2)*9;
					gap-=(G1-G2)*9;
					op+=G1-G2;
					G1=G2;
				}else {
					S1+=needG*9;
					gap-=needG*9;
					G1-=needG;
					op+=needG;
				}
			}
			if (gap>0) {
				needB=gap*11;
				B1-=needB;
				S1+=gap;
				op+=gap;
			}
		}
		if ((G1<G2)||(S1<S2)||(B1<B2)) {
			cout << -1<<endl;
		}else {
			cout <<op<<endl;
		}
	}
    return 0;
}

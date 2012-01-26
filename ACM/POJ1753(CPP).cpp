#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
#define ALL_WHITE 0
#define ALL_BLACK 65535
#define MAX 65536

int flipPiece(int state,int pos)
{
	state^=(1<<pos);
	if (pos-4>=0) {
		state^=(1<<(pos-4));
	}
	if (pos+4<16) {
		state^=(1<<(pos+4));
	}
	if (pos%4!=0) {
		state^=(1<<(pos-1));
	}
	if (pos%4!=3) {
		state^=(1<<(pos+1));
	}
	return state;
}

int main (int argc, const char * argv[]) {
	int state[MAX];
	int currentState;
	queue<int> q;
	int i;
	//memset(queue,0,sizeof(queue));
	memset(state,-1,sizeof(state));
	for (i=0; i<16; i++) {
		char temp;
		scanf("%c",&temp);
		if (temp=='b') 
			currentState+=1<<i;
		if ((i+1)%4==0) {
			scanf("%c",&temp);
		}
	}
	if (currentState==ALL_WHITE||currentState==ALL_BLACK) {
		printf("%d\n",0);
		return 0;
	}
	state[currentState]=0;
	q.push(currentState);
	while (!q.empty()) {
		//currentState=queue[head++];
		currentState=q.front();
		q.pop();
		for (i=0; i<16; i++) {
			int temp=flipPiece(currentState, i);
			if (state[temp]==-1) {
				//queue[tail++]=temp;
				q.push(temp);
				state[temp]=state[currentState]+1;
				if (temp==ALL_WHITE||temp==ALL_BLACK) {
					printf("%d\n",state[temp]);
					return 0;
				}
			}
		}
	}
	if (state[ALL_WHITE]==-1&&state[ALL_BLACK]==-1) {
		printf("Impossible\n");
	}
	
    return 0;
}

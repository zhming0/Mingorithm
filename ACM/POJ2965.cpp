#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 65536
#define ALL_OPEN 65535
using namespace std;
typedef struct movement{
	int state;
	int pos;
	movement* next;
	movement* pre;
}movement;
int op(int state,int pos)
{
	int i;
	int row=pos/4;
	int column=pos%4;
	for (i=(row*4); i<((row+1)*4);i++) {
		state^=(1<<i);
	}
	for (i=column; i<16; i+=4) {
		state^=(1<<i);
	}
	state^=(1<<pos);
	return state;
}
int main (int argc, char * const argv[]) {
	queue<movement*> q;
	int state[MAX];
	int i,currentState;
	memset(state, -1, sizeof(state));
	for (i=0; i<16; i++) {
		char temp;
		cin>>temp;
		if (temp=='-') {
			currentState+=(1<<i);
		}
	}
	movement* move=(movement*)malloc(sizeof(movement));
	move->state=currentState;
	move->next=NULL;move->pre=NULL;
	move->pos=0;
	q.push(move);
	state[move->state]=0;
	while (!q.empty()) {
		move=q.front();
		q.pop();
		if(move->state==ALL_OPEN)
			break;
		for (i=0; i<16; i++) {
			int newState=op(move->state,i);
			if (state[newState]==-1) {
				state[newState]=state[move->state]+1;
				movement* new_move=(movement*)malloc(sizeof(movement));
				new_move->state=newState;new_move->pre=move;
				new_move->next=NULL;new_move->pos=i;
				q.push(new_move);
			}
		}
	}
	if (move->state==ALL_OPEN) {
		printf("%d\n",state[move->state]);
	}
	while (move->pre!=NULL) {
		//printf("%d %d\n",move->pos/4+1,move->pos%4+1);
		move->pre->next=move;
		move=move->pre;
	}
	move=move->next;
	while (move!=NULL) {
		printf("%d %d\n",move->pos/4+1,move->pos%4+1);
		move=move->next;
	}
	
    return 0;
}

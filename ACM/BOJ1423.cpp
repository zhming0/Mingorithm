#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3000
typedef struct cardStruct{
	int num;
	struct cardStruct* next;
	struct cardStruct* pre;
}card;

int main (int argc, const char * argv[]) {
	int n;
	int i;
    scanf("%d",&n);
	
	card* Card;
	card* firstCard;
	card* lastCard;
	
	Card=(card*) malloc(sizeof(card));
	Card->pre=NULL;
	
	firstCard=Card;
	for (i=0; i<n; i++) 
	{
		Card->num=i+1;
		Card->next=(card*) malloc(sizeof(card));
		Card->next->pre=Card;
		Card=Card->next;
	}
	lastCard=Card->pre;
	lastCard->next=NULL;
	
	while (lastCard!=firstCard) 
	{
		printf("%d ",firstCard->num);
		firstCard=firstCard->next;
		//firstCard->pre=NULL;
		
		if (lastCard==firstCard) 
			break;
		
		//lastCard->next=(card*) malloc(sizeof(card));
		//lastCard->next->num=firstCard->num;
		//lastCard->next->pre=lastCard;
		//lastCard=lastCard->next;
		//lastCard->next=NULL;
		
		//firstCard=firstCard->next;
		
		lastCard->next=firstCard;
		lastCard=lastCard->next;
		firstCard=firstCard->next;
	}
	
	printf("%d\n",firstCard->num);
	
    return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>
#define SIZE 1000100
#define M 99991
using namespace std;
struct Node{
	int value, num, next;
}node[SIZE];
void initNode(Node& nd, int value, int num, int next){
	nd.value = value; nd.num = num; nd.next = next;
}
int hash[M], b[SIZE], cnt;
void insertHash(int value)
{
	int key = value % M;
	int head = hash[key];
	if (head == -1) {
		hash[key] = cnt;
		initNode(node[cnt], value, 1, -1);
		cnt++;
		return;
	}
	int last;
	while (head!=-1) {
		if (node[head].value == value) {
			node[head].num++;
			return;
		}
		last = head;
		head = node[head].next;
	}
	node[last].next = cnt;
	initNode(node[cnt], value, 1, -1);
	cnt++;
}
int checkHash(int value)
{
	int key = value % M;
	int head = hash[key];
	while (head!=-1) {
		if (node[head].value==value)
			return head;
		head = node[head].next;
	}
	return -1;
}
int main()
{
	int n, l=0, ret;
	cnt = 0;
	scanf("%d", &n);
	memset(hash, -1, sizeof(hash));
	for (int i=0; i<n; i++) {
		scanf("%d", &b[i]);
		if (checkHash(b[i]) != -1) {
			insertHash(b[i]);
			int j = checkHash(b[l]);
			while (node[j].num > 1) {
				node[j].num--;
				l++;
				ret = min(ret, i - l + 1);
				j = checkHash(b[l]);
			}
		}else {
			insertHash(b[i]);
			ret = i - l + 1;
		}
	}
	printf("%d\n", ret);
}
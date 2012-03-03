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
int Hash(int value) {
	int head = hash[value % M];
	if (head == -1) {
		hash[value%M] = cnt;
		initNode(node[cnt], value, 1, -1);
		cnt++;
		return cnt-1;
	}
	int last;
	while (head!=-1) {
		if (node[head].value == value) {
			node[head].num++;
			return head;
		}
		last = head;
		head = node[head].next;
	}
	node[last].next = cnt;
	initNode(node[cnt], value, 1, -1);
	cnt++;
	return cnt - 1;
}
int main()
{
	int n, l=0, ret;
	cnt = 0;
	scanf("%d", &n);
	memset(hash, -1, sizeof(hash));
	for (int i=0; i<n; i++) {
		scanf("%d", &b[i]);
		int tmp = Hash(b[i]);
		if (node[tmp].num > 1) {
			int j = Hash(b[l]);
			node[j].num--;
			while (node[j].num > 1) {
				node[j].num--;
				l++;
				ret = min(ret, i - l + 1);
				j = Hash(b[l]);
				node[j].num --;
			}
		}else {
			ret = i - l + 1;
		}
	}
	printf("%d\n", ret);
}
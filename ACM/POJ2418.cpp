#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int cnttype;
struct Node{
    Node* left, *right;
    int cnt;
    char s[35];
    Node(char* ts) {
        cnt = 1;
        left = right =NULL;
        strcpy(s, ts);
    }
};
void insert(char* s, Node* node)
{
    int ret = strcmp(s, node->s);
    if (ret == 0) {
        node -> cnt += 1;
        return;
    }
    if (ret < 0) {
        if (node -> left == NULL) {
            node -> left = new Node(s);
        }else
            insert(s, node->left);
    }else {
        if (node -> right == NULL)
            node -> right = new Node(s);
        else
            insert(s, node->right);
    }
}
void print(Node* node) {
    if (node -> left != NULL)
        print(node->left);
    printf("%s %.4lf\n", node->s, (double)node->cnt*100.0/(double)cnttype);
    if (node -> right != NULL)
        print(node->right);
}
int main() {
    //freopen("/home/ming/Desktop/test.in", "r", stdin);
    char s[35];
    Node* root = NULL;
    cnttype = 0;
    while(gets(s)!=NULL)
    {
        cnttype++;
        if (s[0] == '\0' || s[0]=='\n') break;
        if (root == NULL) {
            root = new Node(s);
        }else
            insert(s, root);
    }
    if (root != NULL)
        print(root);
    delete root;
    return 0;
}

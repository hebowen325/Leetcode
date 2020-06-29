#include<iostream>
#include<stack>
using namespace std;
char op[10];
typedef struct node
{
    node* left;
    node* right;
    int value;
    node(int x):left(NULL),right(NULL),value(x) {}
}node;

void postorder_traverse(node* n)
{
    int note=1;
    stack<node*> S;
    S.push(n);
    while(!S.empty())
    {
        while(!S.empty()&&S.top()!=NULL)
        {
            S.push(S.top()->left);
        }
        S.pop();
        while((!S.empty()&&S.top()->right==NULL)||(!S.empty()&&n==S.top()->right))
        {
            n=S.top();
            S.pop();
            if(note==0)
                printf(" %d",n->value);
            else
            {
                printf("%d",n->value);
                note=0;
            }
        }
        if(!S.empty())
            S.push(S.top()->right);
    }
}

int traverse()
{
    int count=5;
    int ans=0;
    while(op[count]!=0)
    {
        ans*=10;
        ans+=op[count]-'0';
        count++;
    }
    return ans;
}
int main()
{
    int N;
    scanf("%d%*c",&N);
    stack<node*> S;
    node* head;
    node* tmp;
    node* last=NULL;
    scanf("%[^\n]%*c",op);
    tmp=new node (traverse());
    S.push(tmp);
    head=last=tmp;
    for(int i=1;i<2*N;i++)
    {
        scanf("%[^\n]%*c",op);
        if(op[1]=='u')
        {
            tmp=new node (traverse());
            if(last->left==NULL)
                last->left=tmp;
            else
                last->right=tmp;
            S.push(tmp);
            last=tmp;
        }
        else
        {
            last=S.top();
            S.pop();
        }
    }
    int note=1;
    postorder_traverse(head);
    return 0;
}
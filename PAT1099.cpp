#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int TreeStruct[200][2];
typedef struct node
{
    int val;
    node* left=NULL;
    node* right=NULL;
    node () {}
}node;
int mark[200];
int num_of_right[200];
int v[200];
node* Nodes[200];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d",TreeStruct[i],TreeStruct[i]+1);
    for(int i=0;i<N;i++)
    {
        scanf("%d",v+i);
        Nodes[i]=new node ();
    }
    sort(v,v+N);
    fill(mark,mark+200,0);
    for(int i=0;i<N;i++)
    {
        if(TreeStruct[i][0]!=-1)
            Nodes[i]->left=Nodes[TreeStruct[i][0]];
        if(TreeStruct[i][1]!=-1)
            Nodes[i]->right=Nodes[TreeStruct[i][1]];
    }
    int count=0;
    stack<node*> S;
    S.push(Nodes[0]);
    while(!S.empty())
    {
        while(S.top()!=NULL)
        {
            S.push(S.top()->left);
        }
        S.pop();
        if(!S.empty())
        {
            node* tmp=S.top();
            S.top()->val=v[count++];
            S.pop();
            S.push(tmp->right);
        }
    }
    vector<node*> Vec1;
    vector<node*> Vec2;
    Vec2.push_back(Nodes[0]);
    printf("%d",Nodes[0]->val);
    while(!Vec2.empty())
    {
        Vec1=Vec2;
        Vec2.clear();
        for(int i=0;i<Vec1.size();i++)
        {
            if(Vec1[i]->left!=NULL)
            {
                printf(" %d",Vec1[i]->left->val);
                Vec2.push_back(Vec1[i]->left);
            }
            if(Vec1[i]->right!=NULL)
            {
                printf(" %d",Vec1[i]->right->val);
                Vec2.push_back(Vec1[i]->right);
            }        
        }
    }
    return 0;
}
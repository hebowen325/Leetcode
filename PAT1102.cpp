#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left=NULL;
    TreeNode *right=NULL;
    TreeNode () {}
}TreeNode;

TreeNode* tree[10];
int main()
{
    int N;
    scanf("%d",&N);
    int root=N*(N-1)/2;
    char s1,s2;
    for(int i=0;i<N;i++)
    {
        tree[i]=new TreeNode ();
    }
    for(int i=0;i<N;i++)
    {
        tree[i]->val=i;
        scanf("\n%c %c",&s1,&s2);
        if(s1!='-')
        {
            tree[i]->right=tree[(s1-'0')];
            root-=(s1-'0');
        }
        if(s2!='-')
        {
            tree[i]->left=tree[(s2-'0')];
            root-=(s2-'0');
        }
    }
    vector<TreeNode*> Vec1;
    vector<TreeNode*> Vec2;
    Vec2.push_back(tree[root]);
    printf("%d",tree[root]->val);
    while(!Vec2.empty())
    {
        Vec1=Vec2;
        Vec2.clear();
        TreeNode* tmp;
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
    stack<TreeNode*> S;
    bool flag=false;
    S.push(tree[root]);
    while(!S.empty())
    {
        while(S.top()!=NULL)
        {
            S.push(S.top()->left);
        }
        S.pop();
        if(!S.empty()&&S.top()!=NULL)
        {
            TreeNode* tmp=S.top();
            if(!flag)
            {
                printf("\n%d",tmp->val);
                flag=true;
            }
            else
            {
                printf(" %d",tmp->val);
            }
            S.pop();
            S.push(tmp->right);
        }
    }
    return 0;
}
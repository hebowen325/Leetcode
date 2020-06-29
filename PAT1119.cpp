#include<iostream>
#include<stack>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():left(NULL),right(NULL) {}
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
}TreeNode;
int preorder[31];
int postorder[31];
bool recursive_produce(int preleft,int preright,int postleft,int postright,TreeNode* &root)
{ 
    bool flag=true;
    root->val=preorder[preleft];
    if(preleft==preright)
    {
        return true;
    }
    int j;
    for(j=0;preorder[preleft+j]!=postorder[postright-1];j++);
    if(j>1)
    {
        root->left=new TreeNode ();
        flag&=recursive_produce(preleft+1,preleft-1+j,postleft,postleft+j-2,root->left);
        root->right=new TreeNode ();
        flag&=recursive_produce(preleft+j,preright,postleft+j-1,postright-1,root->right);
    }
    else
    {
        flag=false;
        root->right=new TreeNode ();
        flag&=recursive_produce(preleft+j,preright,postleft+j-1,postright-1,root->right);
    }
    return flag;
}
int main() 
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",preorder+i);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",postorder+i);
    }
    TreeNode* root=new TreeNode();
    if(recursive_produce(0,N-1,0,N-1,root)==true)
    {
        printf("Yes\n");        
    }
    else
    {
        printf("No\n");
    }
    stack<TreeNode*> S;
    S.push(root);
    TreeNode* tmp=NULL;
    while(!S.empty())
    {
        while(S.top()!=NULL)
        {
            S.push(S.top()->left);
        }
        S.pop();
        if(!S.empty())
        {
            if(tmp!=NULL)
            {
                printf(" ");
            }
            printf("%d",S.top()->val);
            tmp=S.top();
            S.pop();
            S.push(tmp->right);
        }
    }
    printf("\n");
    return 0;
}
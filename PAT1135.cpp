#include<iostream>
#include<math.h>
using namespace std;
typedef struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode():left(NULL),right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;
int N,Result[31];
void PreTraverse(int left,int right,TreeNode* &root)
{
    if(left>right)
    {
        root=NULL;
        return;
    }
    root=new TreeNode(Result[left]);
    int i;
    for(i=left+1;i<=right;i++)
    {
        if(abs(Result[i])>abs(Result[left]))
        {
            break;
        }
    }
    PreTraverse(left+1,i-1,root->left);
    PreTraverse(i,right,root->right);
}

int judge(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->val<0)
    {
        if(root->left!=NULL&&root->left->val<0)
        {
            return -1;
        }
        if(root->right!=NULL&&root->right->val<0)
        {
            return -1;
        }
    }
    int left_num,right_num;
    if(judge(root->left)==-1)
    {
        return -1;
    }
    else
    {
        left_num=judge(root->left);
    }
    if(judge(root->right)==-1)
    {
        return -1;
    }
    else
    {
        right_num=judge(root->right);
    }
    if(root->left==NULL||root->left->val>0)
    {
        left_num++;
    }
    if(root->right==NULL||root->right->val>0)
    {
        right_num++;
    }
    if(left_num==right_num)
    {
        return left_num;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%d",Result+j);
        }
        TreeNode* root;
        PreTraverse(0,N-1,root);
        if(Result[0]<0||judge(root)==-1)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}
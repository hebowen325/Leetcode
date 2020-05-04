#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int ptr[1000];
int findpower(int x)
{
    int ans=-1;
    while(x!=0)
    {
        x/=2;
        ans++;
    }
    return ans;
}
int Pow(int x)
{
    int ans=1;
    for(int i=0;i<x;i++)
    {
        ans*=2;
    }
    return ans;
}
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
}TreeNode;
void GenerateTree(TreeNode* pointer,int left,int right)
{
    if(left==right)
    {
        pointer->val=ptr[left];
        return ;
    }
    int num=right-left+1;
    int p=findpower(num);
    if(num-Pow(p)+1<=Pow(p-1))
    {
        pointer->val=ptr[right-Pow(p-1)+1];
        pointer->left=new TreeNode(0);
        GenerateTree(pointer->left,left,right-Pow(p-1));
        if(p>1)
        {
            pointer->right=new TreeNode(0);
            GenerateTree(pointer->right,right-Pow(p-1)+2,right);
        }
    }
    else
    {
        pointer->val=ptr[left+Pow(p)-1];
        pointer->left=new TreeNode(0);
        GenerateTree(pointer->left,left,left+Pow(p)-2);
        pointer->right=new TreeNode(0);
        GenerateTree(pointer->right,left+Pow(p),right);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",ptr+i);
    }
    sort(ptr,ptr+N);
    TreeNode *root=new TreeNode(0);
    GenerateTree(root,0,N-1);
    queue<TreeNode*> Queue;
    printf("%d",root->val);
    if(root->left!=NULL)
    {
        Queue.push(root->left);
        if(root->right!=NULL)
        {
            Queue.push(root->right);
        }
    }
    while(!Queue.empty())
    {
        root=Queue.front();
        Queue.pop();
        printf(" %d",root->val);
        if(root->left!=NULL)
        {
            Queue.push(root->left);
            if(root->right!=NULL)
            {
                Queue.push(root->right);
            }
        }
    }
    return 0;
}
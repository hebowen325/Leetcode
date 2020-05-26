#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int inorder[10001];
int preorder[10001];
typedef struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode():left(NULL),right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;

void GenerateTree(int inleft,int inright,int preleft,int preright,TreeNode*& root)
{
    if(inleft>inright)
    {
        return;
    }
    root=new TreeNode(preorder[preleft]);
    int j;
    for(j=inleft;inorder[j]!=preorder[preleft];j++);
    GenerateTree(inleft,j-1,preleft+1,preleft+1+j-1-inleft,root->left);
    GenerateTree(j+1,inright,preright+j+1-inright,preright,root->right);
}
int LCAFind(TreeNode* root,int num1,int num2)
{
    if(root==NULL)
    {
        return 0;
    }
    int t1=LCAFind(root->left,num1,num2);
    int t2=LCAFind(root->right,num1,num2);
    if(root->val==num1||root->val==num2)
    {
        if(root->val==num1&&t1+t2==1)
        {
            printf("%d is an ancestor of %d.\n",num1,num2);
            return 2;
        }
        if(root->val==num2&&t1+t2==1)
        {
            printf("%d is an ancestor of %d.\n",num2,num1);
            return 2;
        }
        return 1;
    }
    if(t1==1&&t2==1)
    {
        printf("LCA of %d and %d is %d.\n",num1,num2,root->val);
    }
    return t1+t2;
}
int main()
{
    int M,N;
    set<int> S;
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",inorder+i);
        S.insert(inorder[i]);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",preorder+i);
    }
    TreeNode* root;
    GenerateTree(0,N-1,0,N-1,root);
    for(int i=0;i<M;i++)
    {
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        if(find(S.begin(),S.end(),num1)==S.end()||find(S.begin(),S.end(),num2)==S.end())
        {
            if(find(S.begin(),S.end(),num1)!=S.end())
            {
                printf("ERROR: %d is not found.",num2);
                continue;
            }
            else if(find(S.begin(),S.end(),num2)!=S.end())
            {
                printf("ERROR: %d is not found.",num1);
                continue;
            }
            else
            {
                printf("ERROR: %d and %d are not found.",num1,num2);
                continue;
            }
        }
        if(num1==num2)
        {
            printf("%d is an ancestor of %d.\n",num1,num2);
            continue;
        }
        LCAFind(root,num1,num2);
    }
    return 0;
}
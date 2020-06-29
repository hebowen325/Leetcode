#include<iostream>
using namespace std;
typedef struct TreeNode
{
    int val;
    int height;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(){}
    TreeNode(int x):val(x),height(1) {}
}TreeNode;

int getHeight(TreeNode* node)
{
    if(!node)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}

int getBalanceFactor(TreeNode* node)
{
    return getHeight(node->left)-getHeight(node->right);
}

void UpdateHeight(TreeNode* node)
{
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
}

void Lrotate(TreeNode* &root)
{
    TreeNode* ptr=root->right;
    root->right=ptr->left;
    ptr->left=root;
    UpdateHeight(root);
    UpdateHeight(ptr);
    root=ptr;
}

void Rrotate(TreeNode* &root)
{
    TreeNode* ptr=root->left;
    root->left=ptr->right;
    ptr->right=root;
    UpdateHeight(root);
    UpdateHeight(ptr);
    root=ptr;
}

void insert(TreeNode* &root,int x)
{
    if(!root)
    {
        root=new TreeNode(x);
        return ;
    }
    else if(x<root->val)
    {
        insert(root->left,x);
        UpdateHeight(root);
        if(getBalanceFactor(root)==2)
        {
            if(getBalanceFactor(root->left)==1)
            {
                Rrotate(root);
            }
            else if(getBalanceFactor(root->left)==-1)
            {
                Lrotate(root->left);
                Rrotate(root);
            }
        }
        return ;
    }
    else
    {
        insert(root->right,x);
        UpdateHeight(root);
        if(getBalanceFactor(root)==-2)
        {
            if(getBalanceFactor(root->right)==-1)
            {
                Lrotate(root);
            }
            else if(getBalanceFactor(root->right)==1)
            {
                Rrotate(root->right);
                Lrotate(root);
            }
        }
        return ;
    }
}

int main()
{
    int N;
    int x;
    scanf("%d",&N);
    TreeNode* root=NULL;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        insert(root,x);
    }
    printf("%d",root->val);
    return 0;
}
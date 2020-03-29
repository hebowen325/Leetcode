#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    int height;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int x):val(x),height(1),left(NULL),right(NULL){}
}TreeNode;

int num[1000];
int GetHeight(TreeNode* ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
        return ptr->height;
    }
}

int getBalanceFactor(TreeNode* ptr)
{
    return GetHeight(ptr->left)-GetHeight(ptr->right);
}

void UpdateHeight(TreeNode*& node)
{
    if(node==NULL)
    {
        node->height=0;
    }
    else
    {
        node->height=max(GetHeight(node->left),GetHeight(node->right))+1;
    }
}

void Lrotate(TreeNode*& root)
{
    TreeNode* tmp=root->right;
    root->right=tmp->left;
    tmp->left=root;
    UpdateHeight(root);
    UpdateHeight(tmp);
    root=tmp;
}

void Rrotate(TreeNode*& root)
{
    TreeNode* tmp=root->left;
    root->left=tmp->right;
    tmp->right=root;
    UpdateHeight(root);
    UpdateHeight(tmp);
    root=tmp;
}

void insert(TreeNode*& root,int value)
{
    if(root==NULL)
    {
        root=new TreeNode (value);
    }
    else
    {
        if(value<=root->val)
        {
            insert(root->left,value);
        }
        else
        {
            insert(root->right,value);
        }
    }
    /*UpdateHeight(root);
    if(getBalanceFactor(root)==-2)
    {
        if(getBalanceFactor(root->right)==1)
        {
            Rrotate(root->right);
            Lrotate(root);
        }
        else if(getBalanceFactor(root->right)==-1)
        {
            Lrotate(root);
        }
    }
    else if(getBalanceFactor(root)==2)
    {
        if(getBalanceFactor(root->left)==-1)
        {
            Lrotate(root->left);
            Rrotate(root);
        }
        else if(getBalanceFactor(root->left)==1)
        {
            Rrotate(root);
        }
    }*/
}

int main()
{
    int N;
    TreeNode* root=NULL;
    scanf("%d",&N);
    int tmp;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&tmp);
        insert(root,tmp);
    }
    vector<TreeNode*> v1;
    vector<TreeNode*> v2;
    v2.push_back(root);
    int count=0;
    while(!v2.empty())
    {
        num[count++]=v2.size();
        v1=v2;
        v2.clear();
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]->left!=NULL)
            {
                v2.push_back(v1[i]->left);
            }
            if(v1[i]->right!=NULL)
            {
                v2.push_back(v1[i]->right);
            }
        }
    }
    if(count>=2)
    {
        printf("%d + %d = %d",num[count-1],num[count-2],num[count-1]+num[count-2]);
    }
    else
    {
        printf("%d + 0 = %d",num[count-1],num[count-1]);
    }
    return 0;
}
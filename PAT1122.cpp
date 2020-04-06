#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    int height;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;

int GetHeight(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int GetBalanceFactor(TreeNode* root)
{
    return GetHeight(root->left)-GetHeight(root->right);
}

void UpdateHeight(TreeNode* root)
{
    root->height=max(GetHeight(root->left),GetHeight(root->right))+1;
}

void RRotate(TreeNode*& root)
{
    TreeNode* tmp=root->left;
    root->left=tmp->right;
    tmp->right=root;
    UpdateHeight(root);
    UpdateHeight(tmp);
    root=tmp;
}

void LRotate(TreeNode*& root)
{
    TreeNode* tmp=root->right;
    root->right=tmp->left;
    tmp->left=root;
    UpdateHeight(root);
    UpdateHeight(tmp);
    root=tmp;
}

void insert(TreeNode*& root,int x)
{
    if(root==NULL)
    {
        root=new TreeNode(x);
    }
    else
    {
        if(x<root->val)
        {
            insert(root->left,x);
            if(GetBalanceFactor(root)==2)
            {
                if(GetBalanceFactor(root->left)==1)
                {
                    RRotate(root);
                }
                else if(GetBalanceFactor(root->left)==-1)
                {
                    LRotate(root->left);
                    RRotate(root);
                }
            }
        }
        else
        {
            insert(root->right,x);
            if(GetBalanceFactor(root)==-2)
            {
                if(GetBalanceFactor(root->right)==-1)
                {
                    LRotate(root);
                }
                else if(GetBalanceFactor(root->right)==1)
                {
                    RRotate(root->right);
                    LRotate(root);
                }
            }
        }
    }
    UpdateHeight(root);
}
int num[25];
int main()
{
    int N;
    scanf("%d",&N);
    TreeNode* root=NULL;
    for(int i=0;i<N;i++)
    {
        scanf("%d",num+i);
        insert(root,num[i]);
    }
    vector<TreeNode*> Vec1;
    vector<TreeNode*> Vec2;
    Vec2.push_back(root);
    printf("%d",root->val);
    int count=1;
    bool flag=true;
    while(!Vec2.empty())
    {
        Vec1=Vec2;
        Vec2.clear();
        for(int i=0;i<Vec1.size();i++)
        {
            if(Vec1[i]->left!=NULL)
            {
                Vec2.push_back(Vec1[i]->left);
                printf(" %d",Vec1[i]->left->val);
                count++;
            }
            else if(flag&&count<N)
            {
                flag=false;
            }
            if(Vec1[i]->right!=NULL)
            {
                Vec2.push_back(Vec1[i]->right);
                printf(" %d",Vec1[i]->right->val);
                count++;
            }
            else if(flag&&count<N)
            {
                flag=false;
            }
        }
    }
    if(flag)
    {
        printf("\nYES");
    }
    else
    {
        printf("\nNO");
    }
    return 0;
}
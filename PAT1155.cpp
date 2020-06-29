#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode():left(NULL),right(NULL){}
}TreeNode;
int Level=1;
int flag=0;
void traverse(TreeNode* root,int l,vector<int>& tmp)
{
    if(root->left!=NULL&&root->right!=NULL)
    {
        tmp.push_back(root->val);
        if(flag==0)
        {
            if(root->val>root->left->val)
            {
                flag=1;
            }
            else if(root->val<root->left->val)
            {
                flag=-1;
            }
        }
        if(flag==1)
        {
            if(root->val<root->left->val||root->val<root->right->val)
            {
                flag=2;
            }
        }
        if(flag==-1)
        {
            if(root->val>root->left->val||root->val>root->right->val)
            {
                flag=2;
            }
        }
        traverse(root->right,l+1,tmp);
        traverse(root->left,l+1,tmp);
        tmp.pop_back();
    }
	else if(root->left!=NULL)
	{
        if(flag==0)
        {
            if(root->val>root->left->val)
            {
                flag=1;
            }
            else if(root->val<root->left->val)
            {
                flag=-1;
            }
        }
        else if(flag==1)
        {
            if(root->val<root->left->val)
            {
                flag=2;
            }
        }
        else if(flag==-1)
        {
            if(root->val>root->left->val)
            {
                flag=2;
            }
        }
		tmp.push_back(root->val);
        traverse(root->left,l+1,tmp);
		tmp.pop_back();
	}
	else
	{
		printf("%d",tmp[0]);
        for(int i=1;i<tmp.size();i++)
        {
            printf(" %d",tmp[i]);
        }
        printf(" %d\n",root->val);
	}
}

int main()
{
    int N,Count=1;
    scanf("%d",&N);
    int Val;
    scanf("%d",&Val);
    TreeNode* root=new TreeNode(Val);
    vector<TreeNode*> Vec1,Vec2;
    Vec1.push_back(root);
    while(Count<N)
    {
        Level++;
        Vec2=Vec1;
        Vec1.clear();
        for(int i=0;i<Vec2.size();i++)
        {
            scanf("%d",&Val);
            Vec2[i]->left=new TreeNode(Val);
            Count++;
            if(Count==N)
            {
                break;
            }
            scanf("%d",&Val);
            Vec2[i]->right=new TreeNode(Val);
            Count++;
            Vec1.push_back(Vec2[i]->left);
            Vec1.push_back(Vec2[i]->right);
        }
    }
    vector<int> tmp;
    traverse(root,1,tmp);
    if(flag==1)
    {
        printf("Max Heap");
    }
    else if(flag==-1)
    {
        printf("Min Heap");
    }
    else
    {
        printf("Not Heap");
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
}TreeNode;

int Inorder[31];
int Postorder[31];
void GenerateTreeNode(int Inleft,int Inright,int Postleft,int Postright,TreeNode* &root)
{
    int count=Inleft;
    for(;count<=Inright&&Inorder[count]!=Postorder[Postright];count++);
    root=new TreeNode(Postorder[Postright]);
    if(Inleft<count)
    {
        GenerateTreeNode(Inleft,count-1,Postleft,Postleft+count-1-Inleft,root->left);
    }
    if(count<Inright)
    {
        GenerateTreeNode(count+1,Inright,Postright-Inright+count,Postright-1,root->right);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",Inorder+i);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",Postorder+i);
    }
    TreeNode* root=NULL;
    GenerateTreeNode(0,N-1,0,N-1,root);
    vector<TreeNode*> Vec1;
    vector<TreeNode*> Vec2;
    Vec1.push_back(root);
    printf("%d",root->val);
    int level=0;
    while(!Vec1.empty()||!Vec2.empty())
    {
        Vec2=Vec1;
        Vec1.clear();
        for(int i=0;i<Vec2.size();i++)
        {
            if(Vec2[i]->left!=NULL)
            {
                Vec1.push_back(Vec2[i]->left);
            }
            if(Vec2[i]->right!=NULL)
            {
                Vec1.push_back(Vec2[i]->right);
            }
        }
        if(level%2==0)
        {
            for(int i=0;i<Vec1.size();i++)
            {
                printf(" %d",Vec1[i]->val);
            }
        }
        else
        {
            for(int i=Vec1.size()-1;i>=0;i--)
            {
                printf(" %d",Vec1[i]->val);
            }
        }
        level++;
    }
    return 0;
}
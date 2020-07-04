#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;
int preorder[1001];
int N;
bool JudgeBST(int start,int end,TreeNode* &root)
{
    if(start>end)
    {
        return true;
    }
    root=new TreeNode(preorder[start]);
    int tmp=start+1;
    while(tmp<=end&&preorder[tmp]<preorder[start])
    {
        tmp++;
    }
    int note=tmp-1;
    while(tmp<=end)
    {
        if(preorder[tmp]<preorder[start])
        {
            return false;
        }
        tmp++;
    }
    return JudgeBST(start+1,note,root->left)&&JudgeBST(note+1,end,root->right);
}

bool JudgeMirrorBST(int start,int end,TreeNode* &root)
{
    if(start>end)
    {
        return true;
    }
    root=new TreeNode(preorder[start]);
    int tmp=start+1;
    while(tmp<=end&&preorder[tmp]>=preorder[start])
    {
        tmp++;
    }
    int note=tmp-1;
    while(tmp<=end)
    {
        if(preorder[tmp]>=preorder[start])
        {
            return false;
        }
        tmp++;
    }
    return JudgeMirrorBST(start+1,note,root->left)&&JudgeMirrorBST(note+1,end,root->right);
}
void PostOrderTraverse(TreeNode* root)
{
    vector<int> ans;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty())
    {
        TreeNode* tmp=S.top();
        S.pop();
        ans.push_back(tmp->val);
        if(tmp->left!=NULL)
        {
            S.push(tmp->left);
        }
        if(tmp->right!=NULL)
        {
            S.push(tmp->right);
        }
    }
    for(int i=ans.size()-1;i>0;i--)
    {
        printf("%d ",ans[i]);
    }
    printf("%d",ans[0]);
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",preorder+i);
    }
    TreeNode* root;
    if(JudgeBST(0,N-1,root)==false && JudgeMirrorBST(0,N-1,root)==false)
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        PostOrderTraverse(root);
    }
    return 0;
}


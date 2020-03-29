#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode()
    {
        left=NULL;
        right=NULL;
    }
}TreeNode;

void recursion(TreeNode*& Node,int* postorder,int p_start,int p_end,int* inorder,int i_start,int i_end)
{
    if(p_start>p_end||i_start>i_end)
    {
        Node=NULL;
        return ;
    }
    Node->val=postorder[p_end];
    if(p_start==p_end)
    {
        return ;
    }
    else
    {
        int i_key=i_start;
        while(inorder[i_key]!=Node->val)
        {
            i_key++;
        }
        Node->left=new TreeNode();
        Node->right=new TreeNode();
        recursion(Node->left,postorder,p_start,p_start+i_key-1-i_start,inorder,i_start,i_key-1);
        recursion(Node->right,postorder,p_start+i_key-i_start,p_end-1,inorder,i_key+1,i_end);
    }
}

int main()
{
    int N;
    cin>>N;
    int* postorder=new int [N];
    int* inorder=new int [N];
    for(int i=0;i<N;i++)
    {
        cin>>postorder[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>inorder[i];
    }
    TreeNode* tree=new TreeNode();
    recursion(tree,postorder,0,N-1,inorder,0,N-1);
    queue<TreeNode*> Queue[2];
    Queue[0].push(tree);
    TreeNode* tmp;
    vector<int> ans;
    int count=0;
    while(!(Queue[0].empty()&&Queue[1].empty()))
    {
        if(count%2==0)
        {
            while(!Queue[0].empty())
            {
                tmp=Queue[0].front();
                Queue[0].pop();
                ans.push_back(tmp->val);
                if(tmp->left!=NULL)
                {
                    Queue[1].push(tmp->left);
                }
                if(tmp->right!=NULL)
                {
                    Queue[1].push(tmp->right);
                }
            }
        }
        else
        {
            while(!Queue[1].empty())
            {
                tmp=Queue[1].front();
                Queue[1].pop();
                ans.push_back(tmp->val);
                if(tmp->left!=NULL)
                {
                    Queue[0].push(tmp->left);
                }
                if(tmp->right!=NULL)
                {
                    Queue[0].push(tmp->right);
                }
            }
        }
        count++;
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)
    {
        cout<<" "<<ans[i];
    }
    return 0;
}
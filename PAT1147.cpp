#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(){}
  TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;
void post_traverse(TreeNode* root)
{
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty())
    {
        while(S.top()!=NULL)
        {
            S.push(S.top()->left);
        }
        S.pop();
        if(S.top()->right!=NULL)
        {
            S.push(S.top()->right);
        }
        else
        {
            TreeNode* tmp=S.top();
            S.pop();
            while(!S.empty()&&tmp==S.top()->right)
            {
                printf("%d ",tmp->val);
                tmp=S.top();
                S.pop();
            }
            printf("%d",tmp->val);
            if(tmp!=root)
            {
                printf(" ");
                S.push(S.top()->right);
            }
          	else
            {
              printf("\n");
            }
        }
    }  
}
bool judge_heap(TreeNode* root,bool judge)
{
    if(judge==true)
    {
        if(root->left!=NULL)
        {
            if(root->val<root->left->val || judge_heap(root->left,judge)==false)
            {
                return false;
            }
        }
        if(root->right!=NULL)
        {
            if(root->val<root->right->val || judge_heap(root->right,judge)==false)
            {
                return false;
            }
        }
    }
    else
    {
        if(root->left!=NULL)
        {
            if(root->val>=root->left->val || judge_heap(root->left,judge)==false)
            {
                return false;
            }
        }
        if(root->right!=NULL)
        {
            if(root->val>=root->right->val || judge_heap(root->right,judge)==false)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
  int M,N;
  scanf("%d %d",&M,&N);
  TreeNode* root;
  for(int i=0;i<M;i++)
  {
    int count=0;
    vector<TreeNode**> Vec1;
    Vec1.push_back(&root);
    vector<TreeNode**> Vec2;
    while(count<N)
    {
      for(int i=0;i<Vec1.size()&&count<N;i++)
      {
        int tmp;
        scanf("%d",&tmp);
        *Vec1[i]=new TreeNode (tmp);
        Vec2.push_back(&((*Vec1[i])->left));
        Vec2.push_back(&((*Vec1[i])->right));
        count++;
      }
      Vec1=Vec2;
      Vec2.clear();
    }
    bool judge=true;
    if(root->val<root->left->val)
    {
        judge=false;
    }
    if(judge_heap(root,judge)==true)
    {
        if(judge==true)
        {
            printf("Max Heap\n");
        }
        else
        {
            printf("Min Heap\n");
        }
    }
    else
    {
        printf("Not Heap\n");
    }
    post_traverse(root);
  }
  return 0;
}
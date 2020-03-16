#include<iostream>
#include<cstring>
#include<math.h>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;
TreeNode* node[40];
int main()
{
    int N;
    scanf("%d",&N);
    int sum=N*(N-1)/2;
    string t1,t2;
    for(int i=0;i<N;i++)
    {
        node[i]=new TreeNode(i);
    }
    for(int i=0;i<N;i++)
    {
        cin>>t1>>t2;
        if(t1!="-")
        {
            node[i]->left=node[stoi(t1)];
            sum-=stoi(t1);
        }
        if(t2!="-")
        {
            node[i]->right=node[stoi(t2)];
            sum-=stoi(t2);
        }
    }
    vector<TreeNode*> V1;
    vector<TreeNode*> V2;
    V2.push_back(node[sum]);
    int count=0;
    while(!V2.empty())
    {
        V1=V2;
        V2.clear();
        for(int i=0;i<V1.size();i++)
        {
            if(V1[i]->left!=NULL)
            {
                V2.push_back(V1[i]->left);
            }
            else
            {
                break;
            }
            if(V1[i]->right!=NULL)
            {
                V2.push_back(V1[i]->right);
            }
            else
            {
                break;
            }
        }
        if(V2.size()==int(pow(2.0,(count+1)*1.0)))
        {
            count++;
        }
        else
        {
            if(int(pow(2.0,(count+1)*1.0))-1+V2.size()==N)
            {
                if(V2.size()!=0)
                {
                    printf("YES %d\n",V2[V2.size()-1]->val);
                    break;
                }
                else
                {
                    printf("YES %d\n",V1[V1.size()-1]->val);
                }
            }
            else
            {
                printf("NO %d\n",sum);
                break;
            }
        }
    }
    return 0;
}
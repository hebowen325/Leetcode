#include<iostream>
#include<vector>
#include"limits.h"
#include<algorithm>
using namespace std;
vector<int> edge[10001];
int mark[10001]={0};
int best_result=INT_MIN;
vector<int> best_node;
void simple_dfs(int node)
{
    mark[node]=1;
    for(int i=0;i<edge[node].size();i++)
    {
        if(mark[edge[node][i]]==0)
        {
            simple_dfs(edge[node][i]);
        }
    }
}

int dfs(int father,int node,int depth)
{
    int ans=0;
    if(edge[node].size()==1&&father!=-1)
    {
        return depth;
    }
    else
    {
        for(int i=0;i<edge[node].size();i++)
        {
            if(edge[node][i]!=father)
            {
                ans=max(ans,dfs(node,edge[node][i],depth+1));
            }
        }
    }
    return ans;
}

int main()
{
    int N;
    scanf("%d",&N);
    int node1,node2;
    int root=N*(N+1)/2;
    for(int i=0;i<N-1;i++)
    {
        scanf("%d %d",&node1,&node2);
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }
    fill(mark,mark+10001,0);
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        if(mark[i]==0)
        {
            ans++;
            simple_dfs(i);
        }
    }
    if(ans>1)
    {
        printf("Error: %d components",ans);
    }
    else
    {
        for(int i=1;i<=N;i++)
        {
            if(dfs(-1,i,0)>best_result)
            {
                best_result=dfs(-1,i,0);
                best_node.clear();
                best_node.push_back(i);
            }
            else if(dfs(-1,i,0)==best_result)
            {
                best_node.push_back(i);
            }
        }
        sort(best_node.begin(),best_node.end());
        for(int i=0;i<best_node.size();i++)
        {
            printf("%d\n",best_node[i]);
        }
    }
    return 0;
}
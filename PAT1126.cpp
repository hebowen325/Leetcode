#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int Count[501]={0};
int edge[501][501];
int N,M;
bool DFS()
{
    int C=N;
    int flag[501]={0};
    stack<int> S;
    S.push(1);
    flag[1]=1;
    C--;
    while(!S.empty())
    {
        int tmp=S.top();
        S.pop();
        for(int i=1;i<=N;i++)
        {
            if(edge[tmp][i]==1)
            {
                if(flag[i]==0)
                {
                    S.push(i);
                    flag[i]=1;
                    C--;
                }
            }
        }
    }
    if(C==0)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    fill(edge[0],edge[0]+501*501,0);
    int node1,node2;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&node1,&node2);
        Count[node1]+=1;
        Count[node2]+=1;
        edge[node1][node2]=edge[node2][node1]=1;
    }
    int oddcount=0;
    int zerocount=0;
    printf("%d",Count[1]);
    if(Count[1]%2==1)
    {
        oddcount++;
    }
    for(int i=2;i<=N;i++)
    {
        printf(" %d",Count[i]);
        if(Count[i]%2==1)
        {
            oddcount++;
        }
    }
    if(oddcount==0&&DFS()==true)
    {
        printf("\nEulerian");
    }
    else if(oddcount==2&&DFS()==true)
    {
        printf("\nSemi-Eulerian");
    }
    else
    {
        printf("\nNon-Eulerian");
    }
    return 0;
}
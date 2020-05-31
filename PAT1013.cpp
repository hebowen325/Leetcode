#include<iostream>
#include<algorithm>
using namespace std;
int edges[1000][1000];
bool visit[1000];
int N;
void DFS(int c)
{
    if(!visit[c])
    {
        visit[c]=true;
        for(int i=1;i<=N;i++)
        {
            if(edges[c][i]==1)
            {
                DFS(i);
            }
        }
    }
}
int main()
{
    int M,K;
    scanf("%d%d%d",&N,&M,&K);
    fill(edges[0],edges[0]+1000*1000,0);
    for(int i=0;i<M;i++)
    {
        int city1,city2;
        scanf("%d%d",&city1,&city2);
        edges[city1][city2]=edges[city2][city1]=1;
    }
    for(int i=0;i<K;i++)
    {
        fill(visit,visit+1000,false);
        int city,ans=0;
        scanf("%d",&city);
        visit[city]=true;
        DFS(city%N+1);
        for(int j=1;j<=N;j++)
        {
            if(visit[j]==false)
            {
                ans++;
                DFS(j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
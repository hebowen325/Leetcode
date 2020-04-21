#include<iostream>
using namespace std;
int graph[100001][10000];
int count[100001]={0};
int edge[100001];
int main()
{
    int N,M,K;
    scanf("%d%d",&N,&M);
    int v1,v2;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1][count[v1]++]=i;
        graph[v2][count[v2]++]=i;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        int sum=(M-1)*M/2;
        fill(edge,edge+M+1,0);
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            int vertex;
            scanf("%d",&vertex);
            for(int t=0;t<count[vertex];t++)
            {
                if(edge[graph[vertex][t]]==0)
                {
                    edge[graph[vertex][t]]=1;
                    sum-=graph[vertex][t];
                }
            }
        }
        if(sum>0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}

#include<iostream>
#include "limits.h"
using namespace std;
void print(int* pre,int start,int destination)
{
    if(start!=destination)
    {
        print(pre,start,pre[destination]);
    }
    cout<<destination<<" ";
}
void DJS(int N,int* pre,int* best_distance,int* best_cost,int** roads,int** cost,int start,int destination)
{
    best_distance[start]=0;
    best_cost[start]=0;
    bool* mark=new bool [N];
    for(int i=0;i<N;i++)
    {
        mark[i]=false;
    }
    for(int i=0;i<N;i++)
    {
        int k=-1;
        for(int j=0;j<N;j++)
        {
            if((!mark[j])&&((k<0)||(best_distance[j]<best_distance[k])))
            {
                k=j;
            }
        }
        mark[k]=true;
        for(int j=0;j<N;j++)
        {
            if(roads[k][j]!=-1)
            {
                if((best_distance[j]>best_distance[k]+roads[k][j])||((best_distance[j]==best_distance[k]+roads[k][j])&&(best_cost[k]+cost[k][j]<best_cost[j])))
                {
                    pre[j]=k;
                    best_distance[j]=best_distance[k]+roads[k][j];
                    best_cost[j]=best_cost[k]+cost[k][j];
                }
            }
        }
    }
}
int main()
{
    int N,M,start,destination;
    cin>>N>>M>>start>>destination;
    int** roads=new int* [N];
    int** cost=new int* [N];
    int* best_distance=new int [N];
    int* best_cost=new int [N];
    for(int i=0;i<N;i++)
    {
        roads[i]=new int[N];
        cost[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            roads[i][j]=-1;
        }
        best_distance[i]=INT_MAX;
        best_cost[i]=INT_MAX;
    }
    int* pre=new int [N];
    int city1;
    int city2;
    int Distance;
    int Cost;
    for(int i=0;i<M;i++)
    {
        cin>>city1>>city2>>Distance>>Cost;
        roads[city1][city2]=roads[city2][city1]=Distance;
        cost[city1][city2]=cost[city2][city1]=Cost;
    }
    DJS(N,pre,best_distance,best_cost,roads,cost,start,destination);
    print(pre,start,destination);
    cout<<best_distance[destination]<<" "<<best_cost[destination];
    return 0;
}
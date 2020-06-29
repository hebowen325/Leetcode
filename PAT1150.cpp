#include<iostream>
#include<algorithm>
#include"limits.h"
#include<set>
#include<vector>
using namespace std;
int path[1000][1000]={0};
int main()
{
    fill(path[0],path[0]+1000*1000,0);
    int N,M,K,city1,city2;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        path[t1][t2] = path[t2][t1] = t;
    }
    cin>>K;
    int shortest=INT_MAX;
    int shortest_place;
    for(int i=1;i<=K;i++)
    {
        int num_of_city,start_city,total_dist=0,j;
        int judge[300]={0};
        scanf("%d%d",&num_of_city,&start_city);
        city1=start_city;
        bool flag=true;
        for(j=1;j<num_of_city;j++)
        {
            scanf("%d",&city2);
            if(path[city1][city2]==0)
            {
                flag=false;
            }
            total_dist+=path[city1][city2];
            judge[city1]=judge[city2]=1;
            city1=city2;
        }
        if(flag==false)
        {
            printf("Path %d: NA (Not a TS cycle)\n",i);
        }
        else
        {
            int p;
            for(p=1;p<=N;p++)
            {
                if(judge[p]==0)
                {
                    break;
                }
            }
            if(p<=N||city2!=start_city)
            {
                printf("Path %d: %d (Not a TS cycle)\n",i,total_dist);
            }
            else if(num_of_city==N+1)
            {
                judge[0]=1;
                printf("Path %d: %d (TS simple cycle)\n",i,total_dist);
            }
            else
            {
                judge[0]=1;
                printf("Path %d: %d (TS cycle)\n",i,total_dist);
            }
            if(judge[0]==1&&total_dist<shortest)
            {
                shortest=total_dist;
                shortest_place=i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n",shortest_place,shortest);
    return 0;
}
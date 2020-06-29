#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"limits.h"
using namespace std;
typedef struct reach
{
    int dist;
    int time;
    reach():dist(INT_MAX),time(INT_MAX) {}
}reach;
reach node[501][501];
int src,dst;
string Itoa(int s)
{
    string ans;
    do
    {
        int a=s%10;
        ans=string(1,a+'0')+ans;
        s/=10;
    } while (s!=0);
    return ans;
}
string print(int* pre,int curr_place)
{
    if(curr_place==src)
    {
        return Itoa(src);
    }
    else
    {
        return print(pre,pre[curr_place])+" -> "+Itoa(curr_place);
    }
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int v1,v2,way,d,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d %d %d",&v1,&v2,&way,&d,&t);
        node[v1][v2].dist=d;
        node[v1][v2].time=t;
        if(way==0)
        {
            node[v2][v1].dist=d;
            node[v2][v1].time=t;
        }
    }
    scanf("%d %d",&src,&dst);
    reach best_dist_time[501];
    int mark[501]={0};
    best_dist_time[src].dist=0;
    best_dist_time[src].time=0;
    int pre[501];
    while(true)
    {
        reach curr_best;
        int place;
        for(int i=0;i<N;i++)
        {
            if(mark[i]==0)
            {
                if(curr_best.dist>best_dist_time[i].dist)
                {
                    curr_best=best_dist_time[i];
                    place=i;
                }
                else if(curr_best.dist==best_dist_time[i].dist&&curr_best.time>best_dist_time[i].time)
                {
                    curr_best=best_dist_time[i];
                    place=i;
                }
            }
        }
        mark[place]=1;
        if(place==dst)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(node[place][i].dist!=INT_MAX&&node[place][i].dist+curr_best.dist<best_dist_time[i].dist)
            {
                best_dist_time[i].dist=node[place][i].dist+curr_best.dist;
                best_dist_time[i].time=node[place][i].time+curr_best.time;
                pre[i]=place;
            }
            else if(node[place][i].dist!=INT_MAX&&node[place][i].dist+curr_best.dist==best_dist_time[i].dist&&node[place][i].time+curr_best.time<best_dist_time[i].time)
            {
                best_dist_time[i].dist=node[place][i].dist+curr_best.dist;
                best_dist_time[i].time=node[place][i].time+curr_best.time;
                pre[i]=place;
            }
        }
    }
    string dist_ans=print(pre,dst);
    reach best_time[501];
    fill(mark,mark+N,0);
    best_time[src].time=0;
    best_time[src].dist=0;
    fill(pre,pre+N,0);
    while(true)
    {
        reach curr_best;
        int place;
        for(int i=0;i<N;i++)
        {
            if(mark[i]==0)
            {
                if(curr_best.time>best_time[i].time)
                {
                    curr_best=best_time[i];
                    place=i;
                }
                else if(curr_best.time==best_time[i].time&&curr_best.dist>best_time[i].dist)
                {
                    curr_best=best_time[i];
                    place=i;
                }
            }
        }
        mark[place]=1;
        if(place==dst)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(node[place][i].dist!=INT_MAX&&node[place][i].time+curr_best.time<best_time[i].time)
            {
                best_time[i].time=node[place][i].time+curr_best.time;
                best_time[i].dist=curr_best.dist+1;
                pre[i]=place;
            }
            else if(node[place][i].dist!=INT_MAX&&node[place][i].time+curr_best.time==best_time[i].time&&best_time[i].dist>curr_best.dist+1)
            {
                best_time[i].time=node[place][i].time+curr_best.time;
                best_time[i].dist=curr_best.dist+1;
                pre[i]=place;
            }
        }
    }
    string time_ans=print(pre,dst);
    if(dist_ans!=time_ans)
    {
        printf("Distance = %d: ",best_dist_time[dst].dist);
        cout<<dist_ans<<endl;
        printf("Time = %d: ",best_time[dst].time);
        cout<<time_ans;
    }
    else
    {
        printf("Distance = %d; Time = %d: ",best_dist_time[dst].dist,best_time[dst].time);
        cout<<time_ans;
    }
    return 0;
}
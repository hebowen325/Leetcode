#include<iostream>
#include<algorithm>
#include"limits.h"
#include<vector>
using namespace std;
int capacity[550];
int Distance[550][550];
vector<int> best_place[550];
int best_distance[550];
vector<vector<int>> res;
void dfs(vector<int> tmp)
{
    if(tmp[tmp.size()-1]==0)
    {
        res.push_back(tmp);
    }
    else
    {
        int last=tmp[tmp.size()-1];
        for(int i=0;i<best_place[last].size();i++)
        {
            tmp.push_back(best_place[last][i]);
            dfs(tmp);
            tmp.pop_back();
        }
    }
}
int main()
{
    int Cmax,N,Sp,M;
    fill(Distance[0],Distance[0]+550*550,-1);
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",capacity+i);
    }
    int p1,p2,dist;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&p1,&p2,&dist);
        Distance[p1][p2]=Distance[p2][p1]=dist;
    }
    int start=0;
    int note[550]={0};
    fill(best_distance,best_distance+550,INT_MAX);
    best_distance[0]=0;
    while(start!=Sp)
    {
        int shortest_dist=INT_MAX;
        int shortest_place;
        for(int i=0;i<=N;i++)
        {
            if(note[i]==0&&shortest_dist>best_distance[i])
            {
                shortest_dist=best_distance[i];
                shortest_place=i;
            }
        }
        for(int i=0;i<=N;i++)
        {
            if(Distance[shortest_place][i]!=-1)
            {
                if(Distance[shortest_place][i]+shortest_dist<best_distance[i])
                {
                    best_distance[i]=Distance[shortest_place][i]+shortest_dist;
                    best_place[i].clear();
                    best_place[i].push_back(shortest_place);
                }
                else if(Distance[shortest_place][i]+shortest_dist==best_distance[i])
                {
                    best_place[i].push_back(shortest_place);
                }
            }
        }
        note[shortest_place]=1;
        start=shortest_place;
    }
    vector<int> tmp;
    tmp.push_back(Sp);
    dfs(tmp);
    vector<vector<int>> all_routes=res;
    vector<int> best_route;
    int num=INT_MAX;
    int take_back=INT_MAX;
    for(int i=0;i<all_routes.size();i++)
    {
        vector<int> tmp_route=all_routes[i];
        int tmp_num=0;
        int tmp_ans=0;
        for(int j=tmp_route.size()-2;j>=0;j--)
        {
            if(capacity[tmp_route[j]]<Cmax/2)
            {
                if(tmp_num+capacity[tmp_route[j]]>Cmax/2)
                {
                    tmp_num=tmp_num+capacity[tmp_route[j]]-Cmax/2;
                }
                else
                {
                    tmp_ans+=Cmax/2-tmp_num-capacity[tmp_route[j]];
                    tmp_num=0;
                }
            }
            else
            {
                tmp_num+=capacity[tmp_route[j]]-Cmax/2;
            }
        }
        if(num>tmp_ans||(num==tmp_ans && tmp_num<take_back))
        {
            num=tmp_ans;
            take_back=tmp_num;
            best_route=tmp_route;
        }
    }
    printf("%d 0",num);
    for(int i=best_route.size()-2;i>=0;i--)
    {
        printf("->%d",best_route[i]);
    }
    printf(" %d\n",take_back);
    return 0;
}
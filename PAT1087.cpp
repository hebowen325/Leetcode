#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include "limits.h"
using namespace std;
int cost[300][300];
int happiness[300];
string city[300];
map<string,int> Map;
typedef struct route
{
    vector<int> road;
    int total_happiness=0;
    int average_happiness;
    route(vector<int> R):road(R)
    {
        for(int i=0;i<road.size();i++)
        {
            total_happiness+=happiness[road[i]];
        }
        average_happiness=total_happiness/(road.size()-1);
    }
    route() {}
}route;

bool cmp(const route& r1,const route& r2)
{
    if(r1.total_happiness!=r2.total_happiness)
        return r1.total_happiness>r2.total_happiness;
    else
        return r1.average_happiness>r2.average_happiness;
}

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    fill(cost[0],cost[0]+300*300,INT_MAX);
    char tmp[4];
    char Tmp[4];
    scanf("%s",tmp);
    string start_country(tmp);
    city[0]=start_country;
    Map[start_country]=0;
    happiness[0]=0;
    int t;
    for(int i=1;i<N;i++)
    {
        scanf("%s %d",tmp,&t);
        Map[tmp]=i;
        happiness[i]=t;
        city[i]=string(tmp);
    }
    for(int i=0;i<K;i++)
    {
        scanf("%s %s %d",tmp,Tmp,&t);
        cost[Map[tmp]][Map[Tmp]]=cost[Map[Tmp]][Map[tmp]]=t;
    }
    int record[300]={0};
    int last[300][300];
    int best_road=INT_MAX;
    int least;
    int least_value;
    int dist[300];
    fill(dist,dist+300,INT_MAX);
    fill(last[0],last[0]+300*300,INT_MAX);
    dist[0]=0;
    while(true)
    {
        least_value=INT_MAX;
        for(int i=0;i<N;i++)
        {
            if(least_value>dist[i]&&record[i]==0)
            {
                least=i;
                least_value=dist[i];
            }
        }
        record[least]=1;
        if(least==Map["ROM"])
        {
            best_road=least_value;
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(cost[least][i]!=INT_MAX&&cost[least][i]+least_value<dist[i])
            {
                dist[i]=least_value+cost[least][i];
                fill(last[i],last[i]+300,INT_MAX);
                last[i][least]=0;
                continue;
            }
            if(cost[least][i]!=INT_MAX&&cost[least][i]+least_value==dist[i])
                last[i][least]=0;
        }
    }
    vector<vector<int>> Road;
    vector<vector<int>> road;
    vector<int> tt;
    tt.push_back(Map["ROM"]);
    road.push_back(tt);
    while(true)
    {
        Road=road;
        road.clear();
        int count=Road.size();
        bool flag=true;
        for(int i=0;i<count;i++)
        {
            tt=Road[i];
            if(tt[0]==0)
            {
                road.push_back(tt);
                continue;
            }
            for(int j=0;j<N;j++)
            {
                if(last[tt[0]][j]==0)
                {
                    tt.insert(tt.begin(),j);
                    road.push_back(tt);
                    tt.erase(tt.begin());
                    flag=false;
                }
            }
        }
        if(flag)
            break;
    }
    route* R=new route [Road.size()];
    for(int i=0;i<Road.size();i++)
    {
        R[i]=route(Road[i]);
    }
    sort(R,R+Road.size(),cmp);
    cout<<Road.size()<<" "<<dist[Map["ROM"]]<<" "<<R[0].total_happiness<<" "<<R[0].average_happiness<<endl;
    cout<<start_country;
    for(int i=1;i<R[0].road.size();i++)
    {
        cout<<"->"<<city[R[0].road[i]];
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,map<int,int>> line;
int next_stop[10000][100];
int Count[10000] = {0};
vector<int> path;
map<int,bool> Visit;
int best_dist;
int best_cnt;
int calculate_cnt(vector<int> tpath)
{
    int times=0;
    int curr_route=line[tpath[0]][tpath[1]];
    for(int i=1;i<tpath.size()-1;i++)
    {
        if(curr_route!=line[tpath[i]][tpath[i+1]])
        {
            times++;
            curr_route=line[tpath[i]][tpath[i+1]];
        }
    }
    return times;
}
void DFS(int start,int end,map<int,bool>& visit,vector<int>& tpath,int distance)
{
    if(!visit[start])
    {
        visit[start]=true;
        tpath.push_back(start);
    }
    if(distance>best_dist)
    {
        return;
    }
    if(start==end)
    {
        int transfer_cnt=calculate_cnt(tpath);
        if(distance<best_dist||(distance==best_dist&&best_cnt>transfer_cnt))
        {
            best_dist=distance;
            best_cnt=transfer_cnt;
            path=tpath;
        }
        return;
    }
    for(int i=0;i<Count[start];i++)
    {
        if(!visit[next_stop[start][i]])
        {
            DFS(next_stop[start][i],end,visit,tpath,distance+1);
            visit[next_stop[start][i]]=false;
            tpath.pop_back();
        }
    }
}
int main()
{

    int N, K;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        int pre, curr;
        scanf("%d", &pre);
        Visit[pre]=false;
        for (int j = 1; j < K; j++)
        {
            scanf("%d", &curr);
            Visit[curr]=false;
            next_stop[pre][Count[pre]++] = curr;
            next_stop[curr][Count[curr]++] = pre;
            line[pre][curr]=i+1;
            line[curr][pre]=i+1;
            pre = curr;
        }
    }
    scanf("%d", &K);
    int start,end;
    for(int i=0;i<K;i++)
    {
        map<int,bool> visit=Visit;
        scanf("%d%d",&start,&end);
        vector<int> tpath;
        best_dist=9999;
        best_cnt=9999;
        DFS(start,end,visit,tpath,0);
        vector<int> Line;
        vector<int> Pre;
        int curr_route=line[path[0]][path[1]];
        Line.push_back(curr_route);
        Pre.push_back(start);
        for(int i=1;i<path.size()-1;i++)
        {
            if(curr_route!=line[path[i]][path[i+1]])
            {
                curr_route=line[path[i]][path[i+1]];
                Line.push_back(curr_route);
                Pre.push_back(path[i]);
            }
        }
        Pre.push_back(end);
        printf("%d\n",best_dist);
        for(int i=0;i<Line.size();i++)
        {
            printf("Take Line#%d from %04d to %04d.\n",Line[i],Pre[i],Pre[i+1]);
        }
    }
    return 0;
}
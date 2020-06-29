#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> edges[10001];
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int node1,node2;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&node1,&node2);
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    int K,color;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        set<int> C;
        set<int> colors[10001];
        bool flag=true;
        for(int j=0;j<N;j++)
        {
            scanf("%d",&color);
            if(flag)
            {
                C.insert(color);
                if(find(colors[j].begin(),colors[j].end(),color)==colors[j].end())
                {
                    for(int t=0;t<edges[j].size();t++)
                    {
                        colors[edges[j][t]].insert(color);
                    }
                }
                else
                {
                    flag=false;
                }
            }
        }
        if(flag)
        {
            printf("%d-coloring\n",C.size());
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
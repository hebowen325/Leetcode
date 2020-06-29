#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int graph[201][201];
int main()
{
  int Nv,Ne,M,K,node1,node2;
  scanf("%d %d",&Nv,&Ne);
  fill(graph[0],graph[0]+201*201,0);
  for(int i=0;i<Ne;i++)
  {
    scanf("%d %d",&node1,&node2);
    graph[node1][node2]=1;
    graph[node2][node1]=1;
  }
  scanf("%d",&M);
  for(int i=0;i<M;i++)
  {
    scanf("%d",&K);
    int Hash[201]={0};
    vector<int> Vec;
    int j,t;
    for(j=0;j<K;j++)
    {
      scanf("%d",&node1);
     	Vec.push_back(node1);
      Hash[node1]=1;
    }
    for(j=0;j<K;j++)
    {
      for(t=j+1;t<K;t++)
      {
        if(graph[Vec[j]][Vec[t]]==0)
        {
          break;
        }
      }
      if(t<K)
      {
        break;
      }
    }
    if(j<K)
    {
      printf("Not a Clique\n");
    }
    else
    {
      for(j=1;j<=Nv;j++)
      {
        if(Hash[j]==0)
        {
          for(t=0;t<Vec.size();t++)
          {
            if(graph[j][Vec[t]]==0)
            {
              break;
            }
          }
          if(t==Vec.size())
          {
            printf("Not Maximal\n");
            break;
          }
        }
      }
      if(j>Nv)
      {
        printf("Yes\n");
      }
    }
  }
  return 0;
}
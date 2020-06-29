#include<iostream>
#include<cstring>
using namespace std;
int matrix[1001][1001];
int count[1001]={0};
int main()
{
  int N,M,K;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++)
  {
    int node1,node2;
    scanf("%d %d",&node1,&node2);
    matrix[node1][node2]=1;
    count[node2]++;
  }
  scanf("%d",&K);
  bool first=true;
  for(int i=0;i<K;i++)
  {
    bool flag=true;
    int Count[1001];
    memcpy(Count,count,(N+1)*4);
    for(int j=0;j<N;j++)
    {
      int node;
      scanf("%d",&node);
      if(Count[node]!=0)
      {
        flag=false;
      }
      else
      {
        for(int t=1;t<=N;t++)
        {
          if(matrix[node][t]==1)
          {
            Count[t]--;
          }
        }
      }
    }
    if(flag==false)
    {
      if(first==true)
      {
      	printf("%d",i);
        first=false;
      }
      else
      {
        printf(" %d",i);
      }
    }
  }
  return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
int HashTable[10001]={0};
bool judge(int x)
{
  for(int i=2;i<=sqrt(x);i++)
  {
    if(x%i==0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int MSize,N,M;
  scanf("%d%d%d",&MSize,&N,&M);
  while(judge(MSize)==false)
  {
    MSize++;
  }
  for(int i=0;i<N;i++)
  {
    int tmp;
    scanf("%d",&tmp);
    int j=0;
    for(;j<MSize;j++)
    {
      if(HashTable[(tmp+j*j)%MSize]==0)
      {
        HashTable[(tmp+j*j)%MSize]=tmp;
        break;
      }
    }
    if(j==MSize)
    {
      printf("%d cannot be inserted.\n",tmp);
    }
  }
  int count=0;
  for(int i=0;i<M;i++)
  {
    int tmp;
    scanf("%d",&tmp);
    for(int j=0;j<=MSize;j++)
    {
      count++;
      if(HashTable[(tmp+j*j)%MSize]==tmp||HashTable[(tmp+j*j)%MSize]==0)
      {
        break;
      }
    }
  }
  printf("%.1f",count*1.0/M);
  return 0;
}
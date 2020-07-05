#include<iostream>
using namespace std;
int HeapArray[500];
void HeapAdjust(int begin,int end)
{
  int tmp=HeapArray[begin];
  int s=begin;
  for(int t=s*2+1;t<=end;t=t*2+1)
  {
    if(t+1<=end&&HeapArray[t]<HeapArray[t+1])
    {
      t++;
    }
    if(tmp>HeapArray[t])
    {
      break;
    }
    HeapArray[s]=HeapArray[t];
    s=t;
  }
  HeapArray[s]=tmp;
}
void HeapCreate(int begin,int end)
{  
  for(int j=(end+1)/2-1;j>=begin;j--)
  {
    HeapAdjust(j,end);
  }
}
void Heapsort(int begin,int end)
{
  HeapCreate(begin,end);
  for(int j=end;j>begin;j--)
  {
    swap(HeapArray[begin],HeapArray[j]);
    HeapAdjust(begin,j-1);
  }
}

int main()
{
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",HeapArray+i);
  }
  Heapsort(0,N-1);
  for(int i=0;i<N;i++)
  {
    printf("%d",HeapArray[i]);
  }
  return 0;
}

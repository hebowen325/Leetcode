#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main()
{
  int N,M;
  map<int,vector<int>> Map;
  scanf("%d %d",&N,&M);
  int n1,n2;
  for(int i=0;i<N;i++)
  {
    scanf("%d %d",&n1,&n2);
    Map[n1].push_back(i);
    Map[n2].push_back(i);
  }
  int num;
  for(int i=0;i<M;i++)
  {
    scanf("%d",&num);
    set<int> S;
    int id;
    bool flag=true;
    for(int j=0;j<num;j++)
    {
      scanf("%d",&id);
      if(flag==true)
      {
      	for(int t=0;t<Map[id].size();t++)
      	{
        	if(S.find(Map[id][t])!=S.end())
        	{
            flag=false;
            break;
        	}
          else
          {
            S.insert(Map[id][t]);
          }
      	}
      }
    }
    if(flag)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
  return 0;
}
  
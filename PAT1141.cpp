#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
typedef struct SchoolNode
{
  int rank;
  int scoreA;
  int scoreB;
  int scoreT;
  int totalscore;
  int Ns;
  SchoolNode():scoreT(0),scoreB(0),scoreA(0),Ns(0){}
}SchoolNode;
map<string,SchoolNode> Map;
bool cmp(pair<string,SchoolNode> &p1,pair<string,SchoolNode> &p2)
{
  p1.second.totalscore=p1.second.scoreB/1.5+p1.second.scoreA+p1.second.scoreT*1.5;
  p2.second.totalscore=p2.second.scoreB/1.5+p2.second.scoreA+p2.second.scoreT*1.5;
  if(p1.second.totalscore!=p2.second.totalscore)
  {
    return p1.second.totalscore>p2.second.totalscore;
  }
  else if(p1.second.Ns!=p2.second.Ns)
  {
    return p1.second.Ns<p2.second.Ns;
  }
  else
  {
    return p1.first<p2.first;
  }
}
int main()
{
  int N;
  scanf("%d",&N);
  string stu;
  string school;
  int score;
  for(int i=0;i<N;i++)
  {
    cin>>stu>>score>>school;
    for(int j=0;j<school.size();j++)
    {
        school[j]=tolower(school[j]);
    }
    if(stu[0]=='A')
    {
      Map[school].scoreA+=score;
    }
    else if(stu[0]=='B')
    {
      Map[school].scoreB+=score;
    }
    else
    {
      Map[school].scoreT+=score;
    }
    Map[school].Ns++;
  }
  vector<pair<string,SchoolNode>> Vec(Map.begin(),Map.end());
  sort(Vec.begin(),Vec.end(),cmp);
  printf("%d\n",Vec.size());
  for(int i=0;i<Vec.size();i++)
  {
    if(i!=0&&Vec[i].second.totalscore==Vec[i-1].second.totalscore)
    {
      Vec[i].second.rank=Vec[i-1].second.rank;
    }
    else
    {
      Vec[i].second.rank=i+1;
    }
    printf("%d ",Vec[i].second.rank);
    cout<<Vec[i].first<<" "<<Vec[i].second.totalscore<<" "<<Vec[i].second.Ns<<endl;
  }
  return 0;
}
  
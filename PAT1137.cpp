#include<iostream>
#include<map>
#include<algorithm>
#include<utility>
#include<vector>
#include<math.h>
using namespace std;
int num[3];
map<string,int*> Map;
bool cmp(const pair<string,int*> &p1,const pair<string,int*> &p2)
{
    if(p1.second[3]!=p2.second[3])
    {
        return p1.second[3]>p2.second[3];
    }
    else
    {
        return p1.first<p2.first;
    }
}
int main()
{
    scanf("%d%d%d",num,num+1,num+2);
    string SID;
    int score;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<num[i];j++)
        {
            cin>>SID>>score;
            if(Map.count(SID))
            {
                Map[SID][i]=score;
            }
            else
            {
                Map[SID]=new int [4];
                fill(Map[SID],Map[SID]+4,-1);
                Map[SID][i]=score;
            }
        }
    }
    vector<pair<string,int*>> Vec(Map.begin(),Map.end());
    for(int i=0;i<Vec.size();i++)
    {
        if(Vec[i].second[0]>=200)
        {
            if(Vec[i].second[1]>Vec[i].second[2])
            {
                Vec[i].second[3]=round(Vec[i].second[1]*0.4+Vec[i].second[2]*0.6);
            }
            else
            {
                Vec[i].second[3]=Vec[i].second[2];
            }
        }
    }
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<Vec.size();i++)
    {
        if(Vec[i].second[3]>=60)
        {
            cout<<Vec[i].first<<" "<<Vec[i].second[0]<<" "<<Vec[i].second[1]<<" "<<Vec[i].second[2]<<" "<<Vec[i].second[3]<<"\n";
        }
        else
        {
            break;
        }
    }
    return 0;
}
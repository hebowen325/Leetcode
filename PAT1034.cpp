#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>
#include<unordered_map>
#include<algorithm>
#include "limits.h"
using namespace std;
bool cmp(const pair<string,int> &a,const pair<string,int> &b)
{
    return a.first<b.first;
}
int judge(map<string,map<string,int> > Map,map<string,int> &ans,map<string,bool> &Vec,string key,int threshold)
{
    Vec.clear();
    map<string,int>::iterator Iter=Map[key].begin();
    Vec[key]=true;
    int number=0;
    vector<string> vec;
    vec.push_back(key);
    while(number<vec.size())
    {
        Iter=Map[vec[number]].begin();
        while(Iter!=Map[vec[number]].end())
        {
            if(!Vec.count(Iter->first))
            {
                vec.push_back(Iter->first);
                Vec[Iter->first]=true;
            }
            Iter++;
        }
        number++;
    }
    if(Vec.size()==2)
    {
        return -2;
    }
    string head;
    int largest=INT_MIN;
    int count;
    int total=0;
    for(int i=0;i<Vec.size();i++)
    {
        count=0;
        for(int j=0;j<Vec.size();j++)
        {
            if(i==j)
            {
                continue;
            }
            if(Map[vec[i]].count(vec[j]))
            {
                total+=Map[vec[i]][vec[j]];
                count+=Map[vec[i]][vec[j]];
            }
        }
        if(count>largest)
        {
            largest=count;
            head=vec[i];
        }
    }
    if(total/2>threshold)
    {
        ans[head]=vec.size();
    }
    return 0;
}
int main()
{
    int N,threshold;
    cin>>N>>threshold;
    string people1,people2;
    int time;
    map<string,map<string,int> > Map;
    for(int i=0;i<N;i++)
    {
        cin>>people1>>people2>>time;
        if(Map.count(people1)&&Map[people1].count(people2))
        {
            Map[people1][people2]+=time;
            Map[people2][people1]+=time;
        }
        else
        {
            Map[people1][people2]=time;
            Map[people2][people1]=time;
        }
    }
    map<string,int> ans;
    map<string,bool> have_read;
    map<string,bool> Vec;
    map<string,map<string,int> >::iterator Iter=Map.begin();
    while(Iter!=Map.end())
    {
        if(!have_read.count(Iter->first))
        {
            judge(Map,ans,Vec,Iter->first,threshold);
            have_read.insert(Vec.begin(),Vec.end());
        }
        Iter++;
    }
    cout<<ans.size();
    map<string,int>:: iterator Ite=ans.begin();
    while(Ite!=ans.end())
    {
        cout<<endl<<Ite->first<<" "<<Ite->second;
        Ite++;
    }
    return 0;
}
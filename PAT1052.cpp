#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
bool cmp(const pair<int,string> &a,const pair<int,string> &b)
{
    return a.first<b.first;
}
int main()
{
    int K;
    string StartNode;
    string node1;
    string node2;
    string* ptr;
    int value;
    cin>>K>>StartNode;
    pair<string*,int> Pair;
    pair<int,string> pir;
    map<string,pair<string*,int> > Map;
    vector<pair<int,string>> Vec;
    for(int i=0;i<K;i++)
    {
        cin>>node1>>value>>node2;
        ptr=new string [2];
        ptr[0]=node1;
        ptr[1]=node2;
        Pair.first=ptr;
        Pair.second=value;
        Map[node1]=Pair;
    }
    if(StartNode=="-1")
    {
        cout<<"0 -1";
        return 0;
    }
    while(StartNode!="-1")
    {
        pir.first=Map[StartNode].second;
        pir.second=StartNode;
        Vec.push_back(pir);
        StartNode=Map[StartNode].first[1];
    }
    sort(Vec.begin(),Vec.end(),cmp);
    cout<<Vec.size()<<" "<<Vec[0].second<<endl;
    for(int i=0;i<Vec.size()-1;i++)
    {
        cout<<Vec[i].second<<" "<<Vec[i].first<<" "<<Vec[i+1].second<<endl;
    }
    cout<<Vec[Vec.size()-1].second<<" "<<Vec[Vec.size()-1].first<<" -1";
    return 0;
}
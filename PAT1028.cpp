#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
bool cmp1(const pair<string,string*> &a,const pair<string,string*> &b)
{
    return a.first<b.first;
}

bool cmp2(const pair<string,string*> &a,const pair<string,string*> &b)
{
    if(a.second[0]!=b.second[0])
    {
        return a.second[0]<b.second[0];
    }
    else
    {
        return cmp1(a,b);
    }
}

bool cmp3(const pair<string,string*> &a,const pair<string,string*> &b)
{
    if(a.second[1]!=b.second[1])
    {
        return a.second[1]<b.second[1];
    }
    else
    {
        return cmp1(a,b);
    }
}

int main()
{
    int N,C;
    cin>>N>>C;
    pair<string,string*> records;
    string ID;
    string* tmp;
    vector< pair<string,string*> > Vec;
    for(int i=0;i<N;i++)
    {
        cin>>ID;
        records.first=ID;
        tmp=new string [2];
        cin>>tmp[0];
        cin>>tmp[1];
        records.second=tmp;
        Vec.push_back(records);
    }
    switch(C)
    {
        case(1):
        {
            sort(Vec.begin(),Vec.end(),cmp1);
            break;
        }
        case(2):
        {
            sort(Vec.begin(),Vec.end(),cmp2);
            break;
        }
        case(3):
        {
            sort(Vec.begin(),Vec.end(),cmp3);
            break;
        }
    }
    for(int i=0;i<N-1;i++)
    {
        cout<<Vec[i].first<<" "<<Vec[i].second[0]<<" "<<Vec[i].second[1]<<endl;
    }
    cout<<Vec[N-1].first<<" "<<Vec[N-1].second[0]<<" "<<Vec[N-1].second[1];
    return 0;
}
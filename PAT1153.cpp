#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
map<string,int> Map;
bool cmp(const pair<string,int> &p1,const pair<string,int> &p2)
{
    if(p1.second!=p2.second)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}
bool cmp2(const pair<int,int> &p1,const pair<int,int> &p2)
{
    if(p1.second!=p2.second)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}
void Query1(char level)
{
    map<string,int>::iterator Iter=Map.begin();
    vector<pair<string,int>> Vec;
    while(Iter!=Map.end())
    {
        if(Iter->first[0]==level)
        {
            Vec.push_back(*Iter);
        }
        Iter++;
    }
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<Vec.size();i++)
    {
        printf("%s %d\n",Vec[i].first.c_str(),Vec[i].second);
    }
    if(Vec.size()==0)
    {
        printf("NA\n");
    }
}

void Query2(string num)
{
    map<string,int>::iterator Iter=Map.begin();
    int count=0;
    int score=0;
    while(Iter!=Map.end())
    {
        if(Iter->first.substr(1,3)==num)
        {
            count++;
            score+=Iter->second;
        }
        Iter++;
    }
    if(count!=0)
    {
        printf("%d %d\n",count,score);
    }
    else
    {
        printf("NA\n");
    }
}

void Query3(string num)
{
    bool flag=true;
    map<string,int>::iterator Iter=Map.begin();
    map<int,int> mMap;
    while(Iter!=Map.end())
    {
        if(Iter->first.substr(4,6)==num)
        {
            flag=false;
            mMap[stoi(Iter->first.substr(1,3))]++;
        }
        Iter++;
    }
    vector<pair<int,int>> tVec(mMap.begin(),mMap.end());
    sort(tVec.begin(),tVec.end(),cmp2);
    for(int i=0;i<tVec.size();i++)
    {
        printf("%d %d\n",tVec[i].first,tVec[i].second);
    }
    if(flag)
    {
        printf("NA\n");
    }
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    string ID;
    ID.resize(100);
    int score;
    for(int i=0;i<N;i++)
    {
        scanf("%s %d",&ID[0],&score);
        Map[ID]=score;
    }
    char level;
    string num;
    int type;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&type);
        printf("Case %d: %d ",i+1,type);
        switch(type)
        {
            case 1:
                {
                    scanf(" %c",&level);
                    printf("%c\n",level);
                    Query1(level);
                    break;
                }
            case 2:
                {
                    cin>>num;
                    printf("%s\n",num.c_str());
                    Query2(num);
                    break;
                }
            case 3:
                {
                    cin>>num;
                    printf("%s\n",num.c_str());
                    Query3(num);
                    break;
                }
        }
    }
    return 0;
}
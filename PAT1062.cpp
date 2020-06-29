#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
bool cmp(const pair<string,int*> &p1,const pair<string,int*> &p2)
{
    if(p1.second[0]+p1.second[1]!=p2.second[0]+p2.second[1])
    {
        return p1.second[0]+p1.second[1]>p2.second[0]+p2.second[1];
    }
    else if(p1.second[0]!=p2.second[0])
    {
        return p1.second[0]>p2.second[0];
    }
    else
    {
        return p1.first<p2.first;
    }
}
int main()
{
    int M,L,H;
    scanf("%d %d %d",&M,&L,&H);
    vector<pair<string,int*>> sage;
    vector<pair<string,int*>> nobleman;
    vector<pair<string,int*>> foolman;
    vector<pair<string,int*>> rest;
    pair<string,int*> Pair;
    string ID;
    char id[9];
    int* ptr=new int [2];
    for(int i=0;i<M;i++)
    {
        scanf("%s %d %d",id,ptr,ptr+1);
        if(ptr[0]>=L&&ptr[1]>=L)
        {
            ID=string(id);
            Pair.first=ID;
            Pair.second=ptr;
            if(ptr[0]>=H&&ptr[1]>=H)
            {
                sage.push_back(Pair);
            }
            else if(ptr[0]>=H&&ptr[1]<H)
            {
                nobleman.push_back(Pair);
            }
            else if(ptr[0]<H&&ptr[1]<H&&ptr[0]>=ptr[1])
            {
                foolman.push_back(Pair);
            }
            else
            {
                rest.push_back(Pair);
            }
            ptr=new int [2];
        }
    }
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(foolman.begin(),foolman.end(),cmp);
    sort(rest.begin(),rest.end(),cmp);
    cout<<sage.size()+nobleman.size()+foolman.size()+rest.size()<<endl;
    for(int i=0;i<sage.size();i++)
    {
        cout<<sage[i].first<<" "<<sage[i].second[0]<<" "<<sage[i].second[1]<<endl;
    }
    for(int i=0;i<nobleman.size();i++)
    {
        cout<<nobleman[i].first<<" "<<nobleman[i].second[0]<<" "<<nobleman[i].second[1]<<endl;
    }
    for(int i=0;i<foolman.size();i++)
    {
        cout<<foolman[i].first<<" "<<foolman[i].second[0]<<" "<<foolman[i].second[1]<<endl;
    }
    for(int i=0;i<rest.size();i++)
    {
        cout<<rest[i].first<<" "<<rest[i].second[0]<<" "<<rest[i].second[1]<<endl;
    }
    return 0;
}
#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
char words[1048577];
bool cmp(const pair<string,int>& p1,const pair<string,int>& p2)
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
int main()
{
    scanf("%[^\n]",words);
    map<string,int> Map;
    int start=0;
    int num=0;
    string tmp;
    while(true)
    {
        if(words[start+num]==0)
        {
            break;
        }
        if((words[start+num]>='0'&&words[start+num]<='9')||(words[start+num]>='a'&&words[start+num]<='z'))
        {
            num++;
        }
        else if(words[start+num]>='A'&&words[start+num]<='Z')
        {
            words[start+num]+=32;
            num++;
        }
        else if(num==0)
        {
            start++;
        }
        else
        {
            tmp=string(words+start,num);
            start+=num;
            if(!Map.count(tmp))
            {
                Map[tmp]=1;
            }
            else
            {
                Map[tmp]++;
            }
            num=0;
        }
    }
    if(num>0)
    {
        tmp=string(words+start,num);
        if(!Map.count(tmp))
        {
            Map[tmp]=1;
        }
        else
        {
            Map[tmp]++;
        }
    }
    vector<pair<string,int>> Vec(Map.begin(),Map.end());
    sort(Vec.begin(),Vec.end(),cmp);
    cout<<Vec[0].first<<" "<<Vec[0].second;
    return 0;
}
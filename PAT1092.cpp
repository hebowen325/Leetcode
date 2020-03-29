#include<iostream>
#include<map>
using namespace std;
char beads[2000];
char Eva[2000];
int main()
{
    scanf("%s\n%s",beads,Eva);
    map<char,int> Map;
    int count;
    for(count=0;Eva[count]!=0;count++)
    {
        if(Map.count(Eva[count]))
            Map[Eva[count]]++;
        else
            Map[Eva[count]]=1;
    }
    int cp=count;
    int i;
    for(i=0;beads[i]!=0;i++)
    {
        if(count==0)
            continue;
        if(Map.count(beads[i])&&Map[beads[i]]>0)
        {
            count--;
            Map[beads[i]]--;
        }
    }
    if(count==0)
        cout<<"Yes "<<i-cp;
    else
        cout<<"No "<<count;
    return 0;
}
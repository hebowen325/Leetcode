#include<iostream>
#include<string>
#include"limits.h"
using namespace std;
int time_to_digit(string Time)
{
    string time[3];
    int ans[3];
    time[0]=Time.substr(0,2);
    time[1]=Time.substr(3,2);
    time[2]=Time.substr(6,2);
    for(int i=0;i<3;i++)
    {
        ans[i]=0;
        for(int j=0;j<2;j++)
        {
            ans[i]*=10;
            ans[i]+=time[i][j]-'0';
        }
    }
    return ans[0]*3600+ans[1]*60+ans[0];
}
int main()
{
    int count;
    string ID;
    string locktime;
    string unlocktime;
    string first;
    int firsttime=INT_MAX;
    string last;
    int lasttime=INT_MIN;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>ID;
        cin>>locktime;
        cin>>unlocktime;
        if(time_to_digit(locktime)<firsttime)
        {
            firsttime=time_to_digit(locktime);
            first=ID;
        }
        if(time_to_digit(unlocktime)>lasttime)
        {
            lasttime=time_to_digit(unlocktime);
            last=ID;
        }
    }
    cout<<first<<" "<<last;
    return 0;
}
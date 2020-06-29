#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Time
{
    string time;
    string status;
    Time(string s1,string s2):time(s1),status(s2){}
}Time;
typedef struct person
{
    string month;
    vector<Time> Vec;
    vector<string> online;
    vector<string> offline;
}person;
int price[24];
int time_transfer(string t)
{
    int day=(t[0]-'0')*10+t[1]-'0';
    int hour=(t[3]-'0')*10+t[4]-'0';
    int minute=(t[6]-'0')*10+t[7]-'0';
    return day*1440+hour*60+minute;
}
bool cmp(Time t1,Time t2)
{
    return t1.time<t2.time;
}
int main()
{
    map<string,person> Map;
    for(int i=0;i<24;i++)
    {
        scanf("%d",price+i);
    }
    int N;
    string Name,time,status;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        cin>>Name>>time>>status;
        if(!Map.count(Name))
        {
            Map[Name].month=time.substr(0,2);
        }
        time=time.substr(3);
        Map[Name].Vec.push_back(Time(time,status));
    }
    map<string,person>::iterator Iter=Map.begin();
    for(;Iter!=Map.end();Iter++)
    {
        sort(Iter->second.Vec.begin(),Iter->second.Vec.end(),cmp);
        for(int i=0;i+1<Iter->second.Vec.size();i++)
        {
            if(Iter->second.Vec[i].status=="on-line"&&Iter->second.Vec[i+1].status=="off-line")
            {
                Iter->second.online.push_back(Iter->second.Vec[i].time);
                Iter->second.offline.push_back(Iter->second.Vec[i+1].time);
            }
        }
        if(Iter->second.online.size()==0)
        {
            continue;
        }
        cout<<Iter->first<<" "<<Iter->second.month<<endl;
        int total_money=0;
        int on_count=0;
        int off_count=0;
        for(;on_count<Iter->second.online.size()&&off_count<Iter->second.offline.size();on_count++,off_count++)
        {
            cout<<Iter->second.online[on_count]<<" "<<Iter->second.offline[off_count]<<" ";
            int t1=time_transfer(Iter->second.online[on_count]);
            int t2=time_transfer(Iter->second.offline[off_count]);
            int time_length=t2-t1;
            int money=0;
            for(int tmp=t1;tmp<t2;tmp++)
            {
                int tt=tmp%1440;
                money+=price[tt/60];
            }
            printf("%d $%.2f\n",time_length,money*1.0/100);
            total_money+=money;
        }
        printf("Total amount: $%.2f\n",total_money*1.0/100);
    }
    return 0;
}
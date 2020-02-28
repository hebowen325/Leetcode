#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef struct car
{
    string name;
    int time;
    string status;
}car;
car all[20000],valid[10000];
bool cmp1(const car &c1,const car &c2)
{
    if(c1.name!=c2.name)
        return c1.name<c2.name;
    else
        return c1.time<c2.time;
}
bool cmp2(const car &c1,const car &c2)
{
    return c1.time<c2.time;
}
int convert_time(string t)
{
    return (t[0]-'0')*36000+(t[1]-'0')*3600+(t[3]-'0')*600+(t[4]-'0')*60+(t[6]-'0')*10+t[7]-'0';
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    char s1[10],s2[10],s3[10];
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %s",s1,s2,s3);
        all[i].name=string(s1);
        all[i].time=convert_time(string(s2));
        all[i].status=string(s3);
    }
    sort(all,all+N,cmp1);
    map<string,int> Map;
    int valid_count=0;
    for(int i=0;i<N-1;i++)
    {
        if((all[i].name==all[i+1].name)&&(all[i].status=="in")&&(all[i+1].status=="out"))
        {
            valid[valid_count++]=all[i++];
            valid[valid_count++]=all[i];
            if(Map.count(all[i].name))
                Map[all[i].name]+=all[i].time-all[i-1].time;
            else
                Map[all[i].name]=all[i].time-all[i-1].time;
        }
    }
    sort(valid,valid+valid_count,cmp2);
    int count=0,now=0;
    for(int i=0;i<K;i++)
    {
        scanf("%s",s1);
        int Time=convert_time(s1);
        while(now<valid_count&&valid[now].time<=Time)
        {
            if(valid[now].status=="in")
                count++;
            else
                count--;
            now++;
        }
        cout<<count<<endl;
    }
    map<string,int>::iterator Iter=Map.begin();
    vector<string> ans;
    int longest=-1;
    while(Iter!=Map.end())
    {
        if(longest<Iter->second)
        {
            longest=Iter->second;
            ans.clear();
            ans.push_back(Iter->first);
        }
        else if(longest==Iter->second)
            ans.push_back(Iter->first);
        Iter++;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	printf("%02d:%02d:%02d\n",longest/3600,longest%3600/60,longest%60);
    return 0;
}
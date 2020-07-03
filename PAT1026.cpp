#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef struct player
{
    int arriving_time;
    int play_time;
    int get_time;
    int VIP_tag;
    player(int a,int p,int v):arriving_time(a),play_time(p),get_time(-1),VIP_tag(v){}
}player;
bool cmp(const player& p1,const player& p2)
{
    return p1.arriving_time<p2.arriving_time;
}
bool Cmp(const player& p1,const player& p2)
{
    if(p1.get_time!=p2.get_time)
    {
        return p1.get_time<p2.get_time;
    }
}
vector<player> Vec;
vector<player> Vec2;
int tables[101]={0};
int people_tag[10001]={0};
int free_table[101]={0};
int table_count[101]={0};
typedef struct Table 
{
    int end_time;
    int table_number;
    Table(int e,int t):end_time(e),table_number(t){}
    friend bool operator< (Table Table1,Table Table2)
    {
        if(Table1.end_time!=Table2.end_time)
        {
            return Table1.end_time>Table2.end_time;
        }
        else if(tables[Table1.table_number]!=tables[Table2.table_number])
        {
            return tables[Table1.table_number]<tables[Table2.table_number];
        }
        else
        {
            return Table1.table_number>Table2.table_number;
        }
    }
}Table;
int main()
{
    int N,K,M;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int h,m,s,p,v;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&p,&v);
        int Time=h*3600+m*60+s;
        p=min(p,120);
        Vec.push_back(player(Time,p*60,v));
    }
    sort(Vec.begin(),Vec.end(),cmp);
    scanf("%d %d",&K,&M);
    for(int i=0;i<M;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        tables[tmp]=1;
    }
    priority_queue<Table> Q;
    int C=0;
    for(int i=8*3600;i<21*3600&&C<Vec.size();i++)
    {
        while(Q.size()>0&&Q.top().end_time==i)
        {
            free_table[Q.top().table_number]=0;
            if(tables[Q.top().table_number]==1)
            {
                for(int t=C;t<Vec.size();t++)
                {
                    if(Vec[t].VIP_tag==1&&Vec[t].arriving_time<=i&&people_tag[t]==0)
                    {
                        Vec[t].get_time=i;
                        free_table[Q.top().table_number]=1;
                        people_tag[t]=1;
                        Q.push(Table(i+Vec[t].play_time,Q.top().table_number));
                        table_count[Q.top().table_number]++;
                        Vec2.push_back(Vec[t]);
                        break;
                    }
                }
            }
            Q.pop();
        }
        while(people_tag[C]==1)
        {
            C++;
        }
        if(C<Vec.size()&&Vec[C].arriving_time<=i && Q.size()<K)
        {
            int first_table=1;
            while(free_table[first_table]==1)
            {
                first_table++;
            }
            if(Vec[C].VIP_tag==1)
            {
                int ttt=first_table;
                while(ttt<=K&&(free_table[ttt]==1||tables[ttt]==0))
                {
                    ttt++;
                }
                if(ttt>K)
                {
                    ttt=first_table;
                }
                first_table=ttt;
            }
            Vec[C].get_time=i;
            free_table[first_table]=1;
            people_tag[C]=1;
            Q.push(Table(i+Vec[C].play_time,first_table));
            table_count[first_table]++;
            Vec2.push_back(Vec[C]);
            C++;
        }
    }
    Vec=Vec2;
    for(int i=0;i<Vec.size();i++)
    {
        if(Vec[i].get_time==-1)
        {
            continue;
        }
        int h1=Vec[i].arriving_time/3600;
        int m1=(Vec[i].arriving_time/60)%60;
        int s1=Vec[i].arriving_time%60;
        int h2=Vec[i].get_time/3600;
        int m2=(Vec[i].get_time/60)%60;
        int s2=Vec[i].get_time%60;
        double wait_time=(Vec[i].get_time-Vec[i].arriving_time)*1.0/60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,round(wait_time));
    }
    printf("%d",table_count[1]);
    for(int i=2;i<=K;i++)
    {
        printf(" %d",table_count[i]);
    }
    return 0;
}
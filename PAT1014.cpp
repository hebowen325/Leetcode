#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct customer
{
    int start_time;
    int end_time;
    int serve_time;
    customer():start_time(0),end_time(0),serve_time(0){}
}customer;
vector<customer*> lines[20];
vector<customer*> wait_people;
customer C[1000];
int main()
{
    int N,M,K,Q;
    scanf("%d%d%d%d",&N,&M,&K,&Q);
    for(int i=0;i<K;i++)
    {
        scanf("%d",&C[i].serve_time);
    }
    int start_time=8*60;
    for(int i=0;i<K;i++)
    {
        if(i<N)
        {
            C[i].start_time=8*60;
            C[i].end_time=start_time+C[i].serve_time;
            lines[i].push_back(&C[i]);
        }
        else if(i/N<M)
        {
            C[i].start_time=C[i-N].end_time;
            C[i].end_time=C[i-N].end_time+C[i].serve_time;
            lines[i%N].push_back(&C[i]);
        }
        else
        {
            wait_people.push_back(&C[i]);
        }
    }
    while(start_time<=17*60)
    {
        start_time++;
        if(wait_people.empty())
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(lines[i][0]->end_time<start_time)
            {
                wait_people[0]->start_time=lines[i][lines[i].size()-1]->end_time;
                wait_people[0]->end_time=lines[i][lines[i].size()-1]->end_time+wait_people[0]->serve_time;
                lines[i].erase(lines[i].begin());
                lines[i].push_back(wait_people[0]);
                wait_people.erase(wait_people.begin());
            }
        }
    }
    for(int i=0;i<Q;i++)
    {
        int que;
        scanf("%d",&que);
        if(C[que-1].end_time!=0&&C[que-1].start_time<17*60)
        {
            printf("%02d:%02d\n",C[que-1].end_time/60,C[que-1].end_time%60);
        }
        else
        {
            printf("Sorry\n");
        }
    }
    return 0;
}

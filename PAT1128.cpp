#include<iostream>
#include<algorithm>
using namespace std;
int place[1001];
int judge[2005];
int K,N;
bool judge_row()
{
    fill(judge,judge+N+1,0);
    for(int i=1;i<=N;i++)
    {
        if(judge[place[i]]==0)
        {
            judge[place[i]]=1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool judge_diagnoal()
{
    fill(judge,judge+2*N+1,0);
    for(int i=1;i<=N;i++)
    {
        if(judge[place[i]-i+N]==0)
        {
            judge[place[i]-i+N]=1;
        }
        else
        {
            return false;
        }        
    }
    fill(judge,judge+2*N+1,0);
    for(int i=1;i<=N;i++)
    {
        if(judge[place[i]+i]==0)
        {
            judge[place[i]+i]=1;
        }
        else
        {
            return false;
        }        
    }
    return true;
}
int main()
{
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d",&N);
        for(int j=1;j<=N;j++)
        {
            int row;
            scanf("%d",&row);
            place[j]=row;
        }
        if(judge_row()==false)
        {
            printf("NO\n");
        }
        else if(judge_diagnoal()==false)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int judge[101],N;
int a[101];
bool Judge(int p1,int p2)
{
    int cnt=0,cnt1=0,cnt2=0;
    for(int i=1;i<=N;i++)
    {
        if(judge[i]==p1||judge[i]==p2||(judge[i]<0&&judge[i]!=-p1&&judge[i]!=-p2))
        {
            cnt++;
            if(i==p1||i==p2)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
    }
    if(cnt==2&&cnt1==1&&cnt2==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",judge+i);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(Judge(i,j)==true)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
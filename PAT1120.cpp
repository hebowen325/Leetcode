#include<iostream>
using namespace std;
char num[5];
int Friend[10000]={0};
int N1;
int N2=0;
int calculate()
{
    int ans=0;
    for(int i=0;num[i]!=0;i++)
    {
        ans+=num[i]-'0';
    }
    return ans;
}
int main()
{
    scanf("%d",&N1);
    for(int i=0;i<N1;i++)
    {
        scanf("%s",num);
        Friend[calculate()]=1;
    }
    for(int i=0;i<100;i++)
    {
        if(Friend[i]!=0)
        {
            N2++;
        }
    }
    printf("%d\n",N2);
    for(int i=0;N2>0;i++)
    {
        if(Friend[i]!=0)
        {
            printf("%d",i);
            N2--;
            if(N2!=0)
            {
                printf(" ");
            }
        }
    }
    return 0;
}
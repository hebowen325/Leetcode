#include<iostream>
#include"math.h"
using namespace std;
int prime[1000000]={0};
void prime_compute()
{
    prime[1]=prime[2]=0;
    for(int i=2;i<1000000;i++)
    {
        if(prime[i]==0&&i<sqrt(1000000*1.0))
        {
            for(int j=i*i;j<1000000;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
int main()
{
    prime_compute();
    int L,K;
    scanf("%d%d",&L,&K);
    string s;
    cin>>s;
    for(int i=0;i+K<=L;i++)
    {
        int val=stoi(s.substr(i,K));
        bool flag=false;
        for(int j=2;j<sqrt(val*1.0);j++)
        {
            if(prime[j]==0&&val%j==0)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<s.substr(i,K);
            return 0;
        }
    }
    printf("404");
    return 0;
}
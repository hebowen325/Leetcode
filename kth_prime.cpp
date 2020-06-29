#include<iostream>
int record[100000]={0};
int prime[10000];
int count=0;
int main()
{
    prime[count++]=1;
    int i=2;
    while(count<10000)
    {
        if(record[i]==0)
        {
            prime[count++]=i;
            if(i<46000)
            {
                for(long j=i*i;j<100000;j+=i)
                {
                    record[j]=1;
                }
            }
        }
        i++;
    }
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        printf("%d\n",prime[k]);
    }
    return 0;
}
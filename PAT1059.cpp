#include<iostream>
#include<map>
#include<vector>
#include"limits.h"
#include<math.h>
using namespace std;
vector<int> prime;
void init()
{
    for(int x=2;x<500050;x++)
    {
        bool judge=false;
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                judge=true;
                break;
            }
        }
        if(!judge)
        {
            prime.push_back(x);
        }
    }
}
int main()
{
    init();
    long int n,N; 
    scanf("%ld",&N);
    if(N==1)
    {
        printf("1=1");
        return 0;
    }
    n=N;
    map<long int,int> Map;
    int i=0;
    while(i<prime.size())
    {
        if(N%prime[i]==0)
        {
            N/=prime[i];
            if(Map.count(prime[i]))
            {
                Map[prime[i]]++;
            }
            else
            {
                Map[prime[i]]=1;
            }
            i--;
        }
        i++;
    }
    if(Map.size()==0)
    {
        printf("%d=%d",n,n);
    }
    map<long int,int>::iterator Iter=Map.begin();
    printf("%ld=",n);
    if(Iter->second==1)
    {
        printf("%ld",Iter->first);
    }
    else
    {
        printf("%ld^%d",Iter->first,Iter->second);
    }
    Iter++;
    while(Iter!=Map.end())
    {
        if(Iter->second==1)
        {
            printf("*%ld",Iter->first);
        }
        else
        {
            printf("*%ld^%d",Iter->first,Iter->second);
        }
        Iter++;
    }
    return 0;
}
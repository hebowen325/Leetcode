#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int* coins=new int [N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",coins+i);
    }
    sort(coins,coins+N);
    int j=0;
    for(int i=0;i<N-1;i++)
    {
        if(coins[i]+coins[i+1]>M)
        {
            break;
        }
        while(j>i&&coins[i]+coins[j]>M)
        {
            j--;
        }
        for(;j<N;j++)
        {
            if(coins[i]+coins[j]==M)
            {
                printf("%d %d",coins[i],coins[j]);
                return 0;
            }
            if(coins[i]+coins[j]>M)
            {
                break;
            }
        }
        j-=1;
    }
    printf("No Solution");
    return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
int ranklist[10001]={0};
bool judge_prime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int N,K,tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&tmp);
        ranklist[tmp]=i+1;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d",&tmp);
        printf("%04d: ",tmp);
        if(ranklist[tmp]==-1)
        {
            printf("Checked\n");
        }
        else if(ranklist[tmp]==0)
        {
            printf("Are you kidding?\n");
        }
        else
        {
            if(ranklist[tmp]==1)
            {
                printf("Mystery Award\n");
            }
            else if(judge_prime(ranklist[tmp])==true)
            {
                printf("Minion\n");
            }
            else
            {
                printf("Chocolate\n");
            }
            ranklist[tmp]=-1;
        }
    }
    return 0;
}
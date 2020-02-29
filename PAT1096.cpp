#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int N,s;
    scanf("%d",&N);
    int maxlen=-1;
    for(int i=2;i<=int(sqrt(1.0*N));i++)
    {
        if(N%i==0)
        {
            int tmp=i,k=i,count=0;
            while(N%tmp==0)
            {
                k++;
                tmp*=k;
                count++;
            }
            if(maxlen<count)
            {
                s=k-count;
                maxlen=count;
            }
        }
    }
    if(maxlen==-1)
        printf("1\n%d",N);
    else
    {
        printf("%d\n%d",maxlen,s);
        for(int i=1;i<maxlen;i++)
            printf("*%d",s+i);
    }
    return 0;
}
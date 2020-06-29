#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int blackhole(int x)
{
    int num[4];
    int t1,t2;
    t1=t2=0;
    for(int i=0;i<4;i++)
    {
        num[i]=x%10;
        x/=10;
    }
    sort(num,num+4,cmp);
    for(int i=0;i<4;i++)
    {
        t2*=10;
        t2+=num[i];
        printf("%d",num[i]);
    }
    printf(" - ");
    sort(num,num+4);
    for(int i=0;i<4;i++)
    {
        t1*=10;
        t1+=num[i];
        printf("%d",num[i]);
    }
    printf(" = ");
    x=t2-t1;
    for(int i=0;i<4;i++)
    {
        num[i]=x%10;
        x/=10;
    }
    for(int i=0;i<4;i++)
    {
        printf("%d",num[3-i]);
    }
    printf("\n");
    return t2-t1;
}
int main()
{
    int x;
    scanf("%d",&x);
    do
    {
        x=blackhole(x);
    }while(x!=6174&&x!=0);
    return 0;
}
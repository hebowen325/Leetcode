#include<iostream>
using namespace std;
long long int common_factor(long long int n1,long long int n2)
{
    while(n1!=0&&n2!=0)
    {
        if(abs(n1)>abs(n2))
        {
            n1=n1%n2;
        }
        else
        {
            n2=n2%n1;
        }
    }
    if(n1==0)
    {
        return n2;
    }
    else
    {
        return n1;
    }
}
void fractionplus(long long int &num1,long long int &dem1,long long int num2,long long int dem2)
{
    num1=num1*dem2+num2*dem1;
    dem1=dem1*dem2;
    long long int factor=common_factor(num1,dem1);
    if(factor!=1)
    {
        num1/=factor;
        dem1/=factor;
    }
    if(num1>0&&dem1<0)
    {
        num1*=-1;
        dem1*=-1;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    long long int num1;
    long long int dem1;
    scanf("%lld/%lld",&num1,&dem1);
    long long int num2;
    long long int dem2;
    for(int i=1;i<N;i++)
    {
        scanf("%lld/%lld",&num2,&dem2);
        fractionplus(num1,dem1,num2,dem2);
    }
    if(num1==0)
    {
        cout<<"0";
        return 0;
    }
    if(abs(num1)<abs(dem1))
    {
        cout<<num1<<"/"<<dem1;
    }
    else
    {
        cout<<num1/dem1;
        if(num1%dem1!=0)
        {
            cout<<" "<<num1%dem1<<"/"<<dem1;
        }
    }
    return 0;
}
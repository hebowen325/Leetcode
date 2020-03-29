#include<iostream>
using namespace std;
long long Common_Factor(long long a,long long b)
{
    a=abs(a);
    b=abs(b);
    while(a!=0&&b!=0)
    {
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    return a+b;
}
void simplify(long long a,long long b)
{
    if(a==0)
    {
        cout<<"0";
        return ;
    }
    bool flag=true;
    if((a>0&&b<0)||(a<0&&b>0))
        flag=false;
    if(a<0)
        a*=-1;
    if(b<0)
        b*=-1;
    long long factor=Common_Factor(a,b);
    a/=factor;
    b/=factor;
    long long integer=a/b;
    a%=b;
    if(flag==false)
        printf("(-");
    if(integer>0&&a>0)
        printf("%lld ",integer);
    else if(integer>0)
        printf("%lld",integer);
    if(a>0)
        printf("%lld/%lld",a,b);
    if(flag==false)
        printf(")");
}

void add(long long a1,long long b1,long long c1,long long d1)
{
    simplify(a1,b1);
    printf(" + ");
    simplify(c1,d1);
    printf(" = ");
    simplify(a1*d1+c1*b1,b1*d1);
    printf("\n");
}

void Minus(long long a1,long long b1,long long c1,long long d1)
{
    simplify(a1,b1);
    printf(" - ");
    simplify(c1,d1);
    printf(" = ");
    simplify(a1*d1-c1*b1,b1*d1);
    printf("\n");
}

void multiply(long long a1,long long b1,long long c1,long long d1)
{
    simplify(a1,b1);
    printf(" * ");
    simplify(c1,d1);
    printf(" = ");
    simplify(a1*c1,b1*d1);
    printf("\n");
}

void division(long long a1,long long b1,long long c1,long long d1)
{
    simplify(a1,b1);
    printf(" / ");
    simplify(c1,d1);
    printf(" = ");
    if(c1!=0)
        simplify(a1*d1,b1*c1);
    else
        printf("Inf");
}
int main()
{
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    add(a1,b1,a2,b2);
    Minus(a1,b1,a2,b2);
    multiply(a1,b1,a2,b2);
    division(a1,b1,a2,b2);
    return 0;
}
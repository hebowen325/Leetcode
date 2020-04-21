#include<iostream>
using namespace std;
int upperbound(int a)
{
    if(a%3==0)
    {
        return a/3;
    }
    else
    {
        return a/3+1;
    }
}
int main()
{
    int a;
    int b;
    int c;
    cin>>a;
    cin>>b;
    c=a+b;
    string ans;
    string tmp;
    int copy=c;
    if(c<0)
    {
        copy=-c;
    }
    while(copy>0)
    {
        tmp=char((copy%10)+'0')+tmp;
        copy=copy/10;
    }
    for(int i=1;i<upperbound(tmp.length());i++)
    {
        ans=","+tmp.substr(tmp.length()-3*i,3)+ans;
    }
    ans=tmp.substr(0,tmp.length()-(upperbound(tmp.length())-1)*3)+ans;
    if(c<0)
    {
        ans="-"+ans;
    }
    else if(c==0)
    {
        ans='0';
    }
    cout<<ans;  
    return 0;
}
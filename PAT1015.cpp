#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string transfer_to(int number,int radix)
{
    string ans;
    string tmp;
    do
    {
        string tmp(1,number%radix+'0');
        ans=tmp+ans;
        number/=radix;
    }
    while(number!=0);
    return ans;
}
int transfer(string number,int radix)
{
    int ans=0;
    for(int i=0;i<number.length();i++)
    {
        ans*=radix;
        ans+=number[i]-'0';
    }
    return ans;
}
int judge(int number)
{
    if(number==1)
    {
        return false;
    }
    for(int i=2;i*i<=number;i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string number;
    int radix;
    cin>>number;
    if(number[0]=='-')
    {
        return 0;
    }
    cin>>radix;
    if(judge(transfer(number,10))==true)
    {
        number=transfer_to(transfer(number,10),radix);
        reverse(number.begin(),number.end());
        if(judge(transfer(number,radix))==true)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
    }
    else
    {
        cout<<"No";
    }
    while(true)
    {
        cin>>number;
        if(number[0]=='-')
        {
            break;
        }
        cout<<endl;
        cin>>radix;
        if(judge(transfer(number,10))==true)
        {
            number=transfer_to(transfer(number,10),radix);
            reverse(number.begin(),number.end());
            if(judge(transfer(number,radix))==true)
            {
                cout<<"Yes";
                continue;
            }
        }
        cout<<"No";
    }
    return 0;
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s1,s2,s3;
bool judge()
{
    for(int i=0;i<s1.length()/2;i++)
    {
        if(s1[i]!=s1[s1.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
string add()
{
    int carry=0,count=0;
    char str[10000];
    for(int i=s1.length()-1;i>=0;i--)
    {
        int result=(s1[i]-'0')+(s2[i]-'0')+carry;
        carry=result/10;
        str[count++]=result%10+'0';
    }
    if(carry!=0)
    {
        str[count++]=carry+'0';
    }
    str[count]=0;
    string ss=string(str);
    reverse(ss.begin(),ss.end());
    return ss;
}
int main()
{
    cin>>s1;
    int count=0;
    while(count<10)
    {
        if(judge()==true)
        {
            cout<<s1<<" is a palindromic number.";
            return 0;
        }
        else
        {
            s2=s1;
            reverse(s2.begin(),s2.end());
            s3=add();
            cout<<s1<<" + "<<s2<<" = "<<s3<<endl;
            s1=s3;
            count++;
        }
    }
    printf("Not found in 10 iterations.");
    return 0;
}
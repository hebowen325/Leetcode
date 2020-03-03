#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string s1,string s2)
{
    string ans;
    string tmp;
    int num1;
    int num2;
    int carry=0;
    int result;
    for(int i=0;i<s1.length();i++)
    {
        num1=s1[s1.length()-1-i]-'0';
        num2=s2[s1.length()-1-i]-'0';
        result=num1+num2+carry;
        carry=result/10;
        tmp=string(1,'0'+result%10);
        ans=tmp+ans;
    }
    if(carry>0)
    {
        tmp=string(1,'0'+carry);
        ans=tmp+ans;
    }
    return ans;
}

bool judge(string num)
{
    for(int i=0;i<num.length();i++)
    {
        if(num[i]!=num[num.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string number;
    string tmp;
    int N;
    int count=0;
    cin>>number;
    cin>>N;
    tmp=number;
    if(judge(tmp))
    {
        cout<<tmp<<endl<<count;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        count++;
        tmp=number;
        reverse(number.begin(),number.end());
        tmp=add(tmp,number);
        if(judge(tmp))
        {
            cout<<tmp<<endl<<count;
            return 0;
        }
        number=tmp;
    }
    cout<<number<<endl<<count;
    return 0;
}
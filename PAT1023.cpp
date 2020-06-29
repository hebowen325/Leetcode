#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    int record1[10]={0};
    int record2[10]={0};
    long long int N1;
    string number1;
    string number2;
    string tmp;
    cin>>number1;
    int carry=0;
    int result;
    for(int i=0;i<number1.length();i++)
    {
        result=(number1[number1.length()-1-i]-'0')*2;
        tmp=string(1,'0'+(result+carry)%10);
        carry=(result+carry)/10;
        number2=tmp+number2;
    }
    if(carry>0)
    {
        tmp=string(1,'0'+(carry)%10);
        number2=tmp+number2;
    }
    for(int i=0;i<number1.length();i++)
    {
        record1[number1[i]-'0']++;
    }
    for(int i=0;i<number2.length();i++)
    {
        record2[number2[i]-'0']++;
    }
    for(int i=0;i<10;i++)
    {
        if(record1[i]!=record2[i])
        {
            cout<<"No"<<endl;
            cout<<number2;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    cout<<number2;
    return 0;
}
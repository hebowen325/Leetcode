#include<iostream>
#include<string>
using namespace std;
string words[]={"Qian","Bai","Shi",""};
string Words[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string translate(string word)
{
    string ans;
    for(int i=0;i<word.length();i++)
    {
        bool flag=true;
        if(ans=="")
        {
            if(word[word.length()-1-i]!='0')
                ans=Words[word[word.length()-1-i]-'0'];
            else
                flag=false;
            if(i!=0)
                ans=ans+" "+words[3-i];
        }
        else
        {
            if(word[word.length()-1-i]!='0')
                ans=Words[word[word.length()-1-i]-'0']+" "+words[3-i]+" "+ans;
        }
        if(word[word.length()-1-i]=='0')
        {
            while(i<word.length()&&word[word.length()-1-i]=='0')
                i++;
            i--;
            if(flag)
                ans="ling "+ans;
        }
    }
    return ans;
}
int main()
{
    string num;
    string ans;
    cin>>num;
    if(num=="0")
    {
        cout<<"ling";
        return 0;
    }
    bool flag=true;
    if(num[0]=='-')
    {
        flag=false;
        num=num.substr(1);
    }
    int i;
    for(i=1;i<=num.length()/4;i++)
    {
        if(translate(num.substr(num.length()-4*i,4))=="")
            continue;
        if(i==1)
            ans=translate(num.substr(num.length()-4*i,4));
        else
            ans=translate(num.substr(num.length()-4*i,4))+" Wan "+ans;
    }
    if(i==1)
        ans=translate(num);
    else if(i==2)
    {
        if(num.length()>4)
        {
            ans=translate(num.substr(0,num.length()-4))+" Wan "+ans;
        }
    }
    else if(i==3&&num.length()==9)
        if(ans=="")
            ans=Words[num[0]-'0']+" Yi";
        else
            ans=Words[num[0]-'0']+" Yi "+ans;
    if(!flag)
        ans="Fu "+ans;
    cout<<ans;
    return 0;
}
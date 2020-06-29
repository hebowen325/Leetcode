#include<iostream>
#include<string>
using namespace std;
int note[257]={0};
int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int count1,count2;
    count1=count2=0;
    while(count1<s1.length()&&count2<s2.length())
    {
        if(s1[count1]!=s2[count2])
        {
            if(s1[count1]>='a'&&s1[count1]<='z')
            {
                if(note[s1[count1]+('A'-'a')]==0)
                {
                    cout<<char(s1[count1]+('A'-'a'));
                    note[s1[count1]+('A'-'a')]=1;
                }
            }
            else if(s1[count1]!='-')
            {
                if(note[s1[count1]]==0)
                {
                    cout<<s1[count1];
                    note[s1[count1]]=1;
                }
            }
            else
            {
                s1[count1]=' ';
                if(note[s1[count1]]==0)
                {
                    cout<<s1[count1];
                    note[s1[count1]]=1;
                }
            }
            count1++;
        }
        else
        {
            count1++;
            count2++;
        }
    }
    while(count1<s1.length())
    {
        if(s1[count1]>='a'&&s1[count1]<='z')
        {
            if(note[s1[count1]+('A'-'a')]==0)
            {
                cout<<char(s1[count1]+('A'-'a'));
                note[s1[count1]+('A'-'a')]=1;
            }
        }
        else if(s1[count1]!='-')
        {
            if(note[s1[count1]]==0)
            {
                cout<<s1[count1];
                note[s1[count1]]=1;
            }
        }
        else
        {
            s1[count1]=' ';
            if(note[s1[count1]]==0)
            {
                cout<<s1[count1];
                note[s1[count1]]=1;
            }
        }
        count1++;
    }
    return 0;
}
#include<iostream>
using namespace std;
char ch[200000];
int main()
{
    scanf("%s",ch);
    string s=string(ch);
    long ans=0;
    int count_of_T=0;
    int count_for_A=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='T')
            count_of_T++;
        else if(s[i]=='A')
            count_for_A+=count_of_T;
        else if(s[i]=='P')
            ans+=count_for_A; 
    }
    cout<<ans%1000000007;
    return 0;
}
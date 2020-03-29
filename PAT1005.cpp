#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string words;
    cin>>words;
    int ans=0;
    for(int i=0;i<words.length();i++)
    {
        ans+=(words[i]-'0');
    }
    string dict[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<string> Ans;
    if(ans==0)
    {
        cout<<"zero";
    }
    else
    {
        while(ans!=0)
        {
            Ans.push_back(dict[ans%10]);
            ans/=10;
        }
        cout<<Ans[Ans.size()-1];
        for(int i=Ans.size()-2;i>=0;i--)
        {
            cout<<" "<<Ans[i];
        }
    }
    return 0;
}
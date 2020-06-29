#include<iostream>
#include<string>
#include<vector>;
using namespace std;
int main()
{
    int number;
    int base;
    cin>>number>>base;
    string Num;
    string tmp;
    vector<string> ans;
    int cp;
    do
    {
        cp=number%base;
        Num="";
        do
        {
            tmp=string(1,'0'+cp%10);
            Num=tmp+Num;
            cp/=10;
        }while(cp!=0);
        ans.push_back(Num);
        number/=base;
    }while(number!=0);
    int i;
    for(i=0;i<ans.size();i++)
    {
        if(ans[i]!=ans[ans.size()-1-i])
        {
            break;
        }
    }
    if(i<ans.size())
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    for(int i=0;i<ans.size()-1;i++)
    {
        cout<<ans[ans.size()-1-i]<<" ";
    }
    cout<<ans[0];
    return 0;
}
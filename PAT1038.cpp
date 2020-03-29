#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string a,string b)
{
    return a+b<b+a;
}
int main()
{
    string ans;
    int N;
    cin>>N;
    vector<int> Map;
    string tmp;
    vector<string> Vec;
    for(int i=0;i<N;i++)
    {
        cin>>tmp;
        Vec.push_back(tmp);
    }
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<Vec.size();i++)
    {
        ans=ans+Vec[i];
    }
    int count=0;
    for(;count<ans.size();count++)
    {
        if(ans[count]!='0')
        {
            break;
        }
    }
    cout<<ans.substr(count,ans.size()-count);   
    if(count==ans.size())
    {
        cout<<0;
    } 
    return 0;
}
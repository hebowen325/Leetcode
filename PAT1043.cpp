#include<iostream>
#include<vector>
#include "limits.h"
#include<string>
using namespace std;
string convert_digit(int x)
{
    string ans;
    while(x!=0)
    {
        ans=string(1,'0'+x%10)+ans;
        x/=10;
    }
    return ans;
}
int main()
{
    int best_value=INT_MAX;
    int N,M;
    cin>>N>>M;
    int* value= new int[N];
    for(int i=0;i<N;i++)
    {
        cin>>value[i];
    }
    vector<string> ans;
    int Value=0;
    int i=0,j=0;
    string tmp;
    for(;i<N;i++)
    {
        Value=0;
        for(j=i;j<N;j++)
        {
            Value+=value[j];
            if(Value>=M)
            {
                break;
            }
        }
        if(Value<M||j==N)
        {
            break;
        }
        if(Value-M<best_value-M)
        {
            tmp=convert_digit(i+1)+"-"+convert_digit(j+1);
            ans.clear();
            ans.push_back(tmp);
            best_value=Value;
        }
        else if(Value==best_value)
        {
            tmp=convert_digit(i+1)+"-"+convert_digit(j+1);
            ans.push_back(tmp);
        }
    }
    for(int i=0;i<ans.size()-1;i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<ans[ans.size()-1];
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<iomanip>
using namespace std;
int main()
{
    unordered_map<int,double> Map;
    int K;
    cin>>K;
    int exponent;
    double coefficient;
    for(int i=0;i<K;i++)
    {
        cin>>exponent;
        cin>>coefficient;
        if(Map.count(exponent))
            Map[exponent]+=coefficient;
        else
            Map[exponent]=coefficient;
    }
    cin>>K;
    for(int i=0;i<K;i++)
    {
        cin>>exponent;
        cin>>coefficient;
        if(Map.count(exponent))
        {
            Map[exponent]+=coefficient;
        }
        else
        {
            Map[exponent]=coefficient;
        }
    }
    int count=0;
    for(int i=1000;i>=0;i--)
    {
        if(Map.count(i)&&Map[i]!=0)
        {
            count++;
        }
    }
    cout<<count;
    for(int i=1000;i>=0;i--)
    {
        if(Map.count(i)&&Map[i]!=0)
        {
            cout<<" "<<i;
            cout<<" "<<fixed<<setprecision(1)<<Map[i];
        }
    }
    return 0;
}

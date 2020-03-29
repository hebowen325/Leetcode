#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    unordered_map<int,double> P1;
    unordered_map<int,double> P2;
    unordered_map<int,double> ans;
    unordered_map<int,double>::iterator Iter1;
    unordered_map<int,double>::iterator Iter2;
    int count1;
    int count2;
    cin>>count1;
    int exponent;
    for(int i=0;i<count1;i++)
    {
        cin>>exponent;
        cin>>P1[exponent];
    }
    cin>>count2;
    for(int i=0;i<count2;i++)
    {
        cin>>exponent;
        cin>>P2[exponent];
    }
    for(Iter1=P1.begin();Iter1!=P1.end();Iter1++)
    {
        for(Iter2=P2.begin();Iter2!=P2.end();Iter2++)
        {
            if(!ans.count(Iter1->first+Iter2->first))
            {
                ans[Iter1->first+Iter2->first]=Iter1->second*Iter2->second;
            }
            else
            {
                ans[Iter1->first+Iter2->first]+=Iter1->second*Iter2->second;
            }
        }
    }
    vector<vector<double>> store;
    vector<double> tmp;
    int i;
    for(Iter1=ans.begin();Iter1!=ans.end();Iter1++)
    {
        if(Iter1->second==double(0))
        {
            continue;
        }
        tmp.clear();
        tmp.push_back(Iter1->first);
        tmp.push_back(Iter1->second);
        for(i=0;i<store.size();i++)
        {
            if(Iter1->first>store[i][0])
            {
                store.insert(store.begin()+i,tmp);
                break;
            }
        }
        if(i==store.size())
        {
            store.insert(store.end(),tmp);
        }
    }
    cout<<store.size();
    for(int i=0;i<store.size();i++)
    {
        cout<<" "<<int(store[i][0])<<" "<<fixed<<setprecision(1)<<store[i][1];
    }
    return 0;
}
#include<unordered_map>
#include<utility>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
bool judge(unordered_map<char,string> change_map,string &password)
{
    bool Judge=false;
    for(int i=0;i<password.length();i++)
    {
        if(change_map.count(password[i]))
        {
            if(i==password.length()-1)
            {
                password=password.substr(0,i)+change_map[password[i]];
            }
            else
            {
                password=password.substr(0,i)+change_map[password[i]]+password.substr(i+1,password.length()-1-i);
            }
            Judge=true;
        }
    }
    return Judge;
}
int main()
{
    vector<pair<string,string> > Map;
    int N;
    cin>>N;
    string name;
    string password;
    unordered_map<char,string> change_map;
    change_map['1']="@";
    change_map['0']="%";
    change_map['l']="L";
    change_map['O']="o";
    pair<string,string> Iter;
    for(int i=0;i<N;i++)
    {
        cin>>name>>password;
        if(judge(change_map,password)==true)
        {
            Iter.first=name;
            Iter.second=password;
            Map.push_back(Iter);
        }
    }
    if(Map.empty())
    {
        if(N==1)
        {
            cout<<"There is "<<N<<" account and no account is modified";
        }
        else
        {
            cout<<"There are "<<N<<" accounts and no account is modified";
        }
    }
    else
    {
        cout<<Map.size();
        for(int i=0;i<Map.size();i++)
        {
            cout<<endl<<Map[i].first<<" "<<Map[i].second;
        }
    }
    return 0;
}
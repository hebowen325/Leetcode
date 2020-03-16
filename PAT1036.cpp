#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
bool cmp(const pair<int,string> &a,const pair<int,string> &b)
{
    return a.first>b.first;
}
int main()
{
    int N;
    vector<pair<int,string> > Male;
    vector<pair<int,string> > FeMale;
    cin>>N;
    string name;
    string gender;
    string ID;
    int score;
    pair<int,string> Pair;
    for(int i=0;i<N;i++)
    {
        cin>>name;
        cin>>gender;
        cin>>ID;
        cin>>score;
        Pair.first=score;
        Pair.second=name+" "+ID;
        if(gender=="M")
        {
            Male.push_back(Pair);
        }
        else
        {
            FeMale.push_back(Pair);
        }
    }
    score=-1;
    int Score=-1;
    if(!FeMale.empty())
    {
        sort(FeMale.begin(),FeMale.end(),cmp);
        Score=FeMale[0].first;
        cout<<FeMale[0].second<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    if(!Male.empty())
    {
        sort(Male.begin(),Male.end(),cmp);
        score=Male[Male.size()-1].first;
        cout<<Male[Male.size()-1].second<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    if(score==-1||Score==-1)
    {
        cout<<"NA";
    }
    else
    {
        cout<<Score-score;
    }
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const pair<string,int*>& a,const pair<string,int*>& b)
{
    return ((a.second[0]>b.second[0])||(a.first<b.first&&a.second[0]==b.second[0]));
}

int main()
{
    int N;
    int K;
    cin>>N;
    unordered_map<string,int*> *ptr=new unordered_map<string,int*> [N];
    vector<pair<string,int*>> *Vec=new vector<pair<string,int*>> [N];
    int* tmp;
    string ID;
    int score;
    vector<pair<string,int*>> big_vec;
    for(int i=0;i<N;i++)
    {
        cin>>K;
        for(int j=0;j<K;j++)
        {
            cin>>ID;
            cin>>score;
            tmp=new int[4];
            tmp[0]=score;
            tmp[3]=i+1;
            ptr[i][ID]=tmp;
        }
        Vec[i]=vector<pair<string,int*>>(ptr[i].begin(),ptr[i].end());
        sort(Vec[i].begin(),Vec[i].end(),cmp);
        Vec[i][0].second[1]=1;
        for(int j=1;j<K;j++)
        {
            if(Vec[i][j].second[0]<Vec[i][j-1].second[0])
            {
                Vec[i][j].second[1]=j+1;
            }
            else
            {
                Vec[i][j].second[1]=Vec[i][j-1].second[1];
            }
        }
        big_vec.insert(big_vec.end(),Vec[i].begin(),Vec[i].end());
    }
    sort(big_vec.begin(),big_vec.end(),cmp);
    big_vec[0].second[2]=1;
    for(int i=1;i<big_vec.size();i++)
    {
        if(big_vec[i].second[0]<big_vec[i-1].second[0])
        {
            big_vec[i].second[2]=i+1;
        }
        else
        {
            big_vec[i].second[2]=big_vec[i-1].second[2];
        }
    }
    cout<<big_vec.size()<<endl;
    for(int i=0;i<big_vec.size();i++)
    {
        cout<<big_vec[i].first<<" "<<big_vec[i].second[2]<<" "<<big_vec[i].second[3]<<" "<<big_vec[i].second[1];
        if(i<big_vec.size()-1)
        {
            cout<<endl;
        }
    }
    return 0;
}
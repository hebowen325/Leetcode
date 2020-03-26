#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
    int N;
    int num;
    vector<int> Vec;
    unordered_map<int,int> Map;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        Vec.push_back(num);
        if(!Map.count(num))
        {
            Map[num]=1;
        }
        else
        {
            Map[num]++;
        }
    }
    for(int i=0;i<Vec.size();i++)
    {
        if(Map[Vec[i]]==1)
        {
            cout<<Vec[i];
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
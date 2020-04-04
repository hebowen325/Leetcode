#include<iostream>
#include<unordered_map>
#include<vector>
#include "limits.h"
using namespace std;
int find_max(int* len,int end)
{
    int max=INT_MIN;
    for(int i=0;i<end;i++)
    {
        if(max<len[i])
        {
            max=len[i];
        }
    }
    if(max<len[end])
    {
        max=len[end];
    }
    return max;
}
int main()
{
    int N;
    cin>>N;
    int M;
    cin>>M;
    unordered_map<int,int> Map;
    int tmp;
    int*len =new int [M];
    fill(len,len+M,0);
    for(int i=0;i<M;i++)
    {
        cin>>tmp;
        Map[tmp]=i;
    }
    int K;
    cin>>K;
    vector<int> stripe;
    for(int i=0;i<K;i++)
    {
        cin>>tmp;
        if(Map.count(tmp))
        {
            len[Map[tmp]]=find_max(len,Map[tmp])+1;
        }
    }
    cout<<find_max(len,M-1);
    return 0;
}
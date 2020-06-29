#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{
    unordered_map<string,string> address_map;
    string first_Node;
    string second_Node;
    int N;
    string curr_node;
    char word;
    string next_node; 
    cin>>first_Node>>second_Node>>N;
    if(first_Node==second_Node)
    {
        cout<<first_Node;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        cin>>curr_node>>word>>next_node;
        address_map[curr_node]=next_node;
    }
    map<string,string> Map;
    while(first_Node!="-1"||second_Node!="-1")
    {
        if(first_Node!="-1")
        {
            if(Map.count(first_Node))
            {
                cout<<first_Node;
                return 0;
            }
            else
            {
                Map[first_Node]="0";
                first_Node=address_map[first_Node];
            }
        }
        if(second_Node!="-1")
        {
            if(Map.count(second_Node))
            {
                cout<<second_Node;
                return 0;
            }
            else
            {
                Map[second_Node]="0";
                second_Node=address_map[second_Node];
            }
        }
    }
    cout<<"-1";
    return 0;
}
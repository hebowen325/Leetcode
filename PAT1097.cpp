#include<iostream>
#include<map>
#include<string>
using namespace std;
int mark[15000]={0};
typedef struct node
{
    string curr_addr;
    int value;
    string next_addr;
    node(string t1,string t2,int x):curr_addr(t1),next_addr(t2),value(x){}
    node() {}
}node;
int main()
{
    map<string,node> Map;
    int N;
    char t1[10],t2[10];
    scanf("%s %d",t1,&N);
    string first_node=string(t1);
    int x;
    for(int i=0;i<N;i++)
    {
        scanf("%s %d %s",t1,&x,t2);
        Map[t1]=node(string(t1),string(t2),x);
    }
    string first_duplicate;
    string last_duplicate;
    string last;
    string curr_node=first_node;
    while(curr_node!="-1")
    {
        if(mark[abs(Map[curr_node].value)]==0)
        {
            if(last!="")
            {
                Map[last].next_addr=curr_node;
            }
            last=curr_node;
            mark[abs(Map[curr_node].value)]=1;
        }
        else
        {
            if(first_duplicate=="")
            {
                first_duplicate=last_duplicate=curr_node;
            }
            else
            {
                Map[last_duplicate].next_addr=curr_node;
                last_duplicate=curr_node;
            }
        }
        curr_node=Map[curr_node].next_addr;
    }
    while(first_node!=last)
    {
        cout<<first_node<<" "<<Map[first_node].value<<" "<<Map[first_node].next_addr<<endl;
        first_node=Map[first_node].next_addr;
    }
    cout<<first_node<<" "<<Map[first_node].value<<" -1"<<endl;
    if(first_duplicate!="")
    {
        while(first_duplicate!=last_duplicate)
        {
            cout<<first_duplicate<<" "<<Map[first_duplicate].value<<" "<<Map[first_duplicate].next_addr<<endl;
            first_duplicate=Map[first_duplicate].next_addr;
        }
        cout<<first_duplicate<<" "<<Map[first_duplicate].value<<" -1";
    }
    return 0;
} 
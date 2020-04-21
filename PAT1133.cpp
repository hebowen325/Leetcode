#include<iostream>
#include<map>
using namespace std;
typedef struct Node
{
    string curr_addr;
    int val;
    string next_addr;
    Node(){}
    Node(char *c1,int v,char *c2): curr_addr(c1),val(v),next_addr(c2){}
}Node;

Node n[3][100000];
int main()
{
    string start_addr;
    int N,K;
    cin>>start_addr>>N>>K;
    map<string,Node> Map;
    char tmp[6];
    char tmp2[6];
    int v;
    for(int i=0;i<N;i++)
    {
        scanf("%s %d %s",tmp,&v,tmp2);
        Map[tmp]=Node(tmp,v,tmp2);
    }
    int count[3]={0};
    while(start_addr!="-1")
    {
        if(Map[start_addr].val<0)
        {
            n[0][count[0]++]=Map[start_addr];
        }
        else if(Map[start_addr].val<=K)
        {
            n[1][count[1]++]=Map[start_addr];
        }
        else
        {
            n[2][count[2]++]=Map[start_addr];
        }
        start_addr=Map[start_addr].next_addr;
    }
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            if(flag==0)
            {
                cout<<n[i][j].curr_addr<<" "<<n[i][j].val;
                flag=1;
            }
            else
            {
                cout<<" "<<n[i][j].curr_addr<<"\n"<<n[i][j].curr_addr<<" "<<n[i][j].val;
            }
        }
    }
    cout<<" -1";
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef struct node
{
    int indice;
    int Count;
    node(int x1,int x2):indice(x1),Count(x2){}
    node():indice(0),Count(0){}
    bool operator<(const node& n1)const
    {
        if(n1.Count!=Count)
        {
            return n1.Count<Count;
        }
        else
        {
            return n1.indice>indice;
        }
    }
}node;
int N;
int K;
node Node[50001];
set<node> s;
node R;
int main()
{
    scanf("%d%d",&N,&K);
    int tmp;
    for(int i=0;i<=N;i++)
    {
        Node[i].indice=i;
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",&tmp);
        if(i>0)
        {
            printf("%d:",tmp);
            int j=0;
            for(set<node>::iterator It=s.begin();It!=s.end()&&j<K;It++,j++)
            {
                printf(" %d",It->indice);
            }
            if(i<N-1)
            {
                printf("\n");
            }
        }
        Node[tmp].Count++;
        R.indice=tmp;
        R.Count=Node[tmp].Count;
        if(s.find(node(R.indice,R.Count-1))!=s.end())
        {
            s.erase(node(R.indice,R.Count-1));
        }
        s.insert(R);
    }
    return 0;
}
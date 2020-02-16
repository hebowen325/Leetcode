#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct stu
{
    string name;
    string ID;
    int grade;
}stu;
bool cmp(const stu& S1,const stu& S2)
{
    return S1.grade>S2.grade;
}
stu S[10000];
stu SS[10000];
int main()
{
    int N,tmp;
    scanf("%d",&N);
    char str[11];
    for(int i=0;i<N;i++)
    {
        scanf("%s",str);
        S[i].name=string(str);
        scanf("%s %d",str,&S[i].grade);
        S[i].ID=string(str);
    }
    int count=0;
    int bound1,bound2;
    scanf("%d %d",&bound1,&bound2);
    for(int i=0;i<N;i++)
    {
        if(S[i].grade>=bound1&&S[i].grade<=bound2)
            SS[count++]=S[i];
    }
    if(count==0)
    {
        printf("NONE");
        return 0;
    }
    sort(SS,SS+count,cmp);
    for(int i=0;i<count;i++)
    {
        cout<<SS[i].name<<" "<<SS[i].ID<<endl;
    }
    return 0;
}
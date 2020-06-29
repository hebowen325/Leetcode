#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    vector<string>* Vec=new vector<string> [K];
    char name[10];
    string s;
    int number_of_course;
    int course_number;
    for(int i=0;i<N;i++)
    {
        scanf("%s%d",name,&number_of_course);
        s=string(name);
        for(int j=0;j<number_of_course;j++)
        {
            scanf("%d",&course_number);
            Vec[course_number-1].push_back(s);
        }
    }
    int len;
    for(int i=0;i<K;i++)
    {
        sort(Vec[i].begin(),Vec[i].end());
        len=Vec[i].size();
        printf("%d %d\n",i+1,len);
        for(int j=0;j<Vec[i].size();j++)
        {
            printf("%s\n",Vec[i][j].c_str());
        }
    }
    return 0;
}
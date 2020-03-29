#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    map<string,map<int,int> > Map;
    int number_of_course;
    int number_of_students;
    string student_name;
    map<int,int> Vec;
    for(int i=0;i<K;i++)
    {
        cin>>number_of_course>>number_of_students;
        Vec.clear();
        Vec[number_of_course]=1;
        for(int j=0;j<number_of_students;j++)
        {
            cin>>student_name;
            if(Map.count(student_name))
            {
                Map[student_name][number_of_course]=1;
            }
            else
            {
                Map[student_name]=Vec;
            }
        }
    }
    for(int i=0;i<N-1;i++)
    {
        cin>>student_name;
        cout<<student_name<<" ";
        if(Map.count(student_name))
        {
            map<int,int>::iterator Iter=Map[student_name].begin();
            cout<<Map[student_name].size();
            for(;Iter!=Map[student_name].end();Iter++)
            {
                cout<<" "<<Iter->first;
            }
        }
        else
        {
            cout<<0;
        }
        cout<<endl;
    }
    cin>>student_name;
    cout<<student_name<<" ";
    if(Map.count(student_name))
    {
        map<int,int>::iterator Iter=Map[student_name].begin();
        cout<<Map[student_name].size();
        for(;Iter!=Map[student_name].end();Iter++)
        {
            cout<<" "<<Iter->first;
        } 
    }
    else
    {
        cout<<0;
    }
    return 0;
}
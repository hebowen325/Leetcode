#include<iostream>
#include<map>
#include<string>
using namespace std;
string one[]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string two[]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main()
{
    map<string,int> Map;
    for(int i=1;i<=12;i++)
    {
        Map[one[i]]=i;
        Map[two[i]]=i*13;
    }
    int N;
    scanf("%d\n",&N);
    char ch[10];
    for(int i=0;i<N;i++)
    {
        scanf("%[^\n]%*c",ch);
        string s=string(ch);
        if(ch[0]>='0'&&ch[0]<='9')
        {
            int num=stoi(s);
            if(num<13)
            {
                cout<<one[num];
            }
            else
            {
                if(num%13!=0)
                {
                    cout<<two[num/13]<<" "<<one[num%13];
                }
                else
                {
                    cout<<two[num/13];
                }
            }
        }
        else
        {
            int num=0;
            num+=Map[s.substr(0,3)];
            if(s.length()>3)
            {
                num+=Map[s.substr(4,3)];
            }
            cout<<num;
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
typedef struct Node
{
    int len;
    Node *fail;
    Node *next[26];
    Node() : len(-1), fail(NULL)
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
} Node;

void Build_Tire(string pattern, Node *root)
{
    Node *p = root, q;
    for (int i = 0; i < pattern.length(); i++)
    {
        int tmp = pattern[i] - 'a';
        if (p->next[tmp] == NULL)
        {
            p->next[tmp] = new Node();
        }
        p = p->next[tmp];
    }
    p->len=pattern.length();
}

void Build_AC_automation(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *tmp = Q.front();
        for (int i = 0; i < 26; i++)
        {
            if (tmp->next[i] != NULL)
            {
                Q.push(tmp->next[i]);
                if (tmp == root)
                {
                    tmp->next[i]->fail = root;
                }
                else
                {
                    Node *t = tmp->fail;
                    while (t != NULL)
                    {
                        if (t->next[i] != NULL)
                        {
                            tmp->next[i]->fail = t->next[i];
                            break;
                        }
                        t = t->fail;
                    }
                    if (t == NULL)
                    {
                        tmp->next[i]->fail = root;
                    }
                }
            }
        }
        Q.pop();
    }
}

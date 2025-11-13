#include <stdio.h>
#include <iostream>
/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#pragma region
using namespace std;

#define MAX (10000+500)

int N;
int q[MAX];
int pr, pw;

int strCmp(const char *a, const char *b)
{
    while(*a && (*a == *b)) ++a, ++b;
    return *a-*b;
}

void printQ()
{
    for(int i = pr; i < pw; i++)
    {
        cout<<q[i]<<endl;
    }
}

#pragma endregion

int main(void)
{
    freopen("input.txt","r", stdin);
    cin >> N;
    char cmd[100];
    pr = pw = 0;
    int iter = 0;
    for(;iter<N;iter++)
    {
        cin >> cmd;
        // cout << iter << "#==================" << cmd << endl;
        // cout<<cmd<<endl;
        if(!strCmp(cmd, "push"))
        {
            int val;
            cin >> val;
            // cout << "val=" << val << endl;
            q[pw++] = val;
        }
        else if(!strCmp(cmd, "pop"))
        {
            int val;
            val = (pr>=pw) ? -1 : q[pr++];
            cout<< val << endl;
        }
        else if(!strCmp(cmd, "size"))
        {
            int val;
            val = (pr==pw) ? 0 : (pw-pr);
            cout<< val << endl;
        }
        else if(!strCmp(cmd, "empty"))
        {
            int val;
            val = (pr>=pw) ? 1 : 0;
            cout << val << endl;
        }
        else if(!strCmp(cmd, "front"))
        {
            int val = (pr>=pw) ? -1 : q[pr];
            cout << val << endl;
        }
        else if(!strCmp(cmd, "back"))
        {
            int val = (pr>=pw) ? -1 : q[pw-1];
            cout << val << endl;
        }
    }

    return 0;
}
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 55
#define MAX_DEQ (MAX * MAX * 2)
#define OFFSET (MAX_DEQ/2)

int N, M;
int position[MAX];
int deq[MAX_DEQ*2];
int front, back;

void input()
{
    cin >> N >> M;
    for(int i = 0; i<M; i++) cin >> position[i];
    front = back = OFFSET;
    for(int i = 1; i<= N; i++) deq[back++]=i;
}

int getLeftCnt(int val)
{
    int ret = 0;
    for(int i = front; i<back; i++)
    {
        if(deq[i]==val) return ret;
        ret++;
    }
    return -1;
}

int getRightCnt(int val)
{
    int ret = 0;
    for(int i=back-1; i>=front; i--)
    {
        ret++;
        if(deq[i]==val) return ret;
    }
    return -1;
}

int main(void)
{
    freopen("input.txt","r",stdin);
    input();
    // cout << deq[back-1] << endl;

    int ans = 0;
    for(int i =0; i<M; i++)
    {
        if(deq[front]==position[i]) front++;
        else
        {
            int leftCnt = getLeftCnt(position[i]);
            int rightCnt = getRightCnt(position[i]);
            if(rightCnt>leftCnt)
            {
                for(int k=0; k<leftCnt; k++)
                {
                    deq[back++] = deq[front++];
                }
                front++;
                ans += leftCnt;
            }
            else
            {
                for(int k =0; k<rightCnt; k++)
                    deq[--front] = deq[--back];
                front++;
                ans += rightCnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
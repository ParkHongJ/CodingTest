#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#include <cassert>
#pragma warning(disable :4996)
using namespace std;

void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    int N;
    cin >> N;

    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        q.push(i);
    }

    int dest = 0;

    while (q.size() > 1)
    {
        long long next = ++dest;
        next = next * next * next - 1;

        next = next % q.size();

        // 큐의 정리
        for (int i = 0; i < next; ++i)
        {
            if (q.empty())
                break;
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        q.pop();
    }
    cout << q.front();
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}
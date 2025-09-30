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


    stack<long long> s;

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        long long height;
        cin >> height;

        if (s.empty())
        {
            s.push(height);
            continue;
        }

        while (!s.empty())
        {
            if (s.top() <= height)
            {
                s.pop();
                if (s.empty())
                {
                    s.push(height);
                    break;
                }
            }
            else
            {
                result += s.size();
                s.push(height);
                break;
            }
        }

    }
    cout << result << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}
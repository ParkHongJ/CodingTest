#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>
#pragma warning(disable :4996)
using namespace std;

int N, M, H;
long long dp[1000];
int A[1000][1000];
void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    return 0;
}

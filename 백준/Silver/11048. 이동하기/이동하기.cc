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
long long dp[1001][1001];
int A[1001][1001];
void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    cin >> N >> M;


    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> A[i][j];
		}
    }
    dp[1][1] = A[1][1];

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]),
                dp[i][j - 1]) + A[i][j];
        }
    }

    long long iMax = 0;
    for (int i = 1; i <= M; ++i)
    {
        if (iMax < dp[N][i])
        {
            iMax = dp[N][i];
        }
    }
    cout << iMax << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    return 0;
}
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
#include <list>
#include <iomanip>
#include <math.h>
#pragma warning(disable :4996)
using namespace std;

int dp[10005][3] = { 0 };
void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	* 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 
	* +1 or +2 and 현재 계단까지 연속해서 몇개를 밟았는지?
	즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
		연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
		마지막 도착 계단은 반드시 밟아야 한다.
	*/
	int N;
	cin >> N;

	vector<int> arr(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0][1] = arr[0];
	dp[1][1] = arr[1];
	dp[1][2] = arr[0] + arr[1];
	
	for (int i = 2; i < N; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];

		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	cout << max(dp[N - 1][1], dp[N - 1][2]) << '\n';
}
int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}
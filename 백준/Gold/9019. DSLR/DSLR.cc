#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <cmath>
#pragma warning(disable :4996)
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	/*
	* D: D 는 n을 두 배로 바꾼다. 
	결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 
	그 결과 값(2n mod 10000)을 레지스터에 저장한다.
	S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. 
	n이 0 이라면 9999 가 대신 레지스터에 저장된다.
	L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 
	이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
	R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 
	이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
	*/

	int T;
	cin >> T;

	

	while (T--)
	{
		//depth, before, mod
		vector<tuple<bool, int, string>> visit(10000);

		string A, B;
		cin >> A >> B;
		
		int current = stoi(A);
		int ans = stoi(B);
		//bfs되겄는데?
		queue<tuple<int,int,string>> q;
		q.push({ current, -1, ""});

		while (!q.empty())
		{
			//depth, before

			int num;
			int before;
			string mod;
			tie(num, before, mod) = q.front(); q.pop();
			
			if (get<0>(visit[num]) == false)
			{
				get<0>(visit[num]) = true;
				get<1>(visit[num]) = before;
				get<2>(visit[num]) = mod;
			}
			else
				continue;

			if (num == ans)
			{
				list<char> answer;
				int nxt = ans;
				while (get<1>(visit[nxt]) != -1)
				{
					answer.push_front(get<2>(visit[nxt])[0]);
					nxt = get<1>(visit[nxt]);
				}
				for (auto& iter : answer)
				{
					cout << iter;
				}
				cout << '\n';
				break;
			}

			{
				//D
				int nxt = (num * 2) % 10000;
				if (get<0>(visit[nxt]) == false)
				{
					q.push({nxt, num, "D"});
				}
			}
			{
				//S
				int nxt = num - 1;
				if (nxt < 0)
					nxt = 9999;
				if (get<0>(visit[nxt]) == false)
				{
					q.push({nxt, num, "S"});
				}
			}
			{
				//L
				int nxt = num;
				nxt = nxt % 1000 * 10 + nxt / 1000;

				if (get<0>(visit[nxt]) == false)
				{
					q.push({nxt, num, "L"});
				}
			}
			{
				//R
				int nxt = num;
				nxt = (nxt % 10) * 1000 + nxt / 10;
				if (get<0>(visit[nxt]) == false)
				{
					q.push({nxt, num, "R"});
				}
			}
		}
	}
}

int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

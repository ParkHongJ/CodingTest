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

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	/*
	* 정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

	2를 곱한다.
	1을 수의 가장 오른쪽에 추가한다. 
	A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
	*/
	//너비우선탐색을 하자. *2와 -1

	long A, B;
	cin >> A >> B;

	int answer = 0;
	queue<pair<long, int>> q;

	q.push({ A,0 });

	while (!q.empty())
	{
		pair<long, int> cur = q.front(); q.pop();

		if (cur.first == B)
		{
			answer += cur.second + 1;
			break;
		}

		string str = to_string(cur.first)  + "1";

		pair<long, int> nxt = { stol(str), cur.second + 1 };

		if (nxt.first <= B)
		{
			q.push(nxt);
		}

		nxt = { cur.first * 2, cur.second + 1 };

		if (nxt.first <= B)
		{
			q.push(nxt);
		}
	}

	if (answer == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << answer << '\n';
	}
}
int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}
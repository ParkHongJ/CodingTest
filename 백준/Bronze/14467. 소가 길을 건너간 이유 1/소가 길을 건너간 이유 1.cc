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


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0,0 };

void BackJoon()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	map<int, int> m;

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		map<int, int>::iterator iter = m.find(a);
		if (iter == m.end())
		{
			m.insert({ a,b });
		}
		else
		{
			//소가 등록되었고 길을 건넜다면
			if (iter->second != b)
			{
				iter->second = b;
				++answer;
			}
		}
	}
	cout << answer << '\n';
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}
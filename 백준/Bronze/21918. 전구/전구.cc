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

	int N, M;
	cin >> N >> M;
	
	vector<int> v;
	
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			v[b - 1] = c;
			break;
		case 2:
			for (int j = b; j <= c; ++j)
			{
				if (v[j - 1] == 1)
				{
					v[j - 1] = 0;
				}
				else
				{
					v[j - 1] = 1;
				}
			}
			break;
		case 3:
			for (int j = b; j <= c; ++j)
			{
				v[j - 1] = 0;
			}
			break;
		case 4:
			for (int j = b; j <= c; ++j)
			{
				v[j - 1] = 1;
			}
			break;
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	BackJoon();//출력할때 endl;넣자
	//Programmers();
	return 0;
}
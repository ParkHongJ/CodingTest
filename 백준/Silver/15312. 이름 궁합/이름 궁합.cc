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
#pragma warning(disable :4996)
using namespace std;

//상우하좌
//왼상오상 왼하 오하 
//아래방향은 없다
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 0, 0, -1, -1, 1, 1};

#define X second 
#define Y first 

void func(vector<int>& T);
void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	// 획 수 
	vector<int> v = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

	string A, B;
	cin >> A >> B;

	vector<int> C;
	C.reserve(A.length() * 2);
	for (int i = 0; i < A.length(); ++i)
	{
		int cntA = v[A[i] - 'A'];
		C.push_back(cntA);
		int cntB = v[B[i] - 'A'];
		C.push_back(cntB);
	}

	func(C);
	
}

void func(vector<int>& T)
{
	if (T.size() <= 2)
	{
		cout << T[0] << T[1] << '\n';
		return;
	}
	
	vector<int> temp;
	temp.reserve(T.size() - 1);

	for (int i = 0; i < T.size() - 1; ++i)
	{
		temp.push_back((T[i] + T[i + 1]) % 10);
	}
	func(temp);
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

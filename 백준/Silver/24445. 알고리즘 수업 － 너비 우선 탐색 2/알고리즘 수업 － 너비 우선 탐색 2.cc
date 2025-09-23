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

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

//간선 정보들의 모음?
//정점 자체를 인덱스로하는 정점과 연결된 다음정점
//ex) 정점3번
//board[3] (4,5,6) = 3번 정점은 4,5,6과 연결되어있다.
vector<vector<int>> board;

//bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장

void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
	int N, M, R;
	cin >> N >> M >> R;

	board.resize(N + 1);
	
	//정점정보 N과 연결된 간선 vector.
	vector<vector<int>> p;
	vector<int> vis;
	p.resize(N + 1);
	vis.resize(N + 1); //정점 i에 대한 방문여부

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		p[A].push_back(B);
		p[B].push_back(A);
	}

	for (int i = 0; i < p.size(); ++i)
	{
		sort(p[i].begin(), p[i].end(), [](const int& A, const int& B) {
			return A > B;
			});
	}
	
	queue<int> Q;
	Q.push(R);

	vis[R] = 1;
	vector<int> answer(N+1, 0);
	
	int cnt = 1;
	answer[R] = cnt++;

	while (!Q.empty())
	{
		int Cur = Q.front();
		Q.pop();

		//현재 정점 Cur에 대한 인접정점 출력
		for (int i = 0; i < p[Cur].size(); ++i)
		{
			//이어진 정점이 방문한거라면
			int point = p[Cur][i];
			if (vis[point] == 0)
			{
				vis[point] = 1;
				answer[point] = cnt++;
				Q.push(point);
			}
		}
	}
	for (int i = 1; i <= N; ++i) 
		cout << answer[i] << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}
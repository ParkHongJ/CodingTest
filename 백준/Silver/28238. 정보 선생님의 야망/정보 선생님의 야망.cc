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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void BackJoon()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;

    vector<vector<int>> student(N, vector<int>(5));

    // 입력
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> student[i][j];
        }
    }

    // 두 문제 조합 선택
    int bestA = 0, bestB = 1;
    int maxStu = -1;

    for (int a = 0; a < 5; ++a)
    {
        for (int b = a + 1; b < 5; ++b)
        {
            int cntStu = 0;
            for (int i = 0; i < N; ++i)
            {
                if (student[i][a] == 1 && student[i][b] == 1)
                    ++cntStu;
            }

            if (cntStu > maxStu)
            {
                maxStu = cntStu;
                bestA = a;
                bestB = b;
            }
        }
    }

    // 답 벡터
    vector<int> answer(5, 0);
    answer[bestA] = 1;
    answer[bestB] = 1;

    // 학생 수 계산
    int stuCnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (student[i][bestA] == 1 && student[i][bestB] == 1)
            ++stuCnt;
    }

    // 출력
    cout << stuCnt << '\n';
    for (int i = 0; i < 5; ++i)
    {
        cout << answer[i] << " ";
    }
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

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

void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    int N, K;
    cin >> N >> K;
    
    //이름 길이를 인덱스로하는 큐에다 넣자
    vector<queue<int>> vq;
    vq.resize(25);

    long answer = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int len = str.length();

        //현재 학생의 등수 - 이전에 오래되었던 학생의 등수의 차이가 K 보다 크다면
        //이전에 있던 학생과 현재 학생은 친구가 아니라서 이전학생을 pop한다
        while (!vq[len].empty() 
            && i - vq[len].front() > K) 
        {
            //현재 학생
            vq[len].pop();
        }

        //현재 학생과 전부 친구가 될수있으니까 size를 더함
        answer += vq[len].size();

        //현재 학생의 등수
        vq[len].push(i);
    }
    cout << answer << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}
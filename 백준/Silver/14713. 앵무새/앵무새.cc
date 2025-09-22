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
        
    int N;
    cin >> N;
    cin.ignore();

    vector<queue<string>> vq;
    vq.resize(N);

    for (int i = 0; i < N; ++i)
    {
        string str;
        getline(cin, str);

        string tempstr;
        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == ' ')
            {
                vq[i].push(tempstr);
                tempstr = "";
            }
            else
            {
                tempstr += str[j];
            }
        }

        vq[i].push(tempstr);
    }

    string str;
    getline(cin, str);

    string tempstr;
    for (long long i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ' || i + 1 == str.length())
        {
            if (i + 1 == str.length())
            {
                tempstr += str[i];
            }
            bool bFound = false;
            for (int j = 0; j < vq.size(); ++j)
            {
                if (!vq[j].empty())
                {
                    if (tempstr == vq[j].front())
                    {
                        tempstr = "";
                        bFound = true;
                        vq[j].pop();
                        break;
                    }
                }
            }
            if (!bFound)
            {
                cout << "Impossible" << '\n';
                return;
            }
        }
        else
        {
            tempstr += str[i];
        }
    }
    for (int i = 0; i < vq.size(); i++)
    {
        if (vq[i].empty() == false)
        {
            cout << "Impossible" << '\n';
            return;
        }
    }
    cout << "Possible" << '\n';
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    //Programmers();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>

#pragma warning(disable :4996)
using namespace std;

int M, N, H;
int A, B;
void BackJoon()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        int temp = 0;
        cin >> temp;

        string arrayStr;
        cin >> arrayStr;
        
        deque<int> dd;

        string strNum = "";
        for (int j = 0; j < arrayStr.length(); ++j)
        {
            if (arrayStr[j] == '[' || arrayStr[j] == ',' || arrayStr[j] == ']')
            {
                if (strNum != "")
                {
                    dd.push_back(stoi(strNum));
                    strNum = "";
                }
                continue;
            }
            strNum += arrayStr[j];
        }

        bool bEnd = false;
        int iCursor = 0;
        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == 'R')
            {
                if (iCursor == 0)
                {
                    if (dd.empty())
                    {
                        iCursor = 0;
                    }
                    else
                    {
                        iCursor = dd.size() - 1;
                    }                    
                }
                else
                {
                    iCursor = 0;
                }
            }
            else if (str[j] == 'D')
            {
                if (dd.empty())
                {
                    cout << "error" << '\n';
                    bEnd = true;
                    break;
                }
                else
                {
                    if (iCursor == 0)
                    {
                        dd.pop_front();
                    }
                    else
                    {
                        dd.pop_back();
                    }
                }
            }
        }

        if (bEnd)
            continue;

        string answer = "[";
        //명령어들이 수행된 이후
        if (!dd.empty())
        {
            //역방향
            if (iCursor > 0)
            {
                for (int i = dd.size() - 1; i >= 0; --i)
                {
                    answer += to_string(dd[i]);
                    if (i != 0)
                    {
                        answer += ',';
                    }
                }
            }
            else
            {
                //정방향
                for (int i = 0; i < dd.size(); ++i)
                {
                    answer += to_string(dd[i]);
                    if (i != dd.size() - 1)
                    {
                        answer += ',';
                    }
                }
            }
            
        }
        answer += ']';
        cout << answer << '\n';
    }
}

int main()
{
    BackJoon();//출력할때 endl;넣자
    return 0;
}
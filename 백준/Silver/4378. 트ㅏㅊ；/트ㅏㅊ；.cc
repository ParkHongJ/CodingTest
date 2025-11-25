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
	
	string str;

	map<char, char> t;
	t.insert({ 'W','Q' });
	t.insert({ 'E','W' });
	t.insert({ 'R','E' });
	t.insert({ 'T','R' });
	t.insert({ 'Y','T' });
	t.insert({ 'U','Y' });
	t.insert({ 'I','U' });
	t.insert({ 'O','I' });
	t.insert({ 'P','O' });
	t.insert({ '[','P' });
	t.insert({ ']','[' });
	t.insert({ '\\',']' });
	
	t.insert({ 'S','A' });
	t.insert({ 'D','S' });
	t.insert({ 'F','D' });
	t.insert({ 'G','F' });
	t.insert({ 'H','G' });
	t.insert({ 'J','H' });
	t.insert({ 'K','J' });
	t.insert({ 'L','K' });
	t.insert({ ';','L' });
	t.insert({ '\'',';' });
	
	t.insert({ 'X','Z' });
	t.insert({ 'C','X' });
	t.insert({ 'V','C' });
	t.insert({ 'B','V' });
	t.insert({ 'N','B' });
	t.insert({ 'M','N' });
	t.insert({ ',','M' });
	t.insert({ '.',',' });
	t.insert({ '/','.' });

	t.insert({ '1','`' });
	t.insert({ '2','1' });
	t.insert({ '3','2' });
	t.insert({ '4','3' });
	t.insert({ '5','4' });
	t.insert({ '6','5' });
	t.insert({ '7','6' });
	t.insert({ '8','7' });
	t.insert({ '9','8' });
	t.insert({ '0','9' });
	t.insert({ '-','0' });
	t.insert({ '=','-' });

	while (getline(cin,str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				cout << str[i];
			}
			else
			{
				cout << t.find(str[i])->second;
			}
		}
		cout << '\n';
	}
	
}
int main()
{
	//Programmers();
	BackJoon();
	return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int a = atoi(s.c_str());
	getline(cin, s);
	int b = atoi(s.c_str());
	getline(cin, s);
	int c = atoi(s.c_str());
	int x = (a + b - 1) / b;
	int y = (a + c - 1) / c;
	bool ans = y * 3 <= x * 2;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}

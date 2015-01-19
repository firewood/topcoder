#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	long long N;
	stringstream ss(s);
	ss >> N;
	getline(cin, s);
	long long M = atoi(s.c_str());
	long long ans = (N / M / 1000) * 1000;
	cout << ans << endl;
	return 0;
}

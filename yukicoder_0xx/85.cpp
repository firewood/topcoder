#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

bool solve(int N, int M, int C)
{
	if (N <= 1 || M <= 1) {
		return N <= 2 && M <= 2;
	}
	return N*M % 2 == 0;
}

int main(int argc, char *argv[])
{
	int N, M, C;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> M >> C;
	cout << (solve(N, M, C) ? "YES" : "NO") << endl;
	return 0;
}

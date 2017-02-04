// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		cnt += (a % 2);
	}
	bool ans = cnt % 2;
	cout << (ans ? "NO" : "YES") << endl;
	return 0;
}

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
	int N, A, B;
	cin >> N >> A >> B;
	string s;
	cin >> s;
	int ans = s[A - 1] != s[B - 1];
	cout << ans << endl;
	return 0;
}

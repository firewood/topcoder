// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int A, B;
	ss >> A >> B;
	int ans = A - B;
	ans = max(ans, (900 + A % 100) - B);
	ans = max(ans, (90 + (A / 100) * 100 + (A % 10)) - B);
	ans = max(ans, (9 + (A / 10) * 10) - B);
	ans = max(ans, A - (100 + B % 100));
	ans = max(ans, A - ((B / 100) * 100 + (B % 10)));
	ans = max(ans, A - ((B / 10) * 10));
	cout << ans << endl;
	return 0;
}

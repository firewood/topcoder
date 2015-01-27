#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
	int A, B, S;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> A >> B >> S;
	int ans = 0;
	int a = abs(A - S), b = abs(B - S);
	if (a <= b || S <= 1) {
		ans = a + S;
	} else {
		int c = b + a + abs(A - 1) + 1;
		int d = b + (S - 1) + abs(A - 1) + 1;
		ans = min(c, d);
	}
	cout << ans << endl;
	return 0;
}

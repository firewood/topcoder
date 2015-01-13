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
	} else if (A < B) {
		ans = b + S;
	} else if (A < S * 2) {
		ans = b + a + A;
	} else {
		ans = b + S - 1 + A;
	}
	cout << ans << endl;
	return 0;
}

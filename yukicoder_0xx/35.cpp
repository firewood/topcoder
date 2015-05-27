#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream sa(s);
	int N;
	sa >> N;
	int a = 0, b = 0;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream sb(s);
		int T;
		string k;
		sb >> T >> k;
		int c = (12 * T) / 1000;
		int len = (int)k.length();
		a += min(c, len);
		b += max(0, len - c);
	}
	cout << a << " " << b << endl;
	return 0;
}

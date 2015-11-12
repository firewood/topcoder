#include <iostream>
#include <sstream>
#include <set>

using namespace std;

typedef set<string> StrSet;

int main(int argc, char *argv[]) {
	string a, b;
	int N;
	cin >> a;
	cin >> N;
	cin >> b;

	if (N > 100) {
		N = (N % 6) + 6;
	}

	StrSet m;
	m.insert(a);
	for (int i = 0; i < N; ++i) {
		StrSet n;
		for (string s : m) {
			string c = s;
			c[0] = s[1], c[1] = s[0];
			n.insert(c);
			c[0] = s[0], c[1] = s[2], c[2] = s[1];
			n.insert(c);
		}
		m = n;
	}

	cout << (m.find(b) == m.end() ? "SUCCESS" : "FAILURE") << endl;

	return 0;
}

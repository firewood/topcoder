// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;
	string name;
	cin >> name;
	char t[256] = {};
	for (int i = 0; i != name.length(); ++i) {
		t[name[i]] = name[i];
	}
	for (int i = 0; i < M; ++i) {
		string x, y;
		cin >> x >> y;
		char a = x[0], b = y[0];
		for (int c = 'a'; c <= 'z'; ++c) {
			if (t[c] == a) {
				t[c] = b;
			} else if (t[c] == b) {
				t[c] = a;
			}
		}
	}
	string ans = name;
	for (int i = 0; i != name.length(); ++i) {
		ans[i] = t[name[i]];
	}
	cout << ans << endl;
	return 0;
}

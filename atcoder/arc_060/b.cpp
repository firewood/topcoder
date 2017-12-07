// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	char cnt[256] = {};
	string s;
	cin >> s;
	for (char c : s) {
		++cnt[c];
	}
	bool ans = true;
	for (int c = 'a'; c <= 'z'; ++c) {
		if (cnt[c] % 2) {
			ans = false;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

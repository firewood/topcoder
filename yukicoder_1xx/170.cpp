#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	string S;
	cin >> S;
	set<string> m;
	int len = (int)S.length();
	int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	char s[16] = {};
	do {
		for (int i = 0; i < len; ++i) {
			s[i] = S[seq[i]];
		}
		m.insert(s);
	} while (next_permutation(seq, seq + len));
	cout << (m.size() - 1) << endl;
	return 0;
}

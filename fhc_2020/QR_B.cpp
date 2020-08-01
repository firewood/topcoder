//
// Facebook Hacker Cup 2020 Qualification Round
// B. Alchemy
//

#include <iostream>
#include <sstream>
#include <map>

using namespace std;

bool solve(int n, string s) {
	string x;
	for (char c : s) {
		x += c;
		while (x.length() >= 3) {
			map<int, int> m;
			m[x.back()] += 1;
			m[x[x.length() - 2]] += 1;
			m[x[x.length() - 3]] += 1;
			if (m['A'] == 2) {
				x.resize(x.length() - 3);
				x += 'A';
			} else if (m['B'] == 2) {
				x.resize(x.length() - 3);
				x += 'B';
			} else {
				break;
			}
		}
	}
	return x.length() == 1;
}

int main(int argc, char* argv[]) {
	int T, n;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		string s;
		cin >> s;
		bool ans = solve(n, s);
		cout << "Case #" << t << ": " << (ans ? "Y" : "N") << endl;
	}
	return 0;
}

/*

Code Jam Sprint
Problem B. Repeated Numbers

問題
鴨にゼッケンをつける。
書き留める数字の数を節約するために、K桁の数を1ずつオーバーラップして
記録することにした。
重複している数を昇順に求める。

*/

#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

static string solve(int K, string s) {
	IntSet used, repeated;
	size_t pos;
	for (pos = 0; pos <= s.length() - K; ++pos) {
		int n = atoi(s.substr(pos, K).c_str());
		if (used.count(n) > 0) {
			repeated.insert(n);
		}
		used.insert(n);
	}

	ostringstream ss;
	IntSet::const_iterator it;
	for (it = repeated.begin(); it != repeated.end(); ++it) {
		if (it != repeated.begin()) {
			ss << " ";
		}
		ss << *it;
	}
	return ss.str();
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t, K;
	for (t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		ss >> K;
		ss >> s;
		string result = solve(K, s);
		cout << "Case #" << (t+1) << ": " << (result.empty() ? "NONE" : result) << endl;
	}
	return 0;
}


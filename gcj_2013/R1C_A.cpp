// Google Code Jam 2013 R1C
// Problem A. Consonants

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

typedef vector<int> IntVec;

LL solve(const string &name, int L)
{
	int v[256] = {};
	v['a'] = 1;
	v['e'] = 1;
	v['i'] = 1;
	v['o'] = 1;
	v['u'] = 1;

	// store consecutive consonants's position and length
	int nlen = (int)name.length();
	int i, j;
	IntVec pos, clen;
	for (i = 0; i < nlen; ++i) {
		if (v[name[i]]) {
			continue;
		}
		for (j = i; j < nlen; ++j) {
			if (v[name[j]]) {
				break;
			}
		}
		int c = j - i;
		if (c >= L) {
			pos.push_back(i);
			clen.push_back(c);
		}
		i = j;
	}
	if (pos.size() <= 0) {
		return 0;
	}

	// count number of substrings
	LL ans = 0;
	j = 0;
	for (i = 0; i < nlen; ++i) {
		if (pos[j] < i) {
			int l = clen[j] - (i - pos[j]);
			if (l < L) {
				++j;
				if (j >= (int)pos.size()) {
					break;
				}
			}
		}
		ans += nlen - (max(pos[j], i) + L) + 1;
	}

	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		int L = 0;
		getline(cin, s);
		stringstream ss(s);
		string name;
		ss >> name >> L;
		cout << "Case #" << (t+1) << ": " << solve(name, L) << endl;
	}

	return 0;
}


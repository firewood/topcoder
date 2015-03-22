#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;
typedef map<LL, LLVec> LLMap;

int main(int argc, char *argv[])
{
	LL N, S;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N >> S;
	}
	LLVec P(N);
	for (LL i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		ss >> P[i];
	}
	LLMap m;
	LL a = N - N / 2;
	LL b = 1LL << a;
	for (LL c = 0; c < b; ++c) {
		LL p = 0;
		for (LL i = 0; i < a; ++i) {
			if ((1LL << i) & c) {
				p += P[N / 2 + i];
			}
		}
		if (p <= S) {
			m[p].push_back(c);
		}
	}
	vector<LLVec> ans;
	a = N / 2;
	b = 1LL << a;
	for (LL c = 0; c < b; ++c) {
		LL p = 0;
		for (LL i = 0; i < a; ++i) {
			if ((1LL << i) & c) {
				p += P[i];
			}
		}
		if (p <= S) {
			LLMap::const_iterator it = m.find(S - p);
			if (it != m.end()) {
				for (auto f : it->second) {
					LL x = c | (f << (N / 2));
					LLVec v;
					for (LL i = 0; i < N; ++i) {
						if ((1LL << i) & x) {
							v.push_back(i + 1);
						}
					}
					ans.push_back(v);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto v : ans) {
		string delim = "";
		for (auto n : v) {
			cout << delim << n;
			delim = " ";
		}
		cout << endl;
	}
	return 0;
}

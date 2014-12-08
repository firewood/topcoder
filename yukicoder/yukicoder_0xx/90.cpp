#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<III> IIIVec;

int main(int argc, char *argv[])
{
	int N, M;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N >> M;
	}
	IIIVec v;
	for (int i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int a, b, c;
		ss >> a >> b >> c;
		v.push_back(III(a, II(b, c)));
	}

	int ans = 0;
	int seq[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	do {
		int sum = 0;
		for (int i = 0; i < (int)v.size(); ++i) {
			III &x = v[i];
			bool f = true;
			int j;
			for (j = 0; j < N; ++j) {
				if (seq[j] == x.first) {
					sum += x.second.second;
					break;
				}
				if (seq[j] == x.second.first) {
					break;
				}
			}
		}
		ans = max(ans, sum);
	} while (next_permutation(seq, seq + N));

	cout << ans << endl;

	return 0;
}

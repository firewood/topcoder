// Google Code Jam 2013 R1C
// Problem B. Pogo
// small

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

typedef pair<int, int> II;
typedef map<II, char> IICMap;
typedef vector<II> IIVec;

#define MAX_DIST 1000

string solve(int X, int Y)
{
	IICMap memo[MAX_DIST];

	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	char c[4] = {'W','E','S','N'};

	IIVec q;
	q.push_back(II(0, 0));
	int d, i, j;
	for (d = 1; d <= MAX_DIST; ++d) {
		IICMap &m = memo[d-1];
		IIVec next;
		for (i = 0; i < (int)q.size(); ++i) {
			for (j = 0; j < 4; ++j) {
				int x = q[i].first + dx[j] * d;
				int y = q[i].second + dy[j] * d;
				II key(x, y);
				if (m.count(key) == 0) {
					m[key] = c[j];
					next.push_back(key);
					if (x == X && y == Y) {
						string s;
						for (; d >= 1; --d) {
							s += memo[d-1][II(x, y)];
							for (j = 0; j < 4; ++j) {
								if (c[j] == memo[d-1][II(x, y)]) {
									x -= dx[j] * d;
									y -= dy[j] * d;
									break;
								}
							}
						}
						reverse(s.begin(), s.end());
						return s;
					}
				}
			}
		}
		q = next;
	}

	return "-1";
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		int X = 0, Y = 0;
		getline(cin, s);
		stringstream ss(s);
		ss >> X >> Y;
		cout << "Case #" << (t+1) << ": " << solve(X, Y) << endl;
	}

	return 0;
}


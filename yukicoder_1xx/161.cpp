#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int G, C, P;
	ss >> G >> C >> P;
	getline(cin, s);
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	int g = min(G, cnt['C']);
	int c = min(C, cnt['P']);
	int p = min(P, cnt['G']);
	int ans = (g + c + p) * 3;
	G -= g, C -= c, P -= p;
	cnt['C'] -= g, cnt['P'] -= c, cnt['G'] -= p;
	g = min(G, cnt['G']);
	c = min(C, cnt['C']);
	p = min(P, cnt['P']);
	ans += (g + c + p);
	cout << ans << endl;
	return 0;
}

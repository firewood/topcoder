// BEGIN CUT HERE
/*
// SRM 519 Div2 Medium (600)

問題

始点 (xMe,yMe) から終点 (xHome, yHome) までの最短コストを求める。
ワープできるポイントが3つある。ワープするとコストが10かかる。

#line 109 "ThreeTeleports.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
typedef vector<P> PVec;
typedef map<P, P> PPMap;
typedef vector<LL> LLV;


class ThreeTeleports {
	P Me;
	P Home;
	PVec pv1;
	PVec pv2;
	LLV GoalCost;
	static LL ll_abs(LL n) {
		return n >= 0 ? n : -n;
	}
	static LL Cost(const P &s, const P &d) {
		return ll_abs(s.first - d.first) + ll_abs(s.second - d.second);
	}

public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
		Me = P(xMe, yMe);
		Home = P(xHome, yHome);
		pv1.clear();
		pv2.clear();
		GoalCost.clear();
		int i, j;
		for (i = 0; i < (int)teleports.size(); ++i) {
			int x1, y1, x2, y2;
			if (sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2) != 4) {
				return -1;
			}
			pv1.push_back(P(x1, y1));
			pv2.push_back(P(x2, y2));
			// teleport + walk to goal
			GoalCost.push_back(10 + Cost(*pv2.rbegin(), Home));
			pv1.push_back(P(x2, y2));
			pv2.push_back(P(x1, y1));
			GoalCost.push_back(10 + Cost(*pv2.rbegin(), Home));
		}

		LL Min = Cost(Me, Home);
/*
		for (i = 0; (int)i < pv1.size(); ++i) {
			Min = min(Min, dfs(i));
		}
*/

		bool f = true;
		while (f) {
			f = false;
			for (i = 0; i < (int)pv1.size(); ++i) {
				for (j = 0; j < (int)pv1.size(); ++j) {
					if (i == j) {
						continue;
					}
					// teleport + walk to anther spot + teleport
					LL cost = 10 + Cost(pv2[i], pv1[j]) + GoalCost[j];
					if (cost < GoalCost[i]) {
						f = true;
						GoalCost[i] = cost;
					}
				}
			}
		}

		for (i = 0; i < (int)pv1.size(); ++i) {
			Min = min(Min, Cost(Me, pv1[i]) + GoalCost[i]);
		}

		return (int)Min;
	}
};


// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, ",");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, ",");
	}
	return v;
}

static void Test(int x1, int y1, int x2, int y2, const char *seq, int expected)
{
	vector <string> v = getVector<string>(seq);
	ThreeTeleports ___test;
	int result = ___test.shortestDistance(x1, y1, x2, y2, v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test(3,3,4,5, "1000 1001 1000 1002,1000 1003 1000 1004,1000 1005 1000 1006", 3);

	// example 1
	Test(0,0,20,20, "1 1 18 20,1000 1003 1000 1004,1000 1005 1000 1006", 14);

	// example 2
	Test(0,0,20,20, "1000 1003 1000 1004,18 20 1 1,1000 1005 1000 1006", 14);

	// example 3
	Test(10,10,10000,20000, "1000 1003 1000 1004,3 3 10004 20002,1000 1005 1000 1006", 30);

	// example 4
	Test(3,7,10000,30000,"3 10 5200 4900,12212 8699 9999 30011,12200 8701 5203 4845", 117);

	// example 5
	Test(0,0,1000000000,1000000000,"0 1 0 999999999,1 1000000000 999999999 0,1000000000 1 1000000000 999999999", 36);

	return 0;
}
// END CUT HERE

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
#include <sstream>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
typedef vector<P> PVec;
typedef map<P, P> PPMap;
typedef map<P, LL> PLLMap;
typedef vector<LL> LLV;

#define INF 10000000000


class ThreeTeleports {
	static LL ll_abs(LL n) {
		return n >= 0 ? n : -n;
	}
	static LL Distance(const P &s, const P &d) {
		return ll_abs(s.first - d.first) + ll_abs(s.second - d.second);
	}

public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
#if 1
		PVec points;
		points.push_back(P(xMe, yMe));
		points.push_back(P(xHome, yHome));
		PPMap warp;
		int i;
		for (i = 0; i < (int)teleports.size(); ++i) {
			istringstream s(teleports[i]);
			P p1, p2;
			s >> p1.first >> p1.second >> p2.first >> p2.second;
			points.push_back(p1);
			points.push_back(p2);
			warp[p1] = p2;
			warp[p2] = p1;
		}
		LLV Done(points.size());

		PLLMap Costs;
		LL total = 0;
		int min_index = 0;
		while (min_index != 1) {
			Done[min_index] = 1;
			P Last = points[min_index];
			LL min_cost = INF;
			for (i = 1; i < (int)points.size(); ++i) {
				if (Done[i]) {
					continue;
				}
				LL prev = Costs[points[i]];
				LL d = Distance(Last, points[i]);
				PPMap::const_iterator it = warp.find(points[i]);
				if (it != warp.end()) {
					LL w = 10 + Distance(Last, it->second);
					d = min(d, w);
				}
				LL cost = total + d;
				if (!prev || cost < prev) {
					Costs[points[i]] = cost;
				} else {
					cost = prev;
				}
				if (cost < min_cost) {
					min_index = i;
					min_cost = cost;
				}
			}
			total = min_cost;
		}

		return (int)total;
#else
		P Me(xMe, yMe);
		P Home(xHome, yHome);
		PVec pv1, pv2;
		LLV GoalCost;

		int i, j;
		for (i = 0; i < (int)teleports.size(); ++i) {
			int x1, y1, x2, y2;
			if (sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2) != 4) {
				return -1;
			}
			pv1.push_back(P(x1, y1));
			pv2.push_back(P(x2, y2));
			// teleport + walk to goal
			GoalCost.push_back(10 + Distance(*pv2.rbegin(), Home));
			pv1.push_back(P(x2, y2));
			pv2.push_back(P(x1, y1));
			GoalCost.push_back(10 + Distance(*pv2.rbegin(), Home));
		}

		bool f = true;
		while (f) {
			f = false;
			for (i = 0; i < (int)pv1.size(); ++i) {
				for (j = 0; j < (int)pv1.size(); ++j) {
					if (i == j) {
						continue;
					}
					// teleport + walk to anther spot + teleport
					LL cost = 10 + Distance(pv2[i], pv1[j]) + GoalCost[j];
					if (cost < GoalCost[i]) {
						f = true;
						GoalCost[i] = cost;
					}
				}
			}
		}

		LL Min = Distance(Me, Home);
		for (i = 0; i < (int)pv1.size(); ++i) {
			Min = min(Min, Distance(Me, pv1[i]) + GoalCost[i]);
		}
		return (int)Min;
#endif
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

	Test(0,0,0,10000,"1 1 10 1,11 1 21 1,22 1 32 1", 10000);

	return 0;
}
// END CUT HERE

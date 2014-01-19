// BEGIN CUT HERE
/*
// SRM 520 Div2 Easy (250)

問題

SRMというプログラミングコンテストにN人が参加している。
K個の部屋があり、レートの高い順に割り当てられる。
部屋内で自分よりレートが高い人数を求める。

#line 102 "SRMRoomAssignmentPhase.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class SRMRoomAssignmentPhase {
	public:
	int countCompetitors(vector <int> ratings, int K) {
		int me = ratings[0];
		sort(ratings.begin(), ratings.end());
		int i;
		for (i = ratings.size() - 1; i >= 0; --i) {
			if (ratings[i] == me) {
				break;
			}
		}
		return (ratings.size() - 1 - i) / K;
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
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, int K, int expected)
{
	vector <int> v = getVector<int>(seq);
	SRMRoomAssignmentPhase ___test;
	int result = ___test.countCompetitors(v, K);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("491, 981, 1199, 763, 994, 879, 888", 3, 2);

	// example 1
	Test("1024, 1000, 600", 1, 0);

	// example 2
	Test("505, 679, 900, 1022", 2, 1);

	// example 3
	Test("716, 58, 1000, 1004, 912, 822, 453, 1100, 558", 3, 1);

	// example 4
	Test("422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500", 4, 3);

	// example 5
	Test("1197, 1198, 1196, 1195, 1199", 1, 2);

	return 0;
}
// END CUT HERE

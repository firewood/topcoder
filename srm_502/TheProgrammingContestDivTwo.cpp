// BEGIN CUT HERE
/*
// SRM 502 Div2 Easy (250)

問題
  二人はプログラミングコンテストに参加している
  N個出題されている
  それぞれの問題を解くにはrequiredTime[i]かかる
  t分後に問題を解くと solved +=1, penalty += t
  最適戦略で T 分後の (solved, penalty) を返す

制約条件
  T: 1-100000
  requiredTime: (1-100000)[1-50]

*/
// END CUT HERE
#include <iostream>
#include <string>
#line 80 "TheProgrammingContestDivTwo.cpp"
#include <algorithm>
#include <vector>

using namespace std;
typedef vector <int> VI;

class TheProgrammingContestDivTwo {
	public:
	VI find(int T, VI requiredTime) {
		sort(requiredTime.begin(), requiredTime.end());
		int past = 0;
		int solved = 0;
		int penalty = 0;
		VI::const_iterator it;
		for (it = requiredTime.begin(); it != requiredTime.end(); ++it) {
			past += *it;
			if (past > T) {
				break;
			}
			++solved;
			penalty += past;
		}
		VI r;
		r.push_back(solved);
		r.push_back(penalty);
		return r;
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

template<class T> std::ostream & operator << (std::ostream &os, const vector<T> &t)
{
	vector<T>::const_iterator it;
	for (it = t.begin(); it != t.end(); ++it) {
		if (it != t.begin()) {
			os << ",";
		}
		os << *it;
	}
    return os;
}

static void Test(int T, const char *t)
{
	vector <int> v = getVector<int>(t);
	TheProgrammingContestDivTwo ___test;
	vector <int> r = ___test.find(T, v);
	cout << "result: " << r << endl;
}

int main() {
	// example 0
	// expected {1,47}
	Test(74, "47");

	// example 1
	// expected {0,0}
	Test(74, "4747");

	// example 2
	// expected {2,18}
	Test(47, "8,5");

	// example 3
	// expected {5,86}
	Test(47, "12,3,21,6,4,13");

	// example 4
	// expected {10,249}
	Test(58, "4,5,82,3,4,65,7,6,8,7,6,4,8,7,6,37,8");	// {10, 249 }

	// example 5
	// expected {1,100000}
	Test(100000, "100000");	// {1, 100000 }

	return 0;
}
// END CUT HERE

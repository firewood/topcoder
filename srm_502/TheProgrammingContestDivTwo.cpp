// BEGIN CUT HERE
/*
// SRM 502 Div2 Easy 250
// PROBLEM STATEMENT
// Farmer John and Fox Brus are participating in a programming contest as a team.


The duration of the contest is T minutes and they are given N tasks. Solutions can be submitted at any time during the contest, including exactly T minutes after the start of the contest. It takes them requiredTime[i] minutes to solve the i-th task.


The score in this contest is represented by two numbers, solved and penalty. Initially both numbers are 0. If they solve a task t minutes after the start of the contest, solved increases by 1 and penalty increases by t. Two scores are compared by solved first. If two scores have different solved, the score with bigger solved is better. If two scores have the same solved, the score with smaller penalty is better.


Return a vector <int> containing exactly two integers that describes the best score they can get. The first integer of the return value must represent solved and the second integer must represent penalty.

DEFINITION
Class:TheProgrammingContestDivTwo
Method:find
Parameters:int, vector <int>
Returns:vector <int>
Method signature:vector <int> find(int T, vector <int> requiredTime)


CONSTRAINTS
-T will be between 1 and 100,000, inclusive.
-requiredTime will contain between 1 and 50 elements, inclusive.
-Each element of requiredTime will be between 1 and 100,000, inclusive.


EXAMPLES

0)
74
{47}

Returns: {1, 47 }

They can solve the task. solved will be 1 and penalty will be 47.

1)
74
{4747}

Returns: {0, 0 }

They don't have time enough to solve the task.

2)
47
{8, 5}

Returns: {2, 18 }

The order is important. If they solve task 0 first and task 1 second, solved will be 2 and penalty will be 21. If they solve task 1 first and task 0 second, solved will be 2 and penalty will be 18.

3)
47
{12, 3, 21, 6, 4, 13}

Returns: {5, 86 }



4)
58
{4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8}

Returns: {10, 249 }



5)
100000
{100000}

Returns: {1, 100000 }

*/
#include <iostream>
#include <string>
// END CUT HERE
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
	Test(74, "47");
	Test(74, "4747");
	Test(47, "8,5");
	Test(47, "12,3,21,6,4,13");
	Test(58, "4,5,82,3,4,65,7,6,8,7,6,4,8,7,6,37,8");	// {10, 249 }
	Test(100000, "100000");	// {1, 100000 }
	return 0;
}
// END CUT HERE

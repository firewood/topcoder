// BEGIN CUT HERE
/*
// SRM 504.5 Div2 Easy (250)
// PROBLEM STATEMENT
// John has recently won a jackpot, but he doesn't need the money. He decided to share it with his friends instead. He knows how much money each of his friends has, and he will use this information to perform the distribution. While he still has money left, he will repeat the following steps:

Choose the poorest friend. If there are multiple poorest friends, choose one of them randomly.
Give 1 dollar to the chosen friend.

You are given an int jackpot, the number of dollars John has won, and a vector <int> money, where the i-th element is the number of dollars currently owned by the i-th friend. Return a vector <int> containing the same number of elements as money. The return value must contain the number of dollars owned by each friend after John has performed the above distribution, sorted in non-decreasing order.

DEFINITION
Class:TheJackpotDivTwo
Method:find
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> find(vector <int> money, int jackpot)


CONSTRAINTS
-money will contain between 1 and 47 elements, inclusive.
-Each element of money will be between 1 and 1,000,000, inclusive.
-jackpot will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 2, 3, 4}
2

Returns: {2, 3, 3, 4 }

First, John will give one dollar to the first friend. Then he will give another dollar to the first or the second friend.

1)
{4, 7}
1

Returns: {5, 7 }

Just?one?action?here.

2)
{1}
100

Returns: {101 }

Just one friend here.

3)
{21, 85, 6, 54, 70, 100, 91, 60, 71}
15

Returns: {21, 21, 54, 60, 70, 71, 85, 91, 100 }

*/
#line 59 "TheJackpotDivTwo.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector <int> VI;

class TheJackpotDivTwo {
	public:
	vector <int> find(vector <int> money, int jackpot) {
		sort(money.begin(), money.end());

		int i;
		int sum = jackpot;
		for (i = 0; i < (int)money.size(); ++i) {
			sum += money[i];
		}
		int average;
		for (i = money.size() - 1; i >= 0; --i) {
			average = sum / (i + 1);
			if (average >= money[i]) {
				break;
			}
			sum -= money[i];
		}
		int m = i;
		for (i = 0; i <= m; ++i) {
			int diff = average - money[i];
			money[i] += diff;
			jackpot -= diff;
		}
		for (i = m; jackpot > 0; --i) {
			money[i] += 1;
			jackpot -= 1;
		}

		return money;
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

static void Test(int j, const char *seq, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	TheJackpotDivTwo ___test;
//	int result = 0;
	vector <int> result = ___test.find(v, j);
//	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
	string s;
	char buffer[256];
	size_t i;
	for (i = 0; i < result.size(); ++i) {
		if (!s.empty()) {
			s += ',';
		}
		sprintf(buffer, "%d", result[i]);
		s += buffer;
	}
	printf("expected %s, result: %s, %s\n", expected, strcmp(expected, s.c_str()) == 0 ? "OK" : "FAILED", s.c_str());
}

int main() {
//	Test(2, "1,2,3,4", "2,3,3,4");
//	Test(1, "4,7", "5,7");
//	Test(100, "1", "101");
	Test(15, "21, 85, 6, 54, 70, 100, 91, 60, 71","21,21,54,60,70,71,85,91,100");
	Test(100000, "1,2", "50001,50002");
	return 0;
}
// END CUT HERE

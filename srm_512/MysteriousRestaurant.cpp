// BEGIN CUT HERE
/*
// SRM 512 Div2 Middle (512)
// PROBLEM STATEMENT
// A mysterious new restaurant is open in the city for only N days. Happy to hear that,
Ash and Elsh would like to have lunch at the restaurant on as many days as possible.

The restaurant sells M types of dishes. Being a mysterious restaurant,
it has mysterious rules for the customers:


They can only buy one single dish per day.
If they buy a dish of type j on the i-th day, then on the same day next week,
i.e., on the (i+7)-th day, they can only buy a dish of type j.
If they don't buy any dishes on any day, then they can't buy any dishes again from the restaurant.


Mysteriously, the price of each type of dish varies every day.
You are given a vector <string> prices consisting of N elements, each containing M characters.
prices[i][j] represents the price of the j-th type of dish on the i-th day, encoded as follows:


'0' - '9': denotes the price of 0 - 9 dollars.
'A' - 'Z': denotes the price of 10 - 35 dollars.
'a' - 'z': denotes the price of 36 - 61 dollars.


Ash and Elsh have only budget dollars allocated for having lunch in the restaurant.
Return the maximum number of days they could have lunch in the restaurant.

DEFINITION
Class:MysteriousRestaurant
Method:maxDays
Parameters:vector <string>, int
Returns:int
Method signature:int maxDays(vector <string> prices, int budget)


CONSTRAINTS
-prices will contain between 1 and 50 elements, inclusive.
-Each element of prices will contain the same number of characters, between 1 and 50 characters, inclusive.
-Each character in prices will be '0'-'9', 'a'-'z', or 'A'-'Z'.
-budget will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{"26", "14", "72", "39", "32", "85", "06"}
13

Returns: 5

The restaurant is open for 7 days. They can have lunch for 5 days, each picking the cheaper dish from the two available types. The total prices would be 2+1+2+3+2 = 10.

1)
{"26", "14", "72", "39", "32", "85", "06", "91"}
20

Returns: 8

In this case, it is better to buy the second type of dish on the first and the eighth day, so they can have lunch for the entire 8 days.

2)
{"SRM", "512"}
4

Returns: 0

They don't have sufficient budget.

3)
{"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}
256

Returns: 10



#line 75 "MysteriousRestaurant.cpp"
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
typedef vector<int> VI;

class MysteriousRestaurant {
	public:
	int maxDays(vector <string> prices, int budget) {
		int result = 0;
		int Price[50][50] = {0};
		int Sum[50][50] = {0};
		int days = prices.size();
		int dishes = prices[0].length();
		int day, dish;
		for (day = 0; day < days; ++day) {
			const string &s = prices[day];
			for (dish = 0; dish < dishes; ++dish) {
				const char *tbl = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
				const char *p = strchr(tbl, s[dish]);
				if (p) {
					Price[day][dish] = p - tbl;
				}
				int S = 0;
				int d;
				for (d = day; d >= 0; d -= 7) {
					S += Price[d][dish];
				}
				Sum[day][dish] = S;
			}
		}

		int Week[7] = {0};
		for (day = 0; day < days; ++day) {
			int w = day % 7;
			int Min = 99999999;
			for (dish = 0; dish < dishes; ++dish) {
				Min = min(Min, Sum[day][dish]);
			}
			Week[w] = Min;

			int S = 0;
			for (w = 0; w < 7; ++w) {
				S += Week[w];
			}
			if (S > budget) {
				break;
			}
			++result;
		}

		return result;
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

static void Test(const char *seq, int budget, int expected)
{
	vector <string> v = getVector<string>(seq);
	MysteriousRestaurant ___test;
	int result = ___test.maxDays(v, budget);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("26 14 72 39 32 85 06", 13, 5);
	Test("26 14 72 39 32 85 06 91", 20, 8);
	Test("SRM 512", 4, 0);
	Test("Dear Code rsHa veFu nInT heCh alle ngeP hase andb ecar eful", 256, 10);
	return 0;
}
// END CUT HERE

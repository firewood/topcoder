// BEGIN CUT HERE
/*
// SRM 508 Div2 Easy (250)
// PROBLEM STATEMENT
// Manao has been to a tremendous candy shop several times. He has forgotten its exact placement, but remembers some information about each time he visited the shop.

The city Manao lives in can be represented as an infinite two-dimensional plane with a Cartesian coordinate system. From point (x, y), Manao can move to any of the points (x - 1, y), (x, y - 1), (x + 1, y), or (x, y + 1). In order to perform each of these 4 moves, he needs to walk 1 unit of length. Manao recalls that the candy shop was located at a point with integer coordinates. Also, he remembers that the i-th time he visited the candy shop, he went there from point (X[i], Y[i]) and walked at most R[i] units of length.

Since Manao's visits to the shop span a long period of time, he may have misremembered some details. If no intersection complies with his reminiscence, return 0. Otherwise return the number of different intersections where Manao's candy shop could be, assuming Manao remembers everything correctly.

DEFINITION
Class:CandyShop
Method:countProbablePlaces
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R)


CONSTRAINTS
-X will contain between 1 and 50 elements, inclusive.
-Y will contain the same number of elements as X.
-R will contain the same number of elements as X.
-Each element of X will be between -100 and 100, inclusive.
-Each element of Y will be between -100 and 100, inclusive.
-Each element of R will be between 1 and 100, inclusive.


EXAMPLES

0)
{0}
{0}
{1}

Returns: 5

Manao walked at most 1 unit of distance. Therefore, the shop could be at (0,0) if Manao didn't walk at all and at (1,0), (0,1), (-1,0) or (0,-1) if he walked.

1)
{0}
{0}
{2}

Returns: 13

8 new locations are introduced if Manao walks another unit of distance.

2)
{2,3}
{1,-1}
{2,2}

Returns: 4

The possible places for the shop are intersections (2,0), (2,-1), (3,0) and (3,1).

3)
{2,3,5}
{1,-1,0}
{2,2,3}

Returns: 3

This is the same situation as in the previous example, but Manao has been to the shop once more. After this visit, (2,-1) is also ruled out from the possibilities list.

4)
{-100,-100,-100,0,0,0,100,100,100}
{-100,0,100,-100,0,100,-100,0,100}
{1,1,1,1,1,1,1,1,1}

Returns: 0

Manao is surely mistaken in his reminiscence.

5)
{-3,3,5,5}
{4,5,-2,0}
{10,11,8,6}

Returns: 33



#line 85 "CandyShop.cpp"
*/
// END CUT HERE
#include <string>
#include <vector>

using namespace std;

class CandyShop {
	public:
	int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R) {
		int result = 0;
		int r = R[0];
		int a = X[0] - r;
		int b = X[0] + r;
		int c = Y[0] - r;
		int d = Y[0] + r;
		int x, y;
		for (y = c; y <= d; ++y) {
			for (x = a; x <= b; ++x) {
				int f = 1;
				size_t i;
				for (i = 0; i < X.size(); ++i) {
					if (abs(y - Y[i]) + abs(x - X[i]) > R[i]) {
						f = 0;
						break;
					}
				}
				result += f;
			}
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

static void Test(const char *x, const char *y, const char *r, int expected)
{
	vector <int> X = getVector<int>(x);
	vector <int> Y = getVector<int>(y);
	vector <int> R = getVector<int>(r);
	CandyShop ___test;
	int result = ___test.countProbablePlaces(X, Y, R);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("0", "0", "1", 5);
//	Test("0", "0", "2", 13);
	Test("2,3", "1,-1", "2,2", 4);
	Test("2,3,5", "1,-1,0", "2,2,3", 3);
	Test("-100,-100,-100,0,0,0,100,100,100","-100,0,100,-100,0,100,-100,0,100","1,1,1,1,1,1,1,1,1", 0);
	Test("-3,3,5,5","4,5,-2,0","10,11,8,6", 33);

	return 0;
}
// END CUT HERE

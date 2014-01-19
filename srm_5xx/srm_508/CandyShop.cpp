// BEGIN CUT HERE
/*
// SRM 508 Div2 Easy (250)

問題

キャンディー屋の候補が座標で与えられる
可能性のある座標の個数を求める


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
	// example 0
	Test("0", "0", "1", 5);

	// example 1
	Test("0", "0", "2", 13);

	// example 2
	Test("2,3", "1,-1", "2,2", 4);

	// example 3
	Test("2,3,5", "1,-1,0", "2,2,3", 3);

	// example 4
	Test("-100,-100,-100,0,0,0,100,100,100","-100,0,100,-100,0,100,-100,0,100","1,1,1,1,1,1,1,1,1", 0);

	// example 5
	Test("-3,3,5,5","4,5,-2,0","10,11,8,6", 33);

	return 0;
}
// END CUT HERE

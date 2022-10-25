// BEGIN CUT HERE
/*
SRM 840 Div2 Hard (1000)

PROBLEM STATEMENT

There are N cities in Absurdistan.
They are numbered from 0 to N-1.

For simplicity, we will assume that city x has exactly (x+1) inhabitants.

Initially, no two cities were connected by roads.
Then there was a Y-year period of road construction.

During this period, two cities become reachable from each other as soon as there exists a sequence of one or more roads that allows you to travel between them.

The years of the road construction period were numbered from 0 to Y-1.
For each year x:

During July of year x exactly one new road was constructed: a bidirectional road connecting the cities A[x] and B[x].
Then, during December of year x each inhabitant of the country sent a Christmas postcard to each other inhabitant. All postcards that could reach their destination were delivered. All postcards that could not be delivered were burned by the post office.

Count the total number of delivered postcards during these Y years.
Return that count modulo 10^9 + 7.

In order to keep the input small, the arrays A and B are generated pseudorandomly.
Please use the following pseudocode to generate them:

state = seed
for i = 0 to Y-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    A[i] = state modulo N
    state = (state * 1103515245 + 12345) modulo 2^31
    B[i] = state modulo N


DEFINITION
Class:Postcards
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int N, int Y, int seed)


NOTES
-It is possible that in some years the new road will connect two cities that already were (directly or indirectly) connected. It is also possible that in some years the new road will connect a city to itself. In both cases there will be no changes to reachability between cities.
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-N will be between 1 and 10^9, inclusive.
-Y will be between 1 and 150,000, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
7
1
47

Returns: 112

There is only one year. In July the people build a road that connects city 5 to itself. In December the people send postcards. As no two distinct cities are reachable, only postcards within each city will be delivered.


1)
7
1
42

Returns: 122

This time the only road built connects cities 4 and 0. Compared to the previous example, the postcards sent from city 0 to city 4 or vice versa will also get delivered. This gives us an extra 10 postcards.


2)
7
2
100

Returns: 348

The first road connects cities 0 and 6. Once this road is built a total of 126 postcards will be delivered.

The second road then connects cities 5 and 6. During the second Christmas season the number of delivered postcards will be 222. (Don't forget about postcards between cities 0 and 5. These can now be delivered too.)


3)
7
20
100

Returns: 11942

Here is the full list of all 20 rows in the order in which they are built:

0-6, 6-5, 3-1, 3-3, 0-4, 6-3, 5-3, 1-6, 3-1, 3-2, 3-1, 4-5, 2-5, 6-4, 0-6, 3-6, 3-4, 1-4, 0-4, 1-1

In this test case Absurdistan eventually reaches the situation where in December all postcards get delivered: each of the 28 inhabitants of Absurdistan is able to reach each of the 27 other ones.


4)
123
123
123

Returns: 410499337

The exact total is 1,410,499,344. Remember to compute and output it modulo 10^9 + 7.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

const int64_t MOD = 1000000007;

struct UnionFind {
	std::vector<int> _parent, _size;
	vector<int> _value;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _value(size) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
		_value[ra] += _value[rb];
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class Postcards {
public:
	int count(int N, int Y, int seed) {
		modint ans = 0, x = N + 1;
		x *= N;
		x *= N - 1;
		x *= modint::modinv(3);
		UnionFind uf(Y * 2);
		map<int, int> m;
		int index = 0;
		LL state = seed;
		for (int i = 0; i < Y; ++i) {
			state = (state * 1103515245 + 12345) % (1LL << 31);
			int a = state % N;
			state = (state * 1103515245 + 12345) % (1LL << 31);
			int b = state % N;
			if (m.find(a) == m.end()) {
				uf._value[index] = a + 1;
				m[a] = index++;
			}
			if (m.find(b) == m.end()) {
				uf._value[index] = b + 1;
				m[b] = index++;
			}
			int ra = uf.root(m[a]), rb = uf.root(m[b]);
			if (ra != rb) {
				modint temp = uf._value[ra];
				x -= temp * (uf._value[ra] - 1);
				temp = uf._value[rb];
				x -= temp * (uf._value[rb] - 1);
				uf.unite(ra, rb);
				ra = uf.root(m[a]);
				temp = uf._value[ra];
				x += temp * (uf._value[ra] - 1);
			}
			ans += x;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 1;
			int Arg2 = 47;
			int Arg3 = 112;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 1;
			int Arg2 = 42;
			int Arg3 = 122;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 2;
			int Arg2 = 100;
			int Arg3 = 348;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 20;
			int Arg2 = 100;
			int Arg3 = 11942;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123;
			int Arg1 = 123;
			int Arg2 = 123;
			int Arg3 = 410499337;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Postcards ___test;
	___test.run_test(-1);
}
// END CUT HERE

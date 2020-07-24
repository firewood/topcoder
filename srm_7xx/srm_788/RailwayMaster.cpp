// BEGIN CUT HERE
/*
SRM 788 Div1 Easy (250)

PROBLEM STATEMENT
Alice lives in a city which has N stations. The stations are numbered 0, 1, 2, ..., N-1. In this city there are M railways, numbered 0, 1, 2, ..., M-1.
 Each railway connects two stations. More precisely, railway i connects station a[i] and station b[i] bidirectionally. The value of railway i is v[i] dollars. (Each value is a positive integer.)

Initially, all citizens can travel from any station to any other station only by using some sequence of railways. When this condition is satisfied, we say that the city is connected.

Alice owns all M railways in this city. She is going to sell at most K railways. Her profit will be exactly the sum of values of the sold railways.
The sold railways will no longer be used for public transport. Alice must make sure that the city will remain connected after she sells the railways, otherwise she would get attacked by unhappy citizens.

What is the biggest profit (in dollars) Alice can earn without getting attacked?

DEFINITION
Class:RailwayMaster
Method:maxProfit
Parameters:int, int, int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxProfit(int N, int M, int K, vector <int> a, vector <int> b, vector <int> v)


NOTES
-There can be two or more railways which connect the same pair of stations.


CONSTRAINTS
-N will be between 2 and 101, inclusive.
-M will be between 1 and 100, inclusive.
-K will be between 1 and M, inclusive.
-The length of arrays a, b, and v will all be exactly M.
-a[i] and b[i] will be different numbers, both between 0 and N-1, inclusive.
-v[i] will be between 1 and 10000000 (10 million).
-The given railway network will be connected.


EXAMPLES

0)
3
3
3
{0, 1, 2}
{1, 2, 0}
{224, 258, 239}

Returns: 258

In this example, the city has N = 3 station and the shape of railway is triangular. Here, if Alice sell road 1 which connects station 1 and 2, she can gain 258 dollars.
She can sell at most K = 3 railways, however, if she sells more than one railway, the city will not be connected, and the citizens would attack.
That's why she cannot gain more than 258 dollars, and you should return 258.


1)
4
6
2
{0, 0, 0, 1, 1, 2}
{1, 2, 3, 2, 3, 3}
{500, 900, 600, 700, 800, 100}

Returns: 1700

In this example, there are N = 4 stations, and there is one road between every pair of stations.
Alice can sell at most 2 railways. The best plan for Alice to sell railway 1 and 4. She will get 900 + 800 = 1700 dollars, and the city will still be connected.


2)
5
7
1
{0, 1, 2, 3, 3, 0, 1}
{1, 2, 3, 4, 0, 2, 3}
{100, 100, 100, 900, 100, 100, 100}

Returns: 100

In this example, Alice cannot sell railway 3, because, if sold, the railway network will not be connected.
It is possible to sell one of the other 6 railways. Whichever railway Alice chooses to sell among them, her profit will be 100 dollars.


3)
5
7
3
{0, 0, 0, 0, 1, 2, 3}
{1, 1, 1, 1, 2, 3, 4}
{926, 815, 777, 946, 928, 634, 999}

Returns: 2687

It is possible that there are multiple railways between a pair of stations.
In this example, it is optimal for Alice to sell railway 0, 1, and 3. Her profit will be 926 + 815 + 946 = 2687.


4)
5
7
6
{0, 1, 2, 3, 4, 1, 3}
{1, 2, 3, 4, 0, 4, 0}
{118, 124, 356, 480, 625, 767, 911}

Returns: 2303

In this example, Alice's optimal solution is to sell railway 4, 5, and 6. Her profit will be 625 + 767 + 911 = 2303.


5)
10
15
3
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4}
{1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 5, 6, 7, 8, 9}
{220284, 869120, 787788, 980412, 133333, 314159, 256312, 192916, 298575, 931110, 175353, 926778, 201513, 202729, 155136}

Returns: 2838300

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
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; }
		else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class RailwayMaster {
public:
	int maxProfit(int N, int M, int K, vector <int> a, vector <int> b, vector <int> v) {
		UnionFind uf(N), nx(N);
		vector<II> q;
		for (int i = 0; i < M; ++i) {
			uf.unite(a[i], b[i]);
			q.emplace_back(II(v[i], i));
		}
		sort(q.begin(), q.end());
		vector<int> r;
		for (auto kv : q) {
			int i = kv.second;
			if (uf.root(a[i]) == uf.root(b[i]) && nx.root(a[i]) != nx.root(b[i])) {
				nx.unite(a[i], b[i]);
			} else {
				r.push_back(kv.first);
			}
		}
		sort(r.rbegin(), r.rend());
		return accumulate(r.begin(), r.begin() + min((int)r.size(), K), 0);
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
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arr3[] = {0, 1, 2};
			int Arr4[] = {1, 2, 0};
			int Arr5[] = {224, 258, 239};
			int Arg6 = 258;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 2;
			int Arr3[] = {0, 0, 0, 1, 1, 2};
			int Arr4[] = {1, 2, 3, 2, 3, 3};
			int Arr5[] = {500, 900, 600, 700, 800, 100};
			int Arg6 = 1700;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 1;
			int Arr3[] = {0, 1, 2, 3, 3, 0, 1};
			int Arr4[] = {1, 2, 3, 4, 0, 2, 3};
			int Arr5[] = {100, 100, 100, 900, 100, 100, 100};
			int Arg6 = 100;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 3;
			int Arr3[] = {0, 0, 0, 0, 1, 2, 3};
			int Arr4[] = {1, 1, 1, 1, 2, 3, 4};
			int Arr5[] = {926, 815, 777, 946, 928, 634, 999};
			int Arg6 = 2687;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 6;
			int Arr3[] = {0, 1, 2, 3, 4, 1, 3};
			int Arr4[] = {1, 2, 3, 4, 0, 4, 0};
			int Arr5[] = {118, 124, 356, 480, 625, 767, 911};
			int Arg6 = 2303;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 15;
			int Arg2 = 3;
			int Arr3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
			int Arr4[] = {1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 5, 6, 7, 8, 9};
			int Arr5[] = {220284, 869120, 787788, 980412, 133333, 314159, 256312, 192916, 298575, 931110, 175353, 926778, 201513, 202729, 155136};
			int Arg6 = 2838300;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg6, maxProfit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RailwayMaster ___test;
	___test.run_test(-1);
}
// END CUT HERE

// BEGIN CUT HERE
/*
SRM 618 Div1 Easy (250)

問題
-簡易版の家系図がある
-配列parent1とparent2があり、親のindexが入っている
-親は片方が男で片方が女である
-可能な組み合わせかどうかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb)
			return;
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0)
			return a;
		while (_parent[p] >= 0)
			p = _parent[p];
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class Family {
public:
	string isFamily(vector <int> parent1, vector <int> parent2) {
		UnionFind same(100);
		int N = (int)parent1.size();
		for (int i = 0; i < N; ++i) {
			if (parent1[i] >= 0) {
				for (int j = 0; j < N; ++j) {
					if (parent1[i] == parent1[j]) {
						same.unite(parent2[i], parent2[j]);
					}
					if (parent1[i] == parent2[j]) {
						same.unite(parent2[i], parent1[j]);
					}
					if (parent2[i] == parent1[j]) {
						same.unite(parent1[i], parent2[j]);
					}
					if (parent2[i] == parent2[j]) {
						same.unite(parent1[i], parent1[j]);
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (parent1[i] >= 0) {
				if (same.root(parent1[i]) == same.root(parent2[i])) {
					return "Impossible";
				}
			}
		}
		return "Possible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,0};
			int Arr1[] = {-1,-1,1};
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,-1,-1};
			int Arr1[] = {-1,-1,-1,-1,-1};
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,0,0,1};
			int Arr1[] = {-1,-1,1,2,2};
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
;
			int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
			int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Family ___test;
	___test.run_test(-1);
}
// END CUT HERE

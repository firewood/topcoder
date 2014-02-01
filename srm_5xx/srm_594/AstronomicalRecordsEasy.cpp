// BEGIN CUT HERE
/*
SRM 594 Div2 Medium (500)

問題
-惑星系に関する記録がAとBの二つある
-各要素は太陽からの相対距離である
-AとBは同じ惑星系の記録だが、倍率は異なる可能性がある
-全ての惑星が記録されているとは限らない
-少なくともいくつの惑星があるか求める

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AstronomicalRecordsEasy {

public:
	int minimalPlanets(vector <int> A, vector <int> B) {
		int ans = A.size() + B.size();
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				set<int> s;
				for (int k = 0; k < A.size(); ++k) {
					s.insert(A[k] * B[j]);
				}
				for (int k = 0; k < B.size(); ++k) {
					s.insert(B[k] * A[i]);
				}
				ans = min(ans, (int)s.size());
			}
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
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {2,3,4,5};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {2,4,6,8};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,5,6,8,9};
			int Arr1[] = {2,4,5,6,7,8,9};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {6,7,8,9};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {200,500};
			int Arr1[] = {100,200,300,400,600,700,800,900};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12};
			int Arr1[] = {6,7,8,9,10,11,12,13,14,15};
			int Arg2 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalPlanets(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AstronomicalRecordsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE

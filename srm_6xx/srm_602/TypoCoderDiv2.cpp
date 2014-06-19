// BEGIN CUT HERE
/*
SRM 602 Div2 Easy (250)

問題
-TypoCoder
-1200以上が茶色コーダー
-1200未満は水色コーダー
-レーティングの変化が与えられる
-色が変わった回数を求める

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

class TypoCoderDiv2 {
	public:
	int count(vector <int> rating) {
		bool b = false;
		int ans = 0;
		for (int i = 0; i < (int)rating.size(); ++i) {
			bool n = rating[i] >= 1200;
			ans += b != n;
			b = n;
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
			int Arr0[] = {1000,1200,1199};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1500,2200,900,3000};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {600,700,800,900,1000,1100,1199};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,4000,0,4000,4000,0,0};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	TypoCoderDiv2 ___test;
	___test.run_test(-1);

}
// END CUT HERE


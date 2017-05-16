// BEGIN CUT HERE
/*
SRM 501 Div2 Easy (250)

問題
-数列が与えられる
-末尾に整数xを一つ追加したとき、等差数列または等比数列となるxがいくつあるかを求める

*/
// END CUT HERE

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

struct FoxProgression {
  int theCount(vector<int> seq) {
      seq.push_back(0);
      set<int> s;
      for (int i = -500; i <= 500*500; ++i) {
          seq.back() = i;
          int j;
          for (j = 1; j != seq.size(); ++j) {
              if ((seq[j] - seq[j-1]) != (seq[1]-seq[0])) {
                  break;
              }
          }
          if (j == seq.size()) {
              s.insert(i);
          }
          int r = seq[1]/seq[0];
          if (seq[0]*r == seq[1]) {
              for (j = 1; j != seq.size(); ++j) {
                  if (seq[j] != seq[j-1]*r) {
                      break;
                  }
              }
              if (j == seq.size()) {
                  s.insert(i);
              }
          }
      }
      return s.size() >= 1000 ? -1 : (int)s.size();
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
      int Arr0[] = {1, 2, 4, 8};
      int Arg1 = 1;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_1
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {5, 3, 1};
      int Arg1 = 1;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_2
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {1, 1};
      int Arg1 = 1;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_3
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {8, 4};
      int Arg1 = 1;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_4
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {1};
      int Arg1 = -1;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_5
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {4, 8};
      int Arg1 = 2;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

    // test_case_6
    if ((Case == -1) || (Case == n)){
      int Arr0[] = {1, 3, 4};
      int Arg1 = 0;

      vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
      verify_case(n, Arg1, theCount(Arg0));
    }
    n++;

  }

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
  FoxProgression ___test;
  ___test.run_test(-1);
}
// END CUT HERE

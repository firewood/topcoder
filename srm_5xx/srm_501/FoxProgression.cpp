// BEGIN CUT HERE
/*
SRM 501 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel likes sequences of integers. She especially likes sequences that are either an arithmetic progression of integers or a geometric progression of integers with an integer common ratio. She calls these beautiful sequences. An arithmetic progression is a sequence of numbers such that the difference of any two consecutive numbers of the sequence is a constant. A geometric progression is a sequence of numbers where each number after the first is found by multiplying the previous one by a constant non-zero number which is called the common ratio.

Ciel has a sequence of integers. She says that an integer is good if she can obtain a beautiful sequence by appending the integer to the end of the sequence. You are given a vector <int> seq. Calculate the number of good integers for the given sequence. If there are infinitely many good integers, return -1.

DEFINITION
Class:FoxProgression
Method:theCount
Parameters:vector <int>
Returns:int
Method signature:int theCount(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 500, inclusive.


EXAMPLES

0)
{1, 2, 4, 8}

Returns: 1

This sequence can become a geometric progression with ratio 2 if you append 16.


1)
{5, 3, 1}

Returns: 1

This sequence can become an arithmetic progression with difference -2 if you append -1. Note that neither the difference/ratio nor the appended integer has to be strictly positive.


2)
{1, 1}

Returns: 1

If you append 1, this sequence becomes a geometric progression (with ratio 1) and an arithmetic progression (with ratio 0) simultaneously. Despite the two reasons to call the resulted sequence "beautiful", there is still only one good integer.


3)
{8, 4}

Returns: 1

This sequence can become an arithmetic progression if you append 0. It can also become a geometric progression with ratio 0.5 if you append 2, but progressions with non-integer ratio are not beautiful.


4)
{1}

Returns: -1

Every integer is good for the given sequence.


5)
{4, 8}

Returns: 2

There are two good integers: appending 12 turns this sequence into an arithmetic progression with difference 4, and appending 16 turns it into a geometric progression with ratio 2.


6)
{1, 3, 4}

Returns: 0

This sequence is already neither an arithmetic nor a geometric progression, so nothing that you append can fix it.

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

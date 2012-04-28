/*

Google Code Jam 2012 Round 1A

Problem A. Password Problem


問題

めっちゃ長いパスワードを使っている。長さはBである。
そのうち、すでにA文字入力済である。
入力済の文字が合っている確率が文字数ぶん与えられる。
その状態から、パスワードを正しく入力するまでのストローク数の
最小の期待値を求める。

*/

#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<double> DblVec;

static double solve(int A, int B, DblVec pv) {
	DblVec P(A+1);
	P[0] = 1.0;
	int i;
	for (i = 0; i < A; ++i) {
		P[i+1] = P[i] * pv[i];
	}
	double result = B + 2;
	for (i = 0; i <= A; ++i) {		// i: bs count
		int ok = A - i;		// correct count
		int r = B - A;		// characters to type
		double sta = i*2 + r + 1;		// number of types without retypes
		double stb = sta + B + 1;		// number of types with retypes
		double p = ((P[ok] * sta) + ((1.0 - P[ok]) * stb));
		result = min(result, p);
	}
	return result;
}

int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t;
	for (t = 0; t < T; ++t) {
		int A, B;		// A: typed, B: total length
		DblVec pv;
		getline(cin, s);
		{
			stringstream ss(s);
			ss >> A >> B;
		}
		getline(cin, s);
		{
			stringstream ss(s);
			int i;
			for (i = 0; i < A; ++i) {
				double d;
				ss >> d;
				pv.push_back(d);
			}
		}
		double result = solve(A, B, pv);
		cout << "Case #" << (t+1) << ": " << result << endl;
	}

	return 0;
}


// BEGIN CUT HERE 
/*
// SRM 505 Div2 Medium (500)

問題

1つ変更することで和と積が一致する数列になるかどうかを答える

*/
#line 71 "PerfectSequences.cpp"
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;

class PerfectSequences {
	public:
	string fixIt(vector <int> seq) {
		if (seq.size() <= 1) {
			return "Yes";
		}
		if (isPerfect(seq)) {
			return "No";
		}

		sort(seq.begin(), seq.end());

		int prev = -1;
		size_t i;
		for (i = 0; i < seq.size(); ++i) {
			if (prev == seq[i]) {
				continue;
			}
			prev = seq[i];
			double sum;
			double product;
			if (!calc(seq, 0, seq.size(), i, sum, product)) {
				continue;
			}

			// (product * x) == (sum + x)
			// (product * x) - x == sum
			// x * (product - 1) == sum
			// x == sum / (product - 1)
			if (sum < 1 && product < 1) {
				// all zero
				return "Yes";
			}
			if (product < 2) {
				// div by zero
				continue;
			}
			double d = sum / (product - 1);
			int x = (int)d;
			sum += x;
			product *= x;
			if (sum == product) {
				return "Yes";
			}
		}

		return "No";
	}

	bool calc(const VI &seq, size_t start, size_t end, size_t skip, double &sum, double &product) {
		sum = 0;
		product = 1;
		while (start < end) {
			if (start != skip) {
				sum += seq[start];
				product *= seq[start];
				if (sum > 1000000000 || product > 1000000000) {
					sum = -1;
					return false;
				}
			}
			++start;
		}
		return true;
	}
	bool isPerfect(const VI &seq) {
		if (seq.size() < 1) {
			return false;
		}
		double sum, product;
		calc(seq, 0, seq.size(), seq.size(), sum, product);
		return sum == product;
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

static void Test(const char *seq, const string &expected)
{
	vector <int> v = getVector<int>(seq);
	PerfectSequences ___test;
	string result = ___test.fixIt(v);
	printf("result: %s, %s\n", result == expected ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test("1,3,4", "Yes");

	// example 1
	Test("1,2,3", "No");

	// example 2
	Test("1,4,2,4,2,4", "No");

	// example 3
	Test("1000000,1,1,1,1,2", "Yes");

	// example 4
	Test("8", "Yes");

	// example 5
	Test("2,0,2", "No");

	return 0;
}
// END CUT HERE

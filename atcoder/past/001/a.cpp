#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

string solve(string S) {
    int ans = 0;
    for (char c : S) {
        if (isdigit(c)) {
            ans = ans * 10 + c - '0';
        } else {
            return "error";
        }
    }
    return to_string(ans * 2);
}

int main() {
#ifdef DEBUG
    freopen("in_1.txt", "r", stdin);
#endif

    string S;
    cin >> S;
    cout << solve(S) << endl;
	return 0;
}

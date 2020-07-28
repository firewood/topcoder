#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool is_close(string source, string target) {
    if (source.length() != target.length()) {
        return false;
    }
    int length = (int)source.length();
    int count = 0;
    for (int i = 0; i < length; ++i) {
        count += source[i] == target[i];
    }
    return count == length - 1;
}

int shortestWordEditPath(const string& source, const string& target, const vector<string>& words)
{
    int ans = 0;
    vector<string> queue;
    set<string> seen;
    queue.push_back(source);
    seen.insert(source);
    while (!queue.empty()) {
        vector<string> nq;
        for (string a : queue) {
            if (a == target) {
                return ans;
            }
            for (string b : words) {
                if (seen.find(b) == seen.end() && is_close(a, b)) {
                    nq.emplace_back(b);
                    seen.insert(b);
                }
            }
        }
        ++ans;
        queue = nq;
    }
    return -1;
}

void test_shortestWordEditPath(const string& source, const string& target, const vector<string>& words, int expected) {
    int ans = shortestWordEditPath(source, target, words);
    cout << source << " -> " << target << ": ";
    if (ans == expected) {
        cout << "OK" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}

int main()
{
    test_shortestWordEditPath("bit", "dog", { "but", "put", "big", "pot", "pog", "dog", "lot" }, 5);
    return 0;
}

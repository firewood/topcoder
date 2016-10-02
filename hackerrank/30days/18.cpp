#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    //Write your code here
    vector<char> s;
    queue<char> q;
public:
    void pushCharacter(char ch) { s.push_back(ch); }
    void enqueueCharacter(char ch) { q.push(ch); }
    char popCharacter() {
        char ch = s.back();
        s.pop_back();
        return ch;
    }
    char dequeueCharacter() {
        char ch = q.front();
        q.pop();
        return ch;
    }
};

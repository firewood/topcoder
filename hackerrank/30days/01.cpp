#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int ii;
    double dd;
    string ss;
    
    // Read and save an integer, double, and String to your variables.
    cin >> ii >> dd;
    getline(cin, ss);
    getline(cin, ss);

    // Print the sum of both integer variables on a new line.
    cout << (i + ii) << endl;
    
    // Print the sum of the double variables on a new line.
    cout << (int)(d + dd) << "." << ((int)((d + dd) * 10) % 10) << endl;
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << (s + ss) << endl;

    return 0;
}

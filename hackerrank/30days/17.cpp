//Write your code here
struct Calculator {
    Calculator() { }
    int power(int n, int p) {
        if (n < 0 || p < 0) {
            throw runtime_error("n and p should be non-negative");
        }
        int r = 1;
        for (int i = 0; i < p; ++i) {
            r *= n;
        }
        return r;
    }
};

	// Add your code here
        Difference(vector<int> e) : elements(e) { }
        void computeDifference(void) {
            sort(elements.begin(), elements.end());
            maximumDifference = elements.back() - elements.front();
        }

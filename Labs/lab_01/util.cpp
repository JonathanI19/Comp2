#include "util.h"
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
#include<iomanip>

using namespace std;

void findMax2(vector<int> arr, int &max1, int &max2) {

    // Sort array in descending order
    sort(arr.begin(), arr.end(), greater<int>());

    // Find 2 largest non-duplicate values
    max1 = arr.at(0);
    int i = 1;
    while(true) {
        max2 = arr.at(i);
        if (max1 == max2) {
            i++;
        }
        else {
            return;
        }
    }
}

double findMean(int n, int s) {
    double avg = (double)s/(double)n;
    return avg;
}

void dispResults(double avg, double root, bool i) {

    // Set precision to decimal places (fixed)
    cout << fixed;
    cout << setprecision(2);
    cout << "Avg: " << avg << endl;

    // Different root formatting depending on if result was complex
    if (i) {
        cout << "Root: " << root << "i" << endl;
    }
    else {
        cout << "Root: " << root << endl;
    }
}
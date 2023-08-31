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

double findRoot(int max1, int max2) {
    double product = (double)max1*(double)max2;
    double root = sqrt((double)product);
    return root;
}

void dispResults(double avg, double root) {

    // Set precision to decimal places (fixed)
    cout << fixed;
    cout << setprecision(2);
    cout << "Avg: " << avg << endl;
    cout << "Root: " << root << endl;
}
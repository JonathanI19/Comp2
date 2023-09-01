#ifndef UTIL
#define UTIL
#include<vector>

/// @brief Finds the 2 largest non-duplicate numbers in a given vector
/// @param arr (vector<int>) list of values
/// @param max1 (int) Pass by reference for largest value
/// @param max2 (int) Pass by reference for second largest value
/// @return void
void findMax2(std::vector<int> arr, int &max1, int &max2);

/// @brief Find mean of given data
/// @param n (int) number of lines
/// @param s (int) summation of data values
/// @return (double) avg value
double findMean(int n, int s);

/// @brief Finds root of product of 2 numbers
/// @param max1 (int) First value 
/// @param max2 (int) Second value
/// @return (double) root of product of 2 numbers
double findRoot(int max1, int max2);

/// @brief Outputs formatted results to terminal
/// @param avg (double) Calculated avg value
/// @param root (double) Calculated root value
/// @param i (bool) True if complex
/// @return void 
void dispResults(double, double, bool);

#endif
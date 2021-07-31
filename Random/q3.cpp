// Given an array, you have to return the total number of magical subsequences in it modulo 109 + 7.

// A subsequence is a magical subsequence if we can choose 2 elements from it such that:

// Their absolute difference is at max 1
// They are present one after the other in the subsequence.
// In other words, if a subsequence P has L elements, it will be a magical subsequence if it has at least one index i (1 <= i < L) such that absolute (Pi+1 - Pi) <= 1

// Example
// For arr = [2, 4, 3, 8, 8, 5, 6], the output should be FY22CampusMagicalSubsequences(arr) = 85. Some of the magical subsequences in this example are: [2, 5, 6], [4, 3], [5, 6], [4, 3, 5, 6], [4, 5, 6], [2, 8, 8]. There are total 85 such subsequences in the given array.

// [execution time limit] 1 seconds (cpp)

// [input] array.integer arr

// Guaranteed constraints:
// 2 ≤ arr.length ≤ 1000,
// 1 ≤ arr[i] ≤ 105,

// [output] integer

// Total number of magical subsequences modulo 109 + 7.


int FY22CampusMagicalSubsequences(vector<int> arr) {

}

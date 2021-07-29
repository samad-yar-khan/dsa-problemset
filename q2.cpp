// Bob is painting a wall. The wall contains N sections and he has already painted some sections of the wall randomly. The wall consists of a string of length N containing lower-case alphabets 'a' to 'z' denoting the color of the section.

// In 1 operation, Bob can paint a single section of the wall to any new colour. He is now tired and does not want to do more than k operations. So, he decides to create a continuous segment of the wall which is completely the same colour (a range [i, j] where all wall[k] are equal, i <= k <= j)

// What is the maximum length of such a segment he can create.

// Constraints
// 1 <= N <= 5 * 10^5
// wall[i] = 'a' to 'z'

// 0 <= k <= 5 * 10^5

// Example
// wall = "abaab"
// k = 1

// Output = 4
// Bob can paint the 2nd to 'a' (New Wall = "aaaab") to get the maximum painted segment of length 4 of colour 'a'

// [execution time limit] 1 seconds (cpp)

// [input] string wall

// Defines the colour of the section
// wall[i] = 'a' to 'z'

// [input] integer k

// The amount of operations, Bob can perform

// [output] integer

// The maximum painted segment of the wall
#include<bits/stdc++.h>

int FY22CampusPaintTheWall(string wall, int k) {

}

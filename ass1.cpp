#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;


void question1() {
    cout << "Question 1: Merge two sorted arrays where first array has space for second" << endl;
    
    
    int A[10] = {1, 3, 5, 7, 9}; 
    int B[] = {2, 4, 6, 8, 10};  
    int m = 5; 
    int n = 5; 
    

    cout << "Array A: ";
    for (int i = 0; i < m; i++) cout << A[i] << " ";
    cout << endl;
    
    cout << "Array B: ";
    for (int i = 0; i < n; i++) cout << B[i] << " ";
    cout << endl;
    
    
    int i = m - 1;     
    int j = n - 1;     
    int k = m + n - 1; 
    
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k] = A[i];
            i--;
            k--;
        } else {
            A[k] = B[j];
            j--;
            k--;
        }
    }
    
    
    while (j >= 0) {
        A[k] = B[j];
        j--;
        k--;
    }
 
    cout << "Merged Array: ";
    for (int i = 0; i < m + n; i++) cout << A[i] << " ";
    cout << endl << endl;
}


void question2() {
    cout << "Question 2: Sort strings so anagrams are together" << endl;
    
    vector<string> arr = {"race", "care", "acre", "stone", "tones", "notes", "loop", "pool", "polo", "top", "pot", "opt"};

    
    cout << "Original array: ";
    for (const auto& s : arr) cout << s << " ";
    cout << endl;
    
    auto comparator = [](const string& a, const string& b) {
        string sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        string sortedB = b;
        sort(sortedB.begin(), sortedB.end());
        return sortedA < sortedB;
    };
    
    sort(arr.begin(), arr.end(), comparator);
    
    cout << "Sorted with anagrams together: ";
    for (const auto& s : arr) cout << s << " ";
    cout << endl << endl;
}


int searchRotatedArray(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Check if left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        // Right half must be sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1; // Not found
}

void question3() {
    cout << "Question 3: Search in rotated sorted array" << endl;
    
    vector<int> nums = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 20;
    
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    int index = searchRotatedArray(nums, target);
    cout << "Index of " << target << ": " << index << endl << endl;
}

// Question 4: Sort a 20GB file with one string per line



int searchSparseArray(const vector<string>& arr, const string& target) {

     // Handle edge case for empty array
    if (arr.empty()) return -1;
     for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void question5() {
    cout << "Question 5: Search in array with empty strings" << endl;
    
    vector<string> arr = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string target = "ball";
    
    cout << "Array: ";
    for (const auto& s : arr) cout << "\"" << s << "\" ";
    cout << endl;
    
    int index = searchSparseArray(arr, target);
    cout << "Index of \"" << target << "\": " << index << endl << endl;
}


pair<int, int> searchSortedMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return {-1, -1};
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (int i = 0; i < m; i++) {
        int mini = matrix[i][0];
        int maxi = matrix[i][n - 1];

        if (target >= mini && target <= maxi) {
            int start = 0;
            int end = n - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (matrix[i][mid] == target) {
                    return {i, mid};
                }
                else if (matrix[i][mid] < target) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
    }
    return {-1, -1};
}


void question6() {
    cout << "Question 6: Search in a sorted matrix" << endl;
    
    vector<vector<int>> matrix = {
        {15, 20, 40, 85},
        {20, 35, 80, 95},
        {30, 55, 95, 105},
        {40, 80, 100, 120}
    };
    int target = 55;
    
    cout << "Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) cout << num << "\t";
        cout << endl;
    }
    
    auto result = searchSortedMatrix(matrix, target);
    cout << "Position of " << target << ": (" << result.first << ", " << result.second << ")" << endl << endl;
}

struct Person {
    int height;
    int weight;
};

// Comparator for sorting by height, then weight
bool comparePerson(const Person& a, const Person& b) {
    if (a.height == b.height)
        return a.weight < b.weight;
    return a.height < b.height;
}

int longestIncreasingSubsequence(vector<Person>& people) {
    if (people.empty()) return 0;
    
    
    sort(people.begin(), people.end(), comparePerson);
    
    vector<int> dp(people.size(), 1);
    int max_len = 1;
    
    for (int i = 1; i < people.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (people[i].height > people[j].height && 
                people[i].weight > people[j].weight) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    
    return max_len;
}

void question7() {
    cout << "Question 7: Circus tower problem (Longest increasing subsequence)" << endl;
    
    vector<Person> people = {
        {65, 100}, {70, 150}, {56, 90}, 
        {75, 190}, {60, 95}, {68, 110}
    };
    
    cout << "People (height, weight):" << endl;
    for (const auto& p : people) {
        cout << "(" << p.height << ", " << p.weight << ") ";
    }
    cout << endl;
    
    int max_people = longestIncreasingSubsequence(people);
    cout << "Maximum number of people in tower: " << max_people << endl << endl;
}


int getRankOfNumber(const vector<int>& stream, int x) {
    int count = 0;
    for (int num : stream) {
        if (num <= x) count++;
    }
    return count - 1;  
}

void question8() {
    cout << "Question 8: Rank from stream of integers (Direct Stream Usage)" << endl;

    vector<int> stream = {5, 1, 4, 4, 5, 9, 7, 13, 3};

    cout << "Stream: ";
    for (int num : stream) cout << num << " ";
    cout << endl;

    cout << "getRankOfNumber(1) = " << getRankOfNumber(stream, 1) << endl;
    cout << "getRankOfNumber(3) = " << getRankOfNumber(stream, 3) << endl;
    cout << "getRankOfNumber(4) = " << getRankOfNumber(stream, 4) << endl;
}


int main() {
    question1();
    question2();
    question3();
    // question4();
    question5();
    question6();
    question7();
    question8();
    
    return 0;
}
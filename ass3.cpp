#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Q1) Find maximum in bitonic array
void question1() {
    int n = 7;
    vector<int> arr = {1, 3, 8, 12, 9, 5, 2};  
    cout << "Array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid > 0 && mid < n - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            cout << "Maximum element in array: " << arr[mid] << endl;
            return;
        }
        else if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << "Invalid array input!" << endl;
}

int tileNumber = 1;

// Recursive tiling function
void tileBoard(vector<vector<int>>& board, int topRow, int topCol, int missingRow, int missingCol, int size) {
    if (size == 1) return;

    int t = tileNumber++;
    int subSize = size / 2;

    // Missing square in top-left
    if (missingRow < topRow + subSize && missingCol < topCol + subSize) {
        tileBoard(board, topRow, topCol, missingRow, missingCol, subSize);
    } else {
        board[topRow + subSize - 1][topCol + subSize - 1] = t;
        tileBoard(board, topRow, topCol, topRow + subSize - 1, topCol + subSize - 1, subSize);
    }

    // Missing square in top-right
    if (missingRow < topRow + subSize && missingCol >= topCol + subSize) {
        tileBoard(board, topRow, topCol + subSize, missingRow, missingCol, subSize);
    } else {
        board[topRow + subSize - 1][topCol + subSize] = t;
        tileBoard(board, topRow, topCol + subSize, topRow + subSize - 1, topCol + subSize, subSize);
    }

    // Missing square in bottom-left
    if (missingRow >= topRow + subSize && missingCol < topCol + subSize) {
        tileBoard(board, topRow + subSize, topCol, missingRow, missingCol, subSize);
    } else {
        board[topRow + subSize][topCol + subSize - 1] = t;
        tileBoard(board, topRow + subSize, topCol, topRow + subSize, topCol + subSize - 1, subSize);
    }

    // Missing square in bottom-right
    if (missingRow >= topRow + subSize && missingCol >= topCol + subSize) {
        tileBoard(board, topRow + subSize, topCol + subSize, missingRow, missingCol, subSize);
    } else {
        board[topRow + subSize][topCol + subSize] = t;
        tileBoard(board, topRow + subSize, topCol + subSize, topRow + subSize, topCol + subSize, subSize);
    }
}

// Q2) Tiling Problem
void question2() {
    // Predefined input
    int n = 8;                 
    int missingRow = 1;        
    int missingCol = 1;        

    cout << "\nBoard size: " << n << "x" << n << endl;
    cout << "Missing cell: (" << missingRow << ", " << missingCol << ")\n";

    vector<vector<int>> board(n, vector<int>(n, 0));
    tileBoard(board, 0, 0, missingRow, missingCol, n);

    cout << "Tiling result (numbers represent L-shaped tiles):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Helper for Q3 (Skyline problem)
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int,int>> heights;
    for (auto& b : buildings) {
        heights.push_back({b[0], -b[2]}); 
        heights.push_back({b[1], b[2]}); 
    }

    sort(heights.begin(), heights.end());

    multiset<int> mset = {0};
    int prev = 0;
    vector<vector<int>> res;

    for (auto& h : heights) {
        if (h.second < 0) {
            mset.insert(-h.second); 
        } else {
            mset.erase(mset.find(h.second)); 
        }

        int cur = *mset.rbegin();
        if (cur != prev) {
            res.push_back({h.first, cur});
            prev = cur;
        }
    }
    return res;
}

// Q3) Skyline Problem
void question3() {
    vector<vector<int>> buildings = {
        {2, 9, 10}, 
        {3, 7, 15}, 
        {5, 12, 12}, 
        {15, 20, 10}, 
        {19, 24, 8}
    };

    cout << "\nBuildings: ";
    for (auto& b : buildings) {
        cout << "(" << b[0] << "," << b[1] << "," << b[2] << ") ";
    }
    cout << endl;

    vector<vector<int>> skyline = getSkyline(buildings);

    cout << "Skyline formed is:\n";
    for (auto& point : skyline) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;
}


int main() {
    question1();
    question2();
    question3();
    return 0;
}

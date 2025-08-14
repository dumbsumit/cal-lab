#include <iostream>
#include <vector>
using namespace std;

void question1(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (first increasing then decreasing): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] > arr[mid + 1])) {
            cout << "Maximum element in bitonic array: " << arr[mid] << endl;
            return;
        }
        else if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << "Invalid bitonic array input!" << endl;
}


int tileNumber = 1;

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

void question2() {
    int n, missingRow, missingCol;
    cout << "Enter board size (n must be power of 2): ";
    cin >> n;
    cout << "Enter missing cell row and column (0-indexed): ";
    cin >> missingRow >> missingCol;

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


struct Strip {
    int left, ht;
};

struct Skyline {
    vector<Strip> strips;
};

Skyline mergeSkylines(Skyline left, Skyline right) {
    Skyline result;
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;

    while (i < left.strips.size() && j < right.strips.size()) {
        int x;
        if (left.strips[i].left < right.strips[j].left) {
            x = left.strips[i].left;
            h1 = left.strips[i].ht;
            i++;
        } else {
            x = right.strips[j].left;
            h2 = right.strips[j].ht;
            j++;
        }
        int maxh = max(h1, h2);
        if (result.strips.empty() || result.strips.back().ht != maxh) {
            result.strips.push_back({x, maxh});
        }
    }

    while (i < left.strips.size()) {
        result.strips.push_back(left.strips[i++]);
    }
    while (j < right.strips.size()) {
        result.strips.push_back(right.strips[j++]);
    }

    return result;
}

Skyline findSkyline(vector<vector<int>>& buildings, int l, int r) {
    if (l == r) {
        Skyline res;
        res.strips.push_back({buildings[l][0], buildings[l][1]});
        res.strips.push_back({buildings[l][2], 0});
        return res;
    }
    int mid = (l + r) / 2;
    Skyline left = findSkyline(buildings, l, mid);
    Skyline right = findSkyline(buildings, mid + 1, r);
    return mergeSkylines(left, right);
}

void question3() {
    int n;
    cout << "Enter number of buildings: ";
    cin >> n;
    vector<vector<int>> buildings(n, vector<int>(3));
    cout << "Enter buildings (left height right):\n";
    for (int i = 0; i < n; i++) {
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    }

    Skyline result = findSkyline(buildings, 0, n - 1);

    cout << "Skyline:\n";
    for (auto &s : result.strips) {
        cout << "(" << s.left << ", " << s.ht << ") ";
    }
    cout << endl;
}


int main() {
    question1();
    question2();
    question3();
    return 0;
}

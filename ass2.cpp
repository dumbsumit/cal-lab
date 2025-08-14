
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <map>

int employeeRating(vector<int>& workload) {
    int n = workload.size();
    int maxDays = 0;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (workload[j] > 6) {
                count++;
                maxDays = max(maxDays, count);
            } else {
                break;
            }
        }
    }
    return maxDays;
}
 
void question1() {
    cout << "Question 1: Employee rating based on workload" << endl;
    
    vector<int> workload = {7, 8, 5, 9, 10, 11, 4, 7, 8};
    
    cout << "Workload array: ";
    for (int hrs : workload) cout << hrs << " ";
    cout << endl;
    
    int rating = employeeRating(workload);
    cout << "Employee Rating (Max consecutive days > 6 hrs): " << rating << endl << endl;
}

int findBoxBruteForce(int N, int K) {
    int currentBox = 1;
    int direction = 1; 
    
    for (int candy = 1; candy <= K; candy++) {
        if (candy == K) {
            return currentBox; 
        }
        
       
        currentBox += direction;
        
       
        if (currentBox > N) {
            currentBox = N - 1;
            direction = -1; 
        } else if (currentBox < 1) {
            currentBox = 2;
            direction = 1; 
        }
    }
    return currentBox;
}
void question2() {
    cout << "Question 2: Find box index for K-th candy" << endl;
    
    int N = 4;
    int K = 11; 
    
    cout << "Number of boxes: " << N << endl;
    cout << "K-th candy: " << K << endl;
    
    int boxIndex = findBoxBruteForce(N, K);
    cout << "The K-th candy is placed in box number: " << boxIndex << endl << endl;
}
int main() {
    question1();
    question2();
    return 0;
}

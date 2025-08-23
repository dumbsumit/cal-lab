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

int movedisks(int n , char from , char to , char aux ){
  if(n == 1){
    cout<<"move disk 1 from "<<from<<" to "<<to<<" rod"<<endl;
    return 1 ;
  }
  int steps = 0 ;
  steps+=movedisks(n-1,from , aux , to );
  cout<<"move disk "<<n<<" from "<<from<<" to "<<to<<" rod"<<endl;
  steps++;
  steps+=movedisks(n-1,aux,to,from);
  return steps;
}

void question3(){
    int n = 3 ;
    cout<<"The number of a Disks are: "<<n<<endl;
   int total  = movedisks(n,'A','B','C');
   cout<<"Total steps required to solve Tower of Hanoi for "<<n<< " Disks: "<<total<<endl<<endl;
}

void question4(){
    int x=2, y=2, s=4, t=5, count=0;

    cout<<"Enter the Start X coordinate: "<<x<<endl;
    
    cout<<"Enter the Start Y coordinate: "<<y<<endl;
    
    cout<<"Enter the Side Length: "<<s<<endl;
   
    cout<<"Enter the Time in Seconds: "<<t<<endl;

    for(int i=x;i<=x+s;i++){
        for(int j=y;j<=y+s;j++){
            if(i+j<=t){
                count++;
            }
        }
    }
    cout<<"Total Points secured by the frog: "<<count<<endl<<endl;
}

void question5(){
    int size = 5;
    vector<int> time = {3, 4, 5, 7, 8};  

    sort(time.begin(), time.end());
    int exp = time[0];

    for (int i = 0; i < size; i++) {
        if (time[i] < exp) continue;
        if (time[i] == exp) {
            exp++;
        } else {
            break;
        }
    }
    cout << "The missing time is " << exp << endl << endl;

}


void question6(){
    int n = 6; 
    vector<int> arr = {10, 20, 30, 40, 50, 60};  
    int key = 40;  

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Key found at index " << i<< endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Key not found" << endl << endl;
}

void question7(){
    int n = 7;  
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35}; 
    int key = 25; 
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Key found at index " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) cout << "Key not found" << endl << endl;

}


void question8(){
    int n = 10;
    vector<int> signal = {100, 95, 90, 85, 120, 110, 100, 99, 98, 150};  
    
    int drops = 0;
    int len = 1; 

    for (int i = 1; i < n; i++) {
        if (signal[i] < signal[i - 1]) {
            len++;
        } else {
            if (len >= 3) drops++;
            len = 1;
        }
    }
    if (len >= 3) drops++;

    cout << "Number of signal drops: " << drops  << endl;

}

int main() {
    // question1();
    //question2();
    //question3();
    // question4();
     //question5();
     //question6();
     //question7();
     question8();
    return 0;
}

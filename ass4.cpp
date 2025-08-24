#include <iostream>
using namespace std;

void question1() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[3][3] = {0};
    cout<<"MATRIX A : "<<endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
             cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;
    cout<<"MATRIX B : "<<endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
             cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

   cout<<endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    cout << "Result of 3x3 Matrix Multiplication:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    question1();

    return 0;
}

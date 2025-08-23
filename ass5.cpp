#include <iostream>
using namespace std;

void question1() {
    int houses = 10;
    int localities = 2;

    cout << "The number of houses are " << houses << endl;
    cout << "The number of localities are " << localities << endl;

    if (houses < localities) {
        cout << "Connection cannot be established" << endl;
        return;
    }

    int equal_distribution = houses / localities;
    int remaining = houses % localities;
    int maxi = 0;
    int mini = 0;

    // For minimum connections
    for (int i = 0; i < localities - 1; i++) {
        int common = equal_distribution;
        mini += common * (common - 1) / 2;
    }

    int last = equal_distribution + remaining;
    mini += last * (last - 1) / 2;

    cout << "The minimum number of telephone connections will be " << mini << endl;

    // For maximum connections
    int max_in_one_locality = houses - (localities - 1);
    maxi = max_in_one_locality * (max_in_one_locality - 1) / 2;
    cout << "The maximum number of telephone connections will be " << maxi << endl;
}

void question2() {
   
}

int main() {
    question1();
    question2();
    return 0;
}

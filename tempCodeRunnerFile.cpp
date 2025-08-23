void question6(){
    int n = 6; 
    vector<int> arr = {10, 20, 30, 40, 50, 60};  
    int key = 40;  

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Key found at index " << i << endl << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Key not found" << endl << endl;
}

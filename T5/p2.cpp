#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

// we need a function that firts recives the number of cases, then the next input n the number of univeristies and students
// the next n inputs are the university of the i-th student
// the next n inputs are the hability of the i-th student
// k is the number max number of students that can be in a equipment for each university, this number increases with the number of students in the university
// the output is the sum of all the students that can be in a equipment for each university, and this output is the power of the region that includes al the universities

//the array is a vector with vectors, that represents the universities and the students
void max_power(arr []){
    int n = arr[0].size();
    int k = arr[1].size();
    int result = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < k; j++){
            sum += arr[i][j];
        }
        if (sum <= k){
            result += sum;
        }
    }
    cout << result << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int n;
        cin >> n;
        vector<int> arr[n];
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            arr[j].push_back(a);
        }
        int k;
        cin >> k;
        arr[n].push_back(k);
        max_power(arr);
    }
    return 0;
}
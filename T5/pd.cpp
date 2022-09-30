#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#include <algorithm>
// we need a function that firts recives the number of cases, then the next input n the number of univeristies and students
// the next n inputs are the university of the i-th student
// the next n inputs are the hability of the i-th student
// k is the number max number of students that can be in a equipment for each university, this number increases with the number of students in the university
// the output is the sum of all the students that can be in a equipment for each university, and this output is the power of the region that includes al the universities
// we need a vector with vectors, that represents the universities and the students

void max_power(vector<vector<int>> arr){
    int n = arr.size();
    arr[n].pop_back();
    int k = 1;
    int result = 0;
    vector<vector<int>> arr2(n);
    // sort vector arr
    for (int i = 0; i < n; i++){
        copy(arr[i].begin(), arr[i].end(), arr2[i].begin());
        sort(arr2[i].begin(), arr2[i].end());
        while (arr2[i].size() % k != 0){
            arr2[i].pop_back();
        }
        for (int j = 0; j < k; j++){
            result += arr2[i][j];
        }
    }
    //copy arr in arr2
    for (int i = 0; i < n; i++){
        copy(arr[i].begin(), arr[i].end(), arr2[i].begin());
    }
    for (int i = 0; i < n; i++){
        while (arr2[i].size() % k != 0){
            arr2[i].pop_back();
        }
        for (int j = 0; j < arr2[i].size(); j++){
            result += arr2[i][j];
        }
        k++;
        cout << result << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            arr[j].push_back(a);
        }
        int k;
        cin >> k;
        arr[n].push_back(k);
    }
    max_power(arr);
}
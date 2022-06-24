#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

// Function to find the all the pairs of numbers in an array that
// the maximum common divisor of the two numbers > 1
void findMaxPair(int arr[], int n){
    // Sort the array
    sort(arr, arr+n);
    reverse(arr, arr+n);
    // Initialize the result
    int result = 0;
    // Initialize the two pointers
    int i = 0, j = n-1;
    // Traverse the array
    while (i < n){
        while(i < j){
            // If the maximum common divisor of the two numbers is > 1
            if(__gcd(arr[i], 2 * arr[j]) > 1){
                // Update the result
                result++;
                // Move the pointer to the next element
                j--;
            }
            // If the maximum common divisor of the two numbers is 1
            else{
                // Move the pointer to the next element
                j--;
            }
        }
        i++;
        j = n-1;
    }
    // Print the result
    cout << result << endl;
}

int main(){
    int a;
    int n;
    cin >> a;
    for (int i = 0; i < a; ++i){
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[j];
        }
        findMaxPair(arr, n);
    }
}


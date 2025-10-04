#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++) 
        for (int j = i+1; j < nums.size(); j++) 
            if (nums[i] + nums[j] == target) 
                return {i, j};
    return {};
}

int  main() {
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
    }

    cout << "Enter target value: ";
    cin >> target;
    
    vector<int> result = twoSum(arr, target);

    if (!result.empty()) {
        cout << "Result: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No two numbers found with the given target." << endl;
    }

}
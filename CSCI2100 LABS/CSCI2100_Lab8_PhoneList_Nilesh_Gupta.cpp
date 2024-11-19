#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isConsistent(const vector<string>& phoneNumbers) {
    vector<string> sortedNumbers = phoneNumbers;
    sort(sortedNumbers.begin(), sortedNumbers.end());
    for (size_t i = 0; i < sortedNumbers.size() - 1; ++i) {
        if (sortedNumbers[i + 1].substr(0, sortedNumbers[i].length()) == sortedNumbers[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int numTest; // number of test cases

    cout << "Enter the number of test cases: ";
    cin >> numTest;

    while (numTest--) {
        int nums; // number of phone numbers in the test case

        cout << "Enter the number of phone numbers: ";
        cin >> nums;

        vector<string> phoneNumbers(nums);

        cout << "Enter the phone numbers:" << endl;
        for (int i = 0; i < nums; ++i) {
            cout << "Phone number " << i + 1 << ": ";
            cin >> phoneNumbers[i];
        }

        if (isConsistent(phoneNumbers)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string input_str;
    cout << "Reference string: ";
    getline(cin, input_str);
    stringstream ss(input_str);
    vector<int> re_string;
    int temp;
    while (ss >> temp) {
        re_string.push_back(temp);
        if (ss.peek() == ',')
            ss.ignore();
    }

    int page_fault;
    cout << "Enter No Of Frames: ";
    cin >> page_fault;

    int n = re_string.size();
    vector<int> m(page_fault, -1); // Frames
    vector<int> t(page_fault, 0);  // Time of last use
    vector<int> c;  // Temporary vector for comparison
    int total = 0;  // Total number of page accesses
    int idx = 0;    // Index for the least recently used page
    int sum = 0;    // Total page faults

    cout << "\nOutput will be:\n";
    for (int i = 0; i < n; ++i) {
        int test = 0;
        for (int p = 0; p < page_fault; ++p) {
            c.push_back(m[p]);
        }

        for (int j = 0; j < page_fault; ++j) {
            if (re_string[i] == m[j]) {
                test = 1;
                total += 1;
                t[j] = total; // Update the time of last use
                break;
            }
        }

        if (test == 0) {
            idx = min_element(t.begin(), t.end()) - t.begin(); // Find the index of the least recently used frame
            m[idx] = re_string[i];
            total += 1;
            t[idx] = total; // Update the time of last use
            sum += 1; // Increment page fault count
        }

        if (c == m) {
            for (int q = 0; q < page_fault; ++q) {
                cout << "- ";
            }
        } else {
            for (int q = 0; q < page_fault; ++q) {
                if (m[q] == -1) {
                    cout << "- ";
                } else {
                    cout << m[q] << " ";
                }
            }
        }
        c.clear();
        cout << endl;
    }

    cout << "Page Fault: " << sum << endl;

    return 0;
}

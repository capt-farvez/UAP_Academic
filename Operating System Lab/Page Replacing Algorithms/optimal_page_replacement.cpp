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
    vector<int> c;  // Temporary vector for comparison
    vector<int> l;  // Temporary vector for storing indices
    int sum = 0;

    cout << "\nOutput will be:\n";
    for (int i = 0; i < n; ++i) {
        int test = 0;
        for (int p = 0; p < page_fault; ++p) {
            c.push_back(m[p]);
        }
        if (i < page_fault) {
            m[i] = re_string[i];
            sum += 1;
            re_string[i] = -99;
        } else {
            for (int j = 0; j < page_fault; ++j) {
                if (re_string[i] == m[j]) {
                    test = 1;
                    re_string[i] = -99;
                    break;
                }
            }
            if (test == 0) {
                for (int s = 0; s < page_fault; ++s) {
                    if (find(re_string.begin(), re_string.end(), m[s]) != re_string.end()) {
                        l.push_back(find(re_string.begin(), re_string.end(), m[s]) - re_string.begin());
                    } else {
                        l.push_back(999);
                    }
                }
                int idx = max_element(l.begin(), l.end()) - l.begin();
                m[idx] = re_string[i];
                sum += 1;
                re_string[i] = -99;
            }
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
        l.clear();
        cout << endl;
    }

    cout << "Page Fault: " << sum << endl;

    return 0;
}








// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // Input reference string as a single string
//     string reference_string;
//     cout << "Input reference string: ";
//     cin >> reference_string;
    
//     int string_size = reference_string.size();

//     // Vector to store individual digits of the reference string
//     vector<int> tasks;

//     // Extracting individual digits from the reference string and storing them in the tasks vector
//     for (int i = 0; i < string_size; i++) {
//         if (reference_string[i] != ',') {
//             tasks.push_back(reference_string[i] - '0'); // Convert char to int and store in tasks
//         }
//     }

//     // Input the total number of page frames
//     int page_frame;
//     cout << "Total number of page frame: ";
//     cin >> page_frame;

//     // Variable to store the number of page faults
//     int page_fault = 0;

//     // Vector to represent the page frame
//     vector<int> frame;

//     // Vector to store the index of each reference element in the reference string
//     vector<int> reference_index(10, -1); // Assuming reference string elements are in the range of 0 to 9

//     // Simulating page replacement using the Least Recently Used (LRU) algorithm
//     for (int i = 0; i < tasks.size(); i++) {
//         // If the current reference element is not in the page frame
//         if (reference_index[tasks[i]] == -1) {
//             // If there is space in the frame, add the current reference element
//             if (frame.size() < page_frame) {
//                 frame.push_back(tasks[i]);
//             } 
//             // If the frame is full, replace the least recently used element
//             else {
//                 int least_recently_used = INT_MAX;
//                 int replace_index = -1;
//                 // Find the index of the least recently used element in the frame
//                 for (int j = 0; j < frame.size(); j++) {
//                     if (reference_index[frame[j]] < least_recently_used) {
//                         least_recently_used = reference_index[frame[j]];
//                         replace_index = j;
//                     }
//                 }
//                 // Replace the least recently used element with the current reference element
//                 frame[replace_index] = tasks[i];
//             }
//             // Increment the page fault count
//             page_fault++;
//         }
//         // Update the index of the current reference element in the reference string
//         reference_index[tasks[i]] = i;
//     }

//     // Output the total number of page faults
//     cout << "Number of Page fault : " << page_fault << endl;

//     return 0;
// }


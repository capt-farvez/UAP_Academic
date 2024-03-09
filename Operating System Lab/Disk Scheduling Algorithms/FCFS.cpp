#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string input_queue;
    cout << "Enter the value for queue: ";
    getline(cin, input_queue);
    
    vector <int> queue_vec;
    
    int number = 0;
    bool readingNumber = false;
    for (char ch : input_queue) {
        if (ch == ',') {
            if (readingNumber) {
                queue_vec.push_back(number);
                number = 0;
                readingNumber = false;
            }
        } 
        else if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
            readingNumber = true;
        }
    }

    // Push the last number if there was no comma after it
    if (readingNumber) {
        queue_vec.push_back(number);
    }
    
    int head_start;
    cout << "Enter the head starts: ";
    cin >> head_start;
    
    vector<int> path;
    path.push_back(head_start);
    string distance_path;
    int distance_sum = 0;
    
    while (!queue_vec.empty()) {
        int x = queue_vec.front();
        queue_vec.erase(queue_vec.begin());
        path.push_back(x);
        if (x > head_start) {
            distance_path += "(" + to_string(x) + "-" + to_string(head_start) + ")";
            distance_sum += (x - head_start);
        } else {
            distance_path += "(" + to_string(head_start) + "-" + to_string(x) + ")";
            distance_sum += (head_start - x);
        }

        if (!queue_vec.empty())
            distance_path += " + ";

        head_start = x;
    }

    cout << "Path: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << ", ";
    }
    cout << endl;
    
    cout << "Total Distances: " << distance_path << endl;
    cout << "Illustration shows total head movement of " << distance_sum << " cylinders" << endl;

    return 0;
}

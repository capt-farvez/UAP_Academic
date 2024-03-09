#include <bits/stdc++.h>
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
    string total_distance;
    int distance_sum = 0;
    
    while (!queue_vec.empty()) {
        int mini = 99999;
        int index = 0;
        for (int i = 0; i < queue_vec.size(); ++i) {
            if (abs(head_start - queue_vec[i]) < mini) {
                mini = abs(head_start - queue_vec[i]);
                index = i;
            }
        }
        int x = queue_vec[index];
        queue_vec.erase(queue_vec.begin() + index);
        
        path.push_back(x);
        if (x > head_start) {
            total_distance += "(" + to_string(x) + "-" + to_string(head_start) + ")";
            distance_sum += (x - head_start);
        } else {
            total_distance += "(" + to_string(head_start) + "-" + to_string(x) + ")";
            distance_sum += (head_start - x);
        }

        if (!queue_vec.empty())
            total_distance += " + ";

        head_start = x;
    }

    cout << "Path: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << ", ";
    }
    cout << endl;
    
    cout << "Total Distances: " << total_distance << endl;
    cout << "Illustration shows total head movement of " << distance_sum << " cylinders" << endl;

    return 0;
}

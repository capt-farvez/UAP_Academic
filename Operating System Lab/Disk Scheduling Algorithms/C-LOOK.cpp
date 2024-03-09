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

    int lower_bound;
    cout << "Enter the lower bound: ";
    cin >> lower_bound;

    int upper_bound;
    cout << "Enter the upper bound: ";
    cin >> upper_bound;
    
    vector<int> path;
    path.push_back(head_start);
    string total_distance;
    int distance_sum = 0;
    vector<int> head_to_lower_bound;
    vector<int> head_to_upper_bound;

    for (int i = 0; i < queue_vec.size(); ++i) {
        int x = queue_vec[i];
        if (x < head_start) {
            head_to_lower_bound.push_back(x);
            queue_vec.erase(queue_vec.begin() + i);
            i--;
        } else if (x > head_start) {
            head_to_upper_bound.push_back(x);
            queue_vec.erase(queue_vec.begin() + i);
            i--;
        }
    }
    
    head_to_lower_bound.push_back(lower_bound);
    head_to_upper_bound.push_back(upper_bound);
    sort(head_to_lower_bound.begin(), head_to_lower_bound.end());
    sort(head_to_upper_bound.begin(), head_to_upper_bound.end());
    
    while (!head_to_lower_bound.empty() || !head_to_upper_bound.empty()) {
        int x = 0;
        if (!head_to_lower_bound.empty() && head_to_upper_bound.empty()) {
            x = head_to_lower_bound.front();
            head_to_lower_bound.erase(head_to_lower_bound.begin());
        }

        if (!head_to_upper_bound.empty()) {
            x = head_to_upper_bound.front();
            head_to_upper_bound.erase(head_to_upper_bound.begin());
        }

        if (x == lower_bound || x == upper_bound) {
            continue;
        }
        path.push_back(x);
        if (x > head_start) {
            total_distance += "(" + to_string(x) + "-" + to_string(head_start) + ")";
            distance_sum += (x - head_start);
        } else {
            total_distance += "(" + to_string(head_start) + "-" + to_string(x) + ")";
            distance_sum += (head_start - x);
        }

        if (!head_to_upper_bound.empty() || !head_to_lower_bound.empty())
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

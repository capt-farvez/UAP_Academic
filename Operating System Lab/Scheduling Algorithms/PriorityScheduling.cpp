#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<string, pair<int, int>>> processes;
    for (int i = 0; i < n; i++) {
        string process;
        int burstTime, priority;
        cin >> process >> burstTime >> priority;
        processes.push_back({process, {burstTime, priority}});
    }

    sort(processes.begin(), processes.end(),
         [](const auto& a, const auto& b) {
             return a.second.second < b.second.second;
         });

    string gantt_chart = "0";
    vector<int> waiting_time = {0};
    int burstTime_new = 0;

    for (int i = 0; i < n; ++i) {
        burstTime_new += processes[i].second.first;
        gantt_chart += " " + processes[i].first + " " + to_string(burstTime_new);
        if (i != n - 1) {
            waiting_time.push_back(burstTime_new);
        }
    }

    cout << "Chart is: "<< gantt_chart << endl;
    cout << "Average waiting time is: " << static_cast<double>(accumulate(waiting_time.begin(), waiting_time.end(), 0)) / n << " ms" << endl;

    return 0;
}
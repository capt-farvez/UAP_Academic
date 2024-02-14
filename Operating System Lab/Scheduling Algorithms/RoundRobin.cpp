#include <bits/stdc++.h>

using namespace std;

void findWaitingTime(int n, vector<int>& bt, vector<int>& wt, int qt) {
    vector<int> remaining_time = bt;

    int t = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false;

                if (remaining_time[i] > qt) {
                    t += qt;
                    remaining_time[i] -= qt;
                } else {
                    t += remaining_time[i];
                    wt[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> processes(n);
    vector<int> burst_time(n);

    for (int i = 0; i < n; i++) {
        cin >> processes[i] >> burst_time[i];
    }

    int quantam;
    cout << "Quantam = ";
    cin >> quantam;

    vector<int> waiting_time(n, 0);
    findWaitingTime(n, burst_time, waiting_time, quantam);

    cout << "Chart: ";
    int time = 0;
    string gantt_chart = "0";
    for (int i = 0; i < n; i++) {
        time += waiting_time[i];
          gantt_chart += " " + processes[i] + " " + to_string(time);
    }
    cout <<gantt_chart<< endl;

    double avg_waiting_time =(accumulate(waiting_time.begin(), waiting_time.end(), 0)) / n ;
    cout << "Average waiting time: " << avg_waiting_time << " ms" << endl;

    return 0;
}
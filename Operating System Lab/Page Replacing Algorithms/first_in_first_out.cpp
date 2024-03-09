#include <bits/stdc++.h>
using namespace std;

int main() {
    string reference_string;
    cout << "Input reference string: ";
    cin >> reference_string;
    //cout << reference_string << endl;

    int string_size = reference_string.size();

    vector <int> tasks;

    for(int i=0; i<string_size; i++){
        if(reference_string[i] != ','){
            tasks.push_back(reference_string[i]-'0');
        }
    }

    int page_frame;
    //cout << "Total number of page frame: ";
    cin >> page_frame;

    vector<string> memory(page_frame, "-");

    int i = 0;
    int page_fault = 0;
    for (int x : tasks) {
        if (i == page_frame) {
            i = 0;
        }
        auto task = find(memory.begin(), memory.end(), to_string(x));  // "task" will point to the position of the found element
        if (task != memory.end()) {         //If already in memory, then indicating a hit
            for(int j=0; j<page_frame; j++){
                cout<<"- ";
            }
            cout << endl;
        }
        else {
            page_fault++;
            memory[i] = to_string(x);
            i++;
            for (const auto& page : memory) {
                cout << page << " ";
            }
            cout << endl;
        }
    }

    cout << "Number of Page fault : " << page_fault << endl;

    return 0;
}

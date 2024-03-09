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
    cin >> int page_frame;;

    int page_fault = 0;



    cout << "Number of Page fault : " << page_fault << endl;

    return 0;
}

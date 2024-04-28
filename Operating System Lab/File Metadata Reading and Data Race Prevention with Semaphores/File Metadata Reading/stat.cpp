#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
using namespace std;

int main() {
    const char* filename = "test.cpp";
    struct stat fileStat;

    // Check if file exists
    if (stat(filename, &fileStat) != 0) {
        cerr << "Error: Unable to get file stats." << endl;
        return 1;
    }

    // File permissions
    cout << "File Permissions: ";
    cout << ((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    cout << ((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    cout << ((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    cout << ((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    cout << ((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    cout << ((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    cout << ((fileStat.st_mode & S_IROTH) ? "r" : "-");
    cout << ((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    cout << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    cout << std::endl;

    // File size
    cout << "File Size: " << fileStat.st_size << " bytes" << endl;

    // File creation time
    cout << "File Creation Time: " << ctime(&fileStat.st_ctime);

    // Last modification time
    cout << "Last Modification Time: " << ctime(&fileStat.st_mtime);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class SymbolTableEntry {
public:
    string name;
    string type;
    string size;
    string dimension;
    string line_of_code;
    string address;

    SymbolTableEntry(string name, string type, string size, string dimension, string line_of_code, string address) 
        : name(name), type(type), size(size), dimension(dimension), line_of_code(line_of_code), address(address) {}

    friend ostream& operator<<(ostream& os, const SymbolTableEntry& entry) {
        return os << "Name: " << entry.name << ", Type: " << entry.type << ", Size: " << entry.size
                  << ", Dimension: " << entry.dimension << ", Line of Code: " << entry.line_of_code
                  << ", Address: " << entry.address;
    }
};

class SymbolTable {
private:
    static const int TABLE_SIZE = 100;
    vector<vector<SymbolTableEntry>> table;

    int hashFunction(const string& name) const {
        int hashValue = 0;
        for (char c : name) {
            hashValue += static_cast<int>(c);
        }
        return hashValue % TABLE_SIZE;
    }

public:
    SymbolTable() : table(TABLE_SIZE) {}

    void insert(const SymbolTableEntry& entry) {
        int hashValue = hashFunction(entry.name);
        table[hashValue].push_back(entry);
    }

    SymbolTableEntry* search(const string& name) {
        int hashValue = hashFunction(name);
        vector<SymbolTableEntry>& entries = table[hashValue];
        for (SymbolTableEntry& entry : entries) {
            if (entry.name == name) {
                return &entry;
            }
        }
        return nullptr;
    }

    bool remove(const string& name) {
        int hashValue = hashFunction(name);
        vector<SymbolTableEntry>& entries = table[hashValue];
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->name == name) {
                entries.erase(it);
                return true;
            }
        }
        return false;
    }

    bool update(const string& name, const SymbolTableEntry& newEntry) {
        int hashValue = hashFunction(name);
        vector<SymbolTableEntry>& entries = table[hashValue];
        for (SymbolTableEntry& entry : entries) {
            if (entry.name == name) {
                entry = newEntry;
                return true;
            }
        }
        return false;
    }

    void showContents() const {
        for (const vector<SymbolTableEntry>& entries : table) {
            for (const SymbolTableEntry& entry : entries) {
                cout << entry << endl;
            }
        }
    }

    int getHashKey(const string& name) const {
        return hashFunction(name);
    }
};

int main() {
    SymbolTable symbolTable;

    SymbolTableEntry entry1("Milon", "Int", "3", "2", "5", "0x6dfed4");
    symbolTable.insert(entry1);

    SymbolTableEntry* result = symbolTable.search("Milon");
    if (result != nullptr) {
        cout << "Entry found:" << endl;
        cout << *result << endl;
    } else {
        cout << "Entry not found." << endl;
    }

    bool deleted = symbolTable.remove("Milon");
    if (deleted) {
        cout << "Entry deleted." << endl;
    } else {
        cout << "Entry not found." << endl;
    }

    symbolTable.insert(entry1);

    SymbolTableEntry entry2("Jahid", "Char", "2", "1", "5", "0x7ffdd8747");
    bool updated = symbolTable.update("Milon", entry2);
    if (updated) {
        cout << "Entry updated." << endl;
    } else {
        cout << "Entry not found." << endl;
    }

    symbolTable.showContents();

    int hashKey = symbolTable.getHashKey("Jahid");
    cout << "Hash key: " << hashKey << endl;

    return 0;
}
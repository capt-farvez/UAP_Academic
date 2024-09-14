#include <bits/stdc++.h>
using namespace std;

// C/C++ Keywords
string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

// check if a string is a keyword
bool isKeyword(const string &str){
    for (const auto &kw : keywords){
        if (str == kw)
            return true;
    }
    return false;
}

// check if a character is an operator
bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '>' || ch == '<' || ch == '=' || ch == '!');
}

// check if a character is a punctuation
bool isPunctuation(char ch){
    return (ch == ';' || ch == ':' || ch == ',');
}

// check if a character is a parenthesis
bool isParenthesis(char ch){
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

// check if a string is a valid identifier
bool isIdentifier(const string &str){
    if (!isalpha(str[0]) && str[0] != '_')
        return false;
    for (char ch : str){
        if (!isalnum(ch) && ch != '_')
            return false;
    }
    return true;
}

void tokenize(const string &code){
    unordered_set<string> identifiers;
    unordered_map<string, int> keywordCount, operatorCount, punctuationCount, parenthesisCount, constantCount;
    vector<string> logicalOperators = {">=", "<=", "==", "!="};

    string buffer = "";
    bool insideComment = false;

    for (size_t i = 0; i < code.length(); i++){
        char ch = code[i];

        // Skip comments
        if (ch == '/' && code[i + 1] == '/'){
            insideComment = true;
            i++;
            continue;
        }
        if (insideComment && ch == '\n'){
            insideComment = false;
            continue;
        }
        if (insideComment)
            continue;

        // Skip whitespaces
        if (isspace(ch)){
            if (!buffer.empty()){
                if (isKeyword(buffer)){
                    keywordCount[buffer]++;
                }
                else if (isdigit(buffer[0])){
                    constantCount[buffer]++;
                }
                else if (isIdentifier(buffer)){
                    identifiers.insert(buffer);
                }
                buffer.clear();
            }
            continue;
        }

        // Check if character is a single character operator or punctuation
        if (isOperator(ch)){
            if (!buffer.empty()){
                if (isKeyword(buffer)){
                    keywordCount[buffer]++;
                }
                else if (isdigit(buffer[0])){
                    constantCount[buffer]++;
                }
                else if (isIdentifier(buffer)){
                    identifiers.insert(buffer);
                }
                buffer.clear();
            }
            // Handle multi-character logical operators
            if (i < code.length() - 1 && (ch == '>' || ch == '<' || ch == '=' || ch == '!') && code[i + 1] == '='){
                string op = string(1, ch) + string(1, code[i + 1]);
                operatorCount[op]++;
                i++;
            }
            else{
                operatorCount[string(1, ch)]++;
            }
            continue;
        }

        // Check for parenthesis
        if (isParenthesis(ch)){
            if (!buffer.empty()){
                if (isKeyword(buffer)){
                    keywordCount[buffer]++;
                }
                else if (isdigit(buffer[0])){
                    constantCount[buffer]++;
                }
                else if (isIdentifier(buffer)){
                    identifiers.insert(buffer);
                }
                buffer.clear();
            }
            parenthesisCount[string(1, ch)]++;
            continue;
        }

        // Check for punctuation
        if (isPunctuation(ch)){
            if (!buffer.empty()){
                if (isKeyword(buffer)){
                    keywordCount[buffer]++;
                }
                else if (isdigit(buffer[0])){
                    constantCount[buffer]++;
                }
                else if (isIdentifier(buffer)){
                    identifiers.insert(buffer);
                }
                buffer.clear();
            }
            punctuationCount[string(1, ch)]++;
            continue;
        }

        buffer += ch;
    }

    // Output tokens
    cout << "Keywords: " << keywordCount.size() << endl;
    for (const auto &entry : keywordCount){
        cout << entry.first << " ";
    }
    cout << endl;

    cout << "Identifiers: " << identifiers.size() << endl;
    for (const auto &id : identifiers){
        cout << id << " ";
    }
    cout << endl;

    cout << "Operators: " << operatorCount.size() << endl;
    for (const auto &op : operatorCount){
        cout << op.first << " ";
    }
    cout << endl;

    cout << "Constants: " << constantCount.size() << endl;
    for (const auto &c : constantCount){
        cout << c.first << " ";
    }
    cout << endl;

    cout << "Punctuation: " << punctuationCount.size() << endl;
    for (const auto &p : punctuationCount){
        cout << p.first << " ";
    }
    cout << endl;

    cout << "Parenthesis: " << parenthesisCount.size() << endl;
    for (const auto &paren : parenthesisCount){
        cout << paren.first << " ";
    }
    cout << endl;
}

int main(){
    string code;
    string line;
    cout << "Enter the code:" << endl;

    while (getline(cin, line)){
        if (line.empty()){
            break;
        }
        code += line + "\n";
    }

    tokenize(code);

    return 0;
}

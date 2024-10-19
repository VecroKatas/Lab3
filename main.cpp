#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> keywords = {
        "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const", "continue",
        "default", "do", "double", "else", "enum", "extends", "final", "finally", "float", "for", "goto", "if",
        "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "package", "private",
        "protected", "public", "return", "short", "static", "strictfp", "super", "switch", "synchronized",
        "this", "throw", "throws", "transient", "try", "void", "volatile", "while", "true", "false", "null"
};

unordered_set<string> operators = {
        "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "=", "+=", "-=", "*=", "/="
};

unordered_set<char> delimiters = {
        '(', ')', '{', '}', '[', ']', ';', ',', '.'
};

string ClassifyToken(string &token) {
    static bool inMultilineComment = false;

    if (inMultilineComment) {
        size_t endCommentPos = token.find("*/");
        if (endCommentPos != std::string::npos) {
            inMultilineComment = false;
        }
        return "Multiline comment";
    } else {
        size_t startCommentPos = token.find("/*");
        if (startCommentPos != std::string::npos) {
            inMultilineComment = true;
            size_t endCommentPos = token.find("*/");
            if (endCommentPos != std::string::npos) {
                inMultilineComment = false;
            }
            return "Multiline comment";
        } else {
            if (regex_match(token, regex("//.*"))) {
                return "Inline comment";
            }

            if (regex_match(token, regex("\".*\""))) {
                return "String Literal";
            } else if (regex_match(token, regex("'.'"))) {
                return "Character Literal";
            }

            if (regex_match(token, regex("[0-9]+"))) {
                return "Integer";
            } else if (regex_match(token, regex("[0-9]*\\.[0-9]+"))) {
                return "Float";
            } else if (regex_match(token, regex("0[xX][0-9a-fA-F]+"))) {
                return "Hexadecimal";
            }

            if (keywords.find(token) != keywords.end()) {
                return "Keyword";
            }

            if (operators.find(token) != operators.end()) {
                return "Operator";
            }

            if (token.length() == 1 && delimiters.find(token[0]) != delimiters.end()) {
                return "Delimiter";
            }

            if (regex_match(token, regex("[a-zA-Z_][a-zA-Z0-9_]*"))) {
                return "Identifier";
            }

            return "Unknown";
        }
    }
}

void LexicalAnalysis(string &inputFileName, string &outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }

    string line;
    regex tokenRegex("/\\*|\\*/|//.*|\".*?\"|'.'|[a-zA-Z_][a-zA-Z0-9_]*|[0-9]*\\.[0-9]+|[0-9]+|0[xX][0-9a-fA-F]+|[+\\-*/%=!&|<>]=?|[(){},.;]");
    while (getline(inputFile, line)) {
        auto tokensBegin = sregex_iterator(line.begin(), line.end(), tokenRegex);
        auto tokensEnd = sregex_iterator();

        for (sregex_iterator it = tokensBegin; it != tokensEnd; it++) {
            string token = it->str();
            outputFile << ClassifyToken(token) << ":\t" << token << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFileName1 = R"(D:\Homeworks\sp\Lab3\Input\input1.java)";
    string inputFileName2 = R"(D:\Homeworks\sp\Lab3\Input\input2.java)";
    string inputFileName3 = R"(D:\Homeworks\sp\Lab3\Input\input3.java)";
    string outputFileName1 = R"(D:\Homeworks\sp\Lab3\Output\output1.txt)";
    string outputFileName2 = R"(D:\Homeworks\sp\Lab3\Output\output2.txt)";
    string outputFileName3 = R"(D:\Homeworks\sp\Lab3\Output\output3.txt)";

    LexicalAnalysis(inputFileName1, outputFileName1);
    LexicalAnalysis(inputFileName2, outputFileName2);
    LexicalAnalysis(inputFileName3, outputFileName3);

    return 0;
}
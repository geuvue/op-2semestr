#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void changeFile(string);   //доповнення файла
void findWord(string, string); //знаходження найбільшого слова у реченні, розділення рядків на речення.
void outChangedFile(string, string, string); //створення другого файлу, та заповнення його найбільшими словами та реченями.
bool showFile(string); //демонстрація вмісту файла

int main()
{
    string inPath, outPath;
    cout << "Enter file path 1: ";
    getline(cin, inPath);
    if (showFile(inPath)) {
        char agree;
        cout << "Do you want change the text(y/n)? ";
        cin >> agree;
        cin.ignore();
        if (agree == 'y') {
            changeFile(inPath);
        }
        else if (agree !='n'){
            cout << "It's not 'n' or 'y'...\n";
        }
    }
    cout << "Enter file path 2: ";
    getline(cin, outPath);
    if (showFile(outPath)) {
        findWord(inPath, outPath);
        cout << "Changes saved.\n";
        showFile(outPath);
    }
    return 0;
}

void changeFile(string path) {
    string row;
    ofstream fOut(path, ios::app);
    cout << "Enter text:\n";
    while (true) {
        getline(cin, row);
        for (int i = 0; i < row.size(); i++) {
            if (int(row[i]) > 31  || (int(row[i]) == 10)) {
                fOut << row[i];
            }
            else if (i == 0) {
                return;
            }
            else {
                fOut << endl;
                return;
            }
        }
        fOut << endl;
    }
}

void findWord(string path, string outPath) {
    ifstream fIn(path);
    string line, maxWord, word, sentence;
    int lenWord(0), maxLen(0);
    while (!fIn.eof()) {
        getline(fIn, line);
        for (int i = 0; i < line.size(); i++) {
            sentence += line[i];
            if (isupper(line[i]) || (islower(line[i]) || isalpha(line[i]))) {
                lenWord++;
                word += line[i];
            }
            else {
                if (lenWord > maxLen) {
                    maxLen = lenWord;
                    maxWord = word;
                }
                if (line[i] == '.') {
                    outChangedFile(maxWord, sentence, outPath);
                    sentence = "";
                    maxLen = 0;
                    maxWord = "";
                }
                lenWord = 0;
                word = "";
            }
        }
    }
}

void outChangedFile(string word, string line, string path) {
    ofstream fOut(path, ios::app);
    if (line[0] == ' ') {
        line = line.erase(0, 1);
    }
    fOut << word.size() << ' ' + word + " | " << line << "\n";
    fOut.close();
}

bool showFile(string path) {
    ofstream outFile(path, ios::app);
    if (!outFile.is_open()) {
        cout << "Can't open this file...\n";
        return false;
    }
    outFile.close();
    ifstream inFile(path, ios::ate);
    inFile.seekg(0, ios::end);
    string row;
    if (inFile.tellg() == 0) {
        cout << "\nFile is empty.\n";
    }
    else {
        inFile.clear();
        inFile.seekg(0, ios::beg);
        cout << "\nFile contain:\n";
        while (!inFile.eof()) {
            getline(inFile, row);
            cout << row << endl;
        }
    }
    inFile.close();
    return true;
}


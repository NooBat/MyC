#include<bits/stdc++.h>

using namespace std;

int main() {
    string pathName = "StudyInPink2INP.txt";
    string destName = "Input/input";

    ifstream file(pathName);

    if (file.is_open()) {
        string instruction;
        int numberOfLine = 1;
        int numberOfFile = 0;
        bool newFile = false;

        while (getline(file, instruction)) {
            if (instruction == "") {
                continue;
            } else if (instruction[0] == 'T') {
                numberOfFile++;
                newFile = true;
                continue;
            } else {
                ofstream output;
                if (newFile) {
                    output.open(destName + to_string(numberOfFile) + ".txt", ofstream::trunc);
                    output.close();
                    newFile = false;
                }
                output.open(destName + to_string(numberOfFile) + ".txt", ios_base::app);
                if (output.is_open()) {
                    output << instruction << endl;
                    output.flush();
                } else {
                    cout << "Cannot open file" << endl;
                }
                output.close();
            }
            numberOfLine++;
        }
    }
}
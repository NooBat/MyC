<<<<<<< HEAD
/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink.h"
using namespace std;

int readFile(string filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3) {
//This function is used to read the input file,
//DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> HP1 >> HP2;
        myfile >> EXP1 >> EXP2;
        myfile >> M1 >> M2;
        myfile >> E1 >> E2 >> E3;
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    string filename = "input.txt";
    int HP1 = -1, HP2 = -1;
    int EXP1 = -1, EXP2 = -1;
    int M1 = -1, M2 = -1;
    int E1 = -1, E2 = -1, E3 = -1;
    bool isRead = readFile(filename, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3);
    if (isRead){
        //Task 1
        cout << firstMeet(EXP1, EXP2, E1) << endl;
        cout << EXP1 << " "<< EXP2 << endl;
        //Task 2
        cout << investigateScene(EXP1, EXP2, HP2, M2, E2)<< endl;
        cout << EXP1 << " "<< EXP2 << " " << HP2 << " " << M2 << endl;
        //Task 3
        cout << traceLuggage(HP1, EXP1, M1, E3)<< endl;
        cout << HP1 << " "<< EXP1 << " " << M1 << endl;
    }
    else{
        cout << "Cannot read input file";
    }
    return 0;
}
=======
/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink.h"
using namespace std;

int readFile(string filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3) {
//This function is used to read the input file,
//DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> HP1 >> HP2;
        myfile >> EXP1 >> EXP2;
        myfile >> M1 >> M2;
        myfile >> E1 >> E2 >> E3;
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 1; i++) {
        string filename = "Input/input" + to_string(i) + ".txt";
        string destination = "Output/output" + to_string(i) + ".txt";

        ofstream output;

        output.open(destination, ofstream::trunc);
    
        output.close();

        output.open(destination, ios_base::app);

        int HP1 = -1, HP2 = -1;
        int EXP1 = -1, EXP2 = -1;
        int M1 = -1, M2 = -1;
        int E1 = -1, E2 = -1, E3 = -1;
        bool isRead = readFile(filename, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3);

        if (isRead){
            //Task 1
            output << "Testcase output #" << i << ": " << endl;
            output << "Task 1: " << endl;
            output << "Sum of EXP1 and EXP2 is (if E1 is not in range [0; 999] then print -999): " << firstMeet(EXP1, EXP2, E1) << " " << endl;
            output << "EXP1 = " << EXP1 << ", EXP2 = "<< EXP2 << " " << endl;
            //Task 2
            output << "Task 2: " << endl;
            output << "Sum of EXP1, EXP2, HP2, M2 is (if E2 is not in range [0; 999] then print -999): " << investigateScene(EXP1, EXP2, HP2, M2, E2) << " " << endl;
            output << "EXP1 = " << EXP1 << ", EXP2 = "<< EXP2 << ", HP2 = " << HP2 << ", M2 = " << M2 << " " << endl;
            //Task 3
            output << "Task 3: " << endl;
            output << "Sum of EXP1, HP1, M1 is (if E3 is not in range [0; 999] then print -999): " << traceLuggage(HP1, EXP1, M1, E3) << " " << endl;
            output << "HP1 = " << HP1 << ", EXP1 = " << EXP1 << ", M1 = " << M1 << " " << endl;
            output.flush();
            output.close();
        }
        else{
            cout << "Cannot read input file";
        }

        ifstream testOutput("StudyInPink1OUT.txt");
        ifstream realOutput;
        realOutput.open(destination);

        if (testOutput.is_open()) {
            string inputString;
            string outputString;
            int lineNumber = 1;
            while (getline(testOutput, inputString) && getline(realOutput, outputString)) {
                if (lineNumber < (i - 1) * 11 + 1) {
                    continue;
                } else {
                    if (inputString == "") {
                        continue;
                    } else {
                        for (int j = 0; j < outputString.length(); j++) {
                            if (inputString[j] < '0' || inputString[j] > 'z') {
                                break;
                            } else {
                                if (inputString[j] != outputString[j]) {
                                    cout << "Difference in Output/output" << i << ".txt" << endl;
                                    
                                    break;
                                }
                            }
                        }
                    }
                }
                lineNumber++;
            }
        }
    }
    return 0;
}
>>>>>>> main

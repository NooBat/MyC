#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

//Task 1
void process(const char* name, char* outstr) {
    bool blank = true;

    int idx = 0;

    for (int i = 0; i < strlen(name); i++) {
        if ( (name[i] >= 'a' && name[i] <= 'z') || 
             (name[i] >= 'A' && name[i] <= 'Z') ) {
            if (blank) {
                if (name[i] >= 'a' && name[i] <= 'z') {
                    outstr[idx] = name[i] - 32;
                } else {
                    outstr[idx] = name[i];
                }
            } else {
                if (name[i] >= 'a' && name[i] <= 'z') {
                    outstr[idx] = name[i];
                } else {
                    outstr[idx] = name[i] + 32;
                }
            }

            blank = false;
            idx++;
        }
        else if (name[i] == ' ') {
            if (!blank) {
                outstr[idx++] = ' ';
            }
            blank = true;
        }
    }

    outstr[idx] = '\0';
}

//Task 2
void printFirstRepeatedWord(char str[]) {
    int n = strlen(str);
    char words[n][n];

    int rowIdx = 0;
    int colIdx = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') {
            if (colIdx == 0) {
                continue;
            } else {
                words[rowIdx][colIdx] = '\0';
                rowIdx++;
                colIdx = 0;
            }
        } else {
            words[rowIdx][colIdx++] = str[i];
        }
    }

    for (int i = rowIdx + 1; i < n; i++) {
        words[i][colIdx] = '\0';
    }

    for (int i = 0; i <= rowIdx; i++) {
        for (int j = 0; j <= rowIdx; j++) {
            if (j == i) continue;
            else {
                if (strlen(words[i]) == strlen(words[j])) {
                    bool isRepeat = false;
                    for (int idx = 0; idx < strlen(words[i]); idx++) {
                        if (words[i][idx] == words[j][idx]) {
                            isRepeat = true;
                        } else {
                            isRepeat = false;
                            break;
                        }
                    }

                    if (isRepeat) {
                        cout << words[i];
                        return;
                    }
                }
            } 
        }
    }

    cout << "No Repetition";
}

//Task 3
void replaceString(string s, string s1, string s2) {
    int next = 0;
    int curr = -1;
    do {
        next = s.find(s1, next);
        if (next != -1) {
            curr = next;
            next = curr + 1;
        }

    } while (next != -1);

    if (curr != -1) {
        s.replace(curr, s1.length(), s2);
    }

    cout << s;
}

//Task 4
void deleteWord(string s, string s1) {
    while (s.find(s1) != -1) {
        s.replace(s.find(s1), s1.length(), "");
    }

    cout << s;
}

//Task 5
// int main() {
//     string s;
    
//     getline(cin, s);

//     int count = 1;
//     int max = 1;

//     for (int i = 1; i < s.length(); i++) {
//         if (s[i - 1] == s[i]) {
//             count++;
//         } else {
//             if (count > max) {
//                 max = count;
//             }
//             count = 1;
//         }
//     }

//     cout << ((count > max) ? (count) : (max));
// }

//Task 6
int ascendingRows(int arr[][1000], int row, int col) {
    int result = 0;
    for (int i = 0; i < row; i++) {
        int isHN = false;
        for (int j = 1; j < col; j++) {
            if (arr[i][j - 1] <= arr[i][j]) {
                isHN = true;
            } else {
                isHN = false;
                break;
            }
        }
        
        if (isHN) {
            result++;
        }
    }
    
    return result;
}

//Task 7
bool isPrime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int primeColumns(int arr[][1000], int row, int col) {
    int result = 0;
    for (int i = 0; i < col; i++) {
        int sum = 0;
        for (int j = 0; j < row; j++) {
            sum += arr[j][i];
        }
        
        if (isPrime(sum)) result++;
    }
    
    return result;
}

//Task 8
void uppercase(string output) {
    string s;
    
    getline(cin, s);
    
    ofstream file;
    file.open(output);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
    
    file << s;
}

//Task 9
void threeChars(string fileName)   {
    ifstream file;
    file.open(fileName);
    
    string line;
    while (getline(file, line)) {
        if (line == "***") {
            break;
        } else {
            if (line[0] <= line[1] && line[1] <= line[2]) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }
}

//Task 10
void process(string fileName)   {
    ifstream file;
    file.open(fileName);
    
    int n, m;
    
    file >> n >> m;
    
    float arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = -10000000000000;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            float num;
            file >> num;
            
            if (num > arr[i]) {
                arr[i] = num;
            }
        }
    }
    
    float max = arr[0];
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    cout << max;
}

int main() {
    char str[] = "football voleyball badminton footballl tennis";
    printFirstRepeatedWord(str);
}
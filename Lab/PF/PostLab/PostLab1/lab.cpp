#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//[Q2.3]
bool isSymmetric(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

// int main()  {
//     string s;
//     getline(cin, s);
    
//     int lengthOfSubstr = s.length();
//     bool done = false;
//     while (!done && lengthOfSubstr > 0) {
//         int i = 0;
//         while (i <= s.length() - lengthOfSubstr) {
//             string str = s.substr(i, lengthOfSubstr);
//             if (isSymmetric(str)) {
//                 cout << str;
//                 done = true;
//                 break;
//             } 
//             i++;
//         }
//         lengthOfSubstr--;
//     }
//     if (!done) cout << s;
//     return 0;
// }



//Q[2.2]
bool isNoRepetition(string s) {
    for (int i = 1; i < s.length(); i++) {
        string substr = s.substr(0, i);
        int foundIndex = substr.find(s[i]);
        
        if (foundIndex > -1 && foundIndex < i) {
            return false;
        }
    }
    
    return true;
}

// int main()  {
//     string s;
//     getline(cin, s);
    
//     int count = 1;
//     int max = 0;
//     bool done = false;
    
//     for (int lengthOfSubstr = s.length(); lengthOfSubstr > 0 && !done; lengthOfSubstr--) {
//         for (int i = 0; i <= s.length() - lengthOfSubstr; i++) {
//             string substr = s.substr(i, lengthOfSubstr);
//             if(isNoRepetition(substr)) {
//                 if (substr.length() > max) {
//                     max = substr.length();
//                     done = true;
//                 }
//             }
//         }
//     }
//     cout << max;
    
//     return 0;
// }



//[Q3.6]
bool isPrime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int sumOfRow(int arr[][1000], int rowIdx, int col) {
    int sum = 0;
    
    for (int i = 0; i < col; i++) {
        sum += arr[rowIdx][i];
    }
    
    return sum;
}

int sumOfCol(int arr[][1000], int row, int colIdx) {
    int sum = 0;
    
    for (int i = 0; i < row; i++) {
        sum += arr[i][colIdx];
    }
    
    return sum;
}

int specialCells(int arr[][1000], int row, int col) {
    int numberOfCells = 0;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int sumRow = sumOfRow(arr, i, col);
            int sumCol = sumOfCol(arr, row, j);
            
            if (isPrime(sumRow) && isPrime(sumCol)) {
                numberOfCells++;
            }
        }
    }
    
    return numberOfCells;
}



//[Q3.8]
int subMatrix(int arr[][1000], int row, int col) {
    int numberOfSubarr = 0;
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            int sum = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i - 1][j - 1];
            if (sum % 2 != 0) {
                numberOfSubarr++;
            }
        }
    }
    
    return numberOfSubarr;
}



//[Q4.5]
void studentGrading(string fileName)   {
    // TODO
    ifstream file;
    file.open(fileName);
    
    int n;
    file >> n;
    
    double avgGrade[n];
    bool underFive[n];
    int numberOfStudents[4] = { 0 };
    
    for (int i = 0; i < n; i++) {
        avgGrade[i] = 0;
        underFive[i] = false;
        for (int j = 0; j < 4; j++) {
            double num;
            file >> num;
            
            if (num < 5) {
                underFive[i] = true;
            }
            
            avgGrade[i] += num;
        }
        avgGrade[i] /= 4.0;
        
        if (avgGrade[i] >= 8 && !underFive[i]) {
            numberOfStudents[0]++;
        } else if (avgGrade[i] >= 6.5 && !underFive[i]) {
            numberOfStudents[1]++;
        } else if (avgGrade[i] >= 5 && !underFive[i]) {
            numberOfStudents[2]++;
        } else {
            numberOfStudents[3]++;
        }
    }
    
    char arr[4] = {'A', 'B', 'C', 'D'};
    
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " " << numberOfStudents[i] << endl;
    }
}



//[Q4.6]
void segmentString(string s, string buyersID[], int buyersList[][100], int itemsID[], int itemsPrice[], int id, int numberOfItems) {
    s = s + " ";
    buyersID[id] = s.substr(0, s.find(" "));
    s = s.replace(0, buyersID[id].length() + 1, "");
    while (s.length() > 0) {
        string s1 = s.substr(0, s.find(" "));
        int itemID = stoi(s1);
        s = s.replace(0, s1.length() + 1, "");
        string s2 = s.substr(0, s.find(" "));
        int number = stoi(s2);
        s = s.replace(0, s2.length() + 1, "");
        for (int j = 0; j < numberOfItems; j++) {
            if (itemID == itemsID[j]) {
                buyersList[id][j] = number * itemsPrice[j];
            } 
        }
    }
}

void calMoney(string price, string buy) {
    ifstream priceList, buyList;
    priceList.open(price);
    buyList.open(buy);
    
    int numberOfItems;
    
    priceList >> numberOfItems;
    
    int itemsList[2][numberOfItems];

    for (int i = 0; i < numberOfItems; i++) {
        priceList >> itemsList[0][i] >> itemsList[1][i];
    }
    
    int numberOfBuyers;
    buyList >> numberOfBuyers;
    buyList.ignore();
    
    string buyersID[numberOfBuyers];
    int buyersList[numberOfBuyers][100];
    
    for (int i = 0; i < numberOfBuyers; i++) {
        for (int j = 0; j < numberOfItems; j++) {
            buyersList[i][j] = 0;
        }
    }
    
    string line;
    int id = 0;
    while (getline(buyList >> ws, line)) {
        segmentString(line, buyersID, buyersList, itemsList[0], itemsList[1], id, numberOfItems);
        id++;
    }
    
    for (int i = 0; i < numberOfBuyers; i++) {
        int sum = 0;
        for (int j = 0; j < numberOfItems; j++) {
            sum += buyersList[i][j];
        }
        cout << buyersID[i] << " " << sum << endl;
    }
}


//[Q4.7]
class Library {
private:
    string name;
    int booksID[5];
public:
    Library() {
        
    }
    
    Library(const string& name, int booksID[]) {
        setName(name);
        setBooksID(booksID);
    }
    
    void setName(const string& libName) {
        name = libName;
    }
    
    void setBooksID(int id[]) {
        for (int i = 0; i < 5; i++) {
            booksID[i] = id[i];
        }
    }
    
    string getName() const {
        return name;
    }
    
    int getBooksID(int index) const {
        if (index < 0 || index >= 5) return 0;
        return booksID[index];
    }
    
    bool findBook(int id) const {
        for (int i = 0; i < 5; i++) {
            if (id == booksID[i]) {
                return true;
            }
        }
        
        return false;
    }
};

class Book {
private:
    int id;
    int year;
    string category;
public: 
    Book() {
        
    }
    
    Book(const int& id, const int& year, const string& category) {
        setID(id);
        setYear(year);
        setCategory(category);
    }
    
    void setID(const int& bookID) {
        id = bookID;
    }
    
    void setYear(const int& publishYear) {
        this->year = publishYear;
    }
    
    void setCategory(const string& category) {
        this->category = category;
    }
    
    int getID() const {
        return id;
    }
    
    int getYear() const {
        return year;
    }
    
    string getCategory() const {
        return category;
    }
};

class Author {
private:
    string name;
    int numberOfBooks;
    int id[10000];
    
public:
    Author() {
        
    }
    
    Author(const string& name, int id[], int numberOfBooks) {
        setName(name);
        setID(id, numberOfBooks);
    }
    
    void setName(const string& name) {
        this->name = name;
    }
    
    void setID(int id[], int numberOfBooks) {
        this->numberOfBooks = numberOfBooks;
        for (int i = 0; i < numberOfBooks; i++) {
            this->id[i] = id[i];
        }
    }
    
    string getName() const {
        return name;
    }
    
    int getID(int index) const {
        if (index < 0 || index >= numberOfBooks) return 0;
        
        return id[index];
    }
    
    int getNumberOfBooks() const {
        return numberOfBooks;
    }
};

void stringSegmentation(string s, string& name, int& numberOfBooks, int id[]) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            numberOfBooks++;
        }
    }
    
    s = s + " ";
    
    name = s.substr(0, s.find(" "));
    s.replace(0, name.length() + 1, "");
    
    for (int i = 0; i < numberOfBooks; i++) {
        string bookID = s.substr(0, s.find(" "));
        id[i] = stoi(bookID);
        s.replace(0, bookID.length() + 1, "");
    }
}

void manage(string library, string book, string author){
    ifstream libFile, bookFile, authorFile;
    
    libFile.open(library);
    bookFile.open(book);
    authorFile.open(author);
    
    //processing library.txt
    int numberOfLibraries;
    
    libFile >> numberOfLibraries;
    
    Library libList[numberOfLibraries];
    
    for (int i = 0; i < numberOfLibraries; i++) {
        string name;
        int id[5];
        libFile >> name >> id[0] >> id[1] >> id[2] >> id[3] >> id[4];
        libList[i] = Library(name, id);
    }
    
    //processing book.txt
    int numberOfBooks;
    
    bookFile >> numberOfBooks;
    
    Book bookList[numberOfBooks];
    
    for (int i = 0; i < numberOfBooks; i++) {
        int id;
        int year;
        string category;
        bookFile >> id >> year >> category;
        
        bookList[i] = Book(id, year, category);
    }
    
    //processing author.txt
    int numberOfAuthors;
    
    authorFile >> numberOfAuthors;
    
    Author authorList[numberOfAuthors];
    
    for (int i = 0; i < numberOfAuthors; i++) {
        string line;
        getline(authorFile >> ws, line);
        string name;
        int idWritten[100];
        int booksWritten = 0;
        
        stringSegmentation(line, name, booksWritten, idWritten);
        
        authorList[i] = Author(name, idWritten, booksWritten);
    }
    
    string libName;
    string authorName;
    bool found = false;
    
    cin >> libName >> authorName;
    
    for (int i = 0; i < numberOfLibraries; i++) {
        if (libList[i].getName() == libName) {
            for (int j = 0; j < numberOfAuthors; j++) {
                if (authorList[j].getName() == authorName) {
                    for (int k = 0; k < authorList[j].getNumberOfBooks(); k++) {
                        if (libList[i].findBook(authorList[j].getID(k))) {
                            found = true;
                        }
                    }
                }
            }
        }
    }
    
    cout << ((found) ? ("True") : ("False")); 
}

#ifndef _FILE_READER
#define _FILE_READER

#include<string>
#include<fstream>
#include<vector>
#include<utility>

using namespace std;

class FileReader {
private:
    ifstream myfile;

public:
    FileReader();

    FileReader(const string& filename);

    vector<string> getName() const;

    pair<string, string> getNamePair() const;
};

FileReader::FileReader() {

}

FileReader::FileReader(const string& filename) {
    ifstream myfile(filename);
}

vector<string> FileReader::getName() const {
    vector<string> result;

    if (myfile.is_open()) {
        string temp;
        while (getline(myfile, temp)) {
            
        }
    }
}

#endif
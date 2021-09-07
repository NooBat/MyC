#ifndef _FILE_READER
#define _FILE_READER

#include<string>
#include<fstream>
#include<vector>
#include<utility>

using namespace std;

class FileReader {
public:
    FileReader();

    vector<string> getName() const;

    vector< pair<string, string> > getNamePair() const;
};

FileReader::FileReader() {

}

vector<string> FileReader::getName() const {
    vector<string> result;
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C6/Ex11/cityFile.txt";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string temp;
        while (getline(myfile, temp)) {
            result.push_back(temp);
        }
        temp.clear();
    }

    return result;
}

vector< pair<string, string> > FileReader::getNamePair() const {
    vector< pair<string, string> > result;
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C6/Ex11/flightFile.txt";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string temp;
        while (getline(myfile, temp)) {
            int i;
            for (i = 0; i < temp.length(); i++) {
                if (temp[i] == ',') break;
            }

            string first = temp.substr(0, i);
            string second = temp.substr(i + 2, temp.length() - first.length() - 2);

            pair<string, string> newPair(first, second);

            result.push_back(newPair);
        }
    }

    return result;
}
#endif
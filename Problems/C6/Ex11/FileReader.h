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

    vector< vector<string> > getNamePair() const;
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

vector< vector<string> > FileReader::getNamePair() const {
    vector< vector<string> > result;
    string filename = "/Users/danielnguyen/Repo/C++/Problems/C6/Ex11/flightFile.txt";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string temp;
        while (getline(myfile, temp)) {
            int i;
            vector<string> v;
            for (i = 0; i < temp.length(); i++) {
                if (temp[i] == ',') break;
            }

            string firstCity = temp.substr(0, i);
            v.push_back(firstCity);

            i = (int)temp.find("  ");

            string secondCity = temp.substr(firstCity.length() + 2, i - firstCity.length() - 2);
            v.push_back(secondCity);

            for (; i < temp.length(); i++) {
                if (temp[i] != ' ') break;
            }

            string flightName = temp.substr(i, 3);
            v.push_back(flightName);

            i = i + 8;

            string price = temp.substr(i, 3);
            v.push_back(price);
            result.push_back(v);
        }
    }

    return result;
}
#endif
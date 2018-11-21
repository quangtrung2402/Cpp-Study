#ifndef READER_H
#define READER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Reader:public ifstream
{
public:
    explicit Reader(string filePath);
    ~Reader();

    string getFilePath();

private:
    string *mFilePath;
};

#endif // READER_H

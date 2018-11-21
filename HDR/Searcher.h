#ifndef SEARCHER_H
#define SEARCHER_H

#include <vector>
#include <regex>
#include "Reader.h"

using namespace std;

class Searcher
{
public:
    explicit Searcher(string filePath, vector<string> searchList, string reportPath);
    ~Searcher();
    bool search();

private:
    bool compareTarget();
    void createRegex();

private:
    Reader *mReader;
    vector<string> *mSearchList;
    string *mCurrentLine;
    string *mReportPath;
    regex *re;
};

#endif // SEARCHER_H

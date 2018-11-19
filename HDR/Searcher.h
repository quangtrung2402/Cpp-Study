#ifndef SEARCHER_H
#define SEARCHER_H

#include "Reader.h"
#include "SearchingWord.h"

class Searcher
{
public:
    explicit Searcher(string filePath, vector<string> searchList);
    bool search();

private:
    string *mCurrentLine;
    ifstream *mCurrentFile;
    vector<string> *mSearchList;
};

#endif // SEARCHER_H

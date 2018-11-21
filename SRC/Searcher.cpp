#include "HDR/Searcher.h"

Searcher::Searcher(string filePath, vector<string> searchList, string reportPath):
    mReader(new Reader(filePath)),
    mSearchList(new vector<string>(searchList)),
    mReportPath(new string(reportPath)),
    mCurrentLine(new string()),
    re(nullptr)
{
    createRegex();
}

Searcher::~Searcher()
{
    if(mReader){
        mReader->close();
        delete mReader;
        mReader = nullptr;
    }
    if(mSearchList){
        mSearchList->clear();
        delete mSearchList;
        mSearchList = nullptr;
    }
    if(mReportPath){
        mReportPath->clear();
        delete mReportPath;
        mReportPath = nullptr;
    }
}

bool Searcher::search()
{
    bool result = false;
    if (mReader->is_open())
    {
        while ( mReader->good() )
        {
            getline (*mReader, *mCurrentLine);
            compareTarget();
        }
        mReader->close();
        result = true;
    }
    else {
        //Cannot open file ==> cannot find ==> not include searching word
    }
    return result;
}

bool Searcher::compareTarget()
{
//    for(int )
}

void Searcher::createRegex()
{
    string pattern = "\\s(";
    foreach (string str, mSearchList) {
        pattern += str;
        pattern += "|";
    }
    pattern += ")\\s";

    cout << "@@@@ pattern: " << pattern << endl;
    re = new regex(pattern);
}

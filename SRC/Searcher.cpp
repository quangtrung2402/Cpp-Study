#include "HDR/Searcher.h"

Searcher::Searcher(string filePath, vector<string> searchList)
{
    cout << "Searcher::Searcher(string filePath)" << endl;
    mCurrentFile = new ifstream(filePath);
    mCurrentLine = new string();
    mSearchList = new vector<string>(searchList);
}

bool Searcher::search()
{
    bool result = false;
    //TODO: search word list in the current file of Reader
    if (mCurrentFile->is_open())
    {
        while ( mCurrentFile->good() )
        {
            getline (*mCurrentFile, *mCurrentLine);
            cout << *mCurrentLine << endl;
        }
        mCurrentFile->close();
        result = true;
    }
    else {
        //Cannot open file ==> cannot find ==> not include searching word
    }


    return result;
}

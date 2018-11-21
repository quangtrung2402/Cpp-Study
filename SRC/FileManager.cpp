#include "HDR/FileManager.h"
#include "HDR/Utility.h"

FileManager::FileManager(int argc, char **argv):
    mArgStatus(ARGUMENT_STATUS_T::ARGUMENT_ABNORMAL),
    mSearchPath(nullptr),
    mSearchWordList(nullptr),
    mFileList(nullptr)
{
    /*Check arguments*/
    mArgStatus = checkArguments(argc);
    if(mArgStatus != ARGUMENT_STATUS_T::ARGUMENT_OK){
        cout << "You have problem with the argument. Please re-check!" << endl;
        return;
    }

    /*Prepare data for task*/
    string tmpString = getSearchPath(argv);
    mSearchPath = new string(tmpString);
    if(mSearchPath->empty()
            || !checkDirectoryPathValid(tmpString.c_str())){
        mArgStatus = ARGUMENT_STATUS_T::ARGUMENT_MISSING_PATH;
        cout << "Cannot get searching directory path" << endl;
        return;
    }

    vector<string> wordList = split(argv[1], ' ');
    mSearchWordList = new vector<string>(wordList);
    mArgStatus = ARGUMENT_STATUS_T::ARGUMENT_OK;
}

FileManager::~FileManager()
{
    if(mSearchPath){
        mSearchPath->clear();
        delete mSearchPath;
        mSearchPath = nullptr;
    }
    if(mSearchWordList){
        mSearchWordList->clear();
        delete mSearchWordList;
        mSearchWordList = nullptr;
    }
    if(mFileList){
        mFileList->clear();
        delete mFileList;
        mFileList = nullptr;
    }
}

int FileManager::run()
{
    if(mArgStatus != ARGUMENT_STATUS_T::ARGUMENT_OK){
        cout << "Argument state: " << mArgStatus << endl;
        return mArgStatus;
    } else {
        //TODO: Devide task to thread worker
        {   //Debug infor
            cout << "Path: " << *mSearchPath << endl;
            cout << "Word(s) need(s) to search: " << endl;
            for(int i = 0; i < mSearchWordList->size(); ++i){
                cout << mSearchWordList->at(i) << endl;
            }
        }

        Searcher searcher = Searcher("example.txt", *mSearchWordList, STR_REPORT_FILE_NAME);
        bool result = searcher.search();
        cout << "search result is " << (result? "true" : "false") << endl;
    }
    return ARGUMENT_STATUS_T::ARGUMENT_OK;
}

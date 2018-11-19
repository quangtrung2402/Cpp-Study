#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "HDR/Utility.h"
#include "HDR/Searcher.h"

class FileManager
{
public:
    explicit FileManager(int argc, char **argv);
    int run();

private:
    ArgumentStatus mArgStatus;
    string *mSearchPath;
    vector<string> *mSearchWordList;
    vector<string> *mFileList;
};

#endif // FILEMANAGER_H

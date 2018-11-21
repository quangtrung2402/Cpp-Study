#include "HDR/Reader.h"

Reader::Reader(string filePath):
    ifstream(filePath),
    mFilePath(new string(filePath))
{
    this->is_open();
}

Reader::~Reader()
{
    if(mFilePath){
        mFilePath->clear();
        delete mFilePath;
        mFilePath = nullptr;
    }
}

string Reader::getFilePath()
{
    return *mFilePath;
}

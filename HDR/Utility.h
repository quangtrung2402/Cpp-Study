#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//https://unix.stackexchange.com/questions/32795/what-is-the-maximum-allowed-filename-and-folder-size-with-ecryptfs
#define PATH_MAX 4096

using namespace std;

typedef enum ARGUMENT_STATUS_T{
    ARGUMENT_ABNORMAL = -1,         //abnormal case, case should never raise
    ARGUMENT_OK = 0,                //normal case
    ARGUMENT_MISSING_PATTERN = 1,   //miss pattern to search
    ARGUMENT_REDUNDANT = 2,         //redundant argument
    ARGUMENT_MISSING_PATH = 3,
    ARGUMENT_MAX
} ArgumentStatus;

enum ARGUMENT_POSITION_T{
    ARGUMENT_APP_NAME = 0,
    ARGUMENT_SEARCH_PATTERN = 1,
    ARGUMENT_SEARCH_PATH = 2,
    ARGUMENT_POSITION_MAX
};

template<typename Out>
void split(const string &str, char delimiter, Out result);

vector<string> split(const string &str, char delimiter);

ArgumentStatus checkArguments(int argc);

string getSearchPath(char **argv);

bool checkDirectoryPathValid(const char *path);

#endif // UTILITY_H

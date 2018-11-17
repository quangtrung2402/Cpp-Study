#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

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
} ArgumentPosition;

/*
 * @author: quangtrung2402@gmail.com
 * @description:
 *  split string to separate elements
 * @param:
 *  str: string need to separate
 *  delimiter: signation to separate
 *  retult: function poiter which will push result to container
 * @return:
 *  none
*/
template<typename Out>
void split(const string &str, char delimiter, Out result) {
    stringstream stringStream(str);
    string item;
    while (getline(stringStream, item, delimiter)) {
        *(result++) = item;
    }
}

/*
 * @author: quangtrung2402@gmail.com
 * @description:
 *  split string to separate elements
 * @param:
 *  str: string need to separate
 *  delimiter: signation to separate
 * @return:
 *  list separate elements
*/
vector<string> split(const string &str, char delimiter) {
    vector<string> elements;
    split(str, delimiter, back_inserter(elements));
    return elements;
}

/*
 * @author: quangtrung2402@gmail.com
 * @description:
 *  check valid arguments when init application
 * @param:
 *  argc: ARGument Count. argc should be non negative
 *  argv: ARGument Vector
 * @return:
 *  ArgumentStatus
*/
ArgumentStatus checkArguments(int argc) {
    /*Check arguments*/
    ArgumentStatus result = ARGUMENT_STATUS_T::ARGUMENT_ABNORMAL;
    if(argc < 0){
        cout << "Ooh! Something wrong! ARGument Count is minus! This's abnormal!\n";
        result = ARGUMENT_STATUS_T::ARGUMENT_ABNORMAL;
    } else if (1 == argc ) {
        cout << "Ooh! Something wrong! You should add pattern to search!\n";
        cout << "The command should like this:\n";
        cout << "\t> SearchWord “many words” [path to dictionary]\n";
        result = ARGUMENT_STATUS_T::ARGUMENT_MISSING_PATTERN;
    } else if ((2 == argc )
               || (3 == argc)){
        //Normal case
        result = ARGUMENT_STATUS_T::ARGUMENT_OK;
    }else if (argc > 3) {
        cout << "Ooh! Something wrong! You should just add enough arguments!\n";
        cout << "The command should like this:\n";
        cout << "\t> SearchWord “many words” [path to dictionary]\n";
        result = ARGUMENT_STATUS_T::ARGUMENT_REDUNDANT;
    }
    return result;
}

/*
 * @author: quangtrung2402@gmail.com
 * @description:
 *  get path to search
 * @param:
 *  argc: ARGument Count. argc should be non negative
 *  argv: ARGument Vector
 * @return:
 *  directory path
*/
string getSearchPath(char **argv) {
    string result = "";
    //argv[0]: application name
    //argv[1]: search pattern
    //argv[2]: directory to search
    if(argv[ARGUMENT_POSITION_T::ARGUMENT_SEARCH_PATH] != nullptr){
        result = argv[ARGUMENT_POSITION_T::ARGUMENT_SEARCH_PATH];
    } else {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            result = cwd;
        } else {
            cout << "Ooh! Search path is empty!" << endl;
            result = "";
        }
    }
    return result;
}
#endif // UTILITY_H

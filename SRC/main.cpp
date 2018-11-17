#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <limits>

#include <HDR/Utility.h>

using namespace std;

int main(int argc, char** argv)
{
    /*Check arguments*/
    {
        ArgumentStatus check = checkArguments(argc);
        if(check != ARGUMENT_STATUS_T::ARGUMENT_OK) return check;
    }

    /*Prepare data for task*/
    string searchPath = getSearchPath(argv);
    if("" == searchPath){
        return ARGUMENT_STATUS_T::ARGUMENT_MISSING_PATH;
    }
    vector<string> searchWordList = split(argv[1], ' ');

    {
        //Debug infor
        cout << "Path: " << searchPath << endl;
        cout << "Word(s) need(s) to search: " << endl;
        for(int i = 0; i < searchWordList.size(); ++i){
            cout << searchWordList.at(i) << endl;
        }
    }

    return 0;
}

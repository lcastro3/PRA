#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;
class bufferBuilder {

    public:
        void makeBuffer(int position);
        void searchInBuffer(int position);
    private:
        void bufferStringTreatment(char *filename,int position);
        int  startPosition;
        char *buffer;

};

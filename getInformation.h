#include "bufferBuilder.h"

class storage{
    public:
        void convertData();
        float getCotation(char *data);
        void getCotationBufferized(char *data);
    private:
        int getPosition(string data);
        char *buffer;
};

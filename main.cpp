#include "getInformation.h"

using namespace std;

int main(){
    storage data;
    data.convertData();
    char load[256];
    while(1){
        cout <<"enter date(yyyy-mm-dd)"<<endl;
        cin.getline(load,256);
        data.getCotationBufferized(load);
        if(load[0] =='e'){
            break;
        }
    }
    float cotation;
    cotation = data.getCotation(load);
    cout<<cotation<<endl;
}

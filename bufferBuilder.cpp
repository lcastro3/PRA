#include "bufferBuilder.h"
#include <stdlib.h>
void bufferBuilder :: bufferStringTreatment(char *filename,int position){
    ifstream archive;
    char *buffer = (char*)malloc(4097* sizeof(char));
    archive.open(filename);
    char ch;int numero=0,i=0;
    if(archive.good()){
        archive.seekg(position);
        while((archive.get(ch))&&(i!=4096)){
            if((isdigit(ch))||(ch='.')){
                buffer[i] =ch;
                i++;
                numero=1;
            }else if((ch = '\n')&&(numero == 1)){
                buffer[i] = ch;
                i++;
                numero=0;
            }
        }
    bufferBuilder::startPosition = position;
    bufferBuilder::buffer = buffer;
    }else{
        cout << "Erro ao abrir "<<filename<<endl;
    }
}

void bufferBuilder :: makeBuffer(int position){
    char filename[] = "refinedData.txt";
    bufferStringTreatment(filename,position);
}

void bufferBuilder::searchInBuffer(int position){
    int start = bufferBuilder::startPosition;
    char *buffer = bufferBuilder::buffer;
    if(position == start){
        string g = g + buffer[0]+buffer[1]+buffer[2]+buffer[3];
        cout << "SearchBufferized : "<<g<<endl;
    }else if((position - start > 0)&&(position - start < 28)){
        string g = g + buffer[0 + (position - start)*20]+buffer[1 + (position - start)*20]+buffer[2 + (position - start)*20]+buffer[3 + (position - start)*20];
        cout << "SearchBufferized : "<<g<<endl;
    }else{
         bufferBuilder aux;
         aux.makeBuffer(position);
         aux.searchInBuffer(position);
    }
}

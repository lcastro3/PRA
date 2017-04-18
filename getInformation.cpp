#include "getInformation.h"
#include <stdlib.h>
#include <stdio.h>
void storage :: convertData(){
    ifstream raw;
    ofstream refined;
    raw.open("rawData.txt");
    refined.open("refinedData.txt");
    string ano,mes,dia,valor,result;
    int d=-1,v=-1,n=-1,conta=0;
    if(raw.is_open()==1){
        cout << "Refinando dados"<<endl;
        char ch;
        while(raw.get(ch)){
            if(ch == '['){
                d=0;
            }
            if((isdigit(ch))&&(d!=-1)){
                if(d<=3){
                    ano = ano + ch;
                }else if((d>3)&&(d<=5)){
                    mes = mes+ch;
                }else{
                    dia = dia +ch;
                }
                d++;
            }
            if(d==8){
                ano = ano.substr(2,2);
                result = ano + mes + dia;
                istringstream convert(result);
                convert >> conta;
                dia = "";
                mes = "";
                ano = "";
                d=-1;
                n=1;
            }
            if(ch==']'){
                refined.seekp(conta,raw.beg);
                refined << valor;
                valor="";
                n=-1;
                v=-1;
            }
            if((v==1)&&(n==1)){
                valor = valor + ch;
            }
            if((ch == ',')&&(n==1)){
                d=-1;
                v=1;
                n=1;
            }


        }
        cout <<"Dados Refinados" << endl;
        raw.close();
        refined.close();
    }else{
        cout << "Erro ao Abrir 'Raw Data'"<< endl;
    }

}
int storage::getPosition(string data){
    string ano,mes,dia,result;
    int conta;
    ano = data.substr(0,4);
    mes = data.substr(5,2);
    dia = data.substr(8,2);
    ano = ano.substr(2,2);
    result = ano + mes + dia;
    istringstream convert(result);
    convert >> conta;
    dia = "";
    mes = "";
    ano = "";
    return conta;
};
void storage :: getCotationBufferized(char *data){
    bufferBuilder builder;
    int position = getPosition(data);
    builder.makeBuffer(position);
    builder.searchInBuffer(position);
}

float  storage::getCotation(char *data){
    int position = getPosition(data);
    float k;
    ifstream refined;
    refined.open("refinedData.txt");
    refined.seekg(position,refined.beg);
    char ch;
    string buscado="";
    if(refined.is_open()){
        cout << "buscando" <<endl;
        int num=1;
        while(refined.get(ch)&&(num==1)){
            if(isdigit(ch)||(ch=='.')){
                buscado = buscado +ch;
            }
            if((ch=='\n')&&(buscado!="")){
                num=-1;
            }
        }
        istringstream convert(buscado);
        convert >> k;
        if(k==0){
            cout<<"Cotacao nao encontrada"<<endl;
        }else{
            return k;
        }

    }else{
        cout << "Erro ao abrir refined.txt"<<endl;
    }
    refined.close();
    return -1;
}



#ifndef LISTADOBLE_H
#define LISTADOBLE_H



#include <iostream>
#include <fstream>
#include "cola.h"

using namespace std;

class NodoT{
public:
    Ficha *data;
    NodoT *next;
    NodoT *prev;

    NodoT(Ficha *data){
        this->data=data;
        next = NULL;
        prev = NULL;
    }
};

class ListaDoble {
private:
    NodoT *first;
    NodoT *last;
    int size;

public:
    ListaDoble() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    void print() {
        NodoT *temp = first;
        int i = 1;
        while (temp != NULL) {
            cout << "Posicion "<<i<<" :"<<temp->data->letra << endl;
            temp = temp->next;
            i++;
        }
    }

    void printEditor() {
        NodoT *temp = first;
        int i = 1;
        int b = 98;
        while (temp != NULL) {
            cout <<temp->data->letra;
            if(i==b){
                b += 98;
                cout<<"\n";
                char x = 186;
                cout<<x;
            }
            temp = temp->next;
            i++;
        }
    }

    void deleteList(){
        NodoT *next;
        while (first!=NULL){
            next = first->next;
            delete first;
            first = next;
        }
    }

    void prepend(Ficha * data) {
        NodoT *n = new NodoT(data);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            first->prev=n;
            n->next=first;
            first = n;
        }
        size++;
    }

    void append(Ficha *data) {
        NodoT *n = new NodoT(data);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            last->next = n;
            n->prev= last;
            last = n;
        }
        size++;
    }

    void insertAt(int pos, Ficha *data){
        if(pos>size+1 || pos<1)
        {

            cout<<pos;return;}
        else if (pos==1){
            prepend(data);}
        else if (pos==size+1)
            append(data);
        else if (first!=NULL){
            NodoT *n = new NodoT(data);
            NodoT *cur = first;
            for (int i = 0; i < pos; ++i) {
                cur=cur->next;
            }
            cur->prev->next=n;
            n->prev=cur->prev;
            n->next=cur;
            cur->prev=n;
            size++;
        }
    }

    void removeFirst() {
        if (first->next == NULL) {
            delete first;
            first = NULL;
            last = NULL;
            --size;
        }else if(first != NULL){
            first = first->next;
            delete first->prev;
            first->prev = NULL;
            --size;
        }
    }

    void  removeSpecific(int pos){
        if(pos> size || pos<1)
            return;
        else if (pos == 1)
            removeFirst();
        else if (pos == size)
           removeLast();
        else if (first != NULL){
            NodoT *cur= first;
            for (int i = 0; i < pos-1; ++i) {
                cur = cur->next;
            }
            cur->prev->next= cur->next;
            cur->next->prev=cur->prev;
            delete cur;
            size--;
        }
    }

    void removeLast() {
        if (first->next == NULL) {
            removeFirst();
        } else if (first != NULL) {
            last = last->prev;
            delete last->next;
            last->next =NULL;
            size--;
        }
    }

    int  getSize(){
        return size;
    }

    string getData(int pos){
        if(pos> size || pos<1){
            return "";
        }

        else if (pos == 1)
            return first->data->letra;
        else if (pos == size)
            return last->data->letra;
        else if (first != NULL){
            NodoT *cur= first;
            for (int i = 0; i < pos; ++i) {
                cur = cur->next;
            }
            return cur->data->letra;


        }
    }

    Ficha *getFicha(string letra){
        NodoT *temp = first;
        int i = 1;
        int temporal = i;
        Ficha *ficha = NULL;
        while(temp != NULL){
            if(letra.find(temp->data->letra) != std::string::npos){
                ficha = temp->data;
                temporal = i;
            }
            i++;
            temp = temp->next;
        }
        if(ficha!=NULL){
            removeSpecific(temporal);
            return ficha;
        }else{
            return NULL;
        }
    }




    void graficarListaDoble(){
        string graph = "digraph g{\n";
        NodoT *aux = first;
        for(int i = 0;i< size ;i++){
            graph+="L"+to_string(i)+"[label = \""+aux->data->letra+"\" shape = box, color = green];\n";
            aux = aux->next;
        }
        for (int i = 0; i<size-1; i++){
            graph+="L"+to_string(i)+"->L"+to_string(i+1)+";\n";
        }

        for(int i = size-1; i>0;i--){

            graph+="L"+to_string(i)+"->L"+to_string(i-1)+";\n";
        }
        graph += "\n}";
        ofstream archivo;
         archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt",ios::out);
         if(archivo.fail()){

             cout<<"no jala el archivo";
             exit(1);
         }
        else{
         archivo<<graph;
         archivo.close();

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png");
        }
    }
};

#endif // LISTADOBLE_H

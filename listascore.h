#ifndef LISTASCORE_H
#define LISTASCORE_H

#include <iostream>
#include <fstream>
#include "listaarbol.h"
using namespace std;
class NodoScore {
public:
    Jugador *data;
    int puntaje;
    NodoScore *next;

    NodoScore(Jugador * data, int puntaje) {
        this->data = data;
        next = NULL;
        this->puntaje = puntaje;
    }
};

class ListaScore {
private:
    NodoScore *first;
    NodoScore *last;
    int size;

public:
    ListaScore() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    void append(Jugador * data, int puntaje) {
        NodoScore *n = new NodoScore(data, puntaje);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
        size++;
    }

    void prepend(Jugador * data, int puntaje) {
        NodoScore *n = new NodoScore(data, puntaje);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            NodoScore *temp = first;
            first = n;
            n->next = temp;
        }
        size++;
    }
    void ordenar(){
        NodoScore *pivote = first;
        NodoScore *actual;
        NodoScore *temp;

             while (pivote!=last) {
                 actual = pivote->next;
                 while (actual!=NULL) {
                     if (pivote->puntaje<actual->puntaje){
                         temp->data = pivote->data;
                         temp->puntaje = pivote->puntaje;
                         pivote->data = actual->data;
                         pivote->puntaje = actual->puntaje;
                         actual->data = temp->data;
                         actual->puntaje = temp->puntaje;
                     }
                     actual = actual->next;
                 }
                 pivote = pivote->next;
             }
    }

    void graficar(){
        ordenar();
        NodoScore *temp = first;
        string graph = "digraph f{\nrankdir = LR;\n";
        int i = 0 ;
        while(temp!=NULL){
          graph += to_string(i)+"[shape = box color = darkorchid1 label=\"Nombre: "+temp->data->getNombre()+", Puntaje: "+to_string(temp->puntaje)+"\"];\n";
          temp = temp->next;
          i++;
        }

        for(int x = 0; x<size-1;x++){
            graph += to_string(x)+"->"+to_string(x+1)+";\n";
        }
        graph+="}";
        ofstream archivo;
         archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt",ios::out);
         if(archivo.fail()){

             cout<<"no jala el archivo";
             exit(1);
         }
        else{
         archivo<<graph;
         archivo.close();

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\score.png");

        }
    };
};


#endif // LISTASCORE_H

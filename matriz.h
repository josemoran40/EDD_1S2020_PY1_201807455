#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "fstream"
using namespace std;
#include "circulardoble.h"
#include "cola.h"


class NodoCentral{
public:
    Ficha *data;
    int pos;
    int puntaje;
    NodoCentral *arriba;
    NodoCentral *abajo;
    NodoCentral *izquierda;
    NodoCentral *derecha;

    NodoCentral(Ficha *dato, int pos, int puntaje){
        this->data = dato;
        this->pos =pos;
        arriba = NULL;
        abajo = NULL;
        izquierda = NULL;
        derecha = NULL;
        this->puntaje = puntaje;
    }
};

class NodoCabezera{
 public:
    NodoCabezera *izquierda;
    NodoCabezera *derecha;
    int valor;
    NodoCentral *data;

    NodoCabezera(int valor){
        this->izquierda = NULL;
        this->derecha = NULL;
        this->data = NULL;
        this->valor = valor;
    }

};

class NodoLateral{
public:
    NodoLateral *arriba;
    NodoLateral *abajo;
    int valor;
    NodoCentral *data;

    NodoLateral(int valor){
        this->arriba= NULL;
        this->abajo = NULL;
        this->data = NULL;
        this->valor = valor;
    }
};


class Matriz
{
public:
    NodoCabezera *cabecera;
    NodoLateral *lateral;

    Matriz(){
        cabecera = NULL;
        lateral = NULL;
    };

    void add(int x, int y, Ficha *data, int puntaje){

        add_header_x(x, y, data, puntaje);
        add_header_y(x, y, data, puntaje);

    }

    void add_header_x(int x, int y, Ficha *data, int puntaje){
        if(cabecera ==NULL){
            NodoCabezera *temp = new NodoCabezera(x);
            cabecera = temp;
            add_data_x(y, temp, data, puntaje);
        }else
        {
            NodoCabezera *temp = cabecera;
            if(temp->valor>x){
                NodoCabezera *nuevo = new NodoCabezera(x);
                temp->izquierda= nuevo;
                nuevo->derecha = temp;
                cabecera = nuevo;
                add_data_x(y, nuevo, data, puntaje);
            }else if(temp->valor==x){
                add_data_x(y, temp, data, puntaje);
            }else{
                while (temp->derecha !=NULL && temp->derecha->valor < x) {
                    temp = temp->derecha;
                }
                if(temp->derecha==NULL){
                    NodoCabezera *nuevo = new NodoCabezera(x);
                    temp->derecha = nuevo;
                    nuevo->izquierda = temp;
                    add_data_x(y, nuevo, data, puntaje);
                }else if(temp->derecha->valor !=x) {
                    NodoCabezera *nuevo = new NodoCabezera(x);
                    NodoCabezera *der = temp->derecha;
                    temp->derecha = nuevo;
                    nuevo->derecha = der;
                    nuevo->izquierda= temp;
                    der->izquierda = nuevo;
                    add_data_x(y, nuevo, data, puntaje);
                }else{

                    add_data_x(y, temp->derecha, data, puntaje);
                }
            }
        }

    }


    void addCabezeras(int y){
        for(int i = 0; i<y;i++){
                int x =i;
            if(cabecera ==NULL){
                NodoCabezera *temp = new NodoCabezera(x);
                cabecera = temp;
            }else
            {
                NodoCabezera *temp = cabecera;
                if(temp->valor>x){
                    NodoCabezera *nuevo = new NodoCabezera(x);
                    temp->izquierda= nuevo;
                    nuevo->derecha = temp;
                    cabecera = nuevo;
                }
                else{
                    while (temp->derecha !=NULL && temp->derecha->valor < x) {
                        temp = temp->derecha;
                    }
                    if(temp->derecha==NULL){
                        NodoCabezera *nuevo = new NodoCabezera(x);
                        temp->derecha = nuevo;
                        nuevo->izquierda = temp;
                    }else if(temp->derecha->valor !=x) {
                        NodoCabezera *nuevo = new NodoCabezera(x);
                        NodoCabezera *der = temp->derecha;
                        temp->derecha = nuevo;
                        nuevo->derecha = der;
                        nuevo->izquierda= temp;
                        der->izquierda = nuevo;
                    }
                }
            }
        }
    }

        void add_header_y(int x, int y, Ficha *data, int puntaje){
            if(lateral==NULL){
                NodoLateral *temp = new NodoLateral(y);
                lateral = temp;
                add_data_y(x, temp, data, puntaje);
            }else
            {
                NodoLateral *temp = lateral;
                if(temp->valor>y){
                    NodoLateral*nuevo = new NodoLateral(y);
                    temp->arriba = nuevo;
                    nuevo->abajo = temp;
                    lateral = nuevo;
                    add_data_y(x, nuevo, data, puntaje);
                }else if(temp->valor==y){

                    add_data_y(x, temp, data, puntaje);
                }
                 else{
                    while (temp->abajo !=NULL && temp->abajo->valor < y) {
                        temp = temp->abajo;
                    }
                    if(temp->abajo==NULL){
                        NodoLateral *nuevo = new NodoLateral(y);
                        temp->abajo = nuevo;
                        nuevo->arriba = temp;
                        add_data_y(x, nuevo, data, puntaje);
                    }else if(temp->abajo->valor !=y) {
                        NodoLateral *nuevo = new NodoLateral(y);
                        NodoLateral *der = temp->abajo;
                        temp->abajo = nuevo;
                        nuevo->abajo = der;
                        nuevo->arriba= temp;
                        der->arriba = nuevo;
                        add_data_y(x, nuevo, data, puntaje);
                    }else{

                        add_data_y(x, temp->abajo, data, puntaje);
                    }
                }
            }

        }

        void addLaterales(int x){
            for(int i = 0; i<x;i++){
                int y = i;
                if(lateral==NULL){
                    NodoLateral *temp = new NodoLateral(y);
                    lateral = temp;
                }else
                {
                    NodoLateral *temp = lateral;
                    if(temp->valor>y){
                        NodoLateral*nuevo = new NodoLateral(y);
                        temp->arriba = nuevo;
                        nuevo->abajo = temp;
                        lateral = nuevo;
                    }
                     else{
                        while (temp->abajo !=NULL && temp->abajo->valor < y) {
                            temp = temp->abajo;
                        }
                        if(temp->abajo==NULL){
                            NodoLateral *nuevo = new NodoLateral(y);
                            temp->abajo = nuevo;
                            nuevo->arriba = temp;
                        }else if(temp->abajo->valor !=y) {
                            NodoLateral *nuevo = new NodoLateral(y);
                            NodoLateral *der = temp->abajo;
                            temp->abajo = nuevo;
                            nuevo->abajo = der;
                            nuevo->arriba= temp;
                            der->arriba = nuevo;
                         }
                    }
                }
            }
        }


        void add_data_x(int y, NodoCabezera *c, Ficha *data, int puntaje){
            if(c->data ==NULL){
                NodoCentral *temp = new NodoCentral(data,y, puntaje);
                c->data = temp;
            }else
            {
                NodoCentral *temp = c->data;
                if(temp->pos>y){
                    NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                    temp->arriba = nuevo;
                    nuevo->abajo = temp;
                    c->data=nuevo;
                }else{
                    while (temp->abajo !=NULL && temp->abajo->pos < y) {
                        temp = temp->abajo;
                    }
                    if(temp->abajo==NULL){
                        NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                        temp->abajo = nuevo;
                        nuevo->arriba = temp;
                    }else if(temp->pos !=y) {
                        NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                        NodoCentral *der = temp->abajo;
                        temp->abajo = nuevo;
                        nuevo->abajo = der;
                        nuevo->arriba= temp;
                        der->arriba = nuevo;
                    }else{
                        temp->data = data;
                    }
                }
            }

        }




        void add_data_y(int y, NodoLateral *c, Ficha *data, int puntaje){
            if(c->data ==NULL){
                NodoCentral *temp = new NodoCentral(data,y, puntaje);
                c->data = temp;
            }else
            {
                NodoCentral *temp = c->data;
                if(temp->pos>y){
                    NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                    temp->izquierda = nuevo;
                    nuevo->derecha = temp;
                    c->data=nuevo;
                }else{
                    while (temp->derecha !=NULL && temp->derecha->pos < y) {
                        temp = temp->derecha;
                    }
                    if(temp->derecha==NULL){
                        NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                        temp->derecha = nuevo;
                        nuevo->izquierda = temp;
                    }else if(temp->pos !=y) {
                        NodoCentral *nuevo = new NodoCentral(data,y, puntaje);
                        NodoCentral *der = temp->derecha;
                        temp->derecha = nuevo;
                        nuevo->derecha = der;
                        nuevo->izquierda= temp;
                        der->izquierda = nuevo;
                    }else{
                        temp->data = data;
                    }
                }
            }

        }

        void eliminar(int x,int y){
            eliminarX(x,y);
            eliminarY(x,y);
        }

        void eliminarX(int x, int y){
            NodoCabezera *temp = cabecera;
            if(cabecera == NULL){
                return;
            }
            else if(cabecera->valor==x){
                eliminarDatax(y, cabecera);
                if(cabecera->data ==NULL){
                    cabecera = cabecera->derecha;
                    if(cabecera!=NULL){
                    cabecera->izquierda =NULL;
                    }
                }
            }else{
                while (temp!= NULL && temp->valor!=x) {
                    temp = temp->derecha;
                }
                if(temp->valor == x){
                    eliminarDatax(y, temp);

                    if(temp->data ==NULL){
                        if(temp->derecha!=NULL){
                            temp->izquierda->derecha = temp->derecha;
                            temp->derecha->izquierda = temp->izquierda;
                            delete temp;
                        }else{
                            temp->izquierda->derecha = NULL;
                            delete temp;
                        }
                    }
                }
            }

        }




        void eliminarDatax(int y, NodoCabezera *c){
            if(c->data==NULL){
                return;
            }
            else{
                NodoCentral *temp = c->data;
                if(temp->pos == y){
                    c->data = c->data->abajo;
                    if(c->data!=NULL){
                        c->data->arriba=NULL;
                    }
                }else{
                    while(temp!=NULL && temp->pos!=y){

                        temp = temp->abajo;
                    }
                    if(temp->pos==y){
                        if(temp->abajo!=NULL){
                        temp->arriba->abajo = temp->abajo;
                        temp->abajo->arriba = temp->arriba;
                        delete temp;
                    }else{
                            if(temp->abajo!=NULL){
                                temp->abajo->arriba = NULL;
                            }
                            if(temp->arriba!=NULL){
                                temp->arriba->abajo =NULL;
                            }
                            delete temp;
                        }
                    }
                }
            }
        }

        void eliminarY(int x, int y){
            NodoLateral *temp = lateral;
            if(lateral == NULL){
                return;
            }
            else if(lateral->valor==y){
                eliminarDatay(x, lateral);
                if(lateral->data ==NULL){
                    lateral = lateral->abajo;
                    if(lateral != NULL){
                    lateral->arriba = NULL;
                    }
                    return;
                }
            }else{
                while (temp!= NULL&&temp->valor!=y) {
                    temp = temp->abajo;
                }
                if(temp->valor == y){
                    eliminarDatay(x, temp);

                    if(temp->data ==NULL){
                        if(temp->abajo!=NULL){
                            temp->arriba->abajo = temp->abajo;
                            temp->abajo->arriba = temp->arriba;
                            delete temp;
                        }else{
                            temp->arriba->abajo = NULL;
                            delete temp;
                        }

                    }
                }
            }

        }


        bool existeX(int x, int y){
            NodoCabezera *aux = cabecera;
            while(aux!=NULL){
                NodoCentral *temp = aux->data;
                if(aux->valor ==  x){
                    while(temp!=NULL){
                        if(temp->pos  == y){
                            return true;
                        }
                        temp = temp->abajo;
                    }
                }
                aux = aux->derecha;
            }
            return false;
        }

        bool existeY(int x, int y){
            NodoLateral *aux = lateral;
            while(aux!=NULL){
                NodoCentral *temp = aux->data;
                if(aux->valor ==  y){
                    while(temp!=NULL){
                        if(temp->pos  == x){
                            return true;
                        }
                        temp = temp->derecha;
                    }
                }
                aux = aux->abajo;
            }
            return false;
        }

        int verificarX(CircularDiccionario *diccionario){
            NodoCabezera *aux = cabecera;
            int punteo = 0;
            while(aux!=NULL){
                NodoCentral *x = aux->data;
                string palabra = "";

                while(x!=NULL){
                    palabra+=x->data->letra;
                    punteo =  punteo +(x->data->puntos*x->puntaje);
                    if(x->abajo == NULL){

                        NodoCircular *palabraDic = diccionario->first;
                        if(palabraDic!=NULL){
                            do{
                                if(palabra.find(palabraDic->data) != std::string::npos && palabraDic->find == false){
                                    palabraDic->find = true;
                                    return punteo;
                                }
                                palabraDic = palabraDic->next;
                            }
                            while(palabraDic!=diccionario->first);
                        }
                        palabra = "";
                        punteo = 0;
                    }
                    else if(x->abajo->pos !=  x->pos+1){

                        NodoCircular *palabraDic = diccionario->first;
                        if(palabraDic!=NULL){
                            do{
                                if(palabra.find(palabraDic->data) != std::string::npos && palabraDic->find == false){
                                    palabraDic->find = true;
                                    return punteo;
                                }
                                palabraDic = palabraDic->next;
                            }
                            while(palabraDic!=diccionario->first);
                        }
                        palabra = "";
                        punteo = 0;
                    }
                    x = x->abajo;
                }
                aux = aux->derecha;
            }
            return 0;
        }

        int verificarY(CircularDiccionario *diccionario){
            NodoLateral *aux = lateral;
            int punteo = 0;
            while(aux!=NULL){
                NodoCentral *x = aux->data;
                string palabra = "";

                while(x!=NULL){
                    palabra+=x->data->letra;
                    punteo =  punteo +(x->data->puntos*x->puntaje);
                    if(x->derecha == NULL){

                        NodoCircular *palabraDic = diccionario->first;
                        if(palabraDic!=NULL){
                            do{
                                if(palabra.find(palabraDic->data) != std::string::npos && palabraDic->find == false){
                                    palabraDic->find = true;
                                    return punteo;
                                }
                                palabraDic = palabraDic->next;
                            }
                            while(palabraDic!=diccionario->first);
                        }
                        palabra = "";
                        punteo = 0;
                    }
                    else if(x->derecha->pos !=  x->pos+1){

                        NodoCircular *palabraDic = diccionario->first;
                        if(palabraDic!=NULL){
                            do{
                                if(palabra.find(palabraDic->data) != std::string::npos && palabraDic->find == false){
                                    palabraDic->find = true;
                                    return punteo;
                                }
                                palabraDic = palabraDic->next;
                            }
                            while(palabraDic!=diccionario->first);
                        }
                        palabra = "";
                        punteo = 0;
                    }
                    x = x->derecha;
                }
                aux = aux->abajo;
            }
            return 0;
        }

        void eliminarDatay(int y, NodoLateral *c){
            if(c->data==NULL){

            }
            else{
                NodoCentral *temp = c->data;
                if(c->data->pos == y){
                    c->data = c->data->derecha;
                    if(c->data!=NULL){
                        c->data->izquierda=NULL;
                    }
                }else{
                    while(temp!=NULL && temp->pos!=y){

                        temp = temp->derecha;
                    }
                    if(temp->pos==y){
                        if(temp->derecha!=NULL){
                        temp->derecha->izquierda = temp->izquierda;
                        temp->izquierda->derecha = temp->derecha;
                        delete temp;
                        }else{
                            if(temp->derecha!=NULL){
                            temp->derecha->izquierda = NULL;
                            }
                            if(temp->izquierda!=NULL){
                                temp->izquierda->derecha =NULL;
                            }
                            delete temp;
                        }
                    }
                }
            }
        }


        void print_x(){

            NodoCabezera *temp = cabecera;
            while(temp!=NULL){
                NodoCentral *temp2 = temp->data;
                cout<<temp->valor<<" :";
                while(temp2!=NULL){
                    cout<< temp2->pos<<", ";
                    temp2 = temp2->abajo;
                }
                cout<<endl;
                temp = temp->derecha;
            }
        }

        void print_y(){

            NodoLateral *temp = lateral;
            while(temp!=NULL){
                NodoCentral *temp2 = temp->data;
                cout<<temp->valor<<" :";
                while(temp2!=NULL){
                    cout<< temp2->pos<<", ";
                    temp2 = temp2->derecha;
                }
                cout<<endl;
                temp = temp->abajo;
            }
        }

        void graficar(){
            if(cabecera!=NULL && lateral != NULL){
                string graph ="";
                graph = "digraph Matrix {\n\n"
                         "\tnode [shape=box];\n\n"
                         "\t// Nodo raiz\n"
                         "Matriz[label=\" Matriz \", width = 1.5, style=filled, fillcolor = paleturquoise color= paleturquoise, group = 1];\n\n";
                //Grafica cabezeras

                NodoCabezera *auxCa = cabecera;
                graph += "Matriz->C"+to_string(auxCa->valor)+";\n";
                graph += "C"+to_string(auxCa->valor)+"->Matriz;\n";
                string rankC = "{rank = same; Matriz ";
                while(auxCa!=NULL){
                    graph += "C"+to_string(auxCa->valor)+"[label=\"C"+to_string(auxCa->valor)+"\", width = 1.5, style=filled, fillcolor = paleturquoise color= paleturquoise, group = "+to_string(auxCa->valor)+"];\n\n";
                    if(auxCa->izquierda!=NULL){
                        graph += "C"+to_string(auxCa->izquierda->valor)+"->"+"C"+to_string(auxCa->valor)+"\n";                        
                        graph += "C"+to_string(auxCa->valor)+"->"+"C"+to_string(auxCa->izquierda->valor)+"\n";
                    }
                    rankC += "C"+to_string(auxCa->valor)+" ";
                    NodoCentral *auxCe = auxCa->data;
                    if(auxCe!=NULL){
                        graph += "C"+to_string(auxCa->valor)+"->"+"U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"\n";
                        graph += "U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"->"+"C"+to_string(auxCa->valor)+"\n";

                        while (auxCe!=NULL)
                        {
                            if(auxCe->puntaje==1){
                                graph += "U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"[label=\""+auxCe->data->letra+"\", width = 1.5, style=filled, fillcolor = mintcream color=mintcream, group = "+to_string(auxCa->valor)+"];\n\n";
                            } else if(auxCe->puntaje==2){
                                graph += "U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"[label=\""+auxCe->data->letra+"\", width = 1.5, style=filled, fillcolor = lemonchiffon color=lemonchiffon, group = "+to_string(auxCa->valor)+"];\n\n";
                            }else{
                                graph += "U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"[label=\""+auxCe->data->letra+"\", width = 1.5, style=filled, fillcolor = lightpink color=lightpink, group = "+to_string(auxCa->valor)+"];\n\n";

                            }
                            if(auxCe->arriba!=NULL){
                                graph += "U"+to_string(auxCa->valor)+to_string(auxCe->arriba->pos)+"->"+"U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"\n";                                
                                graph += "U"+to_string(auxCa->valor)+to_string(auxCe->pos)+"->"+"U"+to_string(auxCa->valor)+to_string(auxCe->arriba->pos)+"\n";
                            }
                            auxCe = auxCe->abajo;
                        }
                    }

                    auxCa = auxCa->derecha;
                }
                graph += rankC+ "}";
                //Grafica laterales
                NodoLateral *auxLa = lateral;
                graph += "Matriz->L"+to_string(auxLa->valor)+";\n";                
                graph += "L"+to_string(auxLa->valor)+"->Matriz;\n";
                while(auxLa!=NULL){
                    string ranksame = "{rank = same; ";
                    graph += "L"+to_string(auxLa->valor)+"[label=\"L"+to_string(auxLa->valor)+"\", width = 1.5, style=filled, fillcolor = paleturquoise color=paleturquoise, group = 1];\n\n";
                    ranksame += "L"+to_string(auxLa->valor)+" ";
                    if(auxLa->arriba!=NULL){
                         graph += "L"+to_string(auxLa->arriba->valor)+"->"+"L"+to_string(auxLa->valor)+"\n";
                         graph += "L"+to_string(auxLa->valor)+"->"+"L"+to_string(auxLa->arriba->valor)+"\n";
                    }
                     NodoCentral *auxCe = auxLa->data;
                     if(auxCe!=NULL){
                         graph += "L"+to_string(auxLa->valor)+"->"+"U"+to_string(auxCe->pos)+to_string(auxLa->valor)+"\n";
                         graph += "U"+to_string(auxCe->pos)+to_string(auxLa->valor)+"->"+"L"+to_string(auxLa->valor)+"\n";
                         ranksame += "U"+to_string(auxCe->pos)+to_string(auxLa->valor)+" ";
                         while (auxCe!=NULL) {
                             ranksame += "U"+to_string(auxCe->pos)+to_string(auxLa->valor)+" ";
                             if(auxCe->izquierda!=NULL){
                                 graph += "U"+to_string(auxCe->izquierda->pos)+to_string(auxLa->valor)+"->"+"U"+to_string(auxCe->pos)+to_string(auxLa->valor)+"\n";
                                 graph += "U"+to_string(auxCe->pos)+to_string(auxLa->valor)+"->"+"U"+to_string(auxCe->izquierda->pos)+to_string(auxLa->valor)+"\n";
                             }
                             auxCe = auxCe->derecha;

                        }
                     }
                     graph += ranksame + "}\n";
                    auxLa = auxLa->abajo;
                }

                graph += "}";

                //cout<<graph;

               ofstream archivo;
                archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt",ios::out);
                if(archivo.fail()){

                    cout<<"no jala el archivo";
                    exit(1);
                }
               else{
                archivo<<graph;
                archivo.close();

                system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\matriz.png");

               }


            }

        }
};;



#endif // MATRIZ_H

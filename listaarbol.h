#ifndef LISTAARBOL_H
#define LISTAARBOL_H


#include <iostream>
#include <nodoarbol.h>
#include <fstream>
#include <listadoble.h>
using namespace std;
class Jugador;
class NodoListaArbol;
class ListaArbol;
class NodoArbol;


class NodoPuntajes {
public:
    int data;
    NodoPuntajes *next;

    NodoPuntajes(int data) {
        this->data = data;
        next = NULL;
    }
};

class ListaPuntajes {
private:
    NodoPuntajes *first;
    NodoPuntajes *last;
    int size;

public:
    ListaPuntajes() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    void append(int data) {
        NodoPuntajes *n = new NodoPuntajes(data);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
        size++;
    }

    void prepend(int data) {
        NodoPuntajes *n = new NodoPuntajes(data);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            NodoPuntajes *temp = first;
            first = n;
            n->next = temp;
        }
        size++;
    }

    void print() {
        NodoPuntajes *temp = first;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void removeFirst() {
        if (first != NULL) {
            NodoPuntajes *temp = first;
            first = first->next;
            delete temp;
            --size;
        }
    }

    void removeLast() {
        if (first->next == NULL) {
            removeFirst();
        } else if (first != NULL) {
            NodoPuntajes *cur = first;
            NodoPuntajes *prev;
            while(cur->next !=NULL){
                prev = cur;
                cur = cur->next;
            }
            last = prev;
            prev->next= NULL;
            delete cur;
            size--;
        }
    }

    void removeSpecific(int pos){
        if(pos> size || pos<1)
            return;
        else if (pos == 1)
            removeFirst();
        else if (pos == size)
            removeLast();
        else if (first != NULL){
            NodoPuntajes *prev;
            NodoPuntajes *cur= first;
            for (int i = 0; i < pos; ++i) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
            size--;
        }
    }

    void insertAt(int pos, int data){
        if(pos>size+1 || pos<1)
            return;
        else if (pos==1)
            append(data);
        else if (pos==size+1)
            prepend(data);
        else if (first!=NULL){
            NodoPuntajes *n = new NodoPuntajes(data);
            NodoPuntajes *prev;
            NodoPuntajes *cur = first;
            for (int i = 0; i < pos; ++i) {
                prev = cur;
                cur=cur->next;
            }
            prev->next=n;
            n->next=cur;
            size++;
        }
    }

    void deleteList(){
        NodoPuntajes *next;
        while (first!=NULL){
            next = first->next;
            delete first;
            first = next;
        }
    }

    void ordenar(){
        NodoPuntajes *pivote = first;
        NodoPuntajes *actual;
             int temp;

             while (pivote!=last) {
                 actual = pivote->next;
                 while (actual!=NULL) {
                     if (pivote->data<actual->data){
                         temp = pivote->data;
                         pivote->data = actual->data;
                         actual->data = temp;
                     }
                     actual = actual->next;
                 }
                 pivote = pivote->next;
             }
    }

    void graficar(){
        ordenar();
        NodoPuntajes *temp = first;
        string graph = "digraph f{\nrankdir = LR;\n";
        int i = 0 ;
        while(temp!=NULL){
          graph += to_string(i)+"[shape = box color = darkorchid1 label=\""+to_string(temp->data)+"\"];\n";
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

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\puntajes.png");

        }
    };
};

class Jugador{
  public:
    string nombre;
    ListaDoble *fichas;
    ListaPuntajes *puntajes;
   public:
    Jugador(string nombre){
        this->nombre = nombre;
        fichas = new ListaDoble();
        puntajes = new ListaPuntajes();
    }

    string getNombre(){
        return  nombre;
    }

    void setNombre(string nombre){
        this->nombre = nombre;
    }
};


class NodoArbol
{
public:
    NodoArbol *izquierda;
    NodoArbol *derecha;
    Jugador *valor;
    int index;

public:
    NodoArbol(string nombre, int index){
        izquierda = NULL;
        derecha = NULL;
        valor = new Jugador(nombre);
        this->index = index;
    };
};


class ArbolBinario{
public:
    NodoArbol *cabeza;
public:
    ArbolBinario(){
        cabeza = NULL;
    }



    class NodoListaArbol {
    public:
        Jugador * data;
        NodoListaArbol *next;

        NodoListaArbol(Jugador *data) {
            this->data = data;
            next = NULL;
        }
    };

    class ListaArbol {
    private:
        NodoListaArbol *first;
        NodoListaArbol *last;
        int size;

    public:
        ListaArbol() {
            first = NULL;
            last = NULL;
            size = 0;
        }

        void append(Jugador * data) {
            NodoListaArbol *n = new NodoListaArbol(data);
            if (first == NULL) {
                first = n;
                last = n;
            } else {
                last->next = n;
                last = n;
            }
            size++;
        }

        void prepend(Jugador * data) {
            NodoListaArbol *n = new NodoListaArbol(data);
            if (first == NULL) {
                first = n;
                last = n;
            } else {
                NodoListaArbol *temp = first;
                first = n;
                n->next = temp;
            }
            size++;
        }

        void print() {
            NodoListaArbol *temp = first;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        void removeFirst() {
            if (first != NULL) {
                NodoListaArbol *temp = first;
                first = first->next;
                delete temp;
                --size;
            }
        }

        void removeLast() {
            if (first->next == NULL) {
                removeFirst();
            } else if (first != NULL) {
                NodoListaArbol *cur = first;
                NodoListaArbol *prev;
                while(cur->next !=NULL){
                    prev = cur;
                    cur = cur->next;
                }
                last = prev;
                prev->next= NULL;
                delete cur;
                size--;
            }
        }

        void removeSpecific(int pos){
            if(pos> size || pos<1)
                return;
            else if (pos == 1)
                removeFirst();
            else if (pos == size)
                removeLast();
            else if (first != NULL){
                NodoListaArbol *prev;
                NodoListaArbol *cur= first;
                for (int i = 0; i < pos; ++i) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = cur->next;
                delete cur;
                size--;
            }
        }

        void insertAt(int pos, Jugador * data){
            if(pos>size+1 || pos<1)
                return;
            else if (pos==1)
                append(data);
            else if (pos==size+1)
                prepend(data);
            else if (first!=NULL){
                NodoListaArbol *n = new NodoListaArbol(data);
                NodoListaArbol *prev;
                NodoListaArbol *cur = first;
                for (int i = 0; i < pos; ++i) {
                    prev = cur;
                    cur=cur->next;
                }
                prev->next=n;
                n->next=cur;
                size++;
            }
        }

        void deleteList(){
            NodoListaArbol *next;
            while (first!=NULL){
                next = first->next;
                delete first;
                first = next;
            }
        }

        void graficar(){
            NodoListaArbol *temp = first;
            string graph = "digraph f{\nrankdir = LR;\n";
            int i = 0 ;
            while(temp!=NULL){
              graph += to_string(i)+"[shape = box color = darkorchid1 label=\""+temp->data->getNombre()+"\"];\n";
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

             system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\recorrido.png");

            }
        }
    };



    void agregar(NodoArbol *nuevo){
        if(cabeza==NULL){
            cabeza = nuevo;
        }else{
            agregarRecurviso(cabeza, nuevo);
        }
    }

    void agregarRecurviso(NodoArbol *actual, NodoArbol *nuevo){
        if(actual->valor->getNombre().compare(nuevo->valor->getNombre())>0){
            if(actual->izquierda!=NULL){
                agregarRecurviso(actual->izquierda, nuevo);
            }
            else{
                actual->izquierda = nuevo;
            }
        }else if(actual->valor->getNombre().compare(nuevo->valor->getNombre())<0){
            if(actual->derecha!=NULL){
                agregarRecurviso(actual->derecha, nuevo);
            }
            else{
                actual->derecha = nuevo;
            }
        }

    }

    Jugador *buscarJugador(string nombre){
        if(cabeza!=NULL){
        NodoArbol *nodo = cabeza;
        return buscarJ(nodo, nombre);
        }
        return NULL;
    }

    Jugador *buscarJ(NodoArbol *nodo, string nombre){

        if(nodo->valor->getNombre()==nombre){
            return nodo->valor;
        }
        else if(nombre < nodo->valor->getNombre() && nodo->izquierda!=NULL){
            return buscarJ(nodo->izquierda, nombre);
        }
        else if(nombre > nodo->valor->getNombre() && nodo->derecha!=NULL){
            return buscarJ(nodo->derecha, nombre);
        }
        return NULL;
    }

    void graphviz(){
        string cadena = "";
        cadena +="digraph g{\n";
        cadena += graficar(cabeza);
        cadena +="}";
        cout<<cadena;
        ofstream archivo;
         archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt",ios::out);
         if(archivo.fail()){

             cout<<"no jala el archivo";
             exit(1);
         }
        else{
         archivo.close();

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\arbolJugadores.png");
        }
    }
    void generarPreorder(){
        ListaArbol *lista = new ListaArbol ();
        preorder(lista, cabeza);
        lista->graficar();
    }


    void preorder(ListaArbol *& lista, NodoArbol *nodo){


        if(nodo!=NULL){
            lista->append(nodo->valor);
        }
        if(nodo->izquierda!=NULL){
            preorder(lista,nodo->izquierda);
        }
        if(nodo->derecha!=NULL){
            preorder(lista,nodo->derecha);
        }
    }

    void generarInorder(){
        ListaArbol *lista = new ListaArbol ();
        inorder(lista, cabeza);
        lista->graficar();
    }


    void inorder(ListaArbol *& lista, NodoArbol *nodo){

        if(nodo->izquierda!=NULL){
            preorder(lista,nodo->izquierda);
        }
        if(nodo!=NULL){
            lista->append(nodo->valor);
        }
        if(nodo->derecha!=NULL){
            preorder(lista,nodo->derecha);
        }
    }


    void generarPosorder(){
        ListaArbol *lista = new ListaArbol ();
        posorder(lista, cabeza);
        lista->graficar();
    }


    void posorder(ListaArbol *& lista, NodoArbol *nodo){

        if(nodo->izquierda!=NULL){
            preorder(lista,nodo->izquierda);
        }
        if(nodo->derecha!=NULL){
            preorder(lista,nodo->derecha);
        }
        if(nodo!=NULL){
            lista->append(nodo->valor);
        }
    }
    string graficar(NodoArbol *nodo){
        string cadena = "";

                 cadena += "nodo" + to_string(nodo->index) + "[label = \""+ nodo->valor->getNombre() + "\"  fillcolor=\"#99ccff\" , style=filled ];\n";

                if (nodo->izquierda != NULL) {
                    cadena += graficar(nodo->izquierda) + "nodo" + to_string(nodo->index)+ ":C0->nodo" + to_string(nodo->izquierda->index) + ";\n";
                }
                if (nodo->derecha != NULL) {
                    cadena +=graficar(nodo->derecha) + "nodo" + to_string(nodo->index) + ":C1->nodo" + to_string(nodo->derecha->index) + ";\n";
                }
                return  cadena;


    }



};







#endif // LISTAARBOL_H

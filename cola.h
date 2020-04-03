#ifndef COLA_H
#define COLA_H



#include <iostream>
#include <fstream>


using namespace std;

class Ficha{
public:
    string letra;
    int puntos;

    Ficha(string letra, int puntos){
        this->letra = letra;
        this->puntos = puntos;
    }
};


class Nodo{
public:
    Ficha *ficha;
    Nodo *next;
    Nodo(Ficha *data){
        this->ficha=data;
        next = NULL;
    }
};

class Cola {
public:
    Nodo *first;
    Nodo *last;
    int size;
public:
    Cola(){
        first = NULL;
        last = NULL;
        size = 0;
    }

    void push(Ficha *data){
        Nodo *n = new Nodo(data);
        if(first ==NULL){
            first =n;
            last = n;
        }else{
            last->next=n;
            last = n;
        }
        size++;
    }

    Ficha * pop(){
        if(first==NULL){
            return NULL;
        }else{
            Ficha *datatemp =  first->ficha;
            Nodo *temp =first;
            first = first->next;
            delete temp;

            size--;
            return datatemp;
        }
    }

    Ficha * obtenerFicha(int x){
        if (x == 1)
            return first->ficha;
        else if (x == size)
            return last->ficha;
        else if (first != NULL){
            Nodo *cur= first;
            Nodo *prev;
            for (int i = 0; i < x; ++i) {
                prev = cur;
                cur = cur->next;
            }
            return  prev->ficha;

        }

    }


    int buscarFicha(string letra){
        Nodo *temp = first;
        int i = 1;
        while(temp!=NULL){
            if(temp->ficha->letra == letra){
                return i;
            }
            temp = temp->next;
            i++;
        }
        return NULL;
    }


    void removeFirst() {
           if (first != NULL) {
               Nodo *temp = first;
               first = first->next;
               delete temp;
               --size;
           }
       }

       void removeLast() {
           if (first->next == NULL) {
               removeFirst();
           } else if (first != NULL) {
               Nodo *cur = first;
               Nodo *prev;
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
               Nodo *prev;
               Nodo *cur= first;
               for (int i = 0; i < pos; ++i) {
                   prev = cur;
                   cur = cur->next;
               }
               prev->next = cur->next;
               delete cur;
               size--;
           }
       }

    void eliminarFicha(int x){
        Nodo *temp = first;
        for(int i =0; i<x-2;i++){
            temp = temp->next;
        }
        temp->next= temp->next->next;
        size--;
    }

    void print(){
        if(first==NULL){
        }
        else{
            Nodo *temp = first;
            while (temp!=NULL) {
                cout<<temp->ficha->letra<<endl;
                temp = temp->next;
            }
        }
    }

    void graficarCola(){
        string cadena ="";
        cadena += "digraph G{\n";
        Nodo *aux = first;
        int i =0;
        while(aux!=NULL){
            cadena+="p"+to_string(i)+"[label =  \"Letra: "+aux->ficha->letra+"\\n"
                    "Punteo: "+to_string(aux->ficha->puntos)+"\" shape=box];\n";
            aux = aux->next;
            i++;
        }

        for(int j = 0; j<i-1;j++){
            cadena+="p"+to_string(j)+"->"+"p"+to_string(j+1)+"\n";
        }
        cadena+="}";

        ofstream archivo;
         archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt",ios::out);
         if(archivo.fail()){

             cout<<"no jala el archivo";
             exit(1);
         }
        else{
         archivo<<cadena;
         archivo.close();

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\cola.png");
        }
    }

    /*void generarGraphvizRealizados(){
        string cadena ="";
        cadena += "digraph G{\n";


        int n = 1;
        Nodo * nodoAux = top;
        for (int i = 1; i<size+1;i++)
        {
            cadena +="p";
            string str= to_string(i);
            cadena +=str;
            cadena+="[label = \"";
            if(nodoAux->cambio->getTipo()==true){
                cadena+="Palabra Buscada: NULL \\n";
                cadena+="Palabra Remplazada: NULL \\n";
                cadena+="Estado: No revertido \\n";
                cadena+="Palabra: ";cadena+=nodoAux->cambio->getPalabra();
                cadena+="\\n Posicion: ";//cadena+=nodoAux->cambio->getPosicion();
                cadena+="\\n Agregado";
                if(nodoAux->cambio->getAgregado()){
                    cadena+=" si\" shape=box ,fillcolor=\"#00b33c\" , style=filled]";
                }else{

                    cadena += " no\" shape=box ,fillcolor=\"#00b33c\" , style=filled]";
                }
            }else{

                cadena+="Palabra Buscada: ";cadena+=nodoAux->cambio->getPalabraBuscada();
                cadena+="\\n Palabra Remplazada: ";cadena+=nodoAux->cambio->getPalabraReemplazada();
                cadena+="\\n Estado: No revertido\\n";
                cadena+="Palabra: NULL";
                cadena+="\\n Posicion: NULL";
                cadena+="\\n Agregado: NULL";
                    cadena+="\"shape=box ,fillcolor=\"#00b33c\" , style=filled ;]";

            }
            cadena+="  \n";
            n++;
            nodoAux =  nodoAux->next;
        }
        int aux = n;
        int aux2 = n + 1;
        n = 1;


        for (int i = 0; i < aux-2; i++)
        {

            n++;
        }

        for (int i = 0; i < aux-2; i++)
        {
            cadena += "p";
            string st= to_string(n);
            cadena +=st;
            cadena+=":c->p";
            string str= to_string(n-1);
            cadena +=str;
            cadena+=";\n";
            n--;
        }


        cadena += "}";

         ofstream archivo;
         archivo.open("C:\\Users\\jose_\\OneDrive\\Escritorio\\realizado.txt",ios::out);
         if(archivo.fail()){

             cout<<"no jala el archivo";
             exit(1);
         }
        else{
         archivo<<cadena;
         archivo.close();

         system("dot -Tpng C:\\Users\\jose_\\OneDrive\\Escritorio\\realizado.txt -o C:\\Users\\jose_\\OneDrive\\Escritorio\\realizado.png");
        }
    }*/

};
#endif // COLA_H

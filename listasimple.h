#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>
#include <matriz.h>

using namespace std;
class NodoListaSimple {
public:
    Ficha * data;
    string x;
    string y;
    NodoListaSimple *next;

public:
    NodoListaSimple(Ficha * data, string k , string h) {
        this->data = data;
        this->x = k;
        this->y = h;
        next = NULL;
    }
};

class LinkedList {
public:
    NodoListaSimple *first;
    NodoListaSimple *last;
    int size;

public:
    LinkedList() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    void append(Ficha * data, string x, string y) {
        NodoListaSimple *n = new NodoListaSimple(data,x,y);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
        size++;
    }

    void prepend(Ficha * data, string x, string y) {
        NodoListaSimple *n = new NodoListaSimple(data, x, y);
        if (first == NULL) {
            first = n;
            last = n;
        } else {
            NodoListaSimple *temp = first;
            first = n;
            n->next = temp;
        }
        size++;
    }

    void print() {
        NodoListaSimple *temp = first;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void removeFirst() {
        if (first != NULL) {
            NodoListaSimple *temp = first;
            first = first->next;
            delete temp;
            --size;
        }
    }

    void removeLast() {
        if (first->next == NULL) {
            removeFirst();
        } else if (first != NULL) {
            NodoListaSimple *cur = first;
            NodoListaSimple *prev;
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
            NodoListaSimple *prev;
            NodoListaSimple *cur= first;
            for (int i = 0; i < pos; ++i) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
            size--;
        }
    }

    void insertAt(int pos, Ficha * data, string x, string  y){
        if(pos>size+1 || pos<1)
            return;
        else if (pos==1)
            append(data, x ,y);
        else if (pos==size+1)
            prepend(data,x,y);
        else if (first!=NULL){
            NodoListaSimple *n = new NodoListaSimple(data, x , y);
            NodoListaSimple *prev;
            NodoListaSimple *cur = first;
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
        NodoListaSimple *next;
        while (first!=NULL){
            next = first->next;
            delete first;
            first = next;
        }
    }
};
#endif // LISTASIMPLE_H

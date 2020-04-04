#include <QCoreApplication>
#include <matriz.h>
#include "interfaz.h"
#include <iostream>
#include <conio.h>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include "circulardoble.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <cstddef>
#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "interfaz.h"
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <cstddef>
#include <Winuser.h>
#include <string.h>
#include <ctype.h>
#include "leerjson.h"
#include "cola.h"
#include <cstdlib>
#include <sstream>
#include <listasimple.h>
#include <listaarbol.h>
#include <listascore.h>
using namespace std;

ArbolBinario *arbolJugadores = new ArbolBinario();
leerJson *json = new leerJson();
CircularDoble *dobles = new CircularDoble();
CircularDoble *triples = new CircularDoble();
CircularDiccionario *diccionario = new CircularDiccionario();
Cola *fichas;
Matriz *matriz = new Matriz();
int contadorJugadores =0;
Jugador *jugador1 = NULL;
Jugador *jugador2 = NULL;
LinkedList *fichasUsadas = new LinkedList ();
ListaScore *listaScore = new ListaScore ();
bool archivo = false;

int punteo1 = 0;
int punteo2 = 0;
int dimension=15;
void menu();
void reiniciarCursor();
void inter();
void interprincipal();
void agregarJugador();
void setearCursor(int x, int y);
void limpiarMenu();
void ingresarArchivo();
void agregarFichas();
void jugar();
void setearFichasJugador(Jugador *&jugador);
void ingresarJugador1();
void ingresarJugador2();
void turnoJugador1();
void turnoJugador2();
void limpiarEleccion(int x, int y);
int ingresarX();
int ingresarY();
void menuJugador1();
void menuJugador2();
Ficha *seleccionarFicha();
void cambiarFichas(Jugador *jugador);
void verificarMatriz(Jugador *jugador);
Ficha * ingresarFicha(Jugador *jugador);
void retornarFichas(Jugador *jugador);
void reportes();
void reporteJugador();
void ganador();
void menuSeleccion1();
void menuSeleccion2();

int main(int argc, char *argv[])
{
   /*Ficha *ficha =new Ficha("a",2);
    matriz->add(1,1,ficha);
    matriz->add(1,2,ficha);
    matriz->add(2,1,ficha);
    matriz->graficar();
    matriz->add(2,1,"o");
    matriz->add(3,1,"l");
    matriz->add(4,1,"a");
    matriz->add(5,1,"d");
    matriz->add(5,2,"i");
    matriz->add(5,3,"c");
    matriz->add(5,4,"c");
    matriz->add(5,5,"i");
    matriz->add(5,6,"o");
    matriz->add(5,8,"n");
    matriz->add(5,9,"a");
    matriz->add(5,10,"r");
    matriz->add(5,11,"i");
    matriz->add(5,12,"o");
*/
    NodoArbol *nodoArbol = new NodoArbol("Jose", 1);
    arbolJugadores->agregar(nodoArbol);
    //nodoArbol = new NodoArbol("Juan", 2);
    //arbolJugadores->agregar(nodoArbol);
    //ingresarArchivo();
    menu();
}


void menu(){
    matriz = new Matriz();
    //diccionario->graficar();
    inter();
    interprincipal();
    agregarFichas();
    fichas->graficarCola();
    //ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\edd.png", NULL, NULL, SW_SHOWNORMAL);
    int leer;
    do{
        leer = getch();

    }while(leer<48||leer>53);
    cout<<leer;
    switch (leer) {

        case 52:
            ingresarArchivo();
        break;
        case 51:
            reportes();
        break;
        case 50:
            agregarJugador();
        break;
    case 49:
        jugar();
    break;
    }

}


void agregarJugador(){
    limpiarMenu();
    setearCursor(32,17);
    cout<<"Ingrese el nombre del jugador: ";
    setearCursor(43,18);
    string nombre;
    cin>>nombre;

    NodoArbol *jugador = new NodoArbol(nombre, contadorJugadores);
    setearFichasJugador(jugador->valor);
    contadorJugadores++;
    if(arbolJugadores->buscarJugador(nombre)==NULL){
        arbolJugadores->agregar(jugador);
        setearCursor(43,20);
        cout<<"AGREGADO!";
    }else{
        setearCursor(38,20);
        cout<<"EL NOMBRE YA EXISTE :(";
    }
    setearCursor(0,30);
    arbolJugadores->graphviz();
    reiniciarCursor();

    setearCursor(55,20);
    char x = getch();
    cout<<x;
    arbolJugadores->generarPosorder();
    limpiarMenu();
    menu();
}


void ingresarArchivo(){
    limpiarMenu();
    dobles = new CircularDoble();
    triples = new CircularDoble();
    diccionario = new CircularDiccionario();
    setearCursor(40,18);
    cout<<"INGRESA LA RUTA:";
    setearCursor(26, 19);
    QString rutaJson;
    string ruta;
    cin>>ruta;
    rutaJson = QString::fromStdString(ruta);
     setearCursor(0,32);
    json->jsonExample(rutaJson, dobles, triples, diccionario,dimension);
    //"C:\Users\jose_\OneDrive\Escritorio\entrada.json"
     dobles->print();
     triples->print();
     diccionario->print();
     reiniciarCursor();
     setearCursor(37,22);
     cout<<"AGREGADO EXITOSAMENTE!";
     archivo = true;
     char x = getch();
     limpiarMenu();
     menu();
}


void jugar(){
    if(archivo){
        if(contadorJugadores>1){
            diccionario->reiniciar();
            ingresarJugador1();
            ingresarJugador2();
            punteo1 = 0;
            punteo2 = 0;
            srand(time(0));
            int random = rand()%1 +1;
            if(1 == 1){
                menuJugador1();
            }else{
                turnoJugador2();
            }
        }else{
            limpiarMenu();
            setearCursor(37,22);
            cout<<"INGRESE UN JUGADOR";
            Sleep(600);
            menu();
        }
    }else{
        limpiarMenu();
        setearCursor(37,22);
        cout<<"INGRESE UN ARCHIVO";
        Sleep(600);
        menu();
    }
}


void menuJugador1(){
    limpiarMenu();
    setearCursor(43,17);
    cout<<"JUGADOR 1";
    setearCursor(40, 18);
    cout<<"1. INGRESAR FICHA";
    setearCursor(41, 19);
    cout<<"2. ESCOGER FICHA";
    setearCursor(39, 20);
    cout<<"3. VERIFICAR PALABRA";
    setearCursor(45, 21);
    cout<<"4. SALIR";
    setearCursor(37, 23);
    cout<<"SELECCIONE UNA OPCION: ";
    int leer;
    do{
        leer = getch();

    }while(leer<49||leer>52);
    cout<<leer;
    switch (leer) {

        case 52:
            ganador();
            listaScore->prepend(jugador1, punteo1);
            listaScore->prepend(jugador2, punteo2);
            jugador1->puntajes->append(punteo1);
            jugador2->puntajes->append(punteo2);
            menu();
        break;
        case 51:
            verificarMatriz(jugador1);
        break;
        case 50:
            jugador1->fichas->graficarListaDoble();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
            cambiarFichas(jugador1);
            menuSeleccion1();
            menuJugador2();
        break;
        case 49:
            turnoJugador1();
        break;
    }
}

void turnoJugador1(){
    limpiarMenu();
    setearCursor(43,17);
    cout<<"JUGADOR 1";
    jugador1->fichas->graficarListaDoble();
    ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
    Ficha *temp = ingresarFicha(jugador1);
    int x = ingresarX();
    int y = ingresarY();
    int doble = dobles->buscarDoble(x,y);
    int triple = triples->buscarTriple(x,y);
    bool buscarx = matriz->existeX(x, y);
    bool buscary = matriz->existeY(x,y);
    if(!buscarx && !buscary){
        if(doble == 2){
            matriz->add(x,y , temp,2);
        }else if(triple==3){
            matriz->add(x,y , temp,3);
        }else{
            matriz->add(x,y , temp,1);
        }
        fichasUsadas->append(temp, to_string(x), to_string(y));

    }else{
        limpiarMenu();
        jugador1->fichas->prepend(temp);
        setearCursor(37,22);
        cout<<"YA SE ENCUENTRA OCUPADA ESA CELDA";
        Sleep(600);
    }
    matriz->graficar();
    ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\matriz.png", NULL, NULL, SW_SHOWNORMAL);
    menuJugador1();
}

Ficha * ingresarFicha(Jugador *jugador){
    jugador->fichas->graficarListaDoble();

    setearCursor(40,18);
    cout<<"INGRESA LA FICHA";
    setearCursor(48,19);
    int f = getch();
    std::string s(1, f);
    Ficha *temp = jugador->fichas->getFicha(s);
    if(temp != NULL){
        cout<<s;
        return temp;
    }else{
        setearCursor(40,19);
        cout<<"NO SE ENCONTRO LA FICHA";
        Sleep(200);
        limpiarEleccion(40,18);
        return ingresarFicha(jugador);
    }
}

void ganador(){
    limpiarMenu();
    if(punteo1>punteo2){
        setearCursor(40,19);
        cout<<"JUGADOR 1 ES EL GANADOR";
        Sleep(600);
    }else{
        setearCursor(40,19);
        cout<<"JUGADOR 2 ES EL GANADOR";
        Sleep(600);
    }
}

int ingresarX(){
    limpiarEleccion(36,21);

    setearCursor(36,21);
    cout<<"INGRESA LA COORDENADA EN X";
    setearCursor(48,22);
    int valor = 0;
    string s = "";
    for(int i = 0; i<2; i++){
        char x = getch();
        std::string o(1, x);
        s+=o;
    }
    stringstream geek(s);
    int y = 0;
    geek>>y;
    cout<<y;
    if(y<=dimension){
        return y;
    }else{
        return ingresarX();
    }
}

int ingresarY(){
    limpiarEleccion(36,24);
    setearCursor(36,24);
    cout<<"INGRESA LA COORDENADA EN Y";
    setearCursor(48,25);
    int valor = 0;
    string s = "";
    for(int i = 0; i<2; i++){
        char x = getch();
        std::string o(1, x);
        s+=o;
    }
    stringstream geek(s);
    int y = 0;
    geek>>y;
    cout<<y;
    if(y<=dimension){
        return y;
    }else{
        return ingresarY();
    }
}

void limpiarEleccion(int x, int y){
    setearCursor(2,y);
    for(int i = 0; i<95;i++){
        cout<<" ";
        Sleep(1);
    }
    setearCursor(2,y+1);
    for(int i = 0; i<95;i++){
        cout<<" ";
        Sleep(1);
    }
    setearCursor(x,y);
};

void turnoJugador2(){
    limpiarMenu();
    setearCursor(43,17);
    cout<<"JUGADOR 2";
    jugador2->fichas->graficarListaDoble();
    ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
    Ficha *temp = ingresarFicha(jugador2);
    int x = ingresarX();
    int y = ingresarY();
    int doble = dobles->buscarDoble(x,y);
    int triple = triples->buscarTriple(x,y);

    bool buscarx = matriz->existeX(x, y);
    bool buscary = matriz->existeY(x,y);
    if(!buscarx && !buscary){
        if(doble == 2){
            matriz->add(x,y , temp,2);
        }else if(triple==3){
            matriz->add(x,y , temp,3);
        }else{
            matriz->add(x,y , temp,1);
        }
        fichasUsadas->append(temp, to_string(x), to_string(y));

    }else{
        limpiarMenu();
        jugador2->fichas->prepend(temp);
        setearCursor(37,22);
        cout<<"YA SE ENCUENTRA OCUPADA ESA CELDA";
        Sleep(600);
    }
    matriz->graficar();
    ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\matriz.png", NULL, NULL, SW_SHOWNORMAL);
    menuJugador2();
}


void menuJugador2(){
    limpiarMenu();
    setearCursor(43,17);
    cout<<"JUGADOR 2";
    setearCursor(40, 18);
    cout<<"1. INGRESAR FICHA";
    setearCursor(41, 19);
    cout<<"2. ESCOGER FICHA";
    setearCursor(39, 20);
    cout<<"3. VERIFICAR PALABRA";
    setearCursor(45, 21);
    cout<<"4. SALIR";
    setearCursor(37, 23);
    cout<<"SELECCIONE UNA OPCION: ";
    int leer;
    do{
        leer = getch();

    }while(leer<49||leer>52);
    cout<<leer;
    switch (leer) {

    case 52:
        ganador();
        listaScore->prepend(jugador1, punteo1);
        listaScore->prepend(jugador2, punteo2);
        jugador1->puntajes->append(punteo1);
        jugador2->puntajes->append(punteo2);
        menu();
    break;
    case 51:
        verificarMatriz(jugador2);
    break;
    case 50:
        jugador2->fichas->graficarListaDoble();
        ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
        cambiarFichas(jugador2);
        menuSeleccion2();
        menuJugador1();
    break;
    case 49:
        turnoJugador2();
    break;
    }
}

void verificarMatriz(Jugador *jugador){
    int x = matriz->verificarX(diccionario);
    int y = matriz->verificarY(diccionario);
    if(x!=0 || y!= 0){
        if(jugador->getNombre() == jugador1->getNombre()){
            limpiarMenu();
            setearCursor(41, 19);
            cout<<"SE ENCONTRO UNA PALABRA";
            fichasUsadas = new LinkedList ();
            punteo1 = punteo1 +x +y;
            cout<<punteo1;
            Sleep(600);

            menuJugador2();
        }else
        {
            limpiarMenu();
            setearCursor(41, 19);
            cout<<"SE ENCONTRO UNA PALABRA";
            fichasUsadas = new LinkedList ();
            punteo2 = punteo2 + x + y;
            cout<<punteo2;
            Sleep(600);
            menuJugador1();
        }
    }else{
        if(jugador->getNombre() == jugador1->getNombre()){
            limpiarMenu();
            setearCursor(41, 19);
            retornarFichas(jugador1);
            cout<<"NO SE ENCONTRO UNA PALABRA";
            Sleep(600);
            menuJugador2();
        }else{
            limpiarMenu();
            setearCursor(41, 19);
            retornarFichas(jugador2);
            cout<<"NO SE ENCONTRO UNA PALABRA";
            Sleep(600);
            menuJugador1();
        }

    }
}

void menuSeleccion1(){
    limpiarMenu();
    setearCursor(37,20);
    cout<<"DESEA CAMBIAR OTRA FICHA?";

    setearCursor(42,21);
    cout<<"1. SI     2. NO";
    setearCursor(37, 23);
    cout<<"SELECCIONE UNA OPCION: ";
    int leer;
    do{
        leer = getch();

    }while(leer<49||leer>50);
    cout<<leer;
    if(leer == 49){
        jugador1->fichas->graficarListaDoble();
        ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
        cambiarFichas(jugador1);
        menuSeleccion1();
    }

}

void menuSeleccion2(){
    limpiarMenu();
    setearCursor(37,20);
    cout<<"DESEA CAMBIAR OTRA FICHA?";

    setearCursor(42,21);
    cout<<"1. SI     2. NO";
    setearCursor(37, 23);
    cout<<"SELECCIONE UNA OPCION: ";
    int leer;
    do{
        leer = getch();

    }while(leer<49||leer>50);
    cout<<leer;
    if(leer == 49){
        jugador2->fichas->graficarListaDoble();
        ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\listadoble.png", NULL, NULL, SW_SHOWNORMAL);
        cambiarFichas(jugador2);
        menuSeleccion2();
    }

}

void retornarFichas(Jugador *jugador){
    NodoListaSimple *temp = fichasUsadas->first;
    while (temp !=NULL) {
        jugador->fichas->append(temp->data);

        matriz->eliminar(std::stoi(temp->x), std::stoi(temp->y));
        temp = temp->next;
    }
    fichasUsadas = new LinkedList ();
}


void cambiarFichas(Jugador *jugador){
    limpiarMenu();
    Ficha *ficha = ingresarFicha(jugador);
    fichas->graficarCola();
    ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\cola.png", NULL, NULL, SW_SHOWNORMAL);
    Ficha *nueva = seleccionarFicha();
    jugador->fichas->append(nueva);
    fichas->push(ficha);

}

Ficha *seleccionarFicha(){
    setearCursor(40,21);
    cout<<"INGRESA LA FICHA";
    setearCursor(48,22);
    int f = getch();
    std::string s(1, f);
    int buscar = fichas->buscarFicha(s);
    if(buscar!=0){
        Ficha *temp = fichas->obtenerFicha(buscar);
        if(temp != NULL){
            cout<<s;
            fichas->removeSpecific(buscar);
            return temp;
        }else{
            setearCursor(40,22);
            cout<<"NO SE ENCONTRO LA FICHA";
            Sleep(450);
            limpiarEleccion(40,21);
            return seleccionarFicha();
        }
    }else{

        setearCursor(40,22);
        cout<<"NO SE ENCONTRO LA FICHA";
        Sleep(450);
        limpiarEleccion(40,22);
        return seleccionarFicha();
    }
}

void ingresarJugador1(){
    limpiarMenu();

    setearCursor(33, 17);
    cout<<"Ingrese el nombre del jugador 1:";
    setearCursor(45, 18);
    string nombre;
    cin>>nombre;
    jugador1 = arbolJugadores->buscarJugador(nombre);
    setearCursor(36, 20);
    if(jugador1==NULL){
        cout<<"NO SE ENCONTRO EL JUGADOR";
        Sleep(800);
        ingresarJugador1();
    }else{
        cout<<"SE ENCONTRO EL JUGADOR";
        setearFichasJugador(jugador1);
        Sleep(600);
    }
   // arbolJugadores->generarPreorder(listaArbol);
    //listaArbol->graficar();
}

void ingresarJugador2(){
    string nombre;
    limpiarMenu();
    setearCursor(33, 17);
    cout<<"Ingrese el nombre del jugador 2:";
    setearCursor(45, 18);
    cin>>nombre;
    jugador2 = arbolJugadores->buscarJugador(nombre);
    setearCursor(36, 20);
    if(jugador2==NULL){
        cout<<"NO SE ENCONTRO EL JUGADOR";
        Sleep(800);
        ingresarJugador2();
    }else{
        if(jugador2->getNombre()!= jugador1->getNombre()){
            cout<<"SE ENCONTRO EL JUGADOR";
            setearFichasJugador(jugador2);
            Sleep(600);
        }else{
            cout<<"NO SE ENCUENTRA DISPONIBLE";
            Sleep(800);
            ingresarJugador2();
        }
    }
}

void reportes(){
    limpiarMenu();
    setearCursor(42, 16);
    cout<<"1. DICCIONARIO";
    setearCursor(40, 17);
    cout<<"2. COLA DE FICHAS";
    setearCursor(38, 18);
    cout<<"3. ARBOL DE JUGADORES";
    setearCursor(38, 19);
    cout<<"4. RECORRIDO PREORDER";
    setearCursor(38, 20);
    cout<<"5. RECORRIDO INORDER";
    setearCursor(37, 21);
    cout<<"6. RECORRIDO POSTORDER";
    setearCursor(37, 22);
    cout<<"7. PUNTAJES DE JUGADOR";
    setearCursor(42, 23);
    cout<<"8. SCOREBOARD";
    setearCursor(37, 25);
    cout<<"SELECCIONE UNA OPCION: ";

    int leer;

    do{
        leer = getch();

    }while(leer<48||leer>58);
    cout<<leer;
    switch (leer) {
        case 49:
            diccionario->graficar();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\diccionario.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 50:
            fichas->graficarCola();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\cola.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 51:
            arbolJugadores->graphviz();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\arbolJugadores.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 52:
            arbolJugadores->generarPreorder();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\recorrido.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 53:
            arbolJugadores->generarInorder();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\recorrido.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 54:
            arbolJugadores->generarPosorder();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\recorrido.png", NULL, NULL, SW_SHOWNORMAL);
        break;
        case 55:
            reporteJugador();
        break;
        case 56:
            listaScore->graficar();
            ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\score.png", NULL, NULL, SW_SHOWNORMAL);
        break;

    }

    menu();
}

void reporteJugador(){
    limpiarMenu();

    setearCursor(34, 17);
    cout<<"Ingrese el nombre del jugador:";
    setearCursor(45, 18);
    string nombre;
    cin>>nombre;
    Jugador *jugador = arbolJugadores->buscarJugador(nombre);
    setearCursor(36, 20);
    if(jugador==NULL){
        cout<<"NO SE ENCONTRO EL JUGADOR";
        Sleep(800);
        reporteJugador();
    }else{
        cout<<"SE ENCONTRO EL JUGADOR";
        jugador->puntajes->graficar();
        ShellExecuteA(NULL, "open","C:\\Users\\jose_\\OneDrive\\Escritorio\\Juego\\puntajes.png", NULL, NULL, SW_SHOWNORMAL);
        Sleep(600);
    }
   // arbolJugadores->generarPreorder(listaArbol);
    //listaArbol->graficar();
}

void menuCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 30;
    pos.Y = 21;

    SetConsoleCursorPosition(hcon, pos);
}

void reiniciarCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 0;
    pos.Y = 0;

    SetConsoleCursorPosition(hcon, pos);
}

void setearCursor(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hcon, pos);
}

void inter(){

    system("cls");
    string titulo = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKXWW\n"
                   "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXNWMMMWNOdo0MMMMNkl;,'';x\n"
                   "MMMMMMMMMMMMMWNKOkkOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNNWWX0OOkxONMMMN0l;cdc,lKMMNO; .OMMNk;.,dkd, .\n"
                   "MMMMMMMMMMWXx:,,,,'.cXMMMMMMMMMWNXK00OO0NMMMMMMWKOo,':0Kl..ld,.cXMWXd..dXx..kMMNx. cNWXo..cXMN0:..\n"
                   "MMMMMMMMWXd'.:kKKK0OXWNOdlloONNOc.,odl,.,OWMMWXk;....lXO; :K0:.lNMW0: ,kx,'xNMW0:..kWXo..cKK0Od,.'\n"
                   "MMMMMMMWXo. ,0MMMMMWKd,.;c:'.dXd..lNWXd. lNMNO:,:c, 'ONo..:d;.:0MMXd..:o:.'ckNNx' cXNk, .x0xdxxkk0\n"
                   "MMMMMMMNO;...oNMMMNk;.'xNWKkdO0:..kMWKc.,0N0l,:kx:. cX0;.,dxl'.,xN0: ,0NKd. 'kKc..kWXx' .kWWWWXKNM\n"
                   "MMMMMMMWKo....oNMNk, ,OMMMWWWNx. c0Od;,oKKd,;oxd,. .kNd..dWNKc. ;0x..oWWXo. ,kk' :XMNk; .;kK0xcxNM\n"
                   "MMMMMMMMNKd,...oN0:..dWMMMMMWKc..xk;..:Ox;'oK0kl.  cX0; ,KMNk, .d0c.,0WKo..;O0c..oKKOd:,'.,,'cOWMM\n"
                   "MMMMMMMMMWKx,. ,Ok' 'OMMMMMWNx' cXXkc....;0WMW0:. .kNd..lKOl..;kXx'.,ll;,cxXNOo:ldxxxxOXOdooONMMMM\n"
                   "MMMMMMMMMMN0c. :0k, .lNMWXxx0l..kMMNKx:..'oKWNk,..cKKl,,clccoONWXOxxkO0KXWMMWNNWWWWWWXOkxk0WMMMMMM\n"
                   "MMMMMMMMMMWO;.:0N0o'..,looxKk;.cXMMMWNKkl;.':dxkO0XNXXXXNNNWWMMMWWMMMMMMMMMMMMMMNKOkxxk0NMMMMMMMMM\n"
                   "WNWMMMMMWKd;;dXMMWXOdoox0NWNK00XMMMMMMMWNKOo:,,:lodkKXWMMMMMMMMMMMMMMMMMWNXK0kkkxxxOXWWMMMMWMWWWWM\n"
                   "0xdxxxxxdlokNMMMMMMWWWWMMMMMMMMMMMMMMMMMMMWNNK0xolcccloodddxxxkkkkxxxxkkxxxxxk0XNWWWWWWWWWWNNNNNNW\n"
                   "XKkdoodx0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNNXK0OkxdolllllooddxO0KXNWWWMMMMMMMMWWMMMMMWWMMWM\n";
     cout<<titulo;

     for(int j=0; j<12; j++){
         char x = 186;
         cout<<x;
         for(int i = 0; i<96;i++){
             cout<<" ";
         }
         cout<<x<<endl;;
     }char m = 200;
     cout<<m;
     for(int i = 0; i<96;i++){
         char x = 205;
         cout<<x;
     }char y = 188;
     cout<<y<<endl;

}


void interprincipal(){
    setearCursor(45, 17);
    cout<<"1. JUGAR";
    setearCursor(39, 18);
    cout<<"2. INGRESAR JUGADOR";
    setearCursor(43, 19);
    cout<<"3. REPORTES";
    setearCursor(39, 20);
    cout<<"4. INGRESAR ARCHIVO";
    setearCursor(37, 22);
    cout<<"SELECCIONE UNA OPCION: ";
}

void setearFichasJugador(Jugador *&jugador){
    jugador->fichas = new ListaDoble();
    srand(time(0));
    for(int i=0;i<7;i++){
        int size = fichas->size-1;
        int v1 = rand() % size;
        v1++;
        Ficha *temp = fichas->obtenerFicha(v1);
        Ficha *nueva = new Ficha(temp->letra,temp->puntos);
        jugador->fichas->prepend(nueva);
        fichas->removeSpecific(v1);
    }
    //jugador->fichas->print();

}


void agregarFichas(){
    fichas = new Cola();
    Ficha *ficha = NULL;
    for(int i = 0; i<12;i++){
        ficha = new Ficha("a",1);
        fichas->push(ficha);
        ficha = new Ficha("e",1);
        fichas->push(ficha);
    }
    for(int i = 0; i<9; i++){
        ficha = new Ficha("o",1);
        fichas->push(ficha);
    }
    for(int i = 0; i<6; i++){
        ficha = new Ficha("i",1);
        fichas->push(ficha);
        ficha = new Ficha("s",1);
        fichas->push(ficha);
    }
    for(int i = 0; i<5; i++){
        ficha = new Ficha("n",1);
        fichas->push(ficha);
        ficha = new Ficha("r",1);
        fichas->push(ficha);
        ficha = new Ficha("u",1);
        fichas->push(ficha);
        ficha = new Ficha("d",2);
        fichas->push(ficha);
    }
    for(int i = 0; i<4; i++){
        ficha = new Ficha("l",1);
        fichas->push(ficha);
        ficha = new Ficha("t",1);
        fichas->push(ficha);
    }
    for(int i = 0; i<2; i++){
        ficha = new Ficha("g",2);
        fichas->push(ficha);
        ficha = new Ficha("b",3);
        fichas->push(ficha);
        ficha = new Ficha("m",3);
        fichas->push(ficha);
        ficha = new Ficha("p",3);
        fichas->push(ficha);
        ficha = new Ficha("h",4);
        fichas->push(ficha);
    }
    ficha = new Ficha("f",4);
    fichas->push(ficha);
    ficha = new Ficha("v",4);
    fichas->push(ficha);
    ficha = new Ficha("y",4);
    fichas->push(ficha);
    ficha = new Ficha("q",5);
    fichas->push(ficha);
    ficha = new Ficha("j",8);
    fichas->push(ficha);
    ficha = new Ficha("ñ",8);
    fichas->push(ficha);
    ficha = new Ficha("x",8);
    fichas->push(ficha);
    ficha = new Ficha("z",10);
    fichas->push(ficha);
}


void limpiarMenu(){
    setearCursor(0,15);
    for(int j=0; j<12; j++){
        char x = 186;
        cout<<x;
        for(int i = 0; i<96;i++){
            cout<<" ";
        }

        cout<<x<<endl;;
        Sleep(15);
    }char m = 200;
    cout<<m;
    for(int i = 0; i<96;i++){
        char x = 205;
        cout<<x;
    }char y = 188;
    cout<<y<<endl;
    /* if(leer ==13){
         reiniciarCursor();
         for(int j = 0; j<35; j++){
             for(int i = 0; i<98;i++){
                 char x = 20;
                 cout<<" ";
             }
             Sleep(15);
         }

         reiniciarCursor();
     }*/
}

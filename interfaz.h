#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <conio.h>

using namespace std;

class Interfaz
{
public:
    Interfaz();


    void editor(){
        system("color E0");
        //-----------------
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=201;
            }else if(i==99){
                x=187;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;

        for(int i = 0; i<25;i++){
            char x = 186;
            cout<<x;
            for(int j = 0;j<98;j++){
                cout<<" ";

            }

            cout<<x<<endl;
        }
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=200;
            }else if(i==99){
                x=188;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;
        cout<<"             ";
        for(int i =0; i<3;i++){
            if(i==0){
                cout<<"Buscar y reemplezar(^w)";
            }else if(i==1){
                cout<<"Reportes(^c)";
            }else if(i==2){
                cout<<"Guardar(^s)";
            }
            cout<<"             ";
        }cout<<endl;
        //--------------------------------------

    }

    void principal(){
        system("color E0");
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=201;
            }else if(i==99){
                x=187;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;

        for(int i = 0; i<25;i++){
            char x = 186;
            cout<<x;
            if(i==0){
                cout<<"       UNIVERSIDAD SAN CARLOS DE GUATEMALA       ";
            }else if(i==1){
                cout<<"       FACULTAD DE INGENIERIA                    ";
            }else if(i==2){
                cout<<"       ESTRUCTURAS DE DATOS                      ";
            }else if(i==3){
                cout<<"       PROYECTO 1                                ";
            }else if(i==4){
                cout<<"       JOSE EDUARDO MORAN REYES                  ";
            }else if(i==5){
                cout<<"       201807455                                 ";
            }else if(i==14){
                cout<<"       MENU                                      ";
            }else if(i==15){
                cout<<"       1.Crear Archivo                           ";
            }else if(i==16){
                cout<<"       2.Abrir Archivo                           ";
            }else if(i==17){
                cout<<"       3.Abrir Archivos Recientes                ";
            }else if(i==18){
                cout<<"       4.Salir                                   ";
            }else if(i==20){
                cout<<"       Seleccione una opcion:                    ";
            }else{
                cout<<"                                                 ";
            }

            for(int j = 0;j<98-49;j++){
                cout<<" ";

            }
            cout<<x<<endl;
            string titulo = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKXWW"
                   "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXNWMMMWNOdo0MMMMNkl;,'';x"
                   "MMMMMMMMMMMMMWNKOkkOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNNWWX0OOkxONMMMN0l;cdc,lKMMNO; .OMMNk;.,dkd, ."
                   "MMMMMMMMMMWXx:,,,,'.cXMMMMMMMMMWNXK00OO0NMMMMMMWKOo,':0Kl..ld,.cXMWXd..dXx..kMMNx. cNWXo..cXMN0:.."
                   "MMMMMMMMWXd'.:kKKK0OXWNOdlloONNOc.,odl,.,OWMMWXk;....lXO; :K0:.lNMW0: ,kx,'xNMW0:..kWXo..cKK0Od,.'"
                   "MMMMMMMWXo. ,0MMMMMWKd,.;c:'.dXd..lNWXd. lNMNO:,:c, 'ONo..:d;.:0MMXd..:o:.'ckNNx' cXNk, .x0xdxxkk0"
                   "MMMMMMMNO;...oNMMMNk;.'xNWKkdO0:..kMWKc.,0N0l,:kx:. cX0;.,dxl'.,xN0: ,0NKd. 'kKc..kWXx' .kWWWWXKNM"
                   "MMMMMMMWKo....oNMNk, ,OMMMWWWNx. c0Od;,oKKd,;oxd,. .kNd..dWNKc. ;0x..oWWXo. ,kk' :XMNk; .;kK0xcxNM"
                   "MMMMMMMMNKd,...oN0:..dWMMMMMWKc..xk;..:Ox;'oK0kl.  cX0; ,KMNk, .d0c.,0WKo..;O0c..oKKOd:,'.,,'cOWMM"
                   "MMMMMMMMMWKx,. ,Ok' 'OMMMMMWNx' cXXkc....;0WMW0:. .kNd..lKOl..;kXx'.,ll;,cxXNOo:ldxxxxOXOdooONMMMM"
                   "MMMMMMMMMMN0c. :0k, .lNMWXxx0l..kMMNKx:..'oKWNk,..cKKl,,clccoONWXOxxkO0KXWMMWNNWWWWWWXOkxk0WMMMMMM"
                   "MMMMMMMMMMWO;.:0N0o'..,looxKk;.cXMMMWNKkl;.':dxkO0XNXXXXNNNWWMMMWWMMMMMMMMMMMMMMNKOkxxk0NMMMMMMMMM"
                   "WNWMMMMMWKd;;dXMMWXOdoox0NWNK00XMMMMMMMWNKOo:,,:lodkKXWMMMMMMMMMMMMMMMMMWNXK0kkkxxxOXWWMMMMWMWWWWM"
                   "0xdxxxxxdlokNMMMMMMWWWWMMMMMMMMMMMMMMMMMMMWNNK0xolcccloodddxxxkkkkxxxxkkxxxxxk0XNWWWWWWWWWWNNNNNNW"
                   "XKkdoodx0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNNXK0OkxdolllllooddxO0KXNWWWMMMMMMMMWWMMMMMWWMMWM";
            cout<<titulo;
        }
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=200;
            }else if(i==99){
                x=188;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;
    }
    void archivo(){
        system("color E0");
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=201;
            }else if(i==99){
                x=187;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;

        for(int i = 0; i<25;i++){
            char x = 186;
            cout<<x;


            for(int j = 0;j<98;j++){
                cout<<" ";

            }
            cout<<x<<endl;
        }
        for(int i = 0; i<100;i++){
            char x;
            if(i==0){
            x=200;
            }else if(i==99){
                x=188;
            }else{
            x  = 205;
            }
            cout<<x;
        }cout<<" "<<endl;

    }


};


#endif // INTERFAZ_H

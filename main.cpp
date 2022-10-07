#include <iostream>
#include "Lista.cpp"
#include "Lista.h"

using namespace std;

int main() {
    Lista* newList = new Lista();
    char option;
    cout << "°|    ------------------------------------------    |°" << endl;
    cout << "°|              BIENVENIDO AL PROGRAMA              |°" << endl;
    cout << "°|    ------------------------------------------    |°" << endl;
    bool flag= true;
    do {
      newList->mostrarMenu();
      cout << "\nOpcion: ";
      cin>>option;

         if(option=='1') {  //Inserta los elementos al inicio
            char next;
            do{
                cout<<"\nIngrese el numero que desea insertar"<<endl;
                int dato;
                cin>>dato;
                newList->insertarAlInicio(dato);
                cout<<"\nDesea agregar un nuevo dato(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option=='2') { //Inserta elementos al final
            char next;
            do{
                cout<<"\nIngrese el numero que desea insertar"<<endl;
                int dato;
                cin>>dato;
                newList->insertarAlFinal(dato);
                cout<<"\nDesea agregar un nuevo dato(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
         }

        else if(option=='3') {  //Muestra los elementos de la lista
            newList->mostrarLista();
        }

        else if(option=='4') {
             if (newList->cabeza == nullptr) {
                 cout << "Lista vacia" << endl;
             } else {
                 char next;
                 do {
                     cout << "\nIngrese el numero que desea buscar" << endl;
                     int dato;
                     cin >> dato;
                     newList->buscarElemento(dato);
                     cout << "\nDesea buscar otro elemento(s/n): " << endl;
                     cin >> next;
                 } while (next == 's' || next == 'S');
             }
         }

        else if(option=='5') {
             if (newList->cabeza == nullptr) {
                 cout << "Lista vacia" << endl;
             } else {
                 char next;
                 do {
                     cout << "\nIngrese la posicion que desea ver" << endl;
                     int dato;
                     cin >> dato;
                     newList->buscarPosicion(dato);
                     cout << "\nDesea ver otra posicion(s/n): " << endl;
                     cin >> next;
                 } while (next == 's' || next == 'S');
             }
         }

        else if(option=='6') {
             if (newList->cabeza == nullptr) {
                 cout << "Lista vacia" << endl;
             } else {
                 char next;
                 do {
                     cout << "\nIngrese el numero que desea eliminar" << endl;
                     int dato;
                     cin >> dato;
                     newList->eliminarPorValor(dato);
                     cout << "\nDesea eliminar otro elemento(s/n): " << endl;
                     cin >> next;
                 } while (next == 's' || next == 'S');
             }
         }

        else if(option=='7') {
             if (newList->cabeza == nullptr) {
                 cout << "Lista vacia" << endl;
             } else {
                 char next;
                 do {
                     cout << "\nIngrese la posicion que desea eliminar" << endl;
                     int dato;
                     cin >> dato;
                     newList->elimininarPos(dato);
                     cout << "\nDesea eliminar otra posicion(s/n): " << endl;
                     cin >> next;
                 } while (next == 's' || next == 'S');
             }
         }

        else if(option=='8') {
             if (newList->cabeza == nullptr) {
                 cout << "Lista vacia" << endl;
             } else {
                 char next;
                 do {
                     cout << "\nIngrese la posicion que desea modificar" << endl;
                     int pos;
                     cin >> pos;
                     cout << "\nIngrese el nuevo dato" << endl;
                     int num;
                     cin >> num;
                     newList->modificarPos(pos, num);
                     cout << "\nDesea modificar otra posicion(s/n): " << endl;
                     cin >> next;
                 } while (next == 's' || next == 'S');
             }
         }

         else if (option=='9'){
             flag=false;
             cout << "\n°|    ------------------------------------------    |°" << endl;
             cout << "°|                PROGRAMA FINALIZADO               |°" << endl;
             cout << "°|    ------------------------------------------    |°" << endl;
         }

        else {
            cout<<"Caracter no valido"<<endl;
        }

    } while (flag==true);

  }
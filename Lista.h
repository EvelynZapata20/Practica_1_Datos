#ifndef PRACTICA_1_DATOS_LISTA_H
#define PRACTICA_1_DATOS_LISTA_H

#include "iostream"
#include "string"
using namespace std;

class Node{
private:
    int dato;
    Node* siguiente;
public:
    Node();
    Node(int dato);
    void setDato(int dato);
    void setNext(Node* siguiente);
    int getDato();
    Node* getNext();
};

class Lista {
public:
    Node* cabeza;
    Lista();
    void mostrarMenu();
    void insertarAlInicio(int dato);
    void insertarAlFinal(int dato);
    void mostrarLista();
    void buscarElemento(int busca);
    void buscarPosicion(int pos);
    void eliminarPorValor(int borrar);
    void elimininarPos(int num);
    void modificarPos(int pos, int num);
};


#endif //PRACTICA_1_DATOS_LISTA_H

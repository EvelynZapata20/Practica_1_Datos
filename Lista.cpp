#include "Lista.h"
#include <iostream>

using namespace std;

Node::Node() {
    this -> dato = NULL;
    this -> siguiente = nullptr;
}

Node::Node(int dato) {
    this -> dato = dato;
    this -> siguiente = nullptr;
}

Node *Node::getNext() {
    return this -> siguiente;
}

void Node::setNext(Node *siguiente) {
    this -> siguiente = siguiente;
}

int Node::getDato() {
    return this -> dato;
}

void Node::setDato(int dato) {
    this -> dato = dato;
}

Lista::Lista() {
    this -> cabeza = nullptr;
}

void Lista::mostrarMenu(){
    cout << "\nIngrese 0 para mostrar el menu" << endl;
    char mostrar;
    cin>>mostrar;
    if (mostrar=='0') {
        cout << "\n°|    ------------------------------------------    |°" << endl;
        cout << "°|       ELIJA UNA DE LAS SIGUIENTES OPCIONES       |°" << endl;
        cout << "°|    ------------------------------------------    |°" << endl;
        cout << "°|          1. INSERTAR ELEMENTO Al INICIO          |°" << endl;
        cout << "°|           2. INSERTAR ELEMENTO Al FINAL          |°" << endl;
        cout << "°|               3. MOSTRAR ELEMENTOS               |°" << endl;
        cout << "°|                4. BUSCAR ELEMENTO                |°" << endl;
        cout << "°|                5. BUSCAR POSICION                |°" << endl;
        cout << "°|                6. BORRAR ELEMENTO                |°" << endl;
        cout << "°|                7. BORRAR POSICION                |°" << endl;
        cout << "°|              8. MODIFICAR POSICION               |°" << endl;
        cout << "°|                     9. SALIR                     |°" << endl;
        cout << "° -------------------------------------------------- °" << endl;
    }
    else {
        cout<<"\nCaracter no valido" << endl;
        return mostrarMenu();
    }
}

void Lista::insertarAlInicio(int dato) {
    Node* nuevaHead = new Node(dato);
    nuevaHead -> setNext(this -> cabeza);
    this -> cabeza = nuevaHead;
}

void Lista::insertarAlFinal(int dato) {
    Node* nuevo= new Node(dato);
    Node* aux;
    if (this->cabeza == nullptr){
        this->cabeza = nuevo;
    }
    else{
        aux= this-> cabeza;
        while (aux -> getNext() != nullptr){
            aux= aux->getNext();
        }
        aux->setNext(nuevo);
    }
    cout << "Elemento " << dato <<" agregado a la lista correctamente\n";
}

void Lista::mostrarLista() {
    Node* temp = this -> cabeza;
    if(temp == nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else {
        cout << "Los elementos de la lista son: " <<endl;
        while (temp != nullptr) {
            cout << temp->getDato() << " -> ";
            if (temp->getNext() == nullptr) {
                cout << "NULL";
                break;
            }
            temp = temp->getNext();
        }
    }
}

void Lista::buscarElemento(int busca) {
    int pos=0, cont=0;
    Node *lista= this->cabeza;
    while (lista!=nullptr){
        if(lista->getDato()!= busca){
            lista= lista->getNext();
            pos++;
        }
        else {
            cont ++;
            break;
        }
    }
    if (cont != 0) {
        cout << "\nEl elemento " << busca << " se encuentra en la posicion " << pos+1 << " de la lista" <<endl;
    }
    else {
        cout << "\nEl elemento " << busca<< " no se encuentra" << endl;
    }
}

void Lista::buscarPosicion(int pos) {
    int original=pos;
    Node* actual=this->cabeza;
    while (pos-1>0 && actual != nullptr){
        actual= actual->getNext();
        pos--;
    }
    if (pos!=1){
        cout << "No existe esa posicion" << endl;
    }
    else {
        cout << "El elemento de la posicion " << original << " es " << actual->getDato() << endl;
    }
}

void Lista::eliminarPorValor(int borrar) {
    Node* actual = this -> cabeza;
    Node* anterior = nullptr;
    if (actual->getDato()==borrar){
        this -> cabeza = actual -> getNext();
        cout<<"Elemento "<< borrar << " eliminado correctamente"<< endl;
    }
    else{
        while(actual != nullptr && actual->getDato()!=borrar){
            anterior = actual;
            actual = actual->getNext();
        }
        if (actual==nullptr){
            cout<<"El elemento no existe"<< endl;
        }
        else{
            anterior->setNext(actual->getNext());
            delete actual;
            cout<<"Elemento "<< borrar << " eliminado correctamente"<< endl;
        }
    }
}

void Lista::elimininarPos(int posEliminar) {
    Node* actual= this -> cabeza;
    Node* anterior= nullptr;
    Node* siguiente = actual -> getNext();
    int original=posEliminar;
    if(posEliminar == 1){
        this -> cabeza = siguiente;
        cout<<"Posicion "<< original << " eliminada correctamente"<< endl;
    }
    else{
        while(posEliminar-1 > 0 && actual != nullptr){
            anterior = actual;
            actual = anterior -> getNext();
            posEliminar --;
        }
        if(posEliminar>1){
            cout<<"La posicion no existe"<< endl;
        }
        else {
            anterior->setNext(actual->getNext());
            delete actual;
            cout << "Posicion " << original << " eliminada correctamente" << endl;
        }
    }
}

void Lista::modificarPos(int posMod, int cambio) {
    Node* actual= this -> cabeza;
    int original=posMod;
        while(posMod-1 > 0 && actual != nullptr){
            actual = actual -> getNext();
            posMod --;
        }
        if(posMod>1){
            cout<<"La posicion no existe"<< endl;
        }
        else {
            actual->setDato(cambio);
            cout << "Elemento de la posicion " << original << " modificado a " << cambio << endl;
        }
    }

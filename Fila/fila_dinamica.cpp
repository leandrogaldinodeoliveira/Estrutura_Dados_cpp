#include <iostream>
using namespace std;

// A classe Item representa um nó da pilha
class Item {

private:

int valor;
Item* proximo;

public:

Item (int); // Construtor
void setChave (int); // Altera o valor de x
int getChave (); // Retorna o valor de x
void setProx (Item *); // Altera o ponteiro prox
Item* getProx (); // Retorna o ponteiro prox

};

class Fila {

private: 

int quantidade;
Item * primeiro;
Item * ultimo;

public:    

Fila (); //Cria uma fila vazia
~Fila(); // Destrutor da fila

void setPrimeiro (Item *);
void setUltimo (Item *);
Item * getPrimeiro ();
Item * getUltimo ();

bool vazia ();
void imprimir ();
void enfileirar (int x);
int desenfileirar ();

};

// IMPLEMENTAÇÃO DA CLASSE ITEM

Item::Item(int x){

    this-> setChave(x);
    this-> setProx(NULL);
}
void Item::setChave (int x){
    this-> valor = x;
}
int Item::getChave (){
return this->valor;
}
void Item::setProx(Item* p){
this-> proximo = p;
}
Item* Item::getProx(){
return this-> proximo;    
}

// IMPLEMENTAÇÃO DA CLASSE FILA

Fila::Fila (){

this-> quantidade = 0;
this-> setPrimeiro(NULL);
this-> setUltimo(NULL); 
}

Fila::~Fila() {
    Item* atual = this->primeiro;

    while (atual != NULL) {
        Item* proximo = atual->getProx();
        delete atual;
        atual = proximo;
    }
}



void Fila::setPrimeiro (Item* p){
    this-> primeiro = p;
}
void Fila::setUltimo (Item* p){
    this-> ultimo = p;
}
Item* Fila::getPrimeiro (){

    return this-> primeiro;
}
Item* Fila:: getUltimo(){
    
    return this-> ultimo;
}
bool Fila::vazia(){

    return this->quantidade == 0 && this-> primeiro == NULL && this-> ultimo == NULL;
}

void Fila::enfileirar(int x) { 
    // função que recebe o valor x que será colocado no fim da fila

    Item* novo = new Item(x); 
    // cria um novo nó na heap, com valor x e proximo = NULL

    if (this->vazia()) { 
        // verifica se a fila está vazia

        this->setPrimeiro(novo); 
        // se a fila está vazia, o primeiro nó da fila passa a ser o novo nó

        this->setUltimo(novo); 
        // como só existe um nó, o último nó da fila também é o novo nó
    } 
    else { 
        // caso a fila já tenha pelo menos um nó

        this->ultimo->setProx(novo); 
        // o atributo proximo do nó que atualmente é o último passa a apontar para o novo nó

        this->setUltimo(novo); 
        // agora o ponteiro ultimo da fila passa a apontar para o novo nó
    }

    this->quantidade++; 
    // aumenta em 1 a quantidade de elementos da fila
}
int Fila::desenfileirar(){ 

if(this->vazia()) {
    return -1;}

Item* removido = this->getPrimeiro();
int valor = removido->getChave();

this-> setPrimeiro(removido->getProx());

delete removido;
this->quantidade--;

if (this->quantidade == 0) {
        this->setUltimo(NULL);
    }

return valor;
}

void Fila::imprimir() {
    Item* atual = this->primeiro;

    while (atual != NULL) {
        cout << atual->getChave();

        if (atual->getProx() != NULL) {
            cout << " ";
        }

        atual = atual->getProx();
    }

    cout << endl;
}

int main () {
    char op;
    int x;
    Fila *fila= new Fila ();

    while (cin>> op) {
        switch (op) {

            case 'E': cin>> x;

            fila-> enfileirar(x);
            break;

            case 'D': if (!fila->vazia()) {
                x = fila->desenfileirar();
                cout<< "<" << x << ">\n";
            }
            break;

            case 'M': fila->imprimir();
            break;
        }
    }
            delete fila;
            return 0;
        }

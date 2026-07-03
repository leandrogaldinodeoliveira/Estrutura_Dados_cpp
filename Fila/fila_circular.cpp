#include <iostream>
using namespace std;

class Fila_Circular {

private:

int inicio;
int final;
int tamanho;
int* itens;

public:

Fila_Circular (int);
~Fila_Circular ();

void setItens(int, int);
void setTamanho(int);
void setFinal(int);
void setInicio(int);

int getItens (int);
int getTamanho ();
int getFinal ();
int getInicio ();


bool vazia();
bool cheia();
void mostra();

void enfileirar (int);
int desenfileirar();

};

//IMPLEMENTAÇÃO

//construtor e destrutor
Fila_Circular::Fila_Circular(int tam){

this-> setInicio(0);
this-> setFinal(0);
this-> setTamanho(tam);
this-> itens = new int [tam];
}
Fila_Circular::~Fila_Circular (){
delete [] itens;
}

//funções setters
void Fila_Circular::setInicio(int i){
this-> inicio = i;
}
void Fila_Circular::setFinal(int f){
this-> final = f;
}
void Fila_Circular::setTamanho(int tam){
this-> tamanho = tam;
}
void Fila_Circular::setItens (int i, int valor){
this-> itens[i] = valor;
}

//funções getters
int Fila_Circular::getInicio(){
return this->inicio;
}
int Fila_Circular::getFinal(){
return this->final;
}
int Fila_Circular::getTamanho(){
return this-> tamanho;
}
int Fila_Circular::getItens(int i){
return this-> itens[i];
}

//analisadores
bool Fila_Circular::vazia (){
return this-> getInicio() == this-> getFinal();
}
bool Fila_Circular::cheia() {
return ((this-> getFinal() + 1) % this->getTamanho()) == this->getInicio();
}
void Fila_Circular::mostra() {
    int i = this->getInicio();

    while (i != this->getFinal()) {
        cout << this->getItens(i) << " ";
        i = (i + 1) % this->getTamanho();
    }

    cout << endl;
}

void Fila_Circular::enfileirar(int x){
    this->setItens(this->getFinal(), x);
    this->setFinal((this->getFinal() + 1) % this->getTamanho());
}
int Fila_Circular::desenfileirar() {
    int valor = this->getItens(this->getInicio());
    this->setInicio((this->getInicio() + 1) % this->getTamanho());
    return valor;
}

int main () {

int n, x;
cin>> n;
Fila_Circular fila(n);
char op;
while (cin>> op) {
    switch (op) {

        case 'E': cin>> x;
        if (!fila.cheia() && x > 0) {
            fila.enfileirar(x);
        }
        break;
        
        case 'D': if (!fila.vazia()) {
            x = fila.desenfileirar();
            cout<< x << "\n";
        }
        break;
        
        case 'M': if (!fila.vazia()) {
            fila.mostra();
        }
        break;
    }
}
return 0;
}

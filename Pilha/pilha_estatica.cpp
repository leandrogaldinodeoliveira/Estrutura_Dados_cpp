#include <iostream>
using namespace std;

//Interface:
class Pilha {

private:

int* itens;
int tamanho;
int topo;

public: 

Pilha (int);
~Pilha ();

bool cheia();
bool vazia();
void printBottomUp();
void printTopDown ();
void empilhar (int);
int desempilhar ();

//Métodos set e get:
void setItens (int, int);
void setTamanho (int);
void setTopo (int);

int getItens (int);
int getTamanho ();
int getTopo ();
};

//Implementação:

Pilha::Pilha (int tam) {
this-> setTamanho(tam);
this->itens = new int [tam];
this->setTopo(-1);    
}
Pilha::~Pilha (){
delete [] this->itens;

} 

void Pilha::setItens (int i, int valor) {
this-> itens[i] = valor;

}
void Pilha::setTamanho (int tam){
this-> tamanho = tam;
}
void Pilha::setTopo (int t){
this-> topo = t;
}

int Pilha::getItens (int i) {
return this-> itens[i];
}
int Pilha::getTamanho (){
return this-> tamanho;
}
int Pilha::getTopo (){
return this-> topo;
}


// Imprime do topo para a base:
void Pilha::printTopDown() {
    int i;

    for (i = this->getTopo(); i >= 0; i--) {
        cout << this->getItens(i) << " ";
    }

    cout << endl;
}
// Imprime da base para o topo:
void Pilha::printBottomUp() {
    int i;

    for (i = 0; i <= this->getTopo(); i++) {
        cout << this->getItens(i) << " ";
    }

    cout << endl;
}

// Empilha no topo:
void Pilha::empilhar(int x) {
    this->setTopo(this->getTopo() + 1);
    this->setItens(this->getTopo(), x);
}
// Desempilha do topo:
int Pilha::desempilhar() {
    int valor = this->getItens(this->getTopo());
    this->setTopo(this->getTopo() - 1);
    return valor;
}

bool Pilha::vazia() {
    return this->getTopo() == -1;
}
bool Pilha::cheia() {
    return this->getTopo() == this->getTamanho() - 1;
}


//Código-cliente:
int main () {

int n, x;
std::cin >> n;
Pilha pilha (n);

char op;

while(cin >> op) {

switch(op) {

case 'E': cin >> x;
if (!pilha.cheia ()) {
pilha.empilhar (x);
}
break;

case 'D': if(!pilha.vazia ()) {
x = pilha.desempilhar ();
}
break;

case 'T': pilha.printTopDown ();
break;

case 'B': pilha.printBottomUp ();
break;
}

}
return 0;
}

#include <iostream>
using namespace std;

//INTERFACE
class Fila {

private:

int tamanho, inicio, fim, *itens;

public:

Fila (int); // Construtor
~Fila (); // Destrutor

bool vazia(); // Fila Vazia
bool cheia(); // Fila Cheia
void mostra (); // Mostra a Fila

void enfileirar (int); // Adicionar
int desenfileirar (); // Remover

};

// IMPLEMENTAÇÃO

//Construdor e Destrutor:
Fila::Fila (int tam) {

    this-> tamanho = tam;
    this-> inicio = -1;
    this-> fim = -1;
    this-> itens = new int[tam];
}
Fila::~Fila () {
     delete[] this->itens;
}


bool Fila::vazia(){
  return  this-> inicio == -1 && this-> fim == -1;
}
bool Fila::cheia(){

   return this->fim == this-> tamanho -1;
}

void Fila::enfileirar (int x){
    
    if (this->vazia()) {
        this->inicio = 0;
        this->fim = 0;
    } else {
        this->fim++;
    }
    this->itens[this->fim] = x;
}
int Fila::desenfileirar() {
    int valor = this->itens[this->inicio];

    if (this->inicio == this->fim) {
        this->inicio = -1;
        this->fim = -1;
    } else {
        this->inicio++;
    }

    return valor;
}


int main () {
    int n, x;
    cin >> n;
    Fila fila (n);
    char op; 

    while(cin >> op) {
        
        switch(op){
            
            case'E': cin >> x;
            if(!fila.cheia () && x > 0){ 
            fila.enfileirar (x);}
            break;
            
            case'D': 
            if(!fila.vazia ()){ 
            x = fila.desenfileirar ();
                cout << x << "\n";}
            break;
        }
    }
return 0;
}

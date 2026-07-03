#include <iostream>
using namespace std;

class Item {
private:
    int chave; // conteúdo do nó;
    Item* proximo; // ponteiro para o próximo nó;

public:
    Item(int);

    void setChave(int); //altera/define o conteúdo/chave do nó (objeto);
    int getChave(); // retorna o valor do conteúdo/chave do nó;

    void setProximo(Item*); //altera o ponteiro próximo;
    Item* getProximo(); // retorna o ponteiro próximo;
};

class Lista {
private:
    Item* primeiro; //ponteiro para o primeiro nó;
    int quantidade; //quantidade de nós;

public:
    Lista();
    ~Lista();

    void setPrimeiro(Item*); // altera/define o ponteiro primeiro;
    Item* getPrimeiro(); // retorna o ponteiro primeiro;

    void setQuantidade(int); // altera/define uma nova quantidade;
    int getQuantidade(); // retorna a quantidade;

    bool vazia(); // retorna true a lista está vazia (quantidade == 0);
    bool busca(int); // verifica se há um inteiro na lista e retorna true se sim e false se não;

    void inserir(int); // insere um novo nó na lista do tipo Item (com ponteiro próximo e uma chave)
    void remover(int); // remove um nó da lista
    void mostrar(); // imprime a lista
};

// IMPLEMENTAÇÃO DA CLASSE ITEM

Item::Item(int x) {
    this->setChave(x); // define uma chave para o novo nó;
    this->setProximo(NULL); // define ponteiro do nó criado inicialmente apontando para NULL;
}

void Item::setChave(int x) { // define a chave do objeto;
    this->chave = x; 
}

int Item::getChave() { // retorna a chave do nó;
    return this->chave;
}

void Item::setProximo(Item* p) { // define/altera o ponteiro proximo do nó
    this->proximo = p;
}

Item* Item::getProximo() { // retorna o ponteiro próximo do nó
    return this->proximo;
}

// IMPLEMENTAÇÃO DA CLASSE LISTA

Lista::Lista() {
    this->setPrimeiro(NULL); //  define o ponteiro primeiro como NULL, indicando lista vazia;
    this->setQuantidade(0); // define a quantidade inicial de nós igual a zero;
}
Lista::~Lista() { // liberação da memória heap
    
    Item* atual = this->getPrimeiro(); // objeto atual recebe o conteúdo do ponteiro primeiro;

    while (atual != NULL) {
        Item* proximo = atual->getProximo(); // guarda o endereço do próximo nó antes de deletar o atual
        delete atual; // libera o nó atual da heap
        atual = proximo; // avança para o próximo nó
    }
}

void Lista::setPrimeiro(Item* p) { // altera/define o ponteiro que primeiro que aponta para o primeiro nó;
    this->primeiro = p;
}

Item* Lista::getPrimeiro() { // retorna o ponteiro primeiro que aponta para o primeiro nó;
    return this->primeiro;
}

void Lista::setQuantidade(int q) { //define/altera a quantidade de nós;
    this->quantidade = q;
}

int Lista::getQuantidade() { // retorna a quantidade de nós;
    return this->quantidade;
}

bool Lista::vazia() { //verifica se a lista está vazia;
    return this->getPrimeiro() == NULL && this->getQuantidade() == 0;
}

bool Lista::busca(int x) { // verifica se uma chave já consta na lista;

    Item* atual = this->getPrimeiro();

    while (atual != NULL){

        if (x == atual->getChave()) {

            return true;
        }

        else if (x < atual->getChave ()) { // se x é menor que a chave atual, a busca já passou da posição onde x deveria estar

            return false;
        }

        atual = atual->getProximo();
    }

return false;
    
}

void Lista::inserir(int x) { // insere novo nó na lista;
    if (this->busca(x)) { // verifique se a chave x já existe na lista:
        return; //se sim, saia da função inserir (int x);
    }

    Item* novo = new Item(x); //cria o novo nó;

    if (this->vazia()) { //se a lista está vazia o novo nó será o primeiro e a quantidade será igual a 1
        this->setPrimeiro(novo); // o ponteiro primeiro passa a apontar para o novo nó;
        this->setQuantidade(1); // quantidade é igual a 1
        return;
    }

    if (x < this->getPrimeiro()->getChave()) { // se x é menor que a chave do primeiro nó:
        novo->setProximo(this->getPrimeiro()); // o ponteiro próximo do novo nó aponta para o primeiro nó atual (slide 21-22)
        this->setPrimeiro(novo); //o ponteiro primeiro aponta parao novo nó (slide 21-22)
        this->setQuantidade(getQuantidade()+1);//incrementa a quantidade
        return;
    }

    if (x > this->getPrimeiro()->getChave()){ // se x é maior que a chave do primeiro nó:

    Item* anterior = this->getPrimeiro();  // ponteiro anterior aponta para o primeiro
    Item* atual = this->getPrimeiro()->getProximo(); // ponteiro atual aponta para o próximo do primeiro
    

        while (atual != NULL && atual->getChave() < x) {// enquanto não chegou ao fim e a chave do nó atual ainda é menor que x;
        anterior = atual; //desloca anterior para atual
        atual = atual->getProximo(); // desloca atual para o proximo
        }

        novo->setProximo(atual); // próximo do novo aponta para atual
        anterior->setProximo(novo); // próximo do anterior aponta para novo

        this->setQuantidade(getQuantidade()+1); // incrementa a quantidade.
    }
}

void Lista::remover(int x) { // remove um nó na lista com chave x;
    if (this->vazia()) {
        return;
    }

    if (this->getPrimeiro()->getChave() == x) {
        Item* removido = this->getPrimeiro();

        this->setPrimeiro(removido->getProximo());

        delete removido;
        this->setQuantidade(this->getQuantidade() - 1);

        return;
    }

    Item* anterior = this->getPrimeiro();
    Item* atual = this->getPrimeiro()->getProximo();

    while (atual != NULL && atual->getChave() < x) {
        anterior = atual;
        atual = atual->getProximo();
    }

    if (atual != NULL && atual->getChave() == x) {
        anterior->setProximo(atual->getProximo());
        delete atual;
        this->setQuantidade(this->getQuantidade() - 1);
    }
}

void Lista::mostrar() { // imprime a lista;
    Item* atual = this->getPrimeiro();

    while (atual != NULL) {
        cout << atual->getChave();

        if (atual->getProximo() != NULL) {
            cout << " ";
        }

        atual = atual->getProximo();
    }

    cout << endl;
}

int main() { // função principal.
    Lista lista;

    char op;
    int x;

    while (cin >> op) {
        switch (op) {
            case 'I':
                cin >> x;
                lista.inserir(x);
                break;

            case 'R':
                cin >> x;
                lista.remover(x);
                break;

            case 'B':
                cin >> x;

                if (lista.busca(x)) {
                    cout << "SIM" << endl;
                } else {
                    cout << "NAO" << endl;
                }

                break;

            case 'L':
                lista.mostrar();
                break;

            default:
                break;
        }
    }

    return 0;
}

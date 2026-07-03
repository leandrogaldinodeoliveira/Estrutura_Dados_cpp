#include <iostream>
using namespace std;

//A classe Item representa um nó da pilha
class Item {
    
    private:
        int x; // Conteúdo do item
        Item* prox; // Guarda o endereço do próximo item da pilha

    public:
        Item (int); // Construtor
        void setChave (int); // Altera o valor de x
        int getChave (); // Retorna o valor de x
        void setProx (Item *); // Altera o ponteiro prox
        Item* getProx (); // Retorna o ponteiro prox
};

Item::Item (int x) {
    this->setChave (x);
    this->setProx (NULL);
}

void Item::setChave (int x) { 
    this->x = x; 
}
int Item::getChave () {
     return this->x; 
    }
void Item::setProx (Item *p) {
     this->prox = p; 
    }
Item * Item::getProx () {
     return this->prox; 
    }

class Pilha {

    private:
        Item *topo; //topo é um ponteiro para o item que está no topo da pilha.
        int qtd; //qtd guarda quantos itens existem na pilha.

    public:
        Pilha(); //Cria uma pilha vazia
        ~Pilha(); // Destrutor das pilhas
        bool isVazia(); // Verifica se a pilha está vazia
        void empilhar(int); // Coloca um novo valor no topo
        int desempilhar(); // Remove o valor do topo e retorna este valor
        void imprimir(); // Imprime a pilha do topo para a base
};

Pilha::Pilha() {
     this->topo=NULL; 
     this->qtd=0; 
    }
Pilha::~Pilha() {
    //Criação de dois ponteiros
    Item *atu=this->topo; // atu aponta para o topo.
    Item *ant=NULL; // ant inicia nulo


    while(atu!=NULL) {
        ant = atu; //ponteiro anterior fica igual ao atual
        atu=atu->getProx(); //atual aponta para o próximo item
        delete ant; // ponteiro anterior é destruído
    }
}

bool Pilha::isVazia() { 
    return this->qtd==0 && this-> topo == NULL; 
} 

void Pilha::empilhar(int x) { 
    Item *novo = new Item(x); //cria um nó novo com conteúdo x e ponteiro prox = NULL. Vide: "this->setChave (x); this->setProx (NULL);"
    novo->setProx(this->topo); // O atributo ponteiro prox do novo nó recebe o endereço do nó que era o topo anterior. Vide: "void Item::setProx (Item *p) {this->prox = p;} "
    this->topo = novo; //fazer o topo apontar para esse novo nó "novo"
    this->qtd++; 
}

int Pilha::desempilhar() {  // assume que a pilha nao vazia
    Item *rem = this->topo;//rem recebe o mesmo endereço que o topo guarda
    int x = rem->getChave();//guarda o valor armazenado no nó que será removido
    this->topo = rem->getProx(); //avança o topo para o próximo nó;
    delete rem; //Destrói o ponteiro
    this->qtd--;
    return x; //Retorna o conteúdo do nó apagado.
}
void Pilha::imprimir() {
    Item *atu=this->topo;
    while (atu!=NULL) {
        cout << atu->getChave() << " ";
        atu=atu->getProx();
    }
    cout << endl;
}

int main()
{
    char op; int x;
    Pilha pilha;
    while (cin >> op) { // leitura ate EOF
        switch(op) {
            case 'E': cin >> x;
                    pilha.empilhar(x); break;
            case 'D': if (!pilha.isVazia()) {
                        x = pilha.desempilhar();
                        cout << "[" << x << "]\n";
                    }
                    break;
            case 'M': pilha.imprimir(); break;
        }
    }
    return 0;
}

#include <iostream> // biblioteca usada para entrada e saída: cin e cout
using namespace std; // permite usar cin, cout e endl sem escrever std::

// Classe que representa cada nó da lista
class Item {
private:
    int chave; // valor armazenado dentro do nó
    Item* proximo; // ponteiro que guarda o endereço do próximo nó da lista

public:
    Item(int); // construtor da classe Item

    void setChave(int); // método para alterar/definir a chave do nó
    int getChave(); // método para retornar a chave do nó

    void setProximo(Item*); // método para alterar/definir o ponteiro proximo
    Item* getProximo(); // método para retornar o ponteiro proximo
};

// Classe que representa a lista dinâmica encadeada
class Lista {
private:
    Item* primeiro; // ponteiro que guarda o endereço do primeiro nó da lista
    int quantidade; // quantidade de nós existentes na lista

public:
    Lista(); // construtor da classe Lista
    ~Lista(); // destrutor da classe Lista, usado para liberar memória da heap

    void setPrimeiro(Item*); // método para alterar/definir o ponteiro primeiro
    Item* getPrimeiro(); // método para retornar o ponteiro primeiro

    void setQuantidade(int); // método para alterar/definir a quantidade
    int getQuantidade(); // método para retornar a quantidade

    bool vazia(); // retorna true se a lista estiver vazia
    bool busca(int); // retorna true se a chave procurada existir na lista

    void inserir(int); // insere uma nova chave na lista, mantendo ordem crescente
    void remover(int); // remove uma chave da lista, caso ela exista
    void mostrar(); // imprime os elementos da lista
};

// IMPLEMENTAÇÃO DA CLASSE ITEM

Item::Item(int x) { // construtor do nó, recebe uma chave x
    this->setChave(x); // define a chave do nó como x
    this->setProximo(NULL); // inicialmente, o nó não aponta para nenhum próximo nó
}

void Item::setChave(int x) { // método que altera a chave do nó
    this->chave = x; // o atributo chave recebe o valor x
}

int Item::getChave() { // método que retorna a chave do nó
    return this->chave; // devolve o valor armazenado em chave
}

void Item::setProximo(Item* p) { // método que altera o ponteiro proximo do nó
    this->proximo = p; // o atributo proximo recebe o endereço passado em p
}

Item* Item::getProximo() { // método que retorna o ponteiro proximo do nó
    return this->proximo; // devolve o endereço do próximo nó
}

// IMPLEMENTAÇÃO DA CLASSE LISTA

Lista::Lista() {
    this->setPrimeiro(NULL); // no início, a lista não possui primeiro nó
    this->setQuantidade(0); // no início, a quantidade de nós é zero
}

Lista::~Lista() { // destrutor da lista, chamado ao final do programa
    Item* atual = this->getPrimeiro(); // atual começa apontando para o primeiro nó da lista

    while (atual != NULL) { // enquanto ainda existir nó para deletar
        Item* proximo = atual->getProximo(); // guarda o endereço do próximo nó antes de deletar o atual
        delete atual; // libera da heap o nó apontado por atual
        atual = proximo; // atual passa a apontar para o próximo nó salvo anteriormente
    }
}

void Lista::setPrimeiro(Item* p) { // método que altera o ponteiro primeiro
    this->primeiro = p; // primeiro passa a guardar o endereço recebido em p
}

Item* Lista::getPrimeiro() { // método que retorna o ponteiro primeiro
    return this->primeiro; // devolve o endereço do primeiro nó da lista
}

void Lista::setQuantidade(int q) { // método que altera a quantidade de nós
    this->quantidade = q; // quantidade recebe o valor q
}

int Lista::getQuantidade() { // método que retorna a quantidade de nós
    return this->quantidade; // devolve a quantidade atual
}

bool Lista::vazia() { // método que verifica se a lista está vazia
    return this->getPrimeiro() == NULL && this->getQuantidade() == 0;
    // retorna true se primeiro aponta para NULL e quantidade é zero
}

bool Lista::busca(int x) { // método que verifica se a chave x existe na lista

    Item* atual = this->getPrimeiro(); // atual começa apontando para o primeiro nó

    while (atual != NULL) { // percorre a lista enquanto atual apontar para algum nó

        if (x == atual->getChave()) { // se x for igual à chave do nó atual
            return true; // a chave foi encontrada
        }

        else if (x < atual->getChave()) { 
            // se x é menor que a chave atual, a busca já passou da posição onde x deveria estar
            // isso só funciona porque a lista está ordenada em ordem crescente

            return false; // x não existe na lista
        }

        atual = atual->getProximo(); // atual avança para o próximo nó
    }

    return false; // se chegou ao final da lista, x não foi encontrado
}

void Lista::inserir(int x) { // método que insere a chave x na lista

    if (this->busca(x)) { // verifica se x já existe na lista
        return; // se x já existe, a inserção é ignorada
    }

    Item* novo = new Item(x); // cria um novo nó na heap com chave x

    if (this->vazia()) { // se a lista está vazia
        this->setPrimeiro(novo); // primeiro passa a apontar para o novo nó
        this->setQuantidade(1); // a quantidade passa a ser 1
        return; // encerra a função, pois a inserção já foi feita
    }

    if (x < this->getPrimeiro()->getChave()) { 
        // se x é menor que a chave do primeiro nó, o novo nó deve entrar no início

        novo->setProximo(this->getPrimeiro()); 
        // o próximo do novo nó passa a apontar para o antigo primeiro nó

        this->setPrimeiro(novo); 
        // primeiro passa a apontar para o novo nó

        this->setQuantidade(this->getQuantidade() + 1); 
        // incrementa a quantidade de nós

        return; // encerra a função, pois a inserção já foi feita
    }

    if (x > this->getPrimeiro()->getChave()) { 
        // se x é maior que a chave do primeiro nó, ele deve entrar depois do primeiro

        Item* anterior = this->getPrimeiro(); 
        // anterior começa apontando para o primeiro nó

        Item* atual = this->getPrimeiro()->getProximo(); 
        // atual começa apontando para o nó seguinte ao primeiro

        while (atual != NULL && atual->getChave() < x) { 
            // enquanto não chegou ao fim da lista
            // e enquanto a chave do nó atual ainda for menor que x

            anterior = atual; 
            // anterior avança para onde atual estava

            atual = atual->getProximo(); 
            // atual avança para o próximo nó
        }

        novo->setProximo(atual); 
        // o próximo do novo nó aponta para atual
        // atual é o nó que ficará depois do novo

        anterior->setProximo(novo); 
        // o próximo do nó anterior aponta para o novo nó
        // assim encaixamos o novo entre anterior e atual

        this->setQuantidade(this->getQuantidade() + 1); 
        // incrementa a quantidade de nós
    }
}

void Lista::remover(int x) { // método que remove a chave x da lista

    if (this->vazia()) { // se a lista está vazia
        return; // não há nada para remover
    }

    if (this->getPrimeiro()->getChave() == x) { 
        // se a chave a ser removida está no primeiro nó

        Item* removido = this->getPrimeiro(); 
        // guarda o endereço do primeiro nó, pois ele será removido

        this->setPrimeiro(removido->getProximo()); 
        // primeiro passa a apontar para o segundo nó da lista
        // se não houver segundo nó, primeiro passa a apontar para NULL

        delete removido; 
        // libera da heap o nó removido

        this->setQuantidade(this->getQuantidade() - 1); 
        // decrementa a quantidade de nós

        return; // encerra a função, pois a remoção já foi feita
    }

    Item* anterior = this->getPrimeiro(); 
    // anterior começa apontando para o primeiro nó

    Item* atual = this->getPrimeiro()->getProximo(); 
    // atual começa apontando para o segundo nó

    while (atual != NULL && atual->getChave() < x) { 
        // percorre a lista enquanto não chegar ao fim
        // e enquanto a chave atual ainda for menor que x

        anterior = atual; 
        // anterior avança para onde atual estava

        atual = atual->getProximo(); 
        // atual avança para o próximo nó
    }

    if (atual != NULL && atual->getChave() == x) { 
        // se atual não é NULL e sua chave é igual a x, encontramos o nó a remover

        anterior->setProximo(atual->getProximo()); 
        // o próximo do anterior passa a apontar para o próximo do atual
        // assim, o nó atual é retirado do encadeamento da lista

        delete atual; 
        // libera da heap o nó removido

        this->setQuantidade(this->getQuantidade() - 1); 
        // decrementa a quantidade de nós
    }
}

void Lista::mostrar() { // método que imprime a lista

    Item* atual = this->getPrimeiro(); 
    // atual começa apontando para o primeiro nó

    while (atual != NULL) { 
        // enquanto atual apontar para algum nó

        cout << atual->getChave(); 
        // imprime a chave do nó atual

        if (atual->getProximo() != NULL) { 
            // se existe próximo nó

            cout << " "; 
            // imprime espaço entre os elementos
            // isso evita espaço depois do último elemento
        }

        atual = atual->getProximo(); 
        // atual avança para o próximo nó
    }

    cout << endl; 
    // quebra a linha ao final da impressão da lista
}

int main() { // função principal do programa

    Lista lista; 
    // cria um objeto lista
    // o construtor Lista() será chamado automaticamente

    char op; 
    // variável que armazena o comando: I, R, B ou L

    int x; 
    // variável que armazena o valor usado nos comandos I, R e B

    while (cin >> op) { 
        // lê comandos até o fim da entrada
        // como a entrada é indefinida, usamos while com cin

        switch (op) { 
            // escolhe o que fazer de acordo com o comando lido

            case 'I': 
                // comando de inserção

                cin >> x; 
                // lê o valor a ser inserido

                lista.inserir(x); 
                // insere x na lista, se x ainda não existir

                break; 
                // encerra este case

            case 'R': 
                // comando de remoção

                cin >> x; 
                // lê o valor a ser removido

                lista.remover(x); 
                // remove x da lista, se x existir

                break; 
                // encerra este case

            case 'B': 
                // comando de busca

                cin >> x; 
                // lê o valor a ser buscado

                if (lista.busca(x)) { 
                    // se x existe na lista

                    cout << "SIM" << endl; 
                    // imprime SIM
                } else { 
                    // se x não existe na lista

                    cout << "NAO" << endl; 
                    // imprime NAO
                }

                break; 
                // encerra este case

            case 'L': 
                // comando para listar/imprimir a lista

                lista.mostrar(); 
                // imprime todos os elementos da lista

                break; 
                // encerra este case

            default: 
                // caso apareça algum comando não reconhecido

                break; 
                // não faz nada
        }
    }

    return 0; 
    // indica que o programa terminou corretamente
}

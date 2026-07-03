#include <iostream>
using namespace std;

class No {
public:
    int valor;
    No* proximo;

    No(int v) {
        valor = v;
        proximo = NULL;
    }
};

class Lista {
private:
    No* inicio;

public:
    Lista();
    ~Lista();

    bool vazia();
    bool busca(int);
    void inserir(int);
    void remover(int);
    void mostrar();
};

Lista::Lista() {
    inicio = NULL;
}

Lista::~Lista() {
    No* atual = inicio;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

bool Lista::vazia() {
    return inicio == NULL;
}

bool Lista::busca(int x) {
    No* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == x) {
            return true;
        }

        if (atual->valor > x) {
            return false;
        }

        atual = atual->proximo;
    }

    return false;
}

void Lista::inserir(int x) {
    if (busca(x)) {
        return;
    }

    No* novo = new No(x);

    if (inicio == NULL || x < inicio->valor) {
        novo->proximo = inicio;
        inicio = novo;
        return;
    }

    No* anterior = inicio;
    No* atual = inicio->proximo;

    while (atual != NULL && atual->valor < x) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;
    anterior->proximo = novo;
}

void Lista::remover(int x) {
    if (inicio == NULL) {
        return;
    }

    if (inicio->valor == x) {
        No* removido = inicio;
        inicio = inicio->proximo;
        delete removido;
        return;
    }

    No* anterior = inicio;
    No* atual = inicio->proximo;

    while (atual != NULL && atual->valor < x) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->valor == x) {
        anterior->proximo = atual->proximo;
        delete atual;
    }
}

void Lista::mostrar() {
    No* atual = inicio;

    while (atual != NULL) {
        cout << atual->valor;

        if (atual->proximo != NULL) {
            cout << " ";
        }

        atual = atual->proximo;
    }

    cout << endl;
}

int main() {
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

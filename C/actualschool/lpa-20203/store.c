#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Create a default struct to store type/properties
struct Store{
    char *name;
    int phone;
    float price;
};

// Define build function
struct Store build(char name[20], int phone, float price);

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("WELCOME TO RIFELI'S STORE (RU 2136681). \n\n");
    printf("****************************************************** \n");
    printf("[ I ] Inserir Loja \n");
    printf("[ E ] Excluir loja Cadastrada \n");
    printf("[ P ] Melhores Preços \n");
    printf("[ S ] Sair \n");

    return 0;
}

// Função para montar uma store com suas propriedades
struct Store store(char name[20], int phone, float price) {
    struct Store store;
    store.name = name;
    store.phone = phone;
    store.price = price;
    return store;
}

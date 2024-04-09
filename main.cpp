#include<stdio.h>
#define MAXLIVROS 10

struct Livro{

    char titulo[50];
    char autor[50];
    int numPg;

    void ler() {
        printf("Titulo do livro: ");
        scanf("%[^\n]%*c", titulo);
        printf("Autor do livro: ");
        scanf("%[^\n]%*c", autor);
        printf("Numero de paginas do livro: ");
        scanf("%d%*c", &numPg);
    }

    void imprimir() {
        printf("\nLivros da Biblioteca:\n\n");
        printf("Titulo do livro: %s\n", titulo);
        printf("Autor do livro: %s\n", autor);
        printf("Numero de paginas do livro: %d\n\n", numPg);
    }

};

struct Biblioteca {

    Livro livros[MAXLIVROS];
    int tdsBooks;

    Biblioteca() {
        tdsBooks = 0;
    }

    void ler() {
        if (tdsBooks >= MAXLIVROS) {
            printf("Biblioteca cheia.\n");
            return;
        }
        livros[tdsBooks].ler();
        tdsBooks++;
    }

    void imprimir() {

        if ( tdsBooks == 0) {
            printf("\nBiblioteca vazia.\n\n");
            return;
        }
        for (int i = 0; i < tdsBooks; i++) {
            livros[i].imprimir();

        }
    }

    void imprimirMaior() {
        if (tdsBooks == 0) {
            printf("\nBiblioteca vazia.\n\n");
            return;
        }
        int maior = 0;
        int posicao = -1;

        for (int i = 0; i < tdsBooks; i++) {
            if (livros[i].numPg > maior) {
                maior = livros[i].numPg;
                posicao = i;
            }
        }
        livros[posicao].imprimir();
    }

};

int main() {

    Biblioteca b;

    int n;

    do {
        printf("\n-----DIGITE O NUMERO DA OPCAO QUE DESEJA-----\n\n");
        printf("1. Adicionar livro na biblioteca.\n");
        printf("2. Relacao de livros da biblioteca.\n");
        printf("3. Livro com maior numero de paginas.\n");
        printf("4. Sair.\n\n");
        printf("Digite o numero da opcao: ");
        scanf("%d%*c", &n);

        switch(n) {
            case 1:
                b.ler();
                break;
            case 2:
                b.imprimir();
                break;
            case 3:
                b.imprimirMaior();
                break;
        };

    } while ( n!=4 );

    return 0;
}

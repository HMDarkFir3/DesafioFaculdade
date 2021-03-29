#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

//Utils ----------------------------------------------------|
void clearScreen() {
    system("cls");
}

void jumpLine() {
    printf("\n");
}

//Menu Options --------------------------------------------|
//7 --|--
void quit(int change) {
    int id = 0;

    printf("\tFinalizando o programa...");
    Sleep(3000);
}

//Build Menu -----------------------------------------------|
void buildMenuItem(char str[]) {
    int countLetters = 0;

    for(int i = 0; i < 36; i++) {
        if(str[i] == '\0') {
            break;
        } else {
            countLetters++;
        }
    }

    printf("\t%c", 186);
    printf("%s", str);

    while(countLetters < 36) {
        printf("%c", 32);
        countLetters++;
    }

    printf("%c", 186);
}

void menu() {
    //Variables
    int change;

    //Menu Top --------------------------------------------|
    printf("\t%c", 201);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 187);

    jumpLine();

    //Menu Item -------------------------------------------|
    buildMenuItem(" 1 - Entrada de dados");
    jumpLine(); //
    buildMenuItem(" 2 - Listar dados");
    jumpLine(); //
    buildMenuItem(" 3 - Pesquisar produto");
    jumpLine(); //
    buildMenuItem(" 4 - Pesquisar produto pela 1 letra");
    jumpLine(); //
    buildMenuItem(" 5 - Alterar dados");
    jumpLine(); //
    buildMenuItem(" 6 - Excluir dados");
    jumpLine(); //
    buildMenuItem(" 7 - Sair");
    jumpLine(); //

    //Menu Bottom -----------------------------------------|
    printf("\t%c", 200);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 188);
    jumpLine(); //

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            printf("\tErro no sistema!");
            break;
        case 2:
            printf("\tErro no sistema!");
            break;
        case 3:
            printf("\tErro no sistema!");
            break;
        case 4:
            printf("\tErro no sistema!");
            break;
        case 5:
            printf("\tErro no sistema!");
            break;
        case 6:
            printf("\tErro no sistema!");
            break;
        case 7:
            quit(change);
            break;
    }
}

//Home -----------------------------------------------------|
int main() {
    menu();
    return 0;
}

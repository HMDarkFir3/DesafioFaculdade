#include <stdio.h>

//Utils ----------------------------------------------------|
void clearScreen() { // Limpa tela
    system("cls");
}

void jumpLine() { // Pula linha
    printf("\n");
}

//Menu Options --------------------------------------------|
//1 --|--
void dataEntries() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Escrever no arquivo");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tEntrada de dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEntries();
            break;
    }

}

//2 --|--
void dataList() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Listar dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tListar de dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataList();
            break;
    }
}

//3 --|--
void dataSearchName() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Pesquisar dados por nome");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tPesquisa de dados por nome");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataSearchName();
            break;
    }
}

//4 --|--
void dataSearchLetter() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Pesquisar dados por letra");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\tPesquisa de dados por letra");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataSearchLetter();
            break;
    }
}

//5 --|--
void dataEdit() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Alterar dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\Alterar dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEdit();
            break;
    }
}

//6 --|--
void dataDelete() {
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Excluir dados");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            printf("\Excluir dados");
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataDelete();
            break;
    }
}

//7 --|--
void quit() { // Fechar o programa
    printf("\tFinalizando o programa...");
    Sleep(3000);
}

//Build Menu -----------------------------------------------|
void buildMenuTopLine() {
    //Menu Top --------------------------------------------|
    printf("\t%c", 201);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 187);

    jumpLine();
}

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

void buildMenuBottomLine() {
    //Menu Bottom -----------------------------------------|
    printf("\t%c", 200);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 188);

    jumpLine(); //
}

void menu() {
    //Variavel
    int change;

    //Limpa tela
    clearScreen();

    //Linha superior
    buildMenuTopLine();

    //Menu Item -------------------------------------------|
    buildMenuItem(" 1 - Entrada de dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Listar dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 3 - Pesquisar dados por nome");
    jumpLine(); // Pula linha
    buildMenuItem(" 4 - Pesquisar dados pela 1 letra");
    jumpLine(); // Pula linha
    buildMenuItem(" 5 - Alterar dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 6 - Excluir dados");
    jumpLine(); // Pula linha
    buildMenuItem(" 7 - Sair");
    jumpLine(); // Pula linha

    //Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            dataEntries();
            break;
        case 2:
            dataList();
            break;
        case 3:
            dataSearchName();
            break;
        case 4:
            dataSearchLetter();
            break;
        case 5:
            dataEdit();
            break;
        case 6:
            dataDelete();
            break;
        case 7:
            quit();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            menu();
            break;
    }
}

//Home -----------------------------------------------------|
int main() {
    menu();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Global variables
char product1[20];
char product2[20];
char product3[20];
int amount1 = 0;
int amount2 = 0;
int amount3 = 0;

//Utils ------------------------------------------------------|X*
void clearScreen() { // Limpa tela
    system("cls");
}

void jumpLine() { // Pula linha
    printf("\n");
}
// -----------------------------------------------------------|X*

// Menu Options ----------------------------------------------|O*
// 1 --|--
void dataEntries() { // Entrada de dados
    int change;
    char file[20];

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

    backHere:


    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            clearScreen();

            FILE *f;

            f = fopen("product.txt", "r+");

            if(f == NULL) {
                f = fopen("product.txt", "w");
                f = fopen("product.txt", "r+");
            }

            printf("\tDigite o 1 produto: ");
            scanf("%s", &product1);

            printf("\tDigite a quantidade de %s: ", product1);
            scanf("%d", &amount1);

            jumpLine(); // Pula linha

            printf("\tDigite o 2 produto: ");
            scanf("%s", &product2);

            printf("\tDigite a quantidade de) %s: ", product2);
            scanf("%d", &amount2);

            jumpLine(); // Pula linha

            printf("\tDigite o 3 produto: ");
            scanf("%s", &product3);

            printf("\tDigite a quantidade de %s: ", product3);
            scanf("%d", &amount3);

            // Produto 1
            fwrite(&product1, sizeof(product1), 1, f);
            fwrite(&amount1, sizeof(amount1), 1, f);

            // Produto 2
            fwrite(&product2, sizeof(product2), 1, f);
            fwrite(&amount2, sizeof(amount2), 1, f);

            //Produto 3
            fwrite(&product3, sizeof(product3), 1, f);
            fwrite(&amount3, sizeof(amount3), 1, f);

            fclose(f);

            clearScreen();
            dataEntries();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEntries();
            break;
    }

}

// 2 --|--
void dataList() { // Listar dados
    int change;

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
            clearScreen();

            FILE *f;

            f = fopen("product.txt", "r");

            if(f == NULL) {
                printf("\tNenhum arquivo encontrado.");
                Sleep(2000);
                clearScreen();
                dataList();
            }

            printf("\tProdutos:\n");

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);

            if(product1 && amount1) {
                printf("\t%s: %d unidade(s)\n", product1, amount1);
            }

            fread(&product2, sizeof(product2), 1, f);
            fread(&amount2, sizeof(amount2), 1, f);

            if(product2 && amount2) {
                printf("\t%s: %d unidade(s)\n", product2, amount2);
            }

            fread(&product3, sizeof(product3), 1, f);
            fread(&amount3, sizeof(amount3), 1, f);

            if(product3 && amount3) {
                printf("\t%s: %d unidade(s)\n", product3, amount3);
            }

            jumpLine();

            fclose(f);

            dataList();
            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            clearScreen();
            dataList();
            break;
    }
}

// 3 --|--
void dataSearchName() { // Pesquisar dados por nome
    int change;

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
            clearScreen();

            FILE *f;

            char product[20];
            int i, j;

            printf("\tProcurar produro pelo nome: ");
            scanf("%s", &product);

            f = fopen("product.txt", "r");

            for(i = 0; i < 3; i++) {
                fread(&product1, sizeof(product1), 1, f);
                fread(&amount1, sizeof(amount1), 1, f);

                for(j = 0; product1[j] != '\0'; j++) {
                    if(product[j] != product1[j]) {
                        break;
                    }
                }

                if(product[j] == '\0' && product1[j] == '\0') {
                    clearScreen();

                    printf("\tNome procurado: \n");
                    printf("\t%s: %d unidade(s)\n", product1, amount1);

                    jumpLine();

                    fclose(f);

                    dataSearchName();
                    return;
                } else {
                    clearScreen();
                    printf("\tNenhum registro encontrado.\n");
                    Sleep(2000);
                    clearScreen();

                    fclose(f);

                    dataSearchName();
                    return;
                }
            }

            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            clearScreen();
            dataSearchName();
            break;
    }
}

// 4 --|--
void dataSearchLetter() { //Pesquisar dados por letra
    int change;

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
            clearScreen();

            FILE *f;

            char product;
            int i, j = 0;

            printf("\tProcurar produto pela 1 letra: ");
            scanf(" %c", &product);

            f = fopen("product.txt", "r");

            for(i = 0; i < 3; i++) {
                fread(&product1, sizeof(product1), 1, f);
                fread(&amount1, sizeof(amount1), 1, f);

                if(product == product1[0]) {
                    clearScreen();

                    printf("\tNome procurado: \n");
                    printf("\t%s: %d unidade(s)\n", product1, amount1);

                    jumpLine();

                    dataSearchLetter();

                    fclose(f);

                    j++;
                } else {
                    clearScreen();
                    printf("\tNenhum registro encontrado.\n");
                    Sleep(2000);
                    clearScreen();

                    dataSearchLetter();
                    fclose(f);
                    return;
                }
            }

            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataSearchLetter();
            break;
    }
}

// 5 --|--
void dataEdit() { // Alterar dados
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

            clearScreen();

            int changeProduct;
            int n_bytes;

            FILE *f;

            f = fopen("product.txt", "r");

            if(f == NULL) {
                printf("\tNenhum arquivo encontrado.");
                Sleep(2000);
                clearScreen();
                dataList();
            }

            printf("\tProdutos:\n");

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);

            if(product1 && amount1) {
                printf("\t(1) - %s: %d unidade(s)\n", product1, amount1);
            }

            fread(&product2, sizeof(product2), 1, f);
            fread(&amount2, sizeof(amount2), 1, f);

            if(product2 && amount2) {
                printf("\t(2) - %s: %d unidade(s)\n", product2, amount2);
            }

            fread(&product3, sizeof(product3), 1, f);
            fread(&amount3, sizeof(amount3), 1, f);

            if(product3 && amount3) {
                printf("\t(3) - %s: %d unidade(s)\n", product3, amount3);
            }

            jumpLine();

            fclose(f);

            printf("\tEscolha uma das opcoes acima: ");
            scanf("%d", &changeProduct);

            switch(changeProduct) {
                case 1:

                    jumpLine();

                    n_bytes = (sizeof(product1) + sizeof(amount1)) * 0;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product1, sizeof(product1), 1, f);
                    fread(&amount1, sizeof(amount1), 1, f);

                    printf("\tAlterar %s ->: ", product1);
                    scanf("%s", &product1);
                    printf("\tAlterar %d unidade(s) ->: ", amount1);
                    scanf("%d", &amount1);

                    fseek(f, n_bytes, 0);

                    fwrite(&product1, sizeof(product1), 1, f);
                    fwrite(&amount1, sizeof(amount1), 1, f);

                    fclose(f);

                    dataEdit();
                    break;
                case 2:

                    jumpLine();

                    n_bytes = (sizeof(product2) + sizeof(amount2)) * 1;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product2, sizeof(product2), 1, f);
                    fread(&amount2, sizeof(amount2), 1, f);

                    printf("\tAlterar %s ->: ", product2);
                    scanf("%s", &product2);
                    printf("\tAlterar %d unidade(s) ->: ", amount2);
                    scanf("%d", &amount2);

                    fseek(f, n_bytes, 0);

                    fwrite(&product2, sizeof(product2), 1, f);
                    fwrite(&amount2, sizeof(amount2), 1, f);

                    fclose(f);

                    dataEdit();
                    break;
                case 3:
                    jumpLine();

                    n_bytes = (sizeof(product3) + sizeof(amount3)) * 2;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product3, sizeof(product3), 1, f);
                    fread(&amount3, sizeof(amount3), 1, f);

                    printf("\tAlterar %s ->: ", product3);
                    scanf("%s", &product3);
                    printf("\tAlterar %d unidade(s) ->: ", amount3);
                    scanf("%d", &amount3);

                    fseek(f, n_bytes, 0);

                    fwrite(&product3, sizeof(product3), 1, f);
                    fwrite(&amount3, sizeof(amount3), 1, f);

                    fclose(f);

                    dataEdit();
                    break;
                default:
                    clearScreen();

                    printf("\tErro no sistema.");
                    Sleep(2000);
                    dataEdit();
                    break;
            }

            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataEdit();
            break;
    }
}

// 6 --|--
void dataDelete() { // Excluir dados
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

            clearScreen();

            int changeProduct;
            int n_bytes;

            FILE *f;

            f = fopen("product.txt", "r");

            if(f == NULL) {
                printf("\tNenhum arquivo encontrado.");
                Sleep(2000);
                clearScreen();
                dataList();
            }

            printf("\tProdutos:\n");

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);

            if(product1 && amount1) {
                printf("\t(1) - %s: %d unidade(s)\n", product1, amount1);
            }

            fread(&product2, sizeof(product2), 1, f);
            fread(&amount2, sizeof(amount2), 1, f);

            if(product2 && amount2) {
                printf("\t(2) - %s: %d unidade(s)\n", product2, amount2);
            }

            fread(&product3, sizeof(product3), 1, f);
            fread(&amount3, sizeof(amount3), 1, f);

            if(product3 && amount3) {
                printf("\t(3) - %s: %d unidade(s)\n", product3, amount3);
            }

            jumpLine();

            fclose(f);

            printf("\tEscolha uma das opcoes acima: ");
            scanf("%d", &changeProduct);

            switch(changeProduct) {
                case 1:

                    jumpLine();

                    n_bytes = (sizeof(product1) + sizeof(amount1)) * 0;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product1, sizeof(product1), 1, f);
                    fread(&amount1, sizeof(amount1), 1, f);

                    product1[0] = '\0';
                    amount1 = NULL;

                    fseek(f, n_bytes, 0);

                    fwrite(&product1, sizeof(product1), 1, f);
                    fwrite(&amount1, sizeof(amount1), 1, f);

                    fclose(f);

                    dataDelete();
                    break;
                case 2:
                    jumpLine();

                    n_bytes = (sizeof(product2) + sizeof(amount2)) * 1;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product2, sizeof(product2), 1, f);
                    fread(&amount2, sizeof(amount2), 1, f);

                    product2[0] = '\0';
                    amount2 = NULL;

                    fseek(f, n_bytes, 0);

                    fwrite(&product2, sizeof(product2), 1, f);
                    fwrite(&amount2, sizeof(amount2), 1, f);

                    fclose(f);

                    dataDelete();
                    break;
                case 3:
                    jumpLine();

                    n_bytes = (sizeof(product3) + sizeof(amount3)) * 2;

                    f = fopen("product.txt", "r+");

                    fseek(f, n_bytes, 0);

                    fread(&product3, sizeof(product3), 1, f);
                    fread(&amount3, sizeof(amount3), 1, f);

                    product3[0] = '\0';
                    amount3 = NULL;

                    fseek(f, n_bytes, 0);

                    fwrite(&product3, sizeof(product3), 1, f);
                    fwrite(&amount3, sizeof(amount3), 1, f);

                    fclose(f);

                    dataDelete();
                    break;
                default:
                    clearScreen();

                    printf("\tErro no sistema.");
                    Sleep(2000);
                    dataEdit();
                    break;
            }

            break;
        default:
            clearScreen();
            printf("\tErro no sistema.");
            Sleep(2000);
            dataDelete();
            break;
    }
}

// 7 --|--
void quit() { // Fechar o programa
    clearScreen();
    printf("\tFinalizando o programa...");
    Sleep(3000);
    clearScreen();
}
// ----------------------------------------------------------|O*

// Build Menu -----------------------------------------------|X*
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
            clearScreen();
            dataList();
            break;
        case 3:
            clearScreen();
            dataSearchName();
            break;
        case 4:
            clearScreen();
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
// ----------------------------------------------------------|X*

// Home -----------------------------------------------------|O*
int main() {
    menu();
    return 0;
}
// ----------------------------------------------------------|O*

//Libs
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

//Global variables
char product1[20];
char product2[20];
char product3[20];
int amount1 = 0;
int amount2 = 0;
int amount3 = 0;

char validation[52] = {
    'a', 'b', 'c',
    'd', 'e', 'f',
    'g', 'h', 'i',
    'j', 'k', 'l',
    'm', 'n', 'o',
    'p', 'q', 'r',
    's', 't', 'u',
    'v', 'w', 'x',
    'y', 'z',
    'A', 'B', 'C',
    'D', 'E', 'F',
    'G', 'H', 'I',
    'J', 'K', 'L',
    'M', 'N', 'O',
    'P', 'Q', 'R',
    'S', 'T', 'U',
    'V', 'W', 'X',
    'Y', 'Z',
};

//Utils ------------------------------------------------------|X*
void clearScreen() { // Limpa tela
    system("cls");
}

void jumpLine() { // Pula linha
    printf("\n");
}

int searchName() {
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
            return i;
        }
    }

    fclose(f);
    return -1;
}
// -----------------------------------------------------------|X*

// Menu Options ----------------------------------------------|O*
// 1 --|--
void dataEntries() { // Entrada de dados
    int change;

    // Limpa tela
    clearScreen();

    // Linha superior
    buildMenuTopLine();

    // Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Escrever no arquivo");
    jumpLine(); // Pula linha

    // Linha inferior
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

            f = fopen("product.txt", "w");

            int i, j;
            int validate;

            // Validação produto 1
            do {
                validate = 0;

                printf("\tDigite o 1 produto: ");
                scanf("%s", &product1);

                for(i = 0; i < strlen(product1); i++) {
                    for(j = 0; j < strlen(validation); j++) {
                        if(product1[i] == validation[j]) {
                            validate++;
                        }
                    }
                }

                if(validate != strlen(product1)) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros e/ou caracteres especiais.\n" RESET);
                    jumpLine();
                }

            } while(validate != strlen(product1));

            // Validação quatidade 1
            do {
                printf("\tDigite a quantidade de %s: ", product1);
                scanf("%d", &amount1);

                if(amount1 < 0 || amount1 == 10) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros negativos ou o numero 10.\n" RESET);
                    jumpLine();
                }

            } while(amount1 < 0 || amount1 == 10);

            jumpLine(); // Pula linha

            // Validação produto 2
            do {
                validate = 0;

                printf("\tDigite o 2 produto: ");
                scanf("%s", &product2);

                for(i = 0; i < strlen(product2); i++) {
                    for(j = 0; j < strlen(validation); j++) {
                        if(product2[i] == validation[j]) {
                            validate++;
                        }
                    }
                }

                if(validate != strlen(product2)) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros e/ou caracteres especiais.\n" RESET);
                    jumpLine();
                }

            } while(validate != strlen(product2));

            // Validação quatidade 2
            do {
                printf("\tDigite a quantidade de %s: ", product2);
                scanf("%d", &amount2);

                if(amount2 < 0 || amount2 == 10) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros negativos ou o numero 10.\n" RESET);
                    jumpLine();
                }

            } while(amount2 < 0 || amount2 == 10);

            jumpLine(); // Pula linha

            // Validação produto 3
            do {
                printf("\tDigite o 3 produto: ");
                scanf("%s", &product3);

                for(i = 0; i < strlen(product3); i++) {
                    for(j = 0; j < strlen(validation); j++) {
                        validate++;
                    }
                }

                if(validate != strlen(product3)) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros e/ou caracteres especiais.\n" RESET);
                    jumpLine();
                }

            } while(validate != strlen(product3));

            // Validação quatidade 3
            do {
                printf("\tDigite a quantidade de %s: ", product3);
                scanf("%d", &amount3);

                if(amount3 < 0 || amount3 == 10) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros negativos ou o numero 10.\n" RESET);
                    jumpLine();
                }

            } while(amount3 < 0 || amount3 == 10);

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
            printf(GRN "\tProdutos adicionados com sucesso." RESET);
            Sleep(2500);

            dataEntries();
            break;
        default:
            clearScreen();
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            clearScreen();
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
                clearScreen();
                printf(YEL "\tATENCAO: Nenhum arquivo encontrado." RESET);
                Sleep(2500);

                clearScreen();
                printf(BLU "\tRedirecionando para entrada de dados." RESET);
                Sleep(2500);

                dataEntries();
            }

            printf("\tProduto(s):\n");

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
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            clearScreen();
            dataList();
            break;
    }
}

// 3 --|--
void dataSearchName() { // Pesquisar dados por nome
    int change;
    int search;

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
            search = searchName();

            if(search == -1) {
                clearScreen();
                printf("\tNenhum registro encontrado.\n");
                Sleep(2000);
                clearScreen();
            }

            dataSearchName();

            break;
        default:
            clearScreen();
            printf(RED "\tErro no sistema." RESET);
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

            clearScreen();

            f = fopen("product.txt", "r");

            printf("\tProduto(s):\n");

            for(i = 0; i < 3; i++) {
                fread(&product1, sizeof(product1), 1, f);
                fread(&amount1, sizeof(amount1), 1, f);

                if(product == product1[0]) {
                    printf("\t%s: %d unidade(s)\n", product1, amount1);

                    j++;
                }
            }

            if(j == 0) {
                clearScreen();
                printf("\tNenhum registro encontrado.\n");
                Sleep(2000);
                clearScreen();
                dataSearchLetter();
                return;
            }

            fclose(f);

            jumpLine();

            dataSearchLetter();

            break;
        default:
            clearScreen();
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            clearScreen();
            dataSearchLetter();
            break;
    }
}

// 5 --|--
void dataEdit() { // Alterar dados
    int change;

    // Limpa tela
    clearScreen();

    // Linha superior
    buildMenuTopLine();

    // Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Alterar dados");
    jumpLine(); // Pula linha

    // Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:
            clearScreen();

            int n_reg;
            int n_bytes;

            FILE *f;

            n_reg = searchName();

            if(n_reg == -1) {
                clearScreen();
                printf("\tNenhum registro encontrado.\n");
                Sleep(2000);
                clearScreen();
                dataEdit();
                return;
            }

            n_bytes = (sizeof(product1) + sizeof(amount1)) * n_reg;

            f = fopen("product.txt", "r+");

            fseek(f, n_bytes, 0);

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);

            printf("\tAlterar %s ->: ", product1);
            scanf("%s", &product1);

            int aux;
            aux = amount1;

            do {

                printf("\tAlterar %d unidade(s) ->: ", aux);
                scanf("%d", &amount1);

                if(amount1 < 0 || amount1 == 10) {
                    printf(YEL "\tATENCAO: Nao pode digitar numeros negativos ou o numero 10.\n" RESET);
                    jumpLine();
                }

            } while(amount1 < 0 || amount1 == 10);

            fseek(f, n_bytes, 0);

            fwrite(&product1, sizeof(product1), 1, f);
            fwrite(&amount1, sizeof(amount1), 1, f);

            fclose(f);

            clearScreen();
            printf(GRN "\tProduto alterado(a) com sucesso." RESET);
            Sleep(2500);

            dataEdit();
            break;
        default:
            clearScreen();
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            clearScreen();
            dataEdit();
            break;
    }
}

// 6 --|--
void dataDelete() { // Excluir dados
    int change;

    // Limpa tela
    clearScreen();

    // Linha superior
    buildMenuTopLine();

    // Menu item
    buildMenuItem(" 1 - Voltar");
    jumpLine(); // Pula linha
    buildMenuItem(" 2 - Excluir dados");
    jumpLine(); // Pula linha

    // Linha inferior
    buildMenuBottomLine();

    printf("\tEscolha uma das opcoes acima: ");
    scanf("%d", &change);

    switch(change) {
        case 1:
            menu();
            break;
        case 2:

            clearScreen();

            int n_reg;
            int n_bytes;

            FILE *f;

            n_reg = searchName();

            if(n_reg == -1) {
                clearScreen();
                printf("\tNenhum registro encontrado.\n");
                Sleep(2000);
                clearScreen();
                dataDelete();
                return;
            }

            n_bytes = (sizeof(product1) + sizeof(amount1)) * n_reg;

            f = fopen("product.txt", "r+");

            fseek(f, n_bytes, 0);

            fread(&product1, sizeof(product1), 1, f);
            fread(&amount1, sizeof(amount1), 1, f);

            product1[0] = '*';
            amount1 = NULL;

            fseek(f, n_bytes, 0);

            fwrite(&product1, sizeof(product1), 1, f);
            fwrite(&amount1, sizeof(amount1), 1, f);

            fclose(f);

            clearScreen();
            printf(GRN "\tProduto excluido(a) com sucesso." RESET);
            Sleep(2500);

            dataDelete();

            break;
        default:
            clearScreen();
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            clearScreen();
            dataDelete();
            break;
    }
}

// 7 --|--
void quit() { // Fechar o programa

    for(int i = 3; i >= 0; i--) {
        clearScreen();
        printf("\tFinalizando o programa... %d Aguarde.\n", i);
        Sleep(1000);
    }

    clearScreen();

    printf("\tPrograma encerrado.");
    Sleep(1500);

    exit(0);
}
// ----------------------------------------------------------|O*

// Build Menu -----------------------------------------------|X*
void buildMenuTopLine() { // Linha superior do menu
    //Menu Top --------------------------------------------|
    printf("\t%c", 201);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 187);

    jumpLine();
}

void buildMenuItem(char str[]) { // Seleção do menu
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

void buildMenuBottomLine() { // Linha inferior do menu
    //Menu Bottom -----------------------------------------|
    printf("\t%c", 200);

    for(int i = 0; i < 36; i++) {
        printf("%c", 205);
    }

    printf("%c", 188);

    jumpLine(); //
}

void menu() { // Menu
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
            printf(RED "\tErro no sistema." RESET);
            Sleep(2000);
            menu();
            break;
    }
}
// ----------------------------------------------------------|X*

// Home -----------------------------------------------------|O*
int main() { // Aplicação
    menu();
    return 0;
}
// ----------------------------------------------------------|O*

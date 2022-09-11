#include <stdlib.h>//para alocar memoria , declara funçoes de entrada e saida como STANDARD
#include <stdio.h>//cabeçario padrao de entrada e saida
#include <windows.h>
#include <time.h>

//Prototipos de fucao
void pesquisar();
void cadastro();
void menu();
void alterar();
void excluir();
void sistema();
void Idade();
void login();
void senha_invalida();
void abrir_arq();
void positivo_covid();

//declaraçao de variaveis
int op, op1, op2, op3, op4, i, quant, idade;
FILE *p;
FILE *aux;

struct {
char nome[100];//200 nomes
char email[100] ;
char comorbidade[100];
char bairro[100];
char rua[100];
char estado[100];
char cidade[100];
char nasc[100];
char telefone[100];
char cep[100];
char cpf[100];
}
C[500];

typedef struct{
    char login[30];
    char senha[30];
}pessoa; pessoa pp[1];

int main(){



    system("cls");

    printf("--------------------------------------------------------------------\n");
     printf("--------------------------------------------------------------------\n");
    printf("------------ Hospital PRONTOCLIN SAUDE ------------------------------\n");
     printf("--------------------------------------------------------------------\n");
      printf("--------------------------------------------------------------------\n");
    //system("color "); //cor do programa
    printf("_______________________________________________________________________________________________________\n\n");
    printf(" \t CADASTRO PARA MONITORAMENTO DE PACIENTES SELECIONE UMA OPCAO \n");
    printf("______________________________________________________________________________________________________\n");
    positivo_covid();
}

void pesquisar(){

            system("cls");
        for ( i = 0; i < quant; i++){
            system("cls");
            printf("\n\n\t\t\t    Cadastro %d\n", i);
            printf("\t\t   --------------------\n\n");
            printf("Paciente: %s\n", C[i].nome);
            printf("CPF: %s\n", C[i].cpf);
            printf("Telefone: %s\n", C[i].telefone);
            printf("Rua: %s\n", C[i].rua);
            printf("Bairro %s\n", C[i].bairro);
            printf("Cidade: %s\n", C[i].cidade);
            printf("Estado: %s\n", C[i].estado);
            printf("CEP: %s\n", C[i].cep);
            printf("Data de nascimento: %s\n", C[i].nasc);
            printf("e-mail: %s\n", C[i].email);
            system("pause");
        }
}

void cadastro(){

    p = fopen("piim4.txt","w+b");
    if (p == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }


        system("cls");
        printf("Quantidade de cadastros a serem realizados: ");
        scanf("%d", &quant);
        system("cls");


        for ( i = 0; i < quant; i++){
            abrir_arq();
            printf("\n\n\t\t\t        Cadastro %d\n",i);
            printf("\t\t\t   --------------------\n\n");
            printf("Nome: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].nome);

            printf("CPF: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].cpf);


            printf("Telefone: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].telefone);


            printf("Rua e Numero: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].rua);


            printf("Bairro: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].bairro);


            printf("Cidade: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].cidade);


            printf("Estado: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].estado);


            printf("CEP: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].cep);


            printf("Data de nascimento(dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].nasc);


            printf("e-mail: ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].email);
            printf("\n\n\t\t");

            printf("\n------------------------------CONSULTA------------------------------\n\n");

            char dateStr[9];
            char timeStr[9];
            _strdate(dateStr);
             //printf("data diagnostico: %s\n", dateStr); data em ingles
            _strdate(timeStr);
            //printf("the current date is %s\n", timeStr);

            char dia[5] = {dateStr[3], dateStr[4]};
            char mes[5] = {dateStr[0], dateStr[1]};
            char ano[5] = {dateStr[6], dateStr[7]};
            printf("Data do Diagnostico: %s/%s/20%s\n", dia, mes, ano);
            getchar();

            printf("Comorbidade(Deixar em branco caso nao possua): ");
            fflush(stdin);
            scanf("%[^\n]s\n", C[i].comorbidade);
            printf("\n\n\t\t");


            fprintf(p, "Nome: %s\n", C->nome);
            fprintf(p, "CPF: %s\n", C->cpf);
            fprintf(p, "Telefone: %s\n", C->telefone);
            fprintf(p, "Rua: %s\n", C->rua);
            fprintf(p, "Bairro: %s\n", C->bairro);
            fprintf(p, "Cidade: %s\n", C->cidade);
            fprintf(p, "Estado: %s\n", C->estado);
            fprintf(p, "CEP: %s\n", C->cep);
            fprintf(p, "Data de Nascimento: %s\n", C->nasc);
            fprintf(p, "e-mail: %s\n", C->email);
            fprintf(p, "Data do diagnostico: %s\n", dateStr);
            fprintf(p, "Comorbidade: %s\n", C->comorbidade);
            fseek(p, SEEK_END, 1);
            fclose(p);
            system("pause");
            system("cls");
        }
        Idade();
}

void menu(){
    system("cls");
    while (1)// 1 - executar enquanto for verdadeiro.
    {
        system("cls");
    printf("\t\t\t CADASTRO PARA MONITORAMENTO DE PACIENTES \n\t\t\t    PRONTOCLIN SETOR COVID 19\n");
    printf("--------------------------------------------------------------------\n\n");
    printf("[1] - Cadastrar\n[2] - Pesquisar\n[3] - Alterar\n[4] - Excluir\n[5] - Informacoes do Sistema\n[0] - Sair\n");
    printf("--------------------------------------------------------------------\n\n");
    printf("Digite uma opcao: ");
    scanf("%d", &op);


            if (op == 1)
            {
            cadastro();
            }
            else if (op == 2)
            {
            pesquisar();
            }
            else if (op == 3)
            {
            alterar();
            }
            else if (op == 4)
            {
            excluir();
            }
            else if (op == 5)
            {
            sistema();
            }
            else if (op == 0)
            {
            system("cls");
            printf("[1] - SAIR\n[2] - Menu");
            printf("\n\n");
            scanf("%d", &op2);

            switch(op2){
            case 1:
            system("cls");
            printf("Saindo.");
            Sleep(1000);
            system("cls");
            printf("Saindo..");
            Sleep(1000);
            system("cls");
            printf("Saindo...");
            Sleep(1000);
            system("cls");
            system("cls");
            printf("Saindo.");
            Sleep(1000);
            system("cls");
            printf("Saindo..");
            Sleep(1000);
            system("cls");
            printf("Saindo...");
            Sleep(1000);
            system("cls");
            break;
            }
            exit(1);
    }
}
}

void alterar(){

    system("cls");
        for ( i = 0; i < quant; i++){
            printf("\n\n\t\t\t    Alterar Cadastro do Paciente\n");
            printf("\t\t   --------------------\n\n");
            printf("[1] - Nome\n[2] - CPF\n[3] - Telefone\n[4] - Rua\n[5] - Bairro\n[6] - Cidade\n[7] - Estado\n[8] - CEP\n[9] - Data de Nascimento\n[10] - e-mail\n\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &op1);

            switch(op1){

                case 1:
                for ( i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("Alterar Nome: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].nome);
                    printf("\nNovo Nome: %s\n\n\t\t");
                    system("pause");
                }
                break;

                case 2:
                for ( i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar CPF: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].cpf);
                    printf("\nNovo CPF: %s\n\n\t\t");
                    system("pause");
                }
                break;

                case 3:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Telefone : ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].telefone);
                    printf("\nNovo Telefone: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 4:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Rua: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].rua);
                    printf("\nNova Rua: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 5:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Bairro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].bairro);
                    printf("\nNovo Bairro: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 6:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Cidade: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].cidade);
                    printf("\nNova Cidade: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 7:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Estado: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].estado);
                    printf("\nNovo Estado: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 8:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar CEP: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].cep);
                    printf("\nNovo CEP: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 9:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar Data de Nascimento: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].nasc);
                    printf("\nNova Data de Nascimento: %s\n\n\t\t");
                    system("pause");
                }
                break;


                case 10:
                for (i = 0; i < quant; i++){
                    system("cls");
                    printf("\n\nCadastro %d\n", i);
                    printf("\nAlterar e-mail: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &C[i].email);
                    printf("\nNovo e-mail: %s\n\n\t\t");
                    system("pause");
                }
                break;

            }
        }


}

void excluir(){

    system("cls");
        for (i = 0; i < quant; i++){
            printf("\n\n\t\t\t    Excluir Dados do Paciente\n");
            printf("\t\t   --------------------\n\n");
            printf("[1] - Nome\n[2] - CPF\n[3] - Telefone\n[4] - Rua\n[5] - Bairro\n[6] - Cidade\n[7] - Estado\n[8] - CEP\n[9] - Data de Nascimento\n[10] - e-mail\n[0] - Exclir Todos os Dados\n\n");
            printf("Digite a opcao que deseja excluir: \n");
            scanf("%d", &op4);

            switch(op4){

                case 1:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C [i].nome, 0, sizeof(C[i].nome));//comando para excluir a variavel
                    printf("Nome Excluido!\n\n");
                    system("pause");
                }
            break;



                case 2:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].cpf ,0,sizeof(C[i].cpf));
                    printf("CPF Excluido!\n\n");
                    system("pause");
                }
            break;


                case 3:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].telefone ,0,sizeof(C[i].telefone));
                    printf("Telefone Excluido!\n\n");
                    system("pause");
                }
            break;


                case 4:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].rua ,0,sizeof(C[i].rua));
                    printf("Rua Excluida!\n\n");
                    system("pause");
                }
            break;


                case 5:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].bairro ,0,sizeof(C[i].bairro));
                    printf("Bairro Excluido!\n\n");
                    system("pause");
                }
            break;


                case 6:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].cidade ,0,sizeof(C[i].cidade));
                    printf("Cidade Excluida!\n\n");
                    system("pause");
                }
            break;


                case 7:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].estado ,0,sizeof(C[i].estado ));
                    printf("Estado Excluido!\n\n");
                    system("pause");
                }
            break;


                case 8:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].cep ,0,sizeof(C[i].cep));
                    printf("CEP Excluido!\n\n");
                    system("pause");
                }
            break;


                case 9:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].nasc ,0,sizeof(C[i].nasc));
                    printf("Data de Nascimento Excluida!\n\n");
                    system("pause");
                }
            break;


                case 10:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].email ,0,sizeof(C[i].email));
                    printf("e-mail Excluido!\n\n");
                    system("pause");
                }
            break;

                case 0:
                for (i = 0; i < quant; i++){
                    system("cls");
                    memset(&C[i].nome ,0,sizeof(C[i].nome));
                    memset(&C[i].cpf ,0,sizeof(C[i].cpf));
                    memset(&C[i].telefone ,0,sizeof(C[i].telefone));
                    memset(&C[i].rua ,0,sizeof(C[i].rua));
                    memset(&C[i].bairro ,0,sizeof(C[i].bairro));
                    memset(&C[i].cidade ,0,sizeof(C[i].cidade));
                    memset(&C[i].estado ,0,sizeof(C[i].estado ));
                    memset(&C[i].cep ,0,sizeof(C[i].cep));
                    memset(&C[i].nasc ,0,sizeof(C[i].nasc));
                    memset(&C[i].email ,0,sizeof(C[i].email));
                    printf("Todos os Dados Foram Excluidos!\n\n");
                    system("pause");
                }
            break;
            }
        }

}

void sistema(){

    system("cls");
            printf("Desenvolvedores do Projeto: \n\n");
            printf("Devs..");
            /*printf("");
            printf("");
            printf("");*/
            printf("\ ALUNOS UNIP ANALISE E DESENVOLVIMENTO DE SISTEMAS \n");
            printf("Ingressantes AGO 2121  DEVS.....\n\n");
            printf("Adriano Barboza de Oliveira_RA_2193469\n ");
            printf ("Amauri Santos_RA_0430191 \n");
            printf("Andre Gomes Borges Vieira_RA_0426246 \n");
            printf("Rafae Yoshida_RA_0408427\n\n");
            system("pause");
}

void Idade(){

    aux = fopen("pim41.txt","w+b");
    if (aux == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

        system("cls");
        printf("Informe a idade do paciente: ");
        fflush(stdin);
        scanf("%d", &idade);
        int diferenca_tempo;
        if(idade >= 65)
        {
        printf("\nO Paciente faz parte do grupo de risco!\n", diferenca_tempo);

            fprintf(aux, "\n--------------------------------------------------------------------\n\n");
            fprintf(aux, "\t\t\tGrupo de Risco!!\n\n");
            fprintf(aux, "Nome: %s\n", C->nome);
            fprintf(aux, "CPF: %s\n", C->cpf);
            fprintf(aux, "Telefone: %s\n", C->telefone);
            /*fprintf(aux, "Rua: %s\n", C->rua);
            fprintf(aux, "Bairro: %s\n", C->bairro);
            fprintf(aux, "Cidade: %s\n", C->cidade);
            fprintf(aux, "Estado: %s\n", C->estado);
            fprintf(aux, "Data de Nascimento: %s\n", C->nasc);
            fprintf(aux, "e-mail: %s\n", C->email);
            fprintf(aux, "Data do diagnostico: %s\n", dateStr);
            fprintf(aux, "Comorbidade: %s\n", C->comorbidade);*/
            fprintf(aux, "CEP: %s\n", C->cep);
            fprintf(aux, "Idade: %d\n", idade);
            fseek(aux, SEEK_END, 1);
            //fwrite(&C, sizeof(C), 1, p);
            fclose(aux);
            //fclose(p);
            system("pause");
            system("cls");



        Sleep(1500);
        system("cls");


        }else{
            diferenca_tempo = 65 - idade;
        printf("\nO Paciente nao faz parte do Grupo de Risco!\n\n", diferenca_tempo);
        }
        Sleep(1500);
        system("pause");
        system("cls");

        printf("[1] - Novo cadastro\n[2] - Voltar ao Menu\n");
        scanf("%d", &op);
        Sleep(1500);
        fflush(stdin);

        if (op==2)
        {
            system("cls");
            menu();
        }else if(op==1){
            system("cls");
            cadastro();
        }
}

void login(){
    system("cls");
    //system("color f1");
    char login[30];//maximo de caracteres para o login.
    char senha[30];//maximo de caracteres para a senha.

    strcpy (pp[0]. login, "admin");//login ja definido pelo ADM.(strcpy - faz uma copia da string com valor ja definido ,so assim é possivel alterar o valor como string. )
    strcpy (pp[0]. senha, "0000");//senha ja definida pelo ADM.

    printf("Login: ");
    scanf("%s", login);

    printf("Senha: ");
    scanf("%s", senha);


    while (!strcmp(login, senha))
    {
        system("cls");//cls limpa a tela assim como no cmd
        printf("nome de usuario e senha devem ser diferentes.\n\n");
        printf("Login:");
        scanf("%s",login);
        printf("Senha:");
        scanf("%s", senha);

    }

    if ((strcmp(login, pp[0].login)==0) && (strcmp(senha, pp[0].senha)==0))//strcmp - compara as strings
    {
        system("cls");
        printf("\t--------------------------------------------Usuario Logado!---------------------------------------------\n\n");
        Sleep(1500);
        system("cls");
        printf("\t--------------------------------------------Seja Bem Vindo!---------------------------------------------\n\n");
        printf("\nDigite Uma Opcao Disponivel:\n");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        system("cls");
        senha_invalida();
        menu();
    }

}

void senha_invalida(){

        fflush(stdin);
        system("cls");//cls limpa a tela assim como no cmd
        printf("\tLogin ou Senha Invalidos!\n\n");
        Sleep(1500);

        system("cls");
        printf("\tTente Novamente!");
        Sleep(1500);

        system("cls");

        login();
}

void abrir_arq(){

    p = fopen("piim4.txt","a+b");
    aux = fopen("auxiliar.txt","wb");
    if (p == NULL || aux == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }

}

void positivo_covid(){
do
{

printf("\n\n[1] - Positivo Para Covid-19\n[2] - Negativo\n");
scanf("%d", &op);
    if (op == 1)
    {
        login();
    }else{
            system("cls");
            printf("Saindo.");
            Sleep(1000);
            system("cls");
            printf("Saindo..");
            Sleep(1000);
            system("cls");
            printf("Saindo...");
            Sleep(1000);
            system("cls");
            system("cls");
            printf("Saindo.");
            Sleep(1000);
            system("cls");
            printf("Saindo..");
            Sleep(1000);
            system("cls");
            printf("Saindo...");
            Sleep(1000);
            system("cls");
        exit(1);
    }

} while (op!=2);
}

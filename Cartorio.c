#include <stdio.h>
#include <stdlib.h> // Alocação de Espaço em memória
#include <locale.h> // Corrigir o bug de não reconhecer os acentos e Ç
#include <string.h> // Comando FILE e outras funções relacionadas a strings

// Função Cadastrar Usuários no Sistema | Atributte Unused = Ignore a não utilização da variável menu

int registro(int voltar_menu, int menu __attribute__ ((unused))) 
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40], nome [40], sobrenome [40], cargo[40], arquivo[40];
    printf("\n\t Registro de Nomes \n");
    
    printf("Digite o CPF do usuário que será registrado: ");
    scanf("%s",cpf);
    strcpy(arquivo, cpf); // Copiando o valor da variável "CPF" na variável "arquivo"

    FILE *bd; // Chamando a funcionalidade FILE
    bd = fopen(arquivo, "w"); // Criando o arquivo do banco de dados com w = WRITE
    fprintf(bd, cpf); // Escrevendo dentro do file
    fclose(bd); // Fechando a funcionalidade FILE

    bd = fopen(arquivo, "a"); // Abrindo o bd entrando no arquivo e usando o A (Access) para ATUALIZAR
    fprintf(bd, " | "); // Estamos dentro do .txt, vamos colocar um espaçamento com o fprintf
    fclose(bd); // Fechando a funcionalidade FILE

    printf("Digite o NOME do usuário que será criado: ");
    scanf("%s", nome);
    bd = fopen(arquivo, "a");
    fprintf(bd, nome);
    fclose(bd);

    bd = fopen(arquivo, "a"); 
    fprintf(bd, " | "); 
    fclose(bd);

    printf("Digite o SOBRENOME do usuário que será criado: ");
    scanf("%s",sobrenome);
    bd = fopen(arquivo, "a");
    fprintf(bd, sobrenome);
    fclose(bd);

    bd = fopen(arquivo, "a"); // Abrindo o bd entrando no arquivo e usando o A (Access) para ATUALIZAR
    fprintf(bd, " | "); // Estamos dentro do .txt, vamos colocar a vírgula com o fprintf
    fclose(bd); // Fechando a funcionalidade FILE

    printf("Digite o CARGO do usuário que será criado: ");
    scanf("%s",cargo);
    bd = fopen(arquivo, "a");
    fprintf(bd, cargo);
    fclose(bd);

    printf("\n\n -------- Registro feito com SUCESSO---- \n\n");
    printf("Para consultar os nomes já registrados volte ao menu e selecione a OPÇÃO 2 \n\n");
    printf("Você deseja voltar ao menu principal? 1 Para SIM ou 2 Para NÃO \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OPÇÃO INVÁLIDA, VOCE SERÁ REDIRECIONADO AO MENU \n");
        system("pause");
    }
    system("pause");
    return 1;
}

int consulta(int voltar_menu, int menu __attribute__((unused)))
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40], infos[200];
    printf("\t Consulta de Nomes \n");
    printf("Por favor, digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *bd;  // Definindo o BD como Banco de dados
    bd = fopen(cpf, "r"); // Definindo o nome dp bd como a  variável cpf

    if(bd == NULL) // Se for Nulo / Não encontrado apresente a mensagem abaixo
    {
        printf("USUÁRIO NÃO LOCALIZADO OU REGISTRADO EM NOSSO SISTEMA \n");
    }

    while(fgets(infos, 200, bd) != NULL) // Enquanto a captura de caracteres através do fgets for diferente de NULL faça isso
    {
        printf("Essas são as informações do usuário \n");
        printf("%s",infos);
        printf("\n");
    }

    printf("Você deseja voltar ao menu principal? 1 Para SIM ou 2 Para NÃO \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OPÇÃO INVÁLIDA, VOCE SERÁ REDIRECIONADO AO MENU \n");
    }
    system("pause");
    fclose(bd);
    return 1;
}

int deletar(int voltar_menu, int menu __attribute__((unused))) // SISTEMA DE REMOÇÃO DE USUÁRIOS
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    printf("\t ---- Deletar Usuários ---- \n\n");
    printf("Por favor, digite o CPF do usuário a ser excluido abaixo \n");
    scanf("%s",cpf);

    // Todo comando quando tem sucesso na sua tarefa retorna o valor 0
    if(remove(cpf) == 0) // Se a remoção da variável cpf for bem sucedida ela retornará valor 0 e a mensagem será apresentada
    {
        printf("USUÁRIO REMOVIDO COM SUCESSO \n");
        system("pause");
    }
    else // Se isso não acontecer a exclusão será incompleta
    {
        printf("EXCLUSÃO INCOMPLETA - USUÁRIO NÃO EXISTE NO SISTEMA \n");
    }
    printf("Você deseja voltar ao menu principal? 1 Para SIM ou 2 Para NÃO \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OPÇÃO INVÁLIDA, VOCE SERÁ REDIRECIONADO AO MENU \n");
    }
    system("pause");
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo os acentos para língua Portuguesa
    int escolha = 0, menu = 1, voltar_menu = 0;
    char nome [6];
    printf("Olá esse é o Cartório da Ebac, Digite o seu nome: ");
    scanf("%s",nome);
    
    while(menu == 1)
    {   
        system("cls"); // Limpar a Tela
        printf("\nSeja bem vindo ao cartório da EBAC, %s \n\n",nome);
        printf("\t #### MENU DO CARTÓRIO #### \n \n");
        printf("\t1 - Registrar um Novo nome \n\t2 - Consultar Nomes \n\t3 - Deletar um Nome \n\t4- Sair\n");
        printf("Por favor usuário selecione uma das três opções acima: ");
        scanf("%d",&escolha);
        system("cls"); 

        switch (escolha) // Opções Menu
        {
            case 1:
            menu = registro(voltar_menu, menu); // Utilizando a Função Registro
            break;
            
            case 2:
            menu = consulta(voltar_menu, menu); // Utilizando a Função Consulta
            break;
            
            case 3:
            menu = deletar(voltar_menu, menu); // Utilizando a Função Deletar
            break;

            case 4:
            menu = 0;
            break;
        
            default:
            printf("OPÇÃO INVÁLIDA, POR FAVOR TENTE NOVAMENTE \n");
            system("pause");
            break;
        }
    }
    printf("Muito obrigado por usar o nosso sistema :) \n");
    return 0;
}
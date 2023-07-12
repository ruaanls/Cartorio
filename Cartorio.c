#include <stdio.h>
#include <stdlib.h> // Aloca��o de Espa�o em mem�ria
#include <locale.h> // Corrigir o bug de n�o reconhecer os acentos e �
#include <string.h> // Comando FILE e outras fun��es relacionadas a strings

// Fun��o Cadastrar Usu�rios no Sistema | Atributte Unused = Ignore a n�o utiliza��o da vari�vel menu

int registro(int voltar_menu, int menu __attribute__ ((unused))) 
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40], nome [40], sobrenome [40], cargo[40], arquivo[40];
    printf("\n\t Registro de Nomes \n");
    
    printf("Digite o CPF do usu�rio que ser� registrado: ");
    scanf("%s",cpf);
    strcpy(arquivo, cpf); // Copiando o valor da vari�vel "CPF" na vari�vel "arquivo"

    FILE *bd; // Chamando a funcionalidade FILE
    bd = fopen(arquivo, "w"); // Criando o arquivo do banco de dados com w = WRITE
    fprintf(bd, cpf); // Escrevendo dentro do file
    fclose(bd); // Fechando a funcionalidade FILE

    bd = fopen(arquivo, "a"); // Abrindo o bd entrando no arquivo e usando o A (Access) para ATUALIZAR
    fprintf(bd, " | "); // Estamos dentro do .txt, vamos colocar um espa�amento com o fprintf
    fclose(bd); // Fechando a funcionalidade FILE

    printf("Digite o NOME do usu�rio que ser� criado: ");
    scanf("%s", nome);
    bd = fopen(arquivo, "a");
    fprintf(bd, nome);
    fclose(bd);

    bd = fopen(arquivo, "a"); 
    fprintf(bd, " | "); 
    fclose(bd);

    printf("Digite o SOBRENOME do usu�rio que ser� criado: ");
    scanf("%s",sobrenome);
    bd = fopen(arquivo, "a");
    fprintf(bd, sobrenome);
    fclose(bd);

    bd = fopen(arquivo, "a"); // Abrindo o bd entrando no arquivo e usando o A (Access) para ATUALIZAR
    fprintf(bd, " | "); // Estamos dentro do .txt, vamos colocar a v�rgula com o fprintf
    fclose(bd); // Fechando a funcionalidade FILE

    printf("Digite o CARGO do usu�rio que ser� criado: ");
    scanf("%s",cargo);
    bd = fopen(arquivo, "a");
    fprintf(bd, cargo);
    fclose(bd);

    printf("\n\n -------- Registro feito com SUCESSO---- \n\n");
    printf("Para consultar os nomes j� registrados volte ao menu e selecione a OP��O 2 \n\n");
    printf("Voc� deseja voltar ao menu principal? 1 Para SIM ou 2 Para N�O \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OP��O INV�LIDA, VOCE SER� REDIRECIONADO AO MENU \n");
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
    bd = fopen(cpf, "r"); // Definindo o nome dp bd como a  vari�vel cpf

    if(bd == NULL) // Se for Nulo / N�o encontrado apresente a mensagem abaixo
    {
        printf("USU�RIO N�O LOCALIZADO OU REGISTRADO EM NOSSO SISTEMA \n");
    }

    while(fgets(infos, 200, bd) != NULL) // Enquanto a captura de caracteres atrav�s do fgets for diferente de NULL fa�a isso
    {
        printf("Essas s�o as informa��es do usu�rio \n");
        printf("%s",infos);
        printf("\n");
    }

    printf("Voc� deseja voltar ao menu principal? 1 Para SIM ou 2 Para N�O \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OP��O INV�LIDA, VOCE SER� REDIRECIONADO AO MENU \n");
    }
    system("pause");
    fclose(bd);
    return 1;
}

int deletar(int voltar_menu, int menu __attribute__((unused))) // SISTEMA DE REMO��O DE USU�RIOS
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    printf("\t ---- Deletar Usu�rios ---- \n\n");
    printf("Por favor, digite o CPF do usu�rio a ser excluido abaixo \n");
    scanf("%s",cpf);

    // Todo comando quando tem sucesso na sua tarefa retorna o valor 0
    if(remove(cpf) == 0) // Se a remo��o da vari�vel cpf for bem sucedida ela retornar� valor 0 e a mensagem ser� apresentada
    {
        printf("USU�RIO REMOVIDO COM SUCESSO \n");
        system("pause");
    }
    else // Se isso n�o acontecer a exclus�o ser� incompleta
    {
        printf("EXCLUS�O INCOMPLETA - USU�RIO N�O EXISTE NO SISTEMA \n");
    }
    printf("Voc� deseja voltar ao menu principal? 1 Para SIM ou 2 Para N�O \n");
    scanf("%d",&voltar_menu);
    if(voltar_menu == 2)
    {
        return 0;
    }
    else if(voltar_menu > 2)
    {
        printf("OP��O INV�LIDA, VOCE SER� REDIRECIONADO AO MENU \n");
    }
    system("pause");
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo os acentos para l�ngua Portuguesa
    int escolha = 0, menu = 1, voltar_menu = 0;
    char nome [6];
    printf("Ol� esse � o Cart�rio da Ebac, Digite o seu nome: ");
    scanf("%s",nome);
    
    while(menu == 1)
    {   
        system("cls"); // Limpar a Tela
        printf("\nSeja bem vindo ao cart�rio da EBAC, %s \n\n",nome);
        printf("\t #### MENU DO CART�RIO #### \n \n");
        printf("\t1 - Registrar um Novo nome \n\t2 - Consultar Nomes \n\t3 - Deletar um Nome \n\t4- Sair\n");
        printf("Por favor usu�rio selecione uma das tr�s op��es acima: ");
        scanf("%d",&escolha);
        system("cls"); 

        switch (escolha) // Op��es Menu
        {
            case 1:
            menu = registro(voltar_menu, menu); // Utilizando a Fun��o Registro
            break;
            
            case 2:
            menu = consulta(voltar_menu, menu); // Utilizando a Fun��o Consulta
            break;
            
            case 3:
            menu = deletar(voltar_menu, menu); // Utilizando a Fun��o Deletar
            break;

            case 4:
            menu = 0;
            break;
        
            default:
            printf("OP��O INV�LIDA, POR FAVOR TENTE NOVAMENTE \n");
            system("pause");
            break;
        }
    }
    printf("Muito obrigado por usar o nosso sistema :) \n");
    return 0;
}
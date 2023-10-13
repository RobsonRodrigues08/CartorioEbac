#include <stdlib.h>   // Biblioteca padr�o que fornece fun��es de aloca��o de mem�ria, convers�es num�ricas, entre outros.
#include <locale.h>   // Biblioteca para configurar a localiza��o e formata��o de caracteres.
#include <string.h>   // Biblioteca para fun��es de manipula��o de strings.
#include <stdio.h>    // Biblioteca para fun��es de entrada/sa�da padr�o.

// Fun��o para registrar informa��es em um arquivo
int registrar() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Solicita ao usu�rio que insira o CPF
    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s", cpf);

    // Cria um nome de arquivo com base no CPF fornecido
    strcpy(arquivo, cpf);

    FILE *file;
    // Abre o arquivo para escrita, substituindo o conte�do existente
    file = fopen(arquivo, "w");
    // Escreve o CPF no arquivo
    fprintf(file, "%s\n", cpf);
    // Fecha o arquivo
    fclose(file);

    // Abre o arquivo novamente para adicionar informa��es adicionais
    file = fopen(arquivo, "a");

    // Solicita ao usu�rio que insira o nome
    printf("\nDigite o nome a ser cadastrado: ");
    scanf("%s", nome);
    // Escreve o nome no arquivo
    fprintf(file, "%s\n",nome);
    
    // Solicita ao usu�rio que insira o sobrenome
    printf("\nDigite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    // Escreve o sobrenome no arquivo
    fprintf(file, "%s\n", sobrenome);

    // Solicita ao usu�rio que insira o cargo
    printf("\nDigite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    // Escreve o cargo no arquivo
    fprintf(file, "%s\n", cargo);

    // Fecha o arquivo ap�s adicionar todas as informa��es
    fclose(file);

    // Pausa a execu��o para o usu�rio ver as mensagens
    system("pause");

    return 0;
}


// Fun��o para consultar informa��es com base em um CPF
int consultar() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    // Solicita ao usu�rio que insira o CPF a ser consultado
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    // Abre o arquivo correspondente ao CPF para leitura
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        // Se o arquivo n�o puder ser aberto, exibe uma mensagem de erro
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
        return 1; // Sai da fun��o com um c�digo de erro
    }
    
    // Exibe as informa��es do usu�rio armazenadas no arquivo
    printf("\n\nEssas s�o as informa��es do usu�rio:  ");    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");
    
    // Fecha o arquivo ap�s a leitura
    fclose(file);
    
    return 0; // Retorna 0 para indicar sucesso
}




// Fun��o para excluir informa��es com base em um CPF
void deletar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    // Solicita ao usu�rio que insira o CPF a ser exclu�do
    printf("Digite o CPF a ser exclu�do: ");
    scanf("%s", cpf);

    // Tenta excluir o arquivo correspondente ao CPF
    if (remove(cpf) == 0) {
        // Se a exclus�o for bem-sucedida, exibe uma mensagem de sucesso
        printf("Registro exclu�do com sucesso.\n");
    } else {
        // Se houver um erro na exclus�o, exibe uma mensagem de erro
        printf("N�o foi poss�vel excluir o registro, pois n�o est� cadastrado em nosso sistema\n");
    }
}

// Fun��o principal
int main() {
    int opcao = 0;
    int x = 1;
    for (x = 1; x == 1;) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");
        printf(">>>> CART�RIO <<<< EBAC <<<< \n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1-Registrar nome \n");
        printf("\t2-Consultar nome \n");
        printf("\t3-Excluir nome \n");
        printf("\t4- Sair do sistema\n\n");
        printf("Op��o: ");

        // L� a op��o do usu�rio
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registrar();
                // Exibe mensagem ap�s a conclus�o da opera��o
                printf("Voc� escolheu registrar um nome.\n");
                break;
            case 2:
                consultar();
                // Exibe mensagem ap�s a conclus�o da opera��o
                printf("Voc� escolheu consultar um nome.\n");
                system("pause");
                break;
            case 3:
                deletar();
                // Exibe mensagem ap�s a conclus�o da opera��o
                printf("Voc� escolheu excluir um nome.\n");
                system("pause");
                break;
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;	
            default:
                // Exibe uma mensagem de erro para op��es inv�lidas
                printf("Essa op��o n�o est� dispon�vel.\n");
                system("pause");
                break;
        }
    }
    return 0;
}

	
		

		
	 

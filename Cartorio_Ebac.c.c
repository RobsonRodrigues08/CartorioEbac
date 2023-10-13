#include <stdlib.h>   // Biblioteca padrão que fornece funções de alocação de memória, conversões numéricas, entre outros.
#include <locale.h>   // Biblioteca para configurar a localização e formatação de caracteres.
#include <string.h>   // Biblioteca para funções de manipulação de strings.
#include <stdio.h>    // Biblioteca para funções de entrada/saída padrão.

// Função para registrar informações em um arquivo
int registrar() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Solicita ao usuário que insira o CPF
    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s", cpf);

    // Cria um nome de arquivo com base no CPF fornecido
    strcpy(arquivo, cpf);

    FILE *file;
    // Abre o arquivo para escrita, substituindo o conteúdo existente
    file = fopen(arquivo, "w");
    // Escreve o CPF no arquivo
    fprintf(file, "%s\n", cpf);
    // Fecha o arquivo
    fclose(file);

    // Abre o arquivo novamente para adicionar informações adicionais
    file = fopen(arquivo, "a");

    // Solicita ao usuário que insira o nome
    printf("\nDigite o nome a ser cadastrado: ");
    scanf("%s", nome);
    // Escreve o nome no arquivo
    fprintf(file, "%s\n",nome);
    
    // Solicita ao usuário que insira o sobrenome
    printf("\nDigite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    // Escreve o sobrenome no arquivo
    fprintf(file, "%s\n", sobrenome);

    // Solicita ao usuário que insira o cargo
    printf("\nDigite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    // Escreve o cargo no arquivo
    fprintf(file, "%s\n", cargo);

    // Fecha o arquivo após adicionar todas as informações
    fclose(file);

    // Pausa a execução para o usuário ver as mensagens
    system("pause");

    return 0;
}


// Função para consultar informações com base em um CPF
int consultar() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    // Solicita ao usuário que insira o CPF a ser consultado
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    // Abre o arquivo correspondente ao CPF para leitura
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        // Se o arquivo não puder ser aberto, exibe uma mensagem de erro
        printf("Não foi possível abrir o arquivo, não localizado.\n");
        return 1; // Sai da função com um código de erro
    }
    
    // Exibe as informações do usuário armazenadas no arquivo
    printf("\n\nEssas são as informações do usuário:  ");    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");
    
    // Fecha o arquivo após a leitura
    fclose(file);
    
    return 0; // Retorna 0 para indicar sucesso
}




// Função para excluir informações com base em um CPF
void deletar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    // Solicita ao usuário que insira o CPF a ser excluído
    printf("Digite o CPF a ser excluído: ");
    scanf("%s", cpf);

    // Tenta excluir o arquivo correspondente ao CPF
    if (remove(cpf) == 0) {
        // Se a exclusão for bem-sucedida, exibe uma mensagem de sucesso
        printf("Registro excluído com sucesso.\n");
    } else {
        // Se houver um erro na exclusão, exibe uma mensagem de erro
        printf("Não foi possível excluir o registro, pois não está cadastrado em nosso sistema\n");
    }
}

// Função principal
int main() {
    int opcao = 0;
    int x = 1;
    for (x = 1; x == 1;) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");
        printf(">>>> CARTÓRIO <<<< EBAC <<<< \n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1-Registrar nome \n");
        printf("\t2-Consultar nome \n");
        printf("\t3-Excluir nome \n");
        printf("\t4- Sair do sistema\n\n");
        printf("Opção: ");

        // Lê a opção do usuário
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registrar();
                // Exibe mensagem após a conclusão da operação
                printf("Você escolheu registrar um nome.\n");
                break;
            case 2:
                consultar();
                // Exibe mensagem após a conclusão da operação
                printf("Você escolheu consultar um nome.\n");
                system("pause");
                break;
            case 3:
                deletar();
                // Exibe mensagem após a conclusão da operação
                printf("Você escolheu excluir um nome.\n");
                system("pause");
                break;
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;	
            default:
                // Exibe uma mensagem de erro para opções inválidas
                printf("Essa opção não está disponível.\n");
                system("pause");
                break;
        }
    }
    return 0;
}

	
		

		
	 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

struct Livro {
	char nome[TAM_STRING];
	char autor[TAM_STRING];
	char editora[TAM_STRING];
	int edicao;
	int disponivel; // 1 para sim, 0 para não
};

struct Emprestimo {
	int indiceLivro;
	char nomeUsario[TAM_STRING];
};

void limparBufferEntrada() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	struct Livro* biblioteca;
	struct Emprestimo* emprestimos;

	biblioteca = (struct Livro*)calloc(MAX_LIVROS, sizeof(struct Livro));
	emprestimos = (struct Emprestimo*)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

	if (biblioteca == NULL || emprestimos == NULL) {
		printf("Erro: Falha ao alocar a memoria.\n");
		return 1;
	}

	int totalLivros = 0;
	int totalEmprestimo = 0;
	int opcao;

	do {
		printf("\nBiblioteca - Parte 2\n");
		printf("1 - Cadastrar novo livro\n");
		printf("2 - Listar todos os livros\n");
		printf("3 - Realizar emprestimo\n");
		printf("4 - Listar emprestimos\n");
		printf("0 - Sair\n");
		printf("------------------------------\n");
		scanf_s("%d", &opcao);
		limparBufferEntrada();

		switch (opcao) {
		case 1:
			printf("Cadastro de novo livro\n");
			if (totalLivros < MAX_LIVROS) {
				printf("Digite o nome do livro: ");
				fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

				printf("Digite o autor: ");
				fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

				printf("Digite a editora: ");
				fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

				biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
				biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
				biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

				printf("Digite a edicao: ");
				scanf_s("%d", &biblioteca[totalLivros].edicao);
				limparBufferEntrada();

				biblioteca[totalLivros].disponivel = 1; // <-- Importante

				totalLivros++;
				printf("\nLivro cadastrado com sucesso!\n");
			}
			else {
				printf("Biblioteca cheia! Nao e possivel cadastrar mais livros.\n");
			}
			printf("\nPressione Enter para continuar...");
			getchar();
			break;

		case 2:
			printf("Lista de livros cadastrados\n");
			if (totalLivros == 0) {
				printf("Nenhum livro cadastrado ainda.\n");
			}
			else {
				for (int i = 0; i < totalLivros; i++) {
					printf("LIVRO %d\n", i + 1);
					printf("Nome: %s\n", biblioteca[i].nome);
					printf("Autor: %s\n", biblioteca[i].autor);
					printf("Editora: %s\n", biblioteca[i].editora);
					printf("Edicao: %d\n", biblioteca[i].edicao);
					printf("Disponivel: %s\n", biblioteca[i].disponivel ? "Sim" : "Nao");
				}
			}
			printf("------------------------------------------\n");
			printf("\nPressione Enter para continuar...");
			getchar();
			break;

		case 3:
			printf("Realizar Emprestimo\n");

			if (totalEmprestimo >= MAX_EMPRESTIMOS) {
				printf("Limite de emprestimos atingido\n");
			}
			else {
				printf("Livros disponiveis:\n");
				int disponiveis = 0;
				for (int i = 0; i < totalLivros; i++) { // <-- Corrigido
					if (biblioteca[i].disponivel) {
						printf("%d - %s\n", i + 1, biblioteca[i].nome);
						disponiveis++;
					}
				}
				if (disponiveis == 0) {
					printf("Nenhum livro disponivel para emprestimo\n");
				}
				else {
					printf("\nDigite o numero do livro que deseja emprestar: ");
					int numLivro;
					scanf_s("%d", &numLivro);
					limparBufferEntrada();

					int indice = numLivro - 1;

					if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
						printf("Digite o nome do usuario que esta pegando o livro: ");
						fgets(emprestimos[totalEmprestimo].nomeUsario, TAM_STRING, stdin);
						emprestimos[totalEmprestimo].nomeUsario[strcspn(emprestimos[totalEmprestimo].nomeUsario, "\n")] = '\0';

						emprestimos[totalEmprestimo].indiceLivro = indice;
						biblioteca[indice].disponivel = 0;

						totalEmprestimo++;
						printf("\nEmprestimo realizado com sucesso!\n");
					}
					else {
						printf("\nNumero de livro invalido ou livro indisponivel.\n");
					}
				}
			}
			printf("\nPressione Enter para continuar...");
			getchar();
			break;

		case 4:
			printf("Lista de Emprestimos\n");
			if (totalEmprestimo == 0) {
				printf("Nenhum emprestimo realizado.\n");
			}
			else {
				for (int i = 0; i < totalEmprestimo; i++) {
					int indiceLivro = emprestimos[i].indiceLivro;
					printf("Emprestimo %d\n", i + 1);
					printf("Livro: %s\n", biblioteca[indiceLivro].nome);
					printf("Usuario: %s\n", emprestimos[i].nomeUsario);
				}
			}
			printf("\nPressione Enter para continuar...");
			getchar();
			break;

		case 0:
			printf("Saindo do sistema...\n");
			break;

		default:
			printf("Opcao invalida\n");
			printf("\nPressione Enter para continuar...");
			getchar();
			break;
		}
	} while (opcao != 0);

	free(biblioteca);
	free(emprestimos);

	printf("Memoria liberada!\n");

	return 0;
}

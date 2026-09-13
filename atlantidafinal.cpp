#include <stdio.h>

#define MAX_PROBLEMAS 50


// MOSTRAR NOME DO BAIRRO

void mostrarNomeBairro(int bairro) {

    switch(bairro) {

        case 1:
            printf("Centro");
            break;

        case 2:
            printf("Jardim Aurora");
            break;

        case 3:
            printf("Vila Esperanca");
            break;

        case 4:
            printf("Parque das Aguas");
            break;

        case 5:
            printf("Nova Harmonia");
            break;

        default:
            printf("Bairro desconhecido");
    }
}


// MOSTRAR NOME DA CATEGORIA

void mostrarNomeCategoria(int categoria) {

    switch(categoria) {

        case 1:
            printf("Infraestrutura");
            break;

        case 2:
            printf("Seguranca");
            break;

        case 3:
            printf("Limpeza Urbana");
            break;

        case 4:
            printf("Saneamento");
            break;

        case 5:
            printf("Transporte");
            break;

        default:
            printf("Categoria desconhecida");
    }
}


// FUNCAO 3 - BUSCAR PROBLEMAS POR BAIRRO

void buscarPorBairro(int bairros[], int categorias[], int prioridades[],
                     int pessoasAfetadas[], int quantidadeProblemas) {

    int bairroBusca;
    int encontrou = 0;
    int i;

    printf("       BUSCA DE PROBLEMAS POR BAIRRO\n");

    if (quantidadeProblemas == 0) {
        printf("\nNao existem problemas cadastrados.\n");
        return;
    }

    printf("\nBairros disponiveis:\n");
    printf("1 - Centro\n");
    printf("2 - Jardim Aurora\n");
    printf("3 - Vila Esperanca\n");
    printf("4 - Parque das Aguas\n");
    printf("5 - Nova Harmonia\n");

    printf("\nDigite o bairro que deseja buscar: ");
    scanf("%d", &bairroBusca);

    if (bairroBusca < 1 || bairroBusca > 5) {
        printf("\nBairro invalido.\n");
        return;
    }

    printf("\n RESULTADOS DA BUSCA \n");

    for (i = 0; i < quantidadeProblemas; i++) {

        if (bairros[i] == bairroBusca) {

            encontrou = 1;

            printf("\nProblema %d:\n", i + 1);

            printf("Bairro: ");
            mostrarNomeBairro(bairros[i]);
            printf("\n");

            printf("Categoria: ");
            mostrarNomeCategoria(categorias[i]);
            printf("\n");

            printf("Prioridade: %d\n", prioridades[i]);

            printf("Pessoas afetadas: %d\n",
                   pessoasAfetadas[i]);
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum problema encontrado nesse bairro.\n");
    }
}


// FUNCAO 4 - MOSTRAR PROBLEMA MAIS PRIORITARIO

void mostrarMaiorPrioridade(int bairros[], int categorias[],
                            int prioridades[], int pessoasAfetadas[],
                            int quantidadeProblemas) {

    int maiorPrioridade;
    int posicaoMaior;
    int i;

    if (quantidadeProblemas == 0) {
        printf("\nNao existem problemas cadastrados.\n");
        return;
    }

    maiorPrioridade = prioridades[0];
    posicaoMaior = 0;

    for (i = 1; i < quantidadeProblemas; i++) {

        if (prioridades[i] > maiorPrioridade) {

            maiorPrioridade = prioridades[i];
            posicaoMaior = i;
        }
    }

    printf("       PROBLEMA MAIS PRIORITARIO\n");

    printf("\nProblema %d\n", posicaoMaior + 1);

    printf("Bairro: ");
    mostrarNomeBairro(bairros[posicaoMaior]);
    printf("\n");

    printf("Categoria: ");
    mostrarNomeCategoria(categorias[posicaoMaior]);
    printf("\n");

    printf("Prioridade: %d\n",
           prioridades[posicaoMaior]);

    printf("Pessoas afetadas: %d\n",
           pessoasAfetadas[posicaoMaior]);
}


// FUNCAO 5 - MOSTRAR ESTATISTICAS DA CIDADE

void mostrarEstatisticas(int bairros[], int categorias[],
                         int prioridades[], int pessoasAfetadas[],
                         int quantidadeProblemas) {

    int somaPrioridades = 0;
    int totalPessoas = 0;
    int maiorPrioridade;
    int contadorCategorias[6] = {0};
    int maiorCategoria = 1;
    int i;

    float mediaPrioridades;

    if (quantidadeProblemas == 0) {
        printf("\nNao existem problemas cadastrados.\n");
        return;
    }

    maiorPrioridade = prioridades[0];

    for (i = 0; i < quantidadeProblemas; i++) {

        somaPrioridades += prioridades[i];

        totalPessoas += pessoasAfetadas[i];

        if (prioridades[i] > maiorPrioridade) {
            maiorPrioridade = prioridades[i];
        }

        if (categorias[i] >= 1 &&
            categorias[i] <= 5) {

            contadorCategorias[categorias[i]]++;
        }
    }

    mediaPrioridades =
        (float)somaPrioridades / quantidadeProblemas;

    for (i = 2; i <= 5; i++) {

        if (contadorCategorias[i] >
            contadorCategorias[maiorCategoria]) {

            maiorCategoria = i;
        }
    }

    printf("        ESTATISTICAS DA CIDADE\n");

    printf("\nQuantidade total de problemas: %d\n",
           quantidadeProblemas);

    printf("Media das prioridades: %.2f\n",
           mediaPrioridades);

    printf("Total de pessoas afetadas: %d\n",
           totalPessoas);

    printf("Maior prioridade: %d\n",
           maiorPrioridade);

    printf("Categoria com maior numero de ocorrencias: ");

    mostrarNomeCategoria(maiorCategoria);

    printf("\n");

    printf("\nQuantidade por categoria:\n");

    printf("Infraestrutura: %d\n",
           contadorCategorias[1]);

    printf("Seguranca: %d\n",
           contadorCategorias[2]);

    printf("Limpeza Urbana: %d\n",
           contadorCategorias[3]);

    printf("Saneamento: %d\n",
           contadorCategorias[4]);

    printf("Transporte: %d\n",
           contadorCategorias[5]);
}


// PROGRAMA PRINCIPAL

int main() {

    // Vetores para armazenar os dados dos problemas
    int bairros[MAX_PROBLEMAS];
    int categorias[MAX_PROBLEMAS];
    int prioridades[MAX_PROBLEMAS];
    int pessoasAfetadas[MAX_PROBLEMAS];

    // Variaveis de controle
    int quantidadeProblemas = 0;
    int opcao;
    int i;

    // Menu principal
    do {

        printf("   SISTEMA DE PLANEJAMENTO URBANO\n");
        printf("          CIDADE ATLANTIDA\n");

        printf("1 - Cadastrar problema\n");
        printf("2 - Consultar todos os problemas\n");
        printf("3 - Buscar problemas por bairro\n");
        printf("4 - Mostrar problema mais prioritario\n");
        printf("5 - Mostrar estatisticas da cidade\n");
        printf("0 - Encerrar programa\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // CASE 1 - CADASTRAR PROBLEMA

            case 1:

                if (quantidadeProblemas < MAX_PROBLEMAS) {

                    printf("\n CADASTRO DE PROBLEMA \n");


                    // ESCOLHA DO BAIRRO

                    printf("\nBairros disponiveis:\n");
                    printf("1 - Centro\n");
                    printf("2 - Jardim Aurora\n");
                    printf("3 - Vila Esperanca\n");
                    printf("4 - Parque das Aguas\n");
                    printf("5 - Nova Harmonia\n");

                    printf("\nDigite o bairro: ");

                    scanf("%d",
                           &bairros[quantidadeProblemas]);


                    // VALIDACAO DO BAIRRO

                    if (bairros[quantidadeProblemas] < 1 ||
                        bairros[quantidadeProblemas] > 5) {

                        printf("Bairro invalido\n");
                        printf("O problema nao foi cadastrado.\n");

                        break;
                    }


                    // ESCOLHA DA CATEGORIA

                    printf("\nCategorias disponiveis:\n");
                    printf("1 - Infraestrutura\n");
                    printf("2 - Seguranca\n");
                    printf("3 - Limpeza Urbana\n");
                    printf("4 - Saneamento\n");
                    printf("5 - Transporte\n");

                    printf("\nDigite a categoria: ");

                    scanf("%d",
                           &categorias[quantidadeProblemas]);


                    // VALIDACAO DA CATEGORIA

                    if (categorias[quantidadeProblemas] < 1 ||
                        categorias[quantidadeProblemas] > 5) {

                        printf("Categoria invalida!\n");
                        printf("O problema nao foi cadastrado.\n");

                        break;
                    }


                    // ESCOLHA DA PRIORIDADE

                    printf("Digite o nivel de prioridade (1 a 10): ");

                    scanf("%d",
                           &prioridades[quantidadeProblemas]);


                    // VALIDACAO DA PRIORIDADE

                    if (prioridades[quantidadeProblemas] < 1 ||
                        prioridades[quantidadeProblemas] > 10) {

                        printf("Prioridade invalida!\n");
                        printf("O problema nao foi cadastrado.\n");

                        break;
                    }


                    // QUANTIDADE DE PESSOAS AFETADAS

                    printf("Digite a quantidade de pessoas afetadas: ");

                    scanf("%d",
                           &pessoasAfetadas[quantidadeProblemas]);


                    // VALIDACAO DA QUANTIDADE

                    if (pessoasAfetadas[quantidadeProblemas] < 0) {

                        printf("Quantidade invalida!\n");
                        printf("O problema nao foi cadastrado.\n");

                        break;
                    }


                    // AUMENTA A QUANTIDADE DE PROBLEMAS

                    quantidadeProblemas++;

                    printf("\nProblema cadastrado com sucesso!\n");

                } else {

                    printf("\nLimite maximo de problemas atingido!\n");

                }

                break;


            // CASE 2 - CONSULTAR TODOS OS PROBLEMAS

            case 2:

                printf("       TODOS OS PROBLEMAS CADASTRADOS\n");

                if (quantidadeProblemas == 0) {

                    printf("\nNenhum problema foi cadastrado ainda.\n");

                } else {

                    for (i = 0;
                         i < quantidadeProblemas;
                         i++) {

                        printf("\n--- Problema %d ---\n",
                               i + 1);

                        printf("Bairro: ");
                        mostrarNomeBairro(bairros[i]);
                        printf("\n");

                        printf("Categoria: ");
                        mostrarNomeCategoria(categorias[i]);
                        printf("\n");

                        printf("Prioridade: %d\n",
                               prioridades[i]);

                        printf("Pessoas afetadas: %d\n",
                               pessoasAfetadas[i]);
                    }
                }

                break;


            // CASE 3 - BUSCAR POR BAIRRO

            case 3:

                buscarPorBairro(
                    bairros,
                    categorias,
                    prioridades,
                    pessoasAfetadas,
                    quantidadeProblemas
                );

                break;


            // CASE 4 - MAIOR PRIORIDADE

            case 4:

                mostrarMaiorPrioridade(
                    bairros,
                    categorias,
                    prioridades,
                    pessoasAfetadas,
                    quantidadeProblemas
                );

                break;


            // CASE 5 - ESTATISTICAS
        
            case 5:

                mostrarEstatisticas(
                    bairros,
                    categorias,
                    prioridades,
                    pessoasAfetadas,
                    quantidadeProblemas
                );

                break;


            // CASE 0 - ENCERRAR

            case 0:

                printf("\nEncerrando o Sistema de Planejamento ");
                printf("Urbano de Atlantida...\n");

                break;


            // OPCAO INVALIDA

            default:

                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);


    return 0;
}

# TAG


## [Projeto 1](Projeto%201)

Universidade de Brasília
Departamento de Ciência da Computação
Teoria e Aplicação de Grafos, Turma A, 1/2018
Prof. Díbio

Em 1977, no artigo “W. W. Zachary, An information flow model for conflict and fission in small
groups, Journal of Anthropological Research 33, 452-473 (1977).” uma rede social de amizades entre
34 integrantes de um grupo de karatê foi descrita e apresentada como um grafo para estudos. Os dados
estão em http://www-personal.umich.edu/~mejn/netdata/karate.zip em formato GML, e em http://wwwpersonal.umich.edu/~mejn/netdata/readgml.zip
há um “parser” em C para os dados. O projeto consiste
em escrever um programa em C/C++ que lê o arquivo (karate.zip), monta com esses dados um grafo
não direcionado, sem pesos, usando listas de adjacências, e imprime como saída (tela) em ordem
decrescente, os integrantes (vértices) com maiores graus no grafo, até o de menor. Essa impressão deve
ser somente pelos integrantes, e consequentes graus desses vértices. Uma visualização em gráfico,
mostrando o grafo montado é um ponto adicional (i.e. 11, caso alguém queira fazer). Além disso, o
programa deve encontrar e imprimir um (1) clique maximal (com no mínimo 5 alunos), e um (1) clique
máximo desse grafo, ambos diferentes, (pelos nomes de todos).

O código deve ser bem documentado, de forma modular com funções para cada tarefa independente,
realizado por dois (2) estudantes do curso usando “pair programming”, e entregue via sistema
http://aprender.unb.br do curso, no prazo estipulado.
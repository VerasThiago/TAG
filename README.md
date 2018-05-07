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



## [Projeto 2](Projeto%202)

Universidade de Brasília 
Departamento de Ciência da Computação 
Projeto 2
Teoria e Aplicação de Grafos, Turma A, 1/2018
Prof. Díbio

São fornecidos 4 arquivos (top_datasets.zip), contendo 4 grafos com números de vértices de 10, 100,
10.000,   100.000,   listando   como   pares   de   números   inteiros   por   linha   o   vértice,   e   seu   respectivo
adjacente.  Essas adjacências são todas consideradas direcionadas (i.e. são dígrafos).  Implemente dois
(2)   diferentes   algoritmos   de   ordenação   topológica   (ps.   Indique   explicitamente   com   citação   de   fonte
quais   algoritmos   e   separe-os   em   funções   diferentes),   execute-os   nos   4   dígrafos,   imprima   na   tela   as
maiores ordenações atingidas em cada grafo, e gráficos de execução temporal (x(tempo):y(nós)) para os
2 algoritmos. Indique em quais circunstâncias (i.e. dos 4 tamanhos) a escolha de algoritmo a ser feita,
imprimindo na tela essas opções justificadas pelos gráficos.


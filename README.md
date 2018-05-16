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

## [Projeto 3](Projeto%203)

Universidade de Brasília 
Departamento de Ciência da Computação 
Projeto 2
Teoria e Aplicação de Grafos, Turma A, 1/2018
Prof. Díbio

Considere   para   efeito   deste   projeto   que   uma   determinada   unidade   da   federação   fez   um   concurso   e foram aprovados cem (100) novos professores para escolas públicas. Cada professor aprovado possui uma (1), duas (2), ou até (3) habilitações de conteúdos em que pode atuar. Cinquenta (50) escolas se habilitaram   a   receber   novos   professores,   sendo que   algumas   poderão   receber   no   máximo   um   (1) professor,   e   outras   no   máximo   dois   (2)   professores.   As   escolas   podem   indicar   preferências   de professores  indicando se 3, 2 ou 1 habilitação os candidatos devem ter. Por sua vez, cada professor pode escolher   uma   ordem   de   cinco   (5)   escolas   onde   gostaria   de   atuar.   Neste    rojeto   você(s)   deve(m) implementar   um   algoritmo   que   realize   um   emparelhamento   máximo   entre   os   dois   conjuntos,   com preferências, e forneça uma solução estável. O  lgoritmo pode ser ótimo para os professores, ou ótimo do ponto de vista das escolas. As soluções dadas em (Abraham, Irving & Manlove, 2007) são úteis e qualquer uma pode ser implementada com  ariações pertinentes. Um arquivo entradaProj3TAG.txt com as indicações de código do professor, habilitações e preferências de escolas, bem como das escolas com suas  preferências  em termos   e  habilitações  dos  professores  é fornecido como  entrada.  Uma  versão pública do artigo de  (Abraham, Irving & Manlove, 2007) é fornecida para leitura.

Abraham,   D.J.   and   Irving,    .W.   and   Manlove,   D.F.   (2007).   Two   algorithms   for   the   student-project allocation problem.  Journal of Discrete Algorithms  5(1):pp. 73-90.

O código deve ser bem documentado,  e forma modular com funções para cada tarefa independente, realizado   por   dois   (2)   estudantes   do   curso   usando   “pair programming”,  e entregue via sistema http://prender.unb.br do curso, no prazo estipulado. 
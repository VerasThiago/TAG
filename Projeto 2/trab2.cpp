#include <bits/stdc++.h>
#include "gnu_plot.hpp"

using namespace std;


// Print menu on terminal
void intro(){ 

		printf("\n");
		printf("#############################################\n");
		printf("#                                           #\n");
		printf("#              TOPOLOGICAL SORT             #\n");
		printf("#                                           #\n");
		printf("#############################################\n");
		printf("#                                           #\n");
		printf("#        Aluno: Thiago Veras Machado        #\n");
		printf("#              M: 16/0146682                #\n");
		printf("#                                           #\n");
		printf("#############################################\n");
		printf("#                                           #\n");
		printf("#    Apenas o arquivo huge consegue         #\n");
		printf("#    demorar mais que 0 segundos.           #\n");
		printf("#                                           #\n");
		printf("#    OBS: Apagar a função que imprime os    #\n");
		printf("#    vertices para conseguir vizualizar o   #\n");
		printf("#    o tempo demorado do arquivo huge.      #\n");
		printf("#                                           #\n");
		printf("#############################################\n");

		printf("\n");
}

// Função que cria o grafo e armazena as ligações
vector<vector<int>> create(int *n, string nome){

	// Variáveis para pegar o nome, acessar e ler os dados do arquivo
	ifstream arquivo;
	int x,y;

	
	// Abrindo o arquivo
	arquivo.open(nome);

	// Se não conseguir abrir o arquivo, imprimir a mensagem de falha e encerrar o programa
	if(!arquivo) cout << "Falha ao abrir o arquivo " << nome << endl, exit (EXIT_FAILURE);

	// Ler o primeiro número do arquivo que é a quantidade de vertice
	arquivo >> *n;

	// Criando o vetor de tamanho n
	vector<vector<int>> grafo(*n);

	// Lendo os pontos do arquivo e armazenando no grafo
	while(arquivo >> x >> y)
		grafo[x].push_back(y);

	// Retornando o grafo criado
	return grafo;
}

// Função recursiva usada pela ordenação topológica 1
void ordenacao_Recursiva(vector<vector<int>> &grafo, int v, int *visited, stack<int> &pilha){

	// Marca o nó como visitado
    visited[v] = true;

    // Percorre todos os seus filhos e caso não foram visitados, chamar recursivamente a função
    for(auto u : grafo[v])
    	if(!visited[u])
    		ordenacao_Recursiva(grafo, u, visited, pilha);

  	// Empliha o vértice na pilha que armazena o rsultado
    pilha.push(v);
}


// Ordenação topológica 1 que chama uma função recursiva
// Complexidade : Apenas uma DFS com uma pilha. Logo sua complexidade é a mesma de uma DFS = O(V+E).
// Fonte : https://www.geeksforgeeks.org/topological-sorting/
vector<int> ordenacao_Topologica1(vector<vector<int>>&grafo, int n){

    // Pilha que armazena o resultado
    stack<int> pilha;

    // Vetor de visitados
    int visited[n];

    // Marcando todos como não visitados
    memset(visited,0,sizeof(visited));

    // Percorre todos os vértices e caso não tenha sido visitado, ordenar usando a função recursiva
    for (int i = 0; i < n; i++)
      if (!visited[i])
        ordenacao_Recursiva(grafo, i, visited, pilha);

    // Montando a resposta no vetor com o grafo ordenado topologicamente
    vector<int> resposta;
    while(!pilha.empty())
        resposta.push_back(pilha.top()),pilha.pop();
    
    return resposta;
}

// Ordenação topológica 2 que utiliza uma fila (Kahn’s algorithm)
// Complexidade : O(V+E)
// Fonte: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
vector<int> ordenacao_Topologica2(vector<vector<int>>&grafo, int n){

	// Variaveis para armazenar os nós, gerar a resposta e criar o vetor de incidencia
    queue<int> fila;
    vector<int> resposta;
    vector<int> incidencia(n,0);

    // Gerando a lista de incidencia
    for(int i = 0; i < n; i++)
    	for(auto v: grafo[i])
    		incidencia[v]++;
    
    // Percorrendo os nós que não tem niguém ligado a nele 
    for(int i = 0; i < n; i++)
        if(!incidencia[i])
            fila.push(i);
    
    // Loop Principal
    while(!fila.empty()){

        int u = fila.front(); fila.pop();
        
        // Colocando no vetor de resposta
        resposta.push_back(u);

        // Caminha pelos filhos de u
        for(auto v : grafo[u]){

        	// Diminui a incidencia em 1
        	incidencia[v]--;

        	// Se nao possuir ninguém 
            if(!incidencia[v])
                fila.push(v);
        }
    }

    return resposta;
}

// Função para imprmir o vetor com os nós ordenados
void print_vector(vector<int> &ordenado, int tipo){

	// Imprime mensagem para identificar qual foi o algoritmo usado
	printf("Ordenação topológica %d:",tipo);

	// Imprime os nós ordenados
	for(auto x: ordenado)
		printf(" %d", x);

	// Quebra de linha
	printf("\n\n");
}


double solve(vector<vector<int>> &grafo, int tipo, int n){
	
	// Varável para calcular tempo de duração de cada algoritmo
	clock_t t;
	

	// Vetor que recebe os vertices ordenados
	vector<int> ordenacao_Topologica;
	
	// Recebendo o clock antes de executar o algoritmo
	t = clock();
	
	// Se for o tipo 0, entao ordenação 1, ordenação 2 caso contrário
	if(!tipo)
		ordenacao_Topologica = ordenacao_Topologica1(grafo,n); 
	else
		ordenacao_Topologica = ordenacao_Topologica2(grafo,n); 

	// Recebe o clock depois da execução do algoritmo e tira a diferença
	t = clock() - t;

	// Imprime os nós ordenados topologicamente
	print_vector(ordenacao_Topologica,tipo);

	// Retorna o tempo do algoritmo
	return (double)t/CLOCKS_PER_SEC;
}

// Imprime na tela o tempo de execução do algoritmo
void show_time(vector<double> Kahn, vector<double> DFS, vector<double> sizes){
	for(int i = 0; i < Kahn.size(); i++)
		cout << "Time Kahn’s algorithm in graph size " << sizes[i]  << " = " << Kahn[i] << "segundos" << endl;
		
	for(int i = 0; i < DFS.size(); i++)
		cout << "Time DFS sort algorithm in graph size " << sizes[i]  << " = " << DFS[i] << "segundos" << endl;
}

//Cria o gráfico
void gnuPlot(vector<double> Kahn, vector<double> Dfs, vector<double> sizes){
    try{
    	// Gerando tabela
        Gnuplot g1("lines");
        g1.set_xlabel("Quantidade de vertices");
        g1.set_ylabel("Tempo em segundos");
        g1.set_grid();

        //Gerando as linhas no gráfico
        g1.set_style("lines").plot_xy(sizes, Dfs, "Algoritmo com DFS");
        g1.set_style("lines").plot_xy(sizes,Kahn,"Algoritmo de Kahn");

        // Output na tela
        g1.showonscreen();

        // Aguarda o usuário digitar qualquer tecla
        printf("\tAPERTE QUALQUER TECLA PARA CONTINUAR.\n");
        getchar();
    }
    catch (GnuplotException &ge){
        cout << ge.what() << endl;
    }
}

int main(){

	// Vetor que possui o nome dos arquivos
	vector<string> arquivo = {"top_small.txt", "top_med.txt", "top_large.txt", "top_huge.txt"};

	// Vetores que possuem o  tempo dos algoritmos e tamanho dos grafos
	vector<double> Kahn,DFS,sizes;

	// Monstra menu inicial
	intro();

	// Variável para pegar o tamanho do grafo
	int n;

	for(auto x : arquivo){
		// Grafo criado de tamanho estabelecido pelo arquivo e com as ligações feitas
		vector<vector<int>> grafo = create(&n, x);
	
		// Resolve o problema para o tipo 0
		Kahn.push_back(solve(grafo,0,n));

		// Resolve o problema para o tipo 1
		DFS.push_back(solve(grafo,1,n));

		// Insere o tamanho do grafo
		sizes.push_back(n);
	}
	
	// Mostra o tempo de cada algoritmo com cada arquivo;
	show_time(Kahn, DFS, sizes);
	
	//Gera o gráfico
	gnuPlot(Kahn, DFS, sizes);

	// Fim do programa
	return 0;
}

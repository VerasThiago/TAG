#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> create(int *n){
	// Variáveis para pegar o nome, acessar e ler os dados do arquivo
	string nome;
	ifstream arquivo;
	int x,y;

	// Interação com o usiário
	printf("Digite o nome do arquivo: ");
	
	// Lendo o nome do arquivo
	cin >> nome;

	// Abrindo o arquivo
	arquivo.open(nome);

	// Se não conseguir abrir o arquivo, imprimir a mensagem de falha e encerrar o programa
	if(!arquivo) cout << "Falha ao abrir o arquivo " << nome << endl, exit (EXIT_FAILURE);

	// Ler o primeiro número do arquivo que é a quantidade de vertice
	arquivo >> *n;

	// Criando o vetor de tamanho n
	vector<vector<int>> grafo(*n);

	// Lendo os pontos do arquivo e armazenando no grafo
	while(arquivo >> x >> y)grafo[x].push_back(y);

	// Retornando o grafo criado
	return grafo;
}

// Função recursiva usada pela ordenação topológica 1
void topologicalSortUtil(vector<vector<int>> &grafo, int v, int *visited, stack<int> &pilha){
	// Marca o nó como visitado
    visited[v] = true;

    // Percorre todos os seus filhos e caso não foram visitados, chamar recursivamente a função
    for(auto u : grafo[v])
    	if(!visited[u])
    		topologicalSortUtil(grafo, u, visited, pilha);

  	// Empliha o vértice na pilha que armazena o rsultado
    pilha.push(v);
}


// Ordenação topológica 1 que chama uma função recursiva
void topologicalSort1(vector<vector<int>>&grafo, int n){
    // Pilha que armazena o resultado
    stack<int> pilha;

    // Vetor de visitados
    int visited[n];

    // Marcando todos como não visitados
    memset(visited,0,sizeof(visited));

    // Percorre todos os vértices e caso não tenha sido visitado, ordenar usando a função recursiva
    for (int i = 0; i < n; i++)
      if (!visited[i])
        topologicalSortUtil(grafo, i, visited, pilha);

    // Imprimindo o grafo ordenado topologicamente
    while(!pilha.empty()){
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}

void topologicalSort2(vector<vector<int>>&grafo, int n){
	// Variaveis para armazenar os nós, gerar a resposta e criar o vetor de incidencia
    queue<int> fila;
    vector<int> resp;
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
        resp.push_back(u);

        // Caminha pelos filhos de u
        for(auto v : grafo[u]){

        	// Diminui a incidencia em 1
        	incidencia[v]--;

        	// Se nao possuir ninguém 
            if(!incidencia[v])
                fila.push(v);
        }
    }

    // Imprimindo a resposta  
    for(auto x: resp) cout << x << " ";printf("\n");
}

int main(){
	// Variável para pegar o tamanho do grafo
	int n;

	// Grafo criado de tamanho n já com as ligações feitas
	vector<vector<int>> grafo = create(&n);

	// Ordenação topológica 1
	topologicalSort1(grafo,n);
	topologicalSort2(grafo,n);




}
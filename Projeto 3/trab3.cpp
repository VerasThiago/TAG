#include <bits/stdc++.h>
#include "parser.h"

using namespace std;


// Faz a ligação do professor com a escola diretamente
void assign_Free(Professor* p, Escola* e){

	// Vincula a escola ao match do professor
	p->match = e;

	// Muda sua disponibilidade para falso pois agora ele está vinculado a uma escola
	p->matched = false;

	// Vicula o professor a escola
	e->match.push_back(p);
}


// Faz a substituição de um professor da escola pelo professor atual
Professor* assign_Full(Professor* p, Escola* e){

	// Retorna o professor substituido
	Professor *retorno;

	// Anda pelos professores vinculados na escola
	for(int i = 0; i < e->match.size(); i++){

		// Se a quantidade de habilidades do professor for diferente da preferencia da escola, então ele deve ser removido
		if(e->match[i]->hab != e->pref){

			// Remove o vinculo do professor com a escola pois ele será substituido 
			e->match[i]->match = NULL;

			// Muda para verdadeiro sua disponibilidade pois agora está sem escola
			e->match[i]->matched = true;

			// Atribui ao retorno o professor removido da escola pois deverá voltar para fila
			retorno = e->match[i];

			// Remove da lista de professores associados a escola
			e->match.erase(e->match.begin() + i);

			// Encerra a busca
			break;
		}
	}

	// Como a escola liberou um professor, agora podemos chamar a função que vincula um professor a uma escola com vaga
	assign_Free(p,e);

	// Retorna o professor removido
	return retorno;
}

// Verifica se um dos professores da escola pode ser removido para a substituição
bool change(int hab, Escola* e){

	// Se o professor que deseja aplicar a escola possui a quantidade de habilidade diferente da pretendida pela escola, então a escola recusa ele
	if(hab != e->pref)
		return false;

	// Anda pelos professores vinculados a escola
	for(auto p: e->match){
		
		// Se a quantidade de habilidade do professor da escola for diferente da pretentida, então ele pode ser removido
		if(p->hab != e->pref)
			return true;
	}

	// Retorna falso caso todos atendem as preferencias da escola
	return false;
}

void emparelhamento_estavel_para_professor	(){
	
	// Fila de professores livres
	queue<Professor*> q;

	// Caminha pelos professores
	for(auto x : prof){

		// Se o professor está livre, então ele entra na fila
		if(x->free())
			q.push(x);
	}

	// Enquanto a fila não está vazia
	while(!q.empty()){

		// Pega o professor da fila
		Professor * profe = q.front(); q.pop();

		// Anda pelas escolas de sua preferência, do maior para o menor
		for(auto y : profe->pref){

			// Pega a escola na ordem
			Escola * escol = esc[y-1];

			// Se a escola está livre, então vincula o professor
			if(escol->free()){

				// Vincula o professor a uma escola com vaga
				assign_Free(profe,escol);

				// Encerra o processo de aplicação
				break;
			}

			// Se a escola está cheia, porém é possivel substituir um professor
			else if (!escol->free() and change(profe->hab, escol)){

				// Executa a substituição e já insere o professor removido de volta na fila
				q.push(assign_Full(profe,escol));

				// Encerra o processo de aplicação
				break;
			}
		}
	}
}

void show_schools(){
	
	// Caminha pelas escolas
	for(auto x : esc){

		// Imprime o código da escola
		printf("A escola %d ficou com os professores : ",x->code);
		
		// Caminha pelos professores viculados na escola
		for(auto y : x->match)
			// Imprime o código de cada professor
			printf("%d ", y->code);

		// Quebra de linha
		puts("");
	}

}


int main(){

	read("entradaProj3TAG.txt");

	emparelhamento_estavel_para_professor();

	show_schools();

	return 0;
}
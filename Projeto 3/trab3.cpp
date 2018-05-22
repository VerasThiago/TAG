#include<bits/stdc++.h>
#include"parser.h"

using namespace std;



void assign_Free(Professor* p, Escola* e){
	p->match = e;
	p->matched = false;
	e->match.push_back(p);
}

Professor* assign_Full(Professor* p, Escola* e){
	Professor *retorno;
	for(int i = 0; i < e->match.size(); i++){
		if(e->match[i]->hab != e->pref){
			e->match[i]->match = NULL;
			e->match[i]->matched = true;
			retorno = e->match[i];
			e->match.erase(e->match.begin() + i);
			break;
		}
	}
	assign_Free(p,e);
	return retorno;
}

bool change(int hab, Escola* e){
	if(hab != e->pref)
		return false;

	for(auto p: e->match)
		if(p->hab != e->pref)
			return true;
		

	return false;
}
bool ok(){
	for(auto x: esc){
		if(x->free())
			return true;
	}
	return false;
}

void emparelhamento_estavel_para_professor	(){
	
	queue<Professor*> q;
	for(auto x : prof)
		if(x->free())
			q.push(x);

	
	while(!q.empty() and ok()){
		Professor * profe = q.front(); q.pop();
		for(auto y : profe->pref){
			Escola * escol = esc[y-1];
			if(escol->free()){
				assign_Free(profe,escol);
				break;
			}
			else if (!escol->free() and change(profe->hab, escol)){
				q.push(assign_Full(profe,escol));
				break;
			}
		}
	}

	for(auto x : esc){
		printf("A escola %d ficou com os professores : ",x->code);
		for(auto y : x->match) printf("%d ", y->code);
		puts("");
	}


}


int main(){
	read("entradaProj3TAG.txt");
	emparelhamento_estavel_para_professor();
}
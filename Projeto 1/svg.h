// Simple library to print graph structures as html file
// Por Giovanni M Guidini e Vitor F Dullens
// Modificada por Thiago Veras Machado onde especificado

#define GREEN   "\x1b[32m"
#include <bits/stdc++.h>
using namespace std;

#define HEADER "<!DOCTYPE html>\n<html><head>\n<style>\ndiv.container {\n   height=\"1000\";\n   width=\"1000\";\n    border: 1px solid gray;\n}\n\nheader, footer {\n    padding: 1em;\n    color: white;\n    background-color: black;\n    clear: left;\n    text-align: center;\n}\n\nnav {\n    float: left;\n    max-width: 160px;\n    margin: 0;\n    padding: 1em;\n}\n\nnav ul {\n    list-style-type: none;\n    padding: 0;\n}\n   \nnav ul a {\n    text-decoration: none;\n}\n\narticle {\n    margin-left: 170px;\n    border-left: 1px solid gray;\n    padding: 1em;\n    overflow: hidden;\n}\n</style>\n</head>\n<body>\n"
#define FOOTER "</svg>\n</body>\n</html>\n"

string addCircle(int cx, int cy){
    return "<circle cx=\"" + to_string(cx) + "\" cy=\"" + to_string(cy) + "\" r=\"30\" stroke=\"white\" stroke-width=\"3\" fill=\"lightblue\" />\n";
}

string addLine(int x1, int y1, int x2, int y2){
    return "<line x1=\"" + to_string(x1) + "\" y1=\"" + to_string(y1) + "\" x2=\"" + to_string(x2) +
           "\" y2=\"" + to_string(y2) + "\" style=\"stroke:rgb(2,0,0);stroke-width:2\" />\n";
}

string addText(int x, int y, string text){
    return "<text x=\"" + to_string(x) + "\" y=\"" + to_string(y) + "\" fill=\"black\">" + text +"</text>\n";
}

void printGraph(vector<int>* G, string file = "out.html"){
    srand(34);
    // open file, add header
    ofstream out (file);
    out << HEADER;
    out << "<div class=\"container\">\n<header>\n<h1>Grafo Criado por Thiago Veras</h1>\n</header>\n<article>\n<h1>Total de vértices : " + to_string(nodes.size()) + "</h1>\n<h1>Total de ligações : " + to_string(connections) + "</h1>\n</div>\n<svg height=\"1000\" width=\"1000\">\n";
    int l = node.size();

    // scatter nodes through canvas
    int x[l], y[l];

    for(int i = 0; i < l
        ; i++){
        x[i] = rand() % 960 + 20;
        y[i] = rand() % 960 + 20;
    }

    // add edges to image
    for(int i = 1; i <= l; i++){
        for(auto e : G[i]){
            out << addLine(x[i-1], y[i-1], x[e-1], y[e-1]);
        }
    }

    // add nodes and names
    for(int i = 1; i <= l; i++){
        out << addCircle(x[i-1], y[i-1]) << addText(x[i-1]-5, y[i-1]+5, node[i]);
    }

    out << FOOTER;
    out.close();

    printf("----------------------------------------------\n");
    cout << endl << GREEN << "Graph image generated as file " + file << endl;
}
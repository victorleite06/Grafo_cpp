#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <typeinfo>
#include <map>
#include <set>
#include <vector>
#include <list>

using namespace std;

class Vertice {

    private:
        int id;
        int peso;
        string label;
        
        bool visitado;
        int lowlink = -1;
        int index = -1;

    public:
        Vertice() {this->id = rand();}

        Vertice(int peso, string label) {
            this->id = rand();
            this->peso = peso;
            this->label = label;
        }

        ~Vertice() {}

        int getId() {
            return this->id;
        }

        void setPeso(int peso) {
            this->peso = peso;
        }

        int getPeso() {
            return this->peso;
        }

        void setLabel(string label) {
            this->label = label;
        }

        string getLabel() {
            return this->label;
        }

        void setVisitado(bool visitado) {
            this->visitado = visitado;
        }

        bool getVisitado() {
            return this->visitado;
        }

        void setLowlink(int lowlink) {
            this->lowlink = lowlink;
        }

        int getLowlink() {
            return this->lowlink;
        }

        void setIndex(int index) {
            this->index = index;
        }

        int getIndex() {
            return this->index;
        }
};

class Aresta {

    private:
        int peso;
        string label;
        Vertice origem;
        Vertice destino;

    public:
        Aresta() {}

        Aresta(Vertice origem, Vertice destino) {
            this->origem = origem;
            this->destino = destino;
        }
        
        Aresta(int peso, string label, Vertice origem, Vertice destino) {
            this->peso = peso;
            this->label = label;
            this->origem = origem;
            this->destino = destino;
        }

        ~Aresta() {}

        void setPeso(int peso) {
            this->peso = peso;
        }

        int getPeso() {
            return this->peso;
        }

        void setLabel(string label) {
            this->label = label;
        }

        string getLabel() {
            return this->label;
        }

        void setOrigem(Vertice origem) {
            this->origem = origem;
        }

        Vertice getOrigem() {
            return this->origem;
        }

        void setDestino(Vertice destino) {
            this->destino = destino;
        }

        Vertice getDestino() {
            return this->destino;
        }
};

class Grafo {

    private:
        array<Vertice, 100> vertices;
        array<Aresta, 100> arestas;
        bool direcionado;

    public:
        Grafo(/* args */) {}

        ~Grafo() {}

        array<Vertice, 100> getVertices() {
            return this->vertices;
        }

        void setVertices(array<Vertice, 100> vertices) {
            this->vertices = vertices;
        }

        array<Aresta, 100> getarestas() {
            return this->arestas;
        }

        void setarestas(array<Aresta, 100> arestas) {
            this->arestas = arestas;
        }

        bool getDirecionado() {
            return this->direcionado;
        }

        void setDirecionado(bool direcionado) {
            this->direcionado = direcionado;
        }
};

int index = 0;
array<Vertice, 100> pilha = {};
array<array<Vertice, 100>, 100> SCC = {};
Grafo grafo;

array<Aresta, 100> getAdjascentes(Vertice v) {
    array<Aresta, 100> adjascentes = {};

    for(Aresta ar : grafo.getarestas()) {
        if(ar.getDestino().getId() == v.getId() || ar.getOrigem().getId() == v.getId()) {
            adjascentes[adjascentes.size()] = ar;
        }
    }

    return adjascentes;
}

bool contemNaPilha(Vertice n) {
    bool contem = false;
    for(Vertice ve : pilha) {
        if(ve.getId() == n.getId()) {
            contem = true;
        }
    }
    return contem;
}

Vertice removeLista(array<Vertice, 100> lista, int pos) {
    Vertice ver = lista[pos];

    for(int i = pos; i < lista.size() - 1; i++) {
        lista[pos] = lista[pos + 1];
    }

    return ver;
}

array<array<Vertice, 100>, 100> tarjan(Vertice v) {
        v.setIndex(index);
        v.setLowlink(index);
        index++;
        pilha[0] = v;
        for (Aresta e : getAdjascentes(v)) {
            Vertice n = e.getDestino();
            if (n.getIndex() == -1) {
                tarjan(n);
                v.setLowlink(min(v.getLowlink(), n.getLowlink()));
            } else if (contemNaPilha(n)) {
                v.setLowlink(min(v.getLowlink(), n.getIndex()));
            }
        }
        if (v.getLowlink() == v.getIndex()) {
            Vertice n;
            array<Vertice, 100> component = {};
            do {
                n = removeLista(pilha, 0);
                component[component.size()] = n;
            } while (n.getId() != v.getId());
            SCC[SCC.size()] = component;
        }


    return SCC;
}

array<array<Vertice, 100>, 100> tarjanInit() {
    index = 0;
    pilha = {};
    SCC = {};
    return tarjan(pilha[0]);
}

void criarGrafo() {

}

int main() {
    criarGrafo();

    tarjanInit();
    return 0;
}
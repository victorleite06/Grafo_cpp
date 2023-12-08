#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

class Vertice {

    private:
        int peso;
        string label;
        
        bool visitado;
        int lowlink = -1;
        int index = -1;

    public:
        Vertice() {}

        Vertice(int peso, string label) {
            this->peso = peso;
            this->label = label;
        }

        ~Vertice() {}

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

        array<Aresta, 100> getArestas() {
            return this->arestas;
        }

        void setArestas(array<Aresta, 100> arestas) {
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


int main() {
    
}

array<array<Vertice, 100>, 100> tarjanInit() {
    index = 0;
    pilha = {};
    SCC = {};
    return tarjan();
}

array<array<Vertice, 100>, 100> tarjan() {

    return SCC;
}
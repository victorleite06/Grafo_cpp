#include "vertice.h"
#include "aresta.h"
#include <string>
#include <array>

using namespace std;

class Grafo {

    private:
        array<Vertice, 100> vertices;
        array<Aresta, 100> arestas;
        bool direcionado;

    public:
        Grafo(/* args */);

        ~Grafo();

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
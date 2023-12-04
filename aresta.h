#include "vertice.h"
#include <string>

using namespace std;

class Aresta {

    private:
        int peso;
        string label;
        Vertice origem;
        Vertice destino;

    public:
        Aresta();
        
        Aresta(int peso, string label, Vertice origem, Vertice destino) {
            this->peso = peso;
            this->label = label;
            this->origem = origem;
            this->destino = destino;
        }

        ~Aresta();

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
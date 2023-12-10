#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <climits>
#include <vector>

class GrafoDirecionado {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>> adjacencia;

public:
    GrafoDirecionado() {}

    void adicionarVertice(int vertice) {
        adjacencia[vertice] = std::list<std::pair<int, int>>();
    }

    void adicionarAresta(int origem, int destino, int peso) {
        adjacencia[origem].push_back(std::make_pair(destino, peso));
    }

    void encontrarAGM(int r) {
        std::vector<int> pai(adjacencia.size(), -1);
        std::vector<int> chave(adjacencia.size(), INT_MAX);

        for (auto &arestas : adjacencia) {
            int u = arestas.first;
            for (auto &aresta : arestas.second) {
                int v = aresta.first;
                int peso = aresta.second;

                if (peso < chave[v]) {
                    pai[v] = u;
                    chave[v] = peso;
                }
            }
        }

        std::cout << "Arestas na Árvore de Enraizamento Mínima (AGM) enraizada em " << r << ":" << std::endl;
        for (int i = 0; i < adjacencia.size(); ++i) {
            if (i != r) {
                std::cout << pai[i] << " - " << i << std::endl;
            }
        }
    }

    void mostrarGrafo() {
        std::cout << "Grafo Direcionado com Pesos:" << std::endl;
        for (auto &par : adjacencia) {
            std::cout << "Vertice " << par.first << " está conectado a: ";
            for (auto &aresta : par.second) {
                std::cout << "(" << aresta.first << ", Peso: " << aresta.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    GrafoDirecionado grafo;

    // Adicionando vértices
    grafo.adicionarVertice(0);
    grafo.adicionarVertice(1);
    grafo.adicionarVertice(2);
    grafo.adicionarVertice(3);

    // Adicionando arestas com peso
    grafo.adicionarAresta(0, 1, 5);
    grafo.adicionarAresta(0, 2, 3);
    grafo.adicionarAresta(1, 2, 2);
    grafo.adicionarAresta(2, 0, 8);
    grafo.adicionarAresta(2, 3, 7);
    grafo.adicionarAresta(3, 3, 1);

    // Exibir o grafo original
    grafo.mostrarGrafo();

    // Encontrar a Árvore de Enraizamento Mínima (AGM) enraizada em um vértice específico 'r' usando o Algoritmo de Edmonds
    int verticeRaiz = 0; // Define o vértice raiz desejado
    grafo.encontrarAGM(verticeRaiz);

    return 0;
}
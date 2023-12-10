#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <climits>
#include <queue>
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
        adjacencia[destino].push_back(std::make_pair(origem, peso)); // Considerando que o grafo é não-direcionado
    }

    // Função auxiliar para encontrar a aresta mínima conectada ao componente
    std::pair<int, int> encontrarArestaMinima(int u, std::unordered_map<int, bool>& visitado) {
        int minPeso = INT_MAX;
        std::pair<int, int> arestaMinima = std::make_pair(-1, -1);

        for (auto &aresta : adjacencia[u]) {
            int v = aresta.first;
            int peso = aresta.second;

            if (visitado[v] == false && peso < minPeso) {
                minPeso = peso;
                arestaMinima = std::make_pair(u, v);
            }
        }

        return arestaMinima;
    }

    // Algoritmo de Tarjan adaptado para encontrar uma Árvore Geradora Mínima (AGM) enraizada em 'r'
void encontrarAGM(int r) {
    std::unordered_map<int, bool> visitado;
    std::unordered_map<int, int> pai;

    for (auto &par : adjacencia) {
        visitado[par.first] = false;
        pai[par.first] = -1;
    }

    visitado[r] = true;

    for (auto &aresta : adjacencia[r]) {
        int v = aresta.first;

        if (!visitado[v]) {
            visitado[v] = true;
            pai[v] = r;
        }
    }

    for (auto &par : adjacencia) {
        int u = par.first;

        if (!visitado[u]) {
            std::pair<int, int> arestaMinima = encontrarArestaMinima(u, visitado);
            int v = arestaMinima.second;

            if (v != -1) {
                visitado[v] = true;
                pai[v] = u;
            }
        }
    }

    // Exibir a Árvore Geradora Mínima (AGM) enraizada em 'r'
    std::cout << "Arestas na Árvore Geradora Mínima (AGM) enraizada em " << r << ":" << std::endl;
    for (auto &par : pai) {
        if (par.second != -1) {
            std::cout << par.second << " - " << par.first << std::endl;
        }
    }
}

    // Função para mostrar o grafo original
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

    // Encontrar a Árvore Geradora Mínima (AGM) enraizada em um vértice específico 'r' usando Tarjan
    int verticeRaiz = 0; // Define o vértice raiz desejado
    grafo.encontrarAGM(verticeRaiz);

    return 0;
}
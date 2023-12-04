#include <string>

using namespace std;

class Vertice {

    private:
        int peso;
        string label;

    public:
        Vertice();

        Vertice(int peso, string label) {
            this->peso = peso;
            this->label = label;
        }

        ~Vertice();

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
};
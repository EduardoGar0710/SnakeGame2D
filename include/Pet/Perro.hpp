#include "Juguete.hpp"
#include "Animal.hpp"
#include "Corazon.hpp"

class Perro : public Animal // ES
{
private:
    Corazon corazon; // Tiene
    
public:
    Perro() {}
    ~Perro() {}
    void Jugar(Juguete juguete) // Usa
    {

    }
};
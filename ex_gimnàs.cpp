#include <iostream>
#include <string>

using namespace std;

class Tarifa {
private:
    string nomTarifa;
    double preuMensual;

public:
    Tarifa(string nom = "Estandard", double preu = 30.0)
        : nomTarifa(nom), preuMensual(preu) {
    }

    double getPreu() const {
        return preuMensual;
    }

    void mostrarTarifa() const {
        cout << "Tarifa: " << nomTarifa << " (" << preuMensual << " euros/mes)";
    }
};


class Soci {
protected: 
    string nom;
    int idSoci;
    Tarifa laTarifa; 

public:
    Soci(string n, int id, Tarifa t)
        : nom(n), idSoci(id), laTarifa(t) {
    }

    virtual double calcularQuota() const {
        return laTarifa.getPreu();
    }

    virtual void mostrarEstat() const {
        cout << "Soci: " << nom << " (ID: " << idSoci << ")\n";
        cout << " - ";
        laTarifa.mostrarTarifa();
        cout << "\n - Quota total a pagar: " << calcularQuota() << " euros\n";
    }
};


class SociVIP : public Soci {
private:
    double descompteEntrenador; 

public:
    SociVIP(string n, int id, Tarifa t, double descompte)
        : Soci(n, id, t), descompteEntrenador(descompte) {
    }

    double calcularQuota() const override {
        double preuBase = laTarifa.getPreu();
        return preuBase - descompteEntrenador;
    }

    void mostrarEstat() const override {
        cout << "Soci VIP: " << nom << " (ID: " << idSoci << ")\n";
        cout << " - ";
        laTarifa.mostrarTarifa();
        cout << "\n - Descompte aplicat: " << descompteEntrenador << " euros";
        cout << "\n - Quota total VIP a pagar: " << calcularQuota() << " euros\n";
    }
};


int main() {
    // Creem una tarifa bàsica
    Tarifa tarifaPlana("Plana", 40.0);

    // Creem un soci normal (Composició: li passem la tarifa)
    Soci soci1("Aleix Garcia", 101, tarifaPlana);

    SociVIP soci2("Marc Roca", 202, tarifaPlana, 10.0);

    cout << " INFORMACIO DEL SOCI NORMAL \n";
    soci1.mostrarEstat();

    cout << "\n INFORMACIO DEL SOCI VIP \n";
    soci2.mostrarEstat();

    return 0;
}
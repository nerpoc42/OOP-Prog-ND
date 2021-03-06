#ifndef OOP_PROG_ND_PERSONALAS_H
#define OOP_PROG_ND_PERSONALAS_H

#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>

#include "darbuotojas.h"

#define LINE "-------------------------------------------"

class DarbuotojoAmzius {
public:
    constexpr static unsigned AMZIU_GRUPIU_KIEKIS = 4;

    static bool jaunas(unsigned amzius) {
        return amzius >= 18 && amzius <= 30;
    }

    static bool vidutinis(unsigned amzius) {
        return amzius >= 31 && amzius <= 50;
    }

    static bool pagyvenes(unsigned amzius) {
        return amzius >= 51 && amzius <= 70;
    }

    static bool senyvas(unsigned amzius) {
        return amzius >= 71;
    }
};

class Personalas {
public:
    constexpr static unsigned DARBUOTOJU_KIEKIS = 10;

private:
    std::array<Darbuotojas, DARBUOTOJU_KIEKIS> darbuotojai_;

public:
    Personalas() = default;

    explicit Personalas(std::array<Darbuotojas, DARBUOTOJU_KIEKIS> darbuotojai) : darbuotojai_(std::move(darbuotojai)) {
    }

    //const Darbuotojas& gautiDarbuotoja(unsigned idx) const {
    //    return mDarbuotojai[idx];
    //}

    Darbuotojas &gautiDarbuotoja(unsigned idx) {
        return darbuotojai_[idx];
    }

    bool duomenysUzpildyti() const {
        return std::all_of(darbuotojai_.begin(), darbuotojai_.end(), [](const Darbuotojas &darbuotojas) {
            return darbuotojas.duomenysUzpildyti();
        });
    }

    void spausdintiDarbuotojus(const Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka) const {
        std::cout << LINE << std::endl;
        for (const auto &darbuotojas: darbuotojai_) {
            darbuotojas.spausdintiDuomenis(spausdinimoTvarka);
            std::cout << LINE << std::endl;
        }
    }

    // Filtravimas pagal amžių (2 užduotis)
    void
    filtruotiAmziu(bool (*amziausFiltras)(unsigned), const Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka) const {
        std::cout << LINE << std::endl;
        for (const auto &darbuotojas: darbuotojai_) {
            if (amziausFiltras(darbuotojas.gautiAmziu())) {
                darbuotojas.spausdintiDuomenis(spausdinimoTvarka);
                std::cout << LINE << std::endl;
            }
        }
    }

    // Filtravimas pagal pasirinkimą (3 užduotis)
    // Galima filtruoti tik skaičius
    void filtruotiMinMax(bool (*filtras)(unsigned reiksme, unsigned min, unsigned max), unsigned min, unsigned max,
                         Darbuotojas::DuomensPasirinkimas duomensPasirinkimas,
                         const Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka) const {
        if (duomensPasirinkimas != Darbuotojas::D_AMZIUS && duomensPasirinkimas != Darbuotojas::D_PATIRTIS &&
            duomensPasirinkimas != Darbuotojas::D_ATLYGINIMAS) {
            throw std::runtime_error("Netinkamas darbuotojo duomens tipas");
        }

        std::cout << LINE << std::endl;
        for (const auto &darbuotojas: darbuotojai_) {
            unsigned duomuo = darbuotojas.gautiPasirinkima(duomensPasirinkimas);
            if (filtras(duomuo, min, max)) {
                darbuotojas.spausdintiDuomenis(spausdinimoTvarka);
                std::cout << LINE << std::endl;
            }
        }
    }
};

std::array<Darbuotojas, Personalas::DARBUOTOJU_KIEKIS> gautiPradiniusDarbuotojus() {
    return {
        Darbuotojas("Donald", "Duck", "Duck", 10, 10, 2),
        Darbuotojas("Rick", "Astley", "Singer", 40, 10, 30000),
        Darbuotojas("Elon", "Musk", "Engineer", 50, 30, 100000),
        Darbuotojas("John", "Cena", "Wrestler", 45, 30, 50000),
        Darbuotojas("Robert", "Downey Jr.", "Actor", 57, 40, 70000),
        Darbuotojas("Dwayne", "Johnson", "Actor", 49, 20, 65000),
        Darbuotojas("Leonardo", "DiCaprio", "Actor", 47, 30, 65000),
        Darbuotojas("Ryan", "Reynolds", "Actor", 45, 30, 50000),
        Darbuotojas("Keanu", "Reeves", "Actor", 57, 30, 35000),
        Darbuotojas("Steven", "Spielberg", "Film Director", 75, 40, 55000)
    };
}

#endif//OOP_PROG_ND_PERSONALAS_H

#include <iostream>
#include <cmath>

/*

1.9 užduotis:
 - Funkcija, kuri gražina skaičiaus faktorialą
 - Taip pat jį atspausdina nuo įvesto skaičiaus

*/

int factorial(int n) {
	int res = n;

    // Leidžia skaičiuoti faktorialą nuo neigiamo skaičiaus
	n = std::abs(n);

    for (--n; n > 0; --n) {
        res *= n;
    }

	return res;
}

int main() {
	int sk;

	std::cout << "Įveskite skaičių: ";
	std::cin >> sk;

	std::cout << factorial(sk) << std::endl;

	return 0;
}


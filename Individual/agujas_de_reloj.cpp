#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Superposiciones de manecillas en un reloj de 12 horas:\n\n";

    for (int h = 1; h <= 11; ++h) {
        // Fórmula: minuto = (60 * h) / 11
        double minutos = (60.0 * h) / 11.0;
        int minuto_entero = static_cast<int>(minutos);
        int segundos = static_cast<int>((minutos - minuto_entero) * 60);

        std::cout << std::setw(2) << h << ":"
                  << std::setw(2) << std::setfill('0') << minuto_entero << ":"
                  << std::setw(2) << std::setfill('0') << segundos << "\n";
    }

    // Última coincidencia a las 12:00:00
    std::cout << "12:00:00\n";

    return 0;
}

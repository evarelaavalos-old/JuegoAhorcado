/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, así que quedará pendiente
para más adelante */

#include <iostream>
#include <string>

constexpr int LONGITUD_PALABRA = 7;
constexpr int NUMERO_INTENTOS = 5;

int main()
{
	// introduciendo el juego
	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LONGITUD_PALABRA;
	std::cout << " letras antes de agotar los " << NUMERO_INTENTOS;
	std::cout << " intentos?\n";
	std::cout << std::endl;

	// palabra a adivinar
	const std::string PalabraOculta = "Raqueta";

	// obtener una letra valida por cada uno de los turnos
	for (int IntentoActual = 1; IntentoActual <= NUMERO_INTENTOS; IntentoActual++)
	{
		// todo mostrar el numero de intento y las letras que vaya descubriendo

		// obteniendo una letra del jugador
		std::string LetraSupuesta;
		std::cout << "Ingrese una letra: ";
		getline(std::cin, LetraSupuesta);

		std::cout << std::endl;
	}
}
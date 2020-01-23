/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, así que quedará pendiente
para más adelante */

#include <iostream>
#include <string>

void MostrarIntro();
std::string ObtenerLetra();

constexpr int LONGITUD_PALABRA = 7;
constexpr int NUMERO_INTENTOS = 5;

// el punto de entrada para nuestra aplicacion
int main()
{
	MostrarIntro();

	// palabra a adivinar
	const std::string PalabraOculta = "Raqueta";

	// obtener una letra valida por cada uno de los turnos
	for (int IntentoActual = 1; IntentoActual <= NUMERO_INTENTOS; IntentoActual++)
	{
		// todo mostrar el numero de intento y las letras que vaya descubriendo
		ObtenerLetra();

		std::cout << std::endl;
	}

	return 0;
}

// introduciendo el juego
void MostrarIntro()
{
	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LONGITUD_PALABRA;
	std::cout << " letras antes de agotar los " << NUMERO_INTENTOS;
	std::cout << " intentos?\n";
	std::cout << std::endl;
}

// obteniendo una letra del jugador
std::string ObtenerLetra()
{
	std::string LetraSupuesta;
	std::cout << "Ingrese una letra: ";
	getline(std::cin, LetraSupuesta);

	return LetraSupuesta;
}

/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo */

#include <iostream>
#include <string>

int main()
{
	constexpr int LONGITUD_PALABRA = 6;
	std::cout << "Podras adivinar esta palabra de " << LONGITUD_PALABRA;
	std::cout << " letras?\n";
	std::cout << std::endl;

	constexpr int NUMERO_INTENTOS = 6;

	for (int i = 1; i <= NUMERO_INTENTOS; i++)
	{
		std::string LetraSupuesta;

		std::cout << "Intento " << i << ". ";
		getline(std::cin, LetraSupuesta);

		std::cout << std::endl;

	}

}
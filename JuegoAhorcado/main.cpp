/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, así que quedará pendiente
para más adelante */

#include <iostream>
#include <string>
#include "FJuegoAhorcado.h"

void MostrarIntro();
void JugarAhorcado();
std::string ObtenerLetra();
bool PreguntarPorJugarOtraVez();

FJuegoAhorcado FJAhorcado;
// todo ver si se puede hacer exprconst
int INTENTOS_MAXIMOS = FJAhorcado.ObtenerIntentosMaximos();

// el punto de entrada para nuestra aplicacion
int main()
{
	bool bJugarOtraVez = false;

	do {
		MostrarIntro();
		JugarAhorcado();
		bJugarOtraVez = PreguntarPorJugarOtraVez();
	}
	while (bJugarOtraVez);

	return 0;
}

// introduciendo el juego
void MostrarIntro()
{
	int LongitudPalabra = FJAhorcado.LongitudPalabraOculta();

	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LongitudPalabra;
	std::cout << " letras antes de agotar los " << INTENTOS_MAXIMOS;
	std::cout << " intentos?\n";
	std::cout << std::endl;
}

void JugarAhorcado()
{
	FJAhorcado.Reiniciar();

	// obtener una letra valida por cada uno de los intentos
	// todo cambiar el for por un while
	// while el intento actual sea menor del maximo de intentos
	// dejar que sea la clase de FJuegoAhorcado la que administre los intentos
	for (int IntentoActual = 1; IntentoActual <= INTENTOS_MAXIMOS; IntentoActual++)
	{
		std::string PalabraDescubierta = FJAhorcado.ObtenerPalabraDescubierta();
		
		std::cout << "Intento #" << IntentoActual << std::endl;
		std::cout << "Palabra descubierta: " << PalabraDescubierta << std::endl;

		// todo cambiar el tipo de datos de string a char
		std::string LetraPorDescubrir = "";
		LetraPorDescubrir = ObtenerLetra();

		std::cout << std::endl;
	}
}

// obteniendo una letra del jugador
// todo cambiar el tipo de datos de string a char
std::string ObtenerLetra()
{
	int IntentoActual = FJAhorcado.ObtenerIntentoActual();

	std::string LetraPorDescubrir;
	//std::cout << "Intento # " << IntentoActual << ". Ingrese una letra: ";
	std::cout << "Ingrese una letra: ";
	getline(std::cin, LetraPorDescubrir);

	return LetraPorDescubrir;
}

bool PreguntarPorJugarOtraVez()
{
	std::cout << "Te gustaria jugar otra vez (s/n)? ";
	
	std::string Respuesta;
	getline(std::cin, Respuesta);

	return Respuesta[0] == 's' || Respuesta[0] == 'S';
}
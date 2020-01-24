/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, así que quedará pendiente
para más adelante */

#include <iostream>
#include <string>
#include "FJuegoAhorcado.h"

using FText = std::string;
using int32 = int;

void MostrarIntro();
void JugarAhorcado();
FText ObtenerLetra();
bool PreguntarPorJugarOtraVez();

FJuegoAhorcado FJAhorcado;

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
	int32 LongitudPalabraOculta = FJAhorcado.LongitudPalabraOculta();
	int32 IntentosMaximos = FJAhorcado.ObtenerIntentosMaximos();

	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LongitudPalabraOculta;
	std::cout << " letras antes de agotar los " << IntentosMaximos;
	std::cout << " intentos?\n";
	std::cout << std::endl;
}

void JugarAhorcado()
{
	FJAhorcado.Reiniciar();

	int32 IntentosMaximos = FJAhorcado.ObtenerIntentosMaximos();

	// obtener una letra valida por cada uno de los intentos
	// TODO cambiar el FOR por un WHILE
	// mientras el intento actual sea menor del maximo de intentos
	// dejar que sea la clase de FJuegoAhorcado la que administre los intentos
	for (int32 IntentoActual = 1; IntentoActual <= IntentosMaximos; IntentoActual++)
	{
		FText PalabraDescubierta = FJAhorcado.ObtenerPalabraDescubierta();
		
		std::cout << "Intento #" << IntentoActual << std::endl;
		std::cout << "Palabra descubierta: " << PalabraDescubierta << std::endl;

		// todo cambiar el tipo de datos de string a char
		FText LetraPorDescubrir = "";
		LetraPorDescubrir = ObtenerLetra();

		std::cout << std::endl;
	}
}

// obteniendo una letra del jugador
// TODO cambiar el tipo de datos de string a char
FText ObtenerLetra()
{
	int32 IntentoActual = FJAhorcado.ObtenerIntentoActual();

	FText LetraPorDescubrir;
	std::cout << "Ingrese una letra: ";
	getline(std::cin, LetraPorDescubrir);

	return LetraPorDescubrir;
}

bool PreguntarPorJugarOtraVez()
{
	std::cout << "Te gustaria jugar otra vez (s/n)? ";
	
	FText Respuesta;
	getline(std::cin, Respuesta);

	return Respuesta[0] == 's' || Respuesta[0] == 'S';
}
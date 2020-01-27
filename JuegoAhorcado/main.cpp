/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, as� que quedar� pendiente
para m�s adelante */

#include <iostream>
#include <string>
#include "FJuegoAhorcado.h"

using FText = std::string;
using int32 = int;
using TCHAR = char;

void MostrarIntro();
void JugarAhorcado();
TCHAR ObtenerLetra();
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
	int32 LONGITUD_PALABRA_OCULTA = FJAhorcado.LongitudPalabraOculta();
	int32 INTENTOS_MAXIMOS = FJAhorcado.ObtenerIntentosMaximos();

	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LONGITUD_PALABRA_OCULTA;
	std::cout << " letras antes de agotar los " << INTENTOS_MAXIMOS;
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
		TCHAR LetraPorDescubrir = ObtenerLetra();

		ContadorLetras CLetras = FJAhorcado.IngresarLetra(LetraPorDescubrir);

		std::cout << "Letras: DESCUBIERTAS = " << CLetras.Descubiertas;
		std::cout << ", RESTANTES = " << CLetras.Restantes << std::endl;

		std::cout << std::endl;
	}
}

// obteniendo una letra del jugador
TCHAR ObtenerLetra()
{
	FText PalabraDescubierta = FJAhorcado.ObtenerPalabraDescubierta();
	int32 IntentoActual = FJAhorcado.ObtenerIntentoActual();

	std::cout << "Intento " << IntentoActual << ". ";
	std::cout << PalabraDescubierta << std::endl;
	std::cout << "Ingrese una letra: ";

	// TODO crear una implementacion que me permita preguntarle al usuario
	// si esta de acuerdo con tomar la primera letra ingresada
	FText TextoIngresado;
	std::getline(std::cin, TextoIngresado);

	return TextoIngresado[0];
}

bool PreguntarPorJugarOtraVez()
{
	std::cout << "Te gustaria jugar otra vez (s/n)? ";
	
	FText Respuesta;
	getline(std::cin, Respuesta);

	return Respuesta[0] == 's' || Respuesta[0] == 'S';
}
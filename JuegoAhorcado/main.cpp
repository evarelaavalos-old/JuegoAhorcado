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
void MostrarResumenJuego();
TCHAR ObtenerLetraValida();
bool PreguntarPorJugarOtraVez();
FText ObtenerPalabraEspaciada();

FJuegoAhorcado FJAhorcado;

// el punto de entrada para nuestra aplicacion
int main()
{
	bool bJugarOtraVez = false;

	do {
		MostrarIntro();
		JugarAhorcado();
		MostrarResumenJuego();
		bJugarOtraVez = PreguntarPorJugarOtraVez();
	}
	while (bJugarOtraVez);

	return 0;
}

// introduciendo el juego
void MostrarIntro()
{
	int32 LONGITUD_PALABRA_OCULTA = FJAhorcado.ObtenerLongitudPalabra();
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

	// obtener una letra valida mientras el juego NO se este ganado
	// y todavia queden intentos restantes 
	while (!FJAhorcado.JuegoEstaGanado() && 
		FJAhorcado.ObtenerIntentoActual() <= IntentosMaximos)
	{
		TCHAR Estimacion = ObtenerLetraValida();

		ContadorLetras ContLetras = FJAhorcado.IngresarLetraValida(Estimacion);

		std::cout << "Letras: DESCUBIERTAS = " << ContLetras.Descubiertas;
		std::cout << ", RESTANTES = " << ContLetras.Restantes << "\n\n";
	}
}

// obteniendo una letra del jugador
TCHAR ObtenerLetraValida()
{
	EEstadoLetra Estado = EEstadoLetra::Estado_Invalido;
	do {
		FText Incognita = ObtenerPalabraEspaciada();
		int32 IntentoActual = FJAhorcado.ObtenerIntentoActual();

		std::cout << "Intento " << IntentoActual << ". ";
		std::cout << Incognita << std::endl;
		std::cout << "Letras Utilizadas: ";
		std::cout << FJAhorcado.ObtenerLetrasUtilizadas() << std::endl;
		std::cout << "Ingrese una letra: ";

		// se toma el primer caracter de la cadena ingresada por el usuario
		FText CadenaEntrada;
		std::getline(std::cin, CadenaEntrada);
		TCHAR PrimerCaracEntrada = CadenaEntrada[0];

		// TODO crear una implementacion que me permita preguntarle al usuario
		// si esta de acuerdo con tomar la primera letra ingresada

		// se verifica si el caracter ingresado es valido
		Estado = FJAhorcado.CheckearValidacionCaracter(PrimerCaracEntrada);

		switch(Estado) {
			case EEstadoLetra::No_Letra:
				std::cout << "Por favor ingrese una letra minuscula.\n";
				break;
			case EEstadoLetra::No_Minuscula:
				std::cout << "La letra ingresada debe ser minuscula.\n";
				break;
			case EEstadoLetra::Ingresado_Previamente:
				std::cout << "Ya ha ingresado esta letra previamente.\n";
				break;
			default:
				return CadenaEntrada[0];
		}
		
		std::cout << std::endl;
	} while (Estado != EEstadoLetra::OK);
}

void MostrarResumenJuego()
{
	if (FJAhorcado.JuegoEstaGanado()) {
		std::cout << "FELICITACIONES! HA GANADO EL JUEGO\n";
		std::cout << "LA PALABRA OCULTA ERA: " << FJAhorcado.ObtenerPalabra();
		std::cout << ". Y LE TOMO " << FJAhorcado.ObtenerIntentoActual() << " INTENTOS\n\n";
	}
	else {
		std::cout << "Lo siento, ha agotado todos sus intentos. Mejor suerte la proxima vez.\n\n";
	}
}

bool PreguntarPorJugarOtraVez()
{
	std::cout << "Te gustaria jugar otra vez (s/n)? ";
	
	FText Respuesta;
	getline(std::cin, Respuesta);

	return Respuesta[0] == 's' || Respuesta[0] == 'S';
}

//TODO crear una funcion EspaciarCadena que agregue espacios entre los caracteres de la cadena
//mientras el caracter sea distinto de EOF
FText ObtenerPalabraEspaciada()
{
	FText PalabraOculta = FJAhorcado.ObtenerPalabra();
	int32 LongitudPalabra = FJAhorcado.ObtenerLongitudPalabra();

	FText PalabraEspaciada = "";
	for (int32 CaracPO = 0; CaracPO < LongitudPalabra - 1; CaracPO++) {
		PalabraEspaciada.push_back(PalabraOculta[CaracPO]);
		PalabraEspaciada.push_back(' ');
	}
	PalabraEspaciada.push_back(PalabraOculta[LongitudPalabra - 1]);

	return PalabraEspaciada;
}
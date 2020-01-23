/* La idea original era hacerlo en ingles, pero se me dificulto mucho
el idioma. Solo me entorpecia el trabajo, así que quedará pendiente
para más adelante */

#include <iostream>
#include <string>

int main();

void MostrarIntro();
void JugarAhorcado();
std::string ObtenerLetra();
bool PreguntarPorJugarOtraVez();

constexpr int NUMERO_INTENTOS = 5;

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
	constexpr int LONGITUD_PALABRA = 7;

	std::cout << "Bienvenido al juego del Ahorcado! ";
	std::cout << "Un divertido juego de palabras!\n";
	std::cout << "Podras adivinar esta palabra de " << LONGITUD_PALABRA;
	std::cout << " letras antes de agotar los " << NUMERO_INTENTOS;
	std::cout << " intentos?\n";
	std::cout << std::endl;
}

void JugarAhorcado()
{
	// palabra a adivinar
	const std::string PalabraOculta = "Raqueta";

	// obtener una letra valida por cada uno de los turnos
	for (int IntentoActual = 1; IntentoActual <= NUMERO_INTENTOS; IntentoActual++)
	{
		// todo mostrar el numero de intento y las letras que vaya descubriendo
		std::cout << "Intento #" << IntentoActual << ". ";

		// placeholder
		// todo implementar un metodo que inicialice con guiones bajos
		// y vaya replazandolos por las letras que se van adivinando
		std::cout << "_______\n";

		// todo cambiar el tipo de datos de string a char
		std::string LetraSupuesta = "";
		LetraSupuesta = ObtenerLetra();

		std::cout << std::endl;
	}
}

// obteniendo una letra del jugador
// todo cambiar el tipo de datos de string a char
std::string ObtenerLetra()
{
	std::string LetraSupuesta;
	std::cout << "Ingrese una letra: ";
	getline(std::cin, LetraSupuesta);

	return LetraSupuesta;
}

bool PreguntarPorJugarOtraVez()
{
	std::cout << "Te gustaria jugar otra vez (s/n)? ";
	
	std::string Respuesta;
	getline(std::cin, Respuesta);

	return Respuesta[0] == 's' || Respuesta[0] == 'S';
}
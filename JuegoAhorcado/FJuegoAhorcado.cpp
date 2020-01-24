#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); }

int FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int FJuegoAhorcado::LongitudPalabraOculta() const { return MiPalabraOculta.length(); }
std::string FJuegoAhorcado::ObtenerPalabraDescubierta() const { return MiPalabraDescubierta; }

void FJuegoAhorcado::Reiniciar()
{
	constexpr int INTENTOS_MAXIMOS = 5;
	const std::string PALABRA_OCULTA = "Raqueta";
	const int LONGITUD_PALABRA_OCULTA = PALABRA_OCULTA.length();

	MiIntentoActual = 1;
	MiIntentosMaximos = INTENTOS_MAXIMOS;
	MiPalabraOculta = PALABRA_OCULTA;
	MiPalabraDescubierta = InicializarPalabraDescubierta(LONGITUD_PALABRA_OCULTA);

	return;
}

bool FJuegoAhorcado::EstaJuegoGanado()
{
	return false;
}

bool FJuegoAhorcado::CheckearValidacionCadena(std::string)
{
	return false;
}

std::string FJuegoAhorcado::InicializarPalabraDescubierta(int LongitudPalabra)
{
	std::string PalabraPorDescubrir = "";

	for (int i = 1; i < LongitudPalabra; i++)
	{
		PalabraPorDescubrir.append("_ ");
	}
	PalabraPorDescubrir.append("_");

	return PalabraPorDescubrir;
}


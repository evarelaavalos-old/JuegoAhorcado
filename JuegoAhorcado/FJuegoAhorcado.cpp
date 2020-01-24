#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); }

int FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int FJuegoAhorcado::LongitudPalabraOculta() const { return MiPalabraOculta.length(); }
std::string FJuegoAhorcado::ObtenerPalabraDescubierta() const { return MiPalabraDescubierta; }

void FJuegoAhorcado::Reiniciar()
{
	MiIntentoActual = 1;
	MiIntentosMaximos = 5;
	MiPalabraOculta = "Raqueta";
	MiPalabraDescubierta = "_ _ _ _ _ _ _"; // todo crear un metodo que modifique este string
	// todo implementar un metodo que inicialice con guiones bajos
	// y vaya replazandolos por las letras que se van adivinando
}

bool FJuegoAhorcado::EstaJuegoGanado()
{
	return false;
}

bool FJuegoAhorcado::CheckearValidacionCadena(std::string)
{
	return false;
}


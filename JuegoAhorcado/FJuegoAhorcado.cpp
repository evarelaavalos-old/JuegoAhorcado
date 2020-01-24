#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); }

int32 FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int32 FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int32 FJuegoAhorcado::LongitudPalabraOculta() const { return MiPalabraOculta.length(); }
FString FJuegoAhorcado::ObtenerPalabraDescubierta() const { return MiPalabraDescubierta; }

void FJuegoAhorcado::Reiniciar()
{
	constexpr int32 INTENTOS_MAXIMOS = 5;
	const FString PALABRA_OCULTA = "Raqueta";
	const int32 LONGITUD_PALABRA_OCULTA = PALABRA_OCULTA.length();

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

bool FJuegoAhorcado::CheckearValidacionCadena(FString)
{
	return false;
}

FString FJuegoAhorcado::InicializarPalabraDescubierta(int32 LongitudPalabra)
{
	FString PalabraPorDescubrir = "";

	for (int32 i = 1; i < LongitudPalabra; i++)
	{
		PalabraPorDescubrir.append("_ ");
	}
	PalabraPorDescubrir.append("_");

	return PalabraPorDescubrir;
}


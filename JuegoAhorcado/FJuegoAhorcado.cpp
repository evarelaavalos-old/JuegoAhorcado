#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); } // constructor

int32 FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int32 FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int32 FJuegoAhorcado::LongitudPalabraOculta() const { return MiPalabraOculta.length(); }
FString FJuegoAhorcado::ObtenerPalabraDescubierta() const { return MiPalabraDescubierta; }

void FJuegoAhorcado::Reiniciar()
{
	constexpr int32 INTENTOS_MAXIMOS = 10;
	const FString PALABRA_OCULTA = "raqueta";
	const int32 LONGITUD_PALABRA_OCULTA = PALABRA_OCULTA.length();

	MiIntentoActual = 1;
	MiIntentosMaximos = INTENTOS_MAXIMOS;
	MiLetrasRestantes = LONGITUD_PALABRA_OCULTA;
	MiPalabraOculta = PALABRA_OCULTA;
	MiPalabraDescubierta = InicializarPalabraDescubierta(LONGITUD_PALABRA_OCULTA);

	return;
}

bool FJuegoAhorcado::EstaJuegoGanado()
{
	return false;
}

bool FJuegoAhorcado::CheckearValidacionCaracter(TCHAR)
{
	// es una letra minuscula o mayuscula, no un caracter especial ni un numero
	// no fue ingresado previamente por el usuario
	return false;
}

ContadorLetras FJuegoAhorcado::IngresarLetra(TCHAR LetraIngresada)
{
	// asumiendo que el caracter ingresado es una letra valida
	ContadorLetras CLetras;
	int32 LONGITUD_PALABRA = LongitudPalabraOculta();

	for(int PosLetra = 0; PosLetra < LONGITUD_PALABRA; PosLetra++) {
		// si la letra ingresada es igual a la letra de la palabra oculta en esa posicion
		if (LetraIngresada == MiPalabraOculta[PosLetra]) {
			// las letras de la palabra descubierta se muestran separadas por
			// espacios (osea cada dos letras) por meros fines esteticos
			MiPalabraDescubierta[PosLetra * 2] = LetraIngresada;
			CLetras.Descubiertas++;
			MiLetrasRestantes--;
		}
	}

	CLetras.Restantes = MiLetrasRestantes;
	MiIntentoActual++;
	// TODO agregar la letra ingresada a una lista de letras utilizadas

	return CLetras;
}

FString FJuegoAhorcado::InicializarPalabraDescubierta(int32 LongitudPalabra)
{
	FString PalabraPorDescubrir = "";

	for (int32 i = 1; i < LongitudPalabra; i++) {
		PalabraPorDescubrir.append("_ ");
	}
	PalabraPorDescubrir.append("_");

	return PalabraPorDescubrir;
}


#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); } // constructor

int32 FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int32 FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int32 FJuegoAhorcado::ObtenerLongitudPalabra() const { return MiPalabraOculta.length(); }
FString FJuegoAhorcado::ObtenerPalabra() const { return MiPalabraConFormato; }

void FJuegoAhorcado::Reiniciar()
{
	constexpr int32 INTENTOS_MAXIMOS = 10;
	const FString PALABRA_OCULTA = "raqueta";
	const int32 LONGITUD_PALABRA_OCULTA = PALABRA_OCULTA.length();

	MiIntentoActual = 1;
	MiIntentosMaximos = INTENTOS_MAXIMOS;
	MiLetrasRestantes = LONGITUD_PALABRA_OCULTA;
	MiPalabraOculta = PALABRA_OCULTA;
	MiPalabraConFormato = InicializarPalabraConFormato(LONGITUD_PALABRA_OCULTA);
	
	return;
}

bool FJuegoAhorcado::EstaJuegoGanado()
{
	int LONGITUD_PALABRA = ObtenerLongitudPalabra();

	for (int POCarac = 0; POCarac < LONGITUD_PALABRA; POCarac++) {
		if (MiPalabraConFormato[POCarac] == '_')
			return false;
	}

	return true;
}

EEstadoLetra FJuegoAhorcado::CheckearValidacionCaracter(TCHAR CaracIngresado) const
{
	if (CaracIngresado >= 'A' && CaracIngresado <= 'Z')
	{
		return EEstadoLetra::No_Minuscula;
	}
	else if (!(CaracIngresado >= 'a' && CaracIngresado <= 'z'))
	{
		return EEstadoLetra::No_Letra;
	}
	else if (false) // TODO revisar en una lista de letras ingresadas
	{
		return EEstadoLetra::Ingresado_Previamente;
	}
	else
	{
		return EEstadoLetra::OK;
	}
}

// TODO cambiar el valor de retorno solamente a letras descubiertas
// y hacer de letras restantes una variable global de la clase
ContadorLetras FJuegoAhorcado::IngresarLetraValida(TCHAR LetraIngresada)
{
	MiIntentoActual++;
	// TODO agregar la letra ingresada a una lista de letras utilizadas

	ContadorLetras ContLetras;
	ContLetras.Restantes = MiLetrasRestantes;

	int32 LONGITUD_PALABRA = ObtenerLongitudPalabra();
	// comparar la letra ingresada con cada caracter de la palabra oculta
	for (int POCarac = 0; POCarac < LONGITUD_PALABRA; POCarac++) {
		// si la letra coincide con algun caracter de la palabra oculta
		if (MiPalabraOculta[POCarac] == LetraIngresada) {
			// desvelar la letra en la palabra que se muestra al usuario
			MiPalabraConFormato[POCarac] = LetraIngresada;
			ContLetras.Descubiertas++;
			ContLetras.Restantes--;
		}
	}

	MiLetrasRestantes = ContLetras.Restantes;
	return ContLetras;
}

FString FJuegoAhorcado::InicializarPalabraConFormato(int32 LongitudPalabra) const
{
	FString Palabra = "";
	for (int32 i = 0; i < LongitudPalabra; i++) { Palabra.push_back('_'); }

	return Palabra;
}

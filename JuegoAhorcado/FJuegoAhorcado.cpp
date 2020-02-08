#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); } // constructor

//public
FString FJuegoAhorcado::ObtenerPalabra() const { return MiPalabraConFormato; }
FString FJuegoAhorcado::ObtenerLetrasUtilizadas() const { return MiLetrasUtilizadasComoCadena; }
int32 FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int32 FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int32 FJuegoAhorcado::ObtenerLongitudPalabra() const { return MiPalabraOculta.length(); }
bool FJuegoAhorcado::JuegoEstaGanado() const { return bJuegoEstaGanado; }
bool FJuegoAhorcado::HaSidoUtilizado(TCHAR Caracter) { return MiLetrasUtilizadas[Caracter]; }

void FJuegoAhorcado::Reiniciar()
{
	constexpr int32 INTENTOS_MAXIMOS = 5;
	const FString PALABRA_OCULTA = "rinoceronte";
	const int32 LONGITUD_PALABRA_OCULTA = PALABRA_OCULTA.length();

	MiIntentoActual = 1;
	MiIntentosMaximos = INTENTOS_MAXIMOS;
	MiLetrasRestantes = LONGITUD_PALABRA_OCULTA;
	MiPalabraOculta = PALABRA_OCULTA;
	MiPalabraConFormato = InicializarPalabraConFormato(LONGITUD_PALABRA_OCULTA);
	bJuegoEstaGanado = false;
	MiLetrasUtilizadas.clear();
	MiLetrasUtilizadasComoCadena = "";

	return;
}

EEstadoLetra FJuegoAhorcado::CheckearValidacionCaracter(TCHAR CaracIngresado)
{
	if (CaracIngresado >= 'A' && CaracIngresado <= 'Z')
	{
		return EEstadoLetra::No_Minuscula;
	}
	else if (!(CaracIngresado >= 'a' && CaracIngresado <= 'z'))
	{
		return EEstadoLetra::No_Letra;
	}
	else if (HaSidoUtilizado(CaracIngresado))
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
	IngresarLetraUtilizada(LetraIngresada);

	ContadorLetras ContLetras;
	ContLetras.Restantes = MiLetrasRestantes;

	int32 LONGITUD_PALABRA = ObtenerLongitudPalabra();
	// comparar la letra ingresada con cada caracter de la palabra oculta
	for (int32 CaracPO = 0; CaracPO < LONGITUD_PALABRA; CaracPO++) {
		// si la letra coincide con algun caracter de la palabra oculta
		if (MiPalabraOculta[CaracPO] == LetraIngresada) {
			// desvelar la letra en la palabra que se muestra al usuario
			MiPalabraConFormato[CaracPO] = LetraIngresada;
			ContLetras.Descubiertas++;
			ContLetras.Restantes--;
		}
	}

	if (ContLetras.Restantes == 0) {
		bJuegoEstaGanado = true;
	} else {
		bJuegoEstaGanado = false;
	}

	if (ContLetras.Descubiertas == 0) {
		MiIntentoActual++;
	}

	MiLetrasRestantes = ContLetras.Restantes;
	return ContLetras;
}

//PRIVATE
FString FJuegoAhorcado::InicializarPalabraConFormato(int32 LongitudPalabra) const
{
	// TODO Ver si puedo hacer una implementacion de una sola linea
	FString Palabra = "";
	for (int32 i = 0; i < LongitudPalabra; i++) { Palabra.push_back('_'); }

	return Palabra;
}

void FJuegoAhorcado::IngresarLetraUtilizada(TCHAR Letra)
{
	MiLetrasUtilizadas[Letra] = true;

	bool bSeHaIngresadoLetra = (MiLetrasUtilizadasComoCadena.size() > 0);
	if (!bSeHaIngresadoLetra) {
		//agregar la letra sin mas, por ej: "a"
		MiLetrasUtilizadasComoCadena.push_back(Letra);
	} else {
		//agregar una coma y un espacio antes de la letra ", b"
		MiLetrasUtilizadasComoCadena.append(", ");
		MiLetrasUtilizadasComoCadena.push_back(Letra);
	}
}

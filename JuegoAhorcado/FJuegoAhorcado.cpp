#include "FJuegoAhorcado.h"

FJuegoAhorcado::FJuegoAhorcado() { Reiniciar(); } // constructor

//public
FString FJuegoAhorcado::ObtenerPalabra() const { return MiPalabraConFormato; }
//FString FJuegoAhorcado::ObtenerLetrasUtilizadas() const { return PalabrasUtilizadasComoCadena; }
//TODO implementar la funcion
int32 FJuegoAhorcado::ObtenerIntentoActual() const { return MiIntentoActual; }
int32 FJuegoAhorcado::ObtenerIntentosMaximos() const { return MiIntentosMaximos; }
int32 FJuegoAhorcado::ObtenerLongitudPalabra() const { return MiPalabraOculta.length(); }
bool FJuegoAhorcado::JuegoEstaGanado() const { return bJuegoEstaGanado; }

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
	for (int32 POCarac = 0; POCarac < LONGITUD_PALABRA; POCarac++) {
		// si la letra coincide con algun caracter de la palabra oculta
		if (MiPalabraOculta[POCarac] == LetraIngresada) {
			// desvelar la letra en la palabra que se muestra al usuario
			MiPalabraConFormato[POCarac] = LetraIngresada;
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

FString FJuegoAhorcado::ObtenerLetrasUtilizadas()
{
	int32 CantidadLetras = MiLetrasUtilizadas.size();

	if (CantidadLetras == 0) {
		return "-";
	}
	else if (CantidadLetras == 1) {
		FString Letra(1, MiLetrasUtilizadas.begin()->first);
		return Letra;
	}
	else {
		FString Letras = "";

		TMap<TCHAR, bool>::iterator it = MiLetrasUtilizadas.begin();
		TMap<TCHAR, bool>::iterator Ultimo = --MiLetrasUtilizadas.end();
		for (; it != Ultimo; it++)
		{
			Letras.push_back(it->first);
			Letras.append(", ");
		}
		Letras.push_back(Ultimo->first);
		
		return Letras;
	}
}

//PRIVATE
bool FJuegoAhorcado::HaSidoUtilizado(TCHAR Caracter) { return MiLetrasUtilizadas[Caracter]; }

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


	//TODO agregar las letras a un string de manera que se pueda presentar al usuario
		//si la cadena esta vacia
			//agregar la letra sin mas, por ej: "a"
		//sino
			//agregar ", b"
}

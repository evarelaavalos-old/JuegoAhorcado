#pragma once
#include <string>

using FString = std::string;
using int32 = int;
using TCHAR = char;

struct ContadorLetras
{
	int32 Descubiertas = 0;
	int32 Restantes = 0;
};

enum class EEstadoLetra
{
	Estado_Invalido, // default
	OK,
	No_Letra,
	No_Minuscula,
	Ingresado_Previamente
};

class FJuegoAhorcado {
public:
	FJuegoAhorcado(); //constructor

	int32 ObtenerIntentoActual() const;
	int32 ObtenerIntentosMaximos() const;
	int32 ObtenerLongitudPalabra() const;
	FString ObtenerPalabra() const;
	
	void Reiniciar(); // TODO enriquecer el tipo de retorno
	bool JuegoEstaGanado() const;
	EEstadoLetra CheckearValidacionCaracter(TCHAR) const;
	ContadorLetras IngresarLetraValida(TCHAR);


private:
	int32 MiIntentoActual;
	int32 MiIntentosMaximos;
	int32 MiLetrasRestantes;
	FString MiPalabraOculta; // palabra a adivinar
	FString MiPalabraConFormato; // palabra reemplazada por _
	bool bJuegoEstaGanado;
	// TODO crear una lista de letras ya ingresadas previamente por el usuario
	// bool fin del juego?

	FString InicializarPalabraConFormato(int32) const;
};

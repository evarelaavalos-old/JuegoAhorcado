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

class FJuegoAhorcado {
public:
	FJuegoAhorcado(); //constructor

	int32 ObtenerIntentoActual() const;
	int32 ObtenerIntentosMaximos() const;
	int32 LongitudPalabraOculta() const;
	FString ObtenerPalabraDescubierta() const;
	
	void Reiniciar(); // TODO enriquecer el tipo de retorno
	bool EstaJuegoGanado();
	bool CheckearValidacionCaracter(TCHAR); // TODO enriquecer el tipo de retorno
	ContadorLetras IngresarLetra(TCHAR);


private:
	int32 MiIntentoActual;
	int32 MiIntentosMaximos;
	int32 MiLetrasRestantes;
	FString MiPalabraOculta;
	FString MiPalabraDescubierta;
	// TODO crear una lista de letras ya ingresadas previamente por el usuario
	// bool fin del juego?

	FString InicializarPalabraDescubierta(int32);
};

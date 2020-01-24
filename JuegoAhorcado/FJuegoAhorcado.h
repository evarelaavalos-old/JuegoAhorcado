#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FJuegoAhorcado {
public:
	FJuegoAhorcado(); //constructor

	int32 ObtenerIntentoActual() const;
	int32 ObtenerIntentosMaximos() const;
	int32 LongitudPalabraOculta() const;
	FString ObtenerPalabraDescubierta() const;
	
	void Reiniciar(); // TODO enriquecer el tipo de retorno
	bool EstaJuegoGanado();
	bool CheckearValidacionCadena(FString); // TODO enriquecer el tipo de retorno


private:
	int32 MiIntentoActual;
	int32 MiIntentosMaximos;
	FString MiPalabraOculta;
	FString MiPalabraDescubierta;

	FString InicializarPalabraDescubierta(int32);
};

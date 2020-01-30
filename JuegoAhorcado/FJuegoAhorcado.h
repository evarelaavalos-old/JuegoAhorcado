#pragma once
#include <string>
#include <map>
#define TMap std::map

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
	FString ObtenerLetrasUtilizadas();
	
	void Reiniciar(); // TODO enriquecer el tipo de retorno
	bool JuegoEstaGanado() const;
	EEstadoLetra CheckearValidacionCaracter(TCHAR);
	ContadorLetras IngresarLetraValida(TCHAR);


private:
	int32 MiIntentoActual;
	int32 MiIntentosMaximos;
	int32 MiLetrasRestantes;
	FString MiPalabraOculta; // palabra a adivinar
	FString MiPalabraConFormato; // palabra reemplazada por _
	TMap<TCHAR,bool> LetrasUtilizadas;
	bool bJuegoEstaGanado;

	FString InicializarPalabraConFormato(int32) const;
	bool HaSidoUtilizado(TCHAR);
};

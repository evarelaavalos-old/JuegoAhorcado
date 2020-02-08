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

	FString ObtenerPalabra() const;
	FString ObtenerLetrasUtilizadas();
	int32 ObtenerIntentoActual() const;
	int32 ObtenerIntentosMaximos() const;
	int32 ObtenerLongitudPalabra() const;
	bool JuegoEstaGanado() const;
	
	void Reiniciar(); // TODO enriquecer el tipo de retorno
	EEstadoLetra CheckearValidacionCaracter(TCHAR);
	ContadorLetras IngresarLetraValida(TCHAR);

private:
	TMap<TCHAR,bool> MiLetrasUtilizadas;
	FString MiPalabraOculta; // palabra a adivinar
	FString MiPalabraConFormato; // palabra reemplazada por _
	//TODO crear una nueva variable donde se guarde las letras ingresadas como string
	int32 MiIntentoActual;
	int32 MiIntentosMaximos;
	int32 MiLetrasRestantes;
	bool bJuegoEstaGanado;

	FString InicializarPalabraConFormato(int32) const;
	void IngresarLetraUtilizada(TCHAR);
	bool HaSidoUtilizado(TCHAR);
};

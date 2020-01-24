#pragma once
#include <string>

class FJuegoAhorcado {
public:
	FJuegoAhorcado(); //constructor

	int ObtenerIntentoActual() const;
	int ObtenerIntentosMaximos() const;
	int LongitudPalabraOculta() const;
	std::string ObtenerPalabraDescubierta() const;
	
	void Reiniciar(); // todo enriquecer el tipo de retorno
	bool EstaJuegoGanado();
	bool CheckearValidacionCadena(std::string); // todo enriquecer el tipo de retorno


private:
	int MiIntentoActual;
	int MiIntentosMaximos;
	std::string MiPalabraOculta;
	std::string MiPalabraDescubierta;

	std::string InicializarPalabraDescubierta(int);
};

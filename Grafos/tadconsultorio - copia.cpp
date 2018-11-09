#include "colaenla.h"
#include "listaenla.h"

struct Medico{
	Cola<int> ListaEspera;
	int dni;
};


class Consultorio{
	Consultorio();
	void Alta(const Medico& med);
	void Baja(const Medico& med);
	void introducirPaciente(int paciente);
	int consultarPaciente(int paciente,const Medico& me)const

private:
	Lista<Medico> ConsultorioMedicos_;
};

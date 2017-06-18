#ifndef FECHA_H
#define	FECHA_H

#define DIA_POR_DEFECTO 1
#define MES_POR_DEFECTO 1
#define ANIO_POR_DEFECTO 2000

class Fecha {
    public:
        Fecha(unsigned dia = DIA_POR_DEFECTO, unsigned mes = MES_POR_DEFECTO, unsigned anio = ANIO_POR_DEFECTO);
        Fecha(const Fecha &unaFecha);

        unsigned getDia();
        unsigned getMes();
        unsigned getAnio();

    private:
        unsigned dia;
        unsigned mes;
        unsigned anio; //Puaj!
};

#endif	/* FECHA_H */

#ifndef FECHA_H
#define	FECHA_H

class Fecha {
    public:
        Fecha(unsigned dia, unsigned mes, unsigned anio);
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


#-------------------------------------------------------------------------------
# MAKEFILE DE LA TAREA 6
# PROGRAMACIÓN 4 2017
################################################################################
# directorios
HDIR    = include
CPPDIR  = cpp
ODIR    = obj
TESTDIR = test

MODULOS = ControladorFactory DataMensajeConImagen MensajeConImagen ControladorFecha DataMensajeConVideo MensajeConVideo ControladorMensajes DataMensaje Mensaje ControladorUsuarios DataMensajeDeContacto  MensajeDeContacto Conversacion         DataMensajeSimple MensajeSimple DataContacto  DataNotificacion  UI DataConversacion DataReceptor Usuario DataConversacionGrupo Fecha DataConversacionSimple Grupo


# lista de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=main
EJECUTABLE=Main

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR)
make:
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/ControladorFactory.o ./$(CPPDIR)/ControladorFactory.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataMensajeConImagen.o ./$(CPPDIR)/DataMensajeConImagen.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/MensajeConImagen.o ./$(CPPDIR)/MensajeConImagen.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/Grupo.o ./$(CPPDIR)/Grupo.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataConversacionSimple.o ./$(CPPDIR)/DataConversacionSimple.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/Fecha.o ./$(CPPDIR)/Fecha.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataConversacionGrupo.o ./$(CPPDIR)/DataConversacionGrupo.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/Usuario.o ./$(CPPDIR)/Usuario.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataReceptor.o ./$(CPPDIR)/DataReceptor.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataConversacion.o ./$(CPPDIR)/DataConversacion.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/UI.o ./$(CPPDIR)/UI.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataNotificacion.o ./$(CPPDIR)/DataNotificacion.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataContacto.o ./$(CPPDIR)/DataContacto.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/MensajeSimple.o ./$(CPPDIR)/MensajeSimple.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataMensajeSimple.o ./$(CPPDIR)/DataMensajeSimple.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/Conversacion.o ./$(CPPDIR)/Conversacion.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/MensajeDeContacto.o ./$(CPPDIR)/MensajeDeContacto.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataMensajeDeContacto.o ./$(CPPDIR)/DataMensajeDeContacto.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/ControladorUsuarios.o ./$(CPPDIR)/ControladorUsuarios.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/Mensaje.o ./$(CPPDIR)/Mensaje.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataMensaje.o ./$(CPPDIR)/DataMensaje.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/ControladorMensajes.o ./$(CPPDIR)/ControladorMensajes.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/MensajeConVideo.o ./$(CPPDIR)/MensajeConVideo.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/DataMensajeConVideo.o ./$(CPPDIR)/DataMensajeConVideo.cpp
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/ControladorFecha.o ./$(CPPDIR)/ControladorFecha.cpp
	make principal

principal:
	$(CC) $(CCFLAGS) -c -o ./$(ODIR)/main.o main.cpp

$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@



#Copie el principio uno de los archivos de P3.

ejec: mail.cpp Makefile
	make
	$(CC) $(CCFLAGS) $(OS) main.cpp -o Principal

# borra binarios
clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)


# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean: clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~


check-syntax:
	gcc -o nul -S ${CHK_SOURCES}

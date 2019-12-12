## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = hedi

hedi_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	HAreservation.c HAreservation.h \
	HARecherchevol.c HARecherchevol.h \
	HAreservationvoiture.c HAreservationvoiture.h \
	HArechvoiture.c HArechvoiture.h
	

hedi_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)


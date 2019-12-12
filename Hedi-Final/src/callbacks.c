#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "HAreservation.h"
#include "HAreservationvoiture.h"
#include "HArechvoiture.h"


/***********************************************************************************/


/******************** Debut TRAVAIL DE HEDI AROUA **********************************/


/********************************************************************************/



void on_HAbuttonAfficher_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreReservation;
GtkWidget *HAFenetreAffichage;
GtkWidget *HAtreeview;

HAFenetreReservation=lookup_widget(objet,"HAFenetreReservation");

gtk_widget_destroy(HAFenetreReservation);
HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
HAFenetreAffichage=create_HAFenetreAffichage();

gtk_widget_show(HAFenetreAffichage);

HAtreeview=lookup_widget(HAFenetreAffichage,"HAtreeview");

HAafficher_vol(HAtreeview);
}


/*******************************************************************/ 




void on_HAbuttonAjout_clicked     (GtkWidget       *objet, gpointer         user_data)
{


GtkWidget *input1, *input2, *input3,*output;
GtkWidget *HAFenetreReservation;

GtkWidget *HAspinbuttonJour;
GtkWidget *HAspinbuttonMois;
GtkWidget *HAspinbuttonAnnee;
GtkWidget *HAspinbuttonNbreSiege;

GtkWidget *HAcomboboxDepart;
GtkWidget *HAcomboboxDestination;
GtkWidget *HAcomboboxDatedepart;
GtkWidget *HAcomboboxDatearrive;
GtkWidget *HAcomboboxCompagnie;
GtkWidget *HAcomboboxPrix;

HAvol v;
int x;


HAFenetreReservation=lookup_widget(objet,"HAFenetreReservation");

input1=lookup_widget(objet,"HAentryNom");
input2=lookup_widget(objet,"HAentryPrenom");
input3=lookup_widget(objet,"HAentryCin");


strcpy(v.HANom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.HAPrenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.HACin,gtk_entry_get_text(GTK_ENTRY(input3)));

	HAspinbuttonJour=lookup_widget(objet, "HAspinbuttonJour");
	HAspinbuttonMois=lookup_widget(objet, "HAspinbuttonMois");
	HAspinbuttonAnnee=lookup_widget(objet, "HAspinbuttonAnnee");
	HAspinbuttonNbreSiege=lookup_widget(objet, "HAspinbuttonNbreSiege");

	HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");
	HAcomboboxDestination=lookup_widget(objet, "HAcomboboxDestination");
	HAcomboboxDatedepart=lookup_widget(objet, "HAcomboboxDatedepart");
	HAcomboboxDatearrive=lookup_widget(objet, "HAcomboboxDatearrive");
	HAcomboboxCompagnie=lookup_widget(objet, "HAcomboboxCompagnie");
	HAcomboboxPrix=lookup_widget(objet, "HAcomboboxPrix");

	v.HAdateresr.HAjour= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonJour));
	v.HAdateresr.HAmois= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonMois));
	v.HAdateresr.HAannee= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonAnnee));
	v.HAnombre= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonNbreSiege));

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart))!=-1)
	{ strcpy(v.HAdepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDestination))!=-1)
	{ strcpy(v.HAdestination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDatedepart))!=-1)
	{ strcpy(v.HAdatedepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDatedepart)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDatearrive))!=-1)
	{ strcpy(v.HAdateretour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDatearrive)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxCompagnie))!=-1)
	{ strcpy(v.HAcompagnie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxCompagnie)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxPrix))!=-1)
	{ strcpy(v.HAprix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxPrix)));}

v.HAprixt=HAcalculprix(v);
output=lookup_widget(objet,"HAlabelcontroleres");

if ( (strlen(v.HANom)==0) || (strlen(v.HAPrenom)==0) || (strlen(v.HACin)==0) )  
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}

else
{
x=HAajouter_vol(v);
if (x==1)
{
gtk_label_set_text(GTK_LABEL(output),"Votre reservation a ete enregistre avec succes !!");
}
else if (x!=1)
{
gtk_label_set_text(GTK_LABEL(output),"Nombre de siege indisponible !! ");
}
}
}



/*******************************************************************/ 



void on_HAbuttonModifier_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichage;
GtkWidget *HAFenetreModification;


HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
gtk_widget_destroy(HAFenetreAffichage);

HAFenetreModification=lookup_widget(objet,"HAFenetreModification");
HAFenetreModification=create_HAFenetreModification();

gtk_widget_show(HAFenetreModification);
}


/*******************************************************************/ 




void on_HAbuttonSupprimer_clicked     (GtkWidget       *objet, gpointer         selection)
{
GtkWidget *HAFenetreAffichage;
GtkWidget *HAtreeview;
HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
HAtreeview=lookup_widget(HAFenetreAffichage,"HAtreeview");
HAsupprimervol(HAtreeview);

}



/*******************************************************************/ 



void on_HAbuttonRetour_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichage;
GtkWidget *HAFenetreReservation;


HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
gtk_widget_destroy(HAFenetreAffichage);

HAFenetreReservation=lookup_widget(objet,"HAFenetreReservation");
HAFenetreReservation=create_HAFenetreReservation();

gtk_widget_show(HAFenetreReservation);
}


/*******************************************************************/ 




void on_HAbuttonRemplir_clicked     (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAcomboboxDepart;
char depart[50][50];
int x,i;

HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");

x=HAFillDepart(depart);
for(i=0;i<=x;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDepart),0);
for(i=0;i<x;i++)
{ gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDepart),_(depart[i]));}
}

/*********************************************************************/


void on_HAbuttonConfirmerp_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxDepart;
GtkWidget *HAcomboboxDestination;
GtkWidget *output;
char destination[100][100];
char depart[100];
int i,y;
output=lookup_widget(objet,"HAlabelcontroleres");
	HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");
	HAcomboboxDestination=lookup_widget(objet, "HAcomboboxDestination");
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart))!=-1)
	{
strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));
y=HAFillDestination(destination,depart);
for(i=0;i<=y;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDestination),0);
for(i=0;i<y;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDestination),_(destination[i]));
	}
else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}

}

/************************************************************************/


void on_HAbuttonConfirmerd_clicked     (GtkWidget       *objet, gpointer         user_data)
{
HAvol v;
GtkWidget *HAcomboboxDepart;
GtkWidget *HAcomboboxDestination;
GtkWidget *HAcomboboxDatedepart;
GtkWidget *HAcomboboxDatearrive;
GtkWidget *HAcomboboxCompagnie;
GtkWidget *HAcomboboxPrix;
GtkWidget *output;


char datedepart[100][100];
char datearrive[100][100];
char compagnie[100][100];
char PRIX[100][100];
char depart[100];
char destination[100];
int i,d,r,c,p;
	output=lookup_widget(objet,"HAlabelcontroleres");
	HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");
	HAcomboboxDestination=lookup_widget(objet, "HAcomboboxDestination");
	HAcomboboxDatedepart=lookup_widget(objet, "HAcomboboxDatedepart");
	HAcomboboxDatearrive=lookup_widget(objet, "HAcomboboxDatearrive");
	HAcomboboxCompagnie=lookup_widget(objet, "HAcomboboxCompagnie");
	HAcomboboxPrix=lookup_widget(objet, "HAcomboboxPrix");
	

	if ( (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDestination))!=-1) &&  (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart))!=-1) )
	{
strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));
strcpy(destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination)));

d=HAFillDatedepart(datedepart,destination,depart);
r=HAFillDatearrive(datearrive,destination,depart);
c=HAFillCompagnie(compagnie,destination,depart);
p=HAFillPrix(PRIX,destination,depart);

for(i=0;i<=d;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDatedepart),0);
for(i=0;i<d;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDatedepart),_(datedepart[i]));

for(i=0;i<=r;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDatearrive),0);
for(i=0;i<r;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDatearrive),_(datearrive[i]));

for(i=0;i<=c;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxCompagnie),0);
for(i=0;i<c;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxCompagnie),_(compagnie[i]));

for(i=0;i<=p;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxPrix),0);
for(i=0;i<p;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxPrix),_(PRIX[i]));
	}

else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}

}

/****************************************************************************/




void on_HAbuttonOK3_clicked     (GtkWidget       *objet, gpointer         user_data)
{


char depart[50][50];
GtkWidget *HAcomboboxDepart3;

int x,i;

HAcomboboxDepart3=lookup_widget(objet, "HAcomboboxDepart3");

x=HAFillDepart(depart);
for(i=0;i<=x;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDepart3),0);
for(i=0;i<x;i++)
{ gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDepart3),_(depart[i]));}
}


/**************************************************************/



void on_HAbuttonConfirmerDepart3_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxDepart3;
GtkWidget *HAcomboboxDestination3;
GtkWidget *output;
char destination[100][100];
char depart[100];
int i,y;

	output=lookup_widget(objet,"HAlabelmod80");
	HAcomboboxDepart3=lookup_widget(objet, "HAcomboboxDepart3");
	HAcomboboxDestination3=lookup_widget(objet, "HAcomboboxDestination3");
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart3))!=-1)
	{
strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart3)));
y=HAFillDestination(destination,depart);
for(i=0;i<=y;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDestination3),0);
for(i=0;i<y;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDestination3),_(destination[i]));
	}

else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}

}

/**************************************************************/


void on_HAbuttonConfirmerDestination3_clicked     (GtkWidget       *objet, gpointer         user_data)
{
HAvol v;
GtkWidget *HAcomboboxDepart3;
GtkWidget *HAcomboboxDestination3;
GtkWidget *HAcomboboxDatedepart3;
GtkWidget *HAcomboboxDateretour3;
GtkWidget *HAcomboboxCompagnie3;
GtkWidget *HAcomboboxPrix3;
GtkWidget *output;


char datedepart[100][100];
char datearrive[100][100];
char compagnie[100][100];
char PRIX[100][100];
char depart[100];
char destination[100];
int i,d,r,c,p;

	output=lookup_widget(objet,"HAlabelmod80");

	HAcomboboxDepart3=lookup_widget(objet, "HAcomboboxDepart3");
	HAcomboboxDestination3=lookup_widget(objet, "HAcomboboxDestination3");
	HAcomboboxDatedepart3=lookup_widget(objet, "HAcomboboxDatedepart3");
	HAcomboboxDateretour3=lookup_widget(objet, "HAcomboboxDateretour3");
	HAcomboboxCompagnie3=lookup_widget(objet, "HAcomboboxCompagnie3");
	HAcomboboxPrix3=lookup_widget(objet, "HAcomboboxPrix3");
	

	if ( (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDestination3))!=-1) &&  (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart3))!=-1) )
	{
strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart3)));
strcpy(destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination3)));

d=HAFillDatedepart(datedepart,destination,depart);
r=HAFillDatearrive(datearrive,destination,depart);
c=HAFillCompagnie(compagnie,destination,depart);
p=HAFillPrix(PRIX,destination,depart);

for(i=0;i<=d;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDatedepart3),0);
for(i=0;i<d;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDatedepart3),_(datedepart[i]));

for(i=0;i<=r;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxDateretour3),0);
for(i=0;i<r;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDateretour3),_(datearrive[i]));

for(i=0;i<=c;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxCompagnie3),0);
for(i=0;i<c;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxCompagnie3),_(compagnie[i]));

for(i=0;i<=p;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxPrix3),0);
for(i=0;i<p;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxPrix3),_(PRIX[i]));
	}
else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}
}


/**************************************************************/



void on_HAbuttonApply3_clicked     (GtkWidget       *objet, gpointer         user_data)
{



GtkWidget *input1, *input2, *input3,*input6,*output;
GtkWidget *HAFenetreModification;



GtkWidget *HAspinbuttonJour3;
GtkWidget *HAspinbuttonMois3;
GtkWidget *HAspinbuttonAnnee3;
GtkWidget *HAspinbuttonNombre3;

GtkWidget *HAcomboboxDepart3;
GtkWidget *HAcomboboxDestination3;
GtkWidget *HAcomboboxDatedepart3;
GtkWidget *HAcomboboxDateretour3;
GtkWidget *HAcomboboxCompagnie3;
GtkWidget *HAcomboboxPrix3;
HAvol v;
char cin[20];
int x=0;


HAFenetreModification=lookup_widget(objet,"HAFenetreModification");

input1=lookup_widget(objet,"HAentryNom3");
input2=lookup_widget(objet,"HAentryPrenom3");
input3=lookup_widget(objet,"HAentryCin3");


strcpy(v.HANom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.HAPrenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.HACin,gtk_entry_get_text(GTK_ENTRY(input3)));

	HAspinbuttonJour3=lookup_widget(objet, "HAspinbuttonJour3");
	HAspinbuttonMois3=lookup_widget(objet, "HAspinbuttonMois3");
	HAspinbuttonAnnee3=lookup_widget(objet, "HAspinbuttonAnnee3");
	HAspinbuttonNombre3=lookup_widget(objet, "HAspinbuttonNombre3");

	HAcomboboxDepart3=lookup_widget(objet, "HAcomboboxDepart3");
	HAcomboboxDestination3=lookup_widget(objet, "HAcomboboxDestination3");
	HAcomboboxDatedepart3=lookup_widget(objet, "HAcomboboxDatedepart3");
	HAcomboboxDateretour3=lookup_widget(objet, "HAcomboboxDateretour3");
	HAcomboboxCompagnie3=lookup_widget(objet, "HAcomboboxCompagnie3");
	HAcomboboxPrix3=lookup_widget(objet, "HAcomboboxPrix3");

	v.HAdateresr.HAjour= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonJour3));
	v.HAdateresr.HAmois= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonMois3));
	v.HAdateresr.HAannee= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonAnnee3));
	v.HAnombre= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonNombre3));


	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDepart3))!=-1)
	{ strcpy(v.HAdepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart3)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDestination3))!=-1)
	{ strcpy(v.HAdestination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination3)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDatedepart3))!=-1)
	{ strcpy(v.HAdatedepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDatedepart3)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxDateretour3))!=-1)
	{ strcpy(v.HAdateretour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDateretour3)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxCompagnie3))!=-1)
	{ strcpy(v.HAcompagnie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxCompagnie3)));}

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxPrix3))!=-1)
	{ strcpy(v.HAprix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxPrix3)));}


input6=lookup_widget(objet,"HAentryCin2");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input6)));

output=lookup_widget(objet,"HAlabelmod80");
v.HAprixt=HAcalculprix(v);

if ( (strlen(v.HANom)==0) || (strlen(v.HAPrenom)==0) || (strlen(v.HACin)==0) )  
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}



else 
	{
x= HAmodifiervol(cin, v);


if (x!=1)
{
gtk_label_set_text(GTK_LABEL(output),"Verifier votre numero de CIN !!");
}
else if (x==1)
{


gtk_label_set_text(GTK_LABEL(output),"Modification a eu lieu avec succes!");

}
	}

}


/**************************************************************/



void on_HAbuttonRetour3_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichage;
GtkWidget *HAFenetreModification;
GtkWidget *HAtreeview;

HAFenetreModification=lookup_widget(objet,"HAFenetreModification");
gtk_widget_destroy(HAFenetreModification);

HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
HAFenetreAffichage=create_HAFenetreAffichage();

gtk_widget_show(HAFenetreAffichage);
HAtreeview=lookup_widget(HAFenetreAffichage,"HAtreeview");

HAafficher_vol(HAtreeview);
}


void
on_HAbuttonReserverVol_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreReservation;
GtkWidget *HAMenuAgent;
GtkWidget *HAtreeview;

HAMenuAgent=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(HAMenuAgent);

HAFenetreReservation=lookup_widget(objet,"HAFenetreReservation");
HAFenetreReservation=create_HAFenetreReservation();

gtk_widget_show(HAFenetreReservation);



}







void
on_HAbuttonReservervoiture_clicked (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreReservationvoiture;
GtkWidget *HAMenuAgent;
GtkWidget *HAtreeview;

HAMenuAgent=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(HAMenuAgent);

HAFenetreReservationvoiture=lookup_widget(objet,"HAFenetreReservationvoiture");
HAFenetreReservationvoiture=create_HAFenetreReservationvoiture();

gtk_widget_show(HAFenetreReservationvoiture);
}




/************************************************************/


void on_HAbuttonFenetreRech_clicked         (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichage;
GtkWidget *HAFenetreRecherchevol;


HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
gtk_widget_destroy(HAFenetreAffichage);

HAFenetreRecherchevol=lookup_widget(objet,"HAFenetreRecherchevol");
HAFenetreRecherchevol=create_HAFenetreRecherchevol();

gtk_widget_show(HAFenetreRecherchevol);
}

/***************************************************************/



void on_HAbuttonRechercheVol_clicked        (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *input1,*output;
GtkWidget *HAtreeviewRechercheVol;

int x;
char cin[100];


input1=lookup_widget(objet,"HAentryCinRecherchevol");

output=lookup_widget(objet,"HAlabelErreurVol");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));

HAtreeviewRechercheVol=lookup_widget(objet,"HAtreeviewRechercheVol");

x=HARajouter_vol(cin);
if (x==1)
{
HARafficher_vol(HAtreeviewRechercheVol);
gtk_label_set_text(GTK_LABEL(output),"Reservation trouve !!");
}
else if (x!=1)
{
gtk_label_set_text(GTK_LABEL(output),"Aucune reservation trouve, Verifier le numero de votre CIN !! ");
}

}



/*************************************************************/

void on_HAbuttonRetourRechercheVol_clicked  (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAFenetreAffichage;
GtkWidget *HAFenetreRecherchevol;
GtkWidget *HAtreeview;

HAFenetreRecherchevol=lookup_widget(objet,"HAFenetreRecherchevol");
gtk_widget_destroy(HAFenetreRecherchevol);

HAFenetreAffichage=lookup_widget(objet,"HAFenetreAffichage");
HAFenetreAffichage=create_HAFenetreAffichage();
gtk_widget_show(HAFenetreAffichage);
HAtreeview=lookup_widget(HAFenetreAffichage,"HAtreeview");

HAafficher_vol(HAtreeview);

}

/******************************             Voiture           ********************************/


void
on_HAbuttonConfirmMarque_clicked       (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxmarquevoiture;
GtkWidget *HAcomboboxprixvoiture;
GtkWidget *output;
char PRIX[100][100];
char Marque[100];
int i,y;
	output =lookup_widget(objet,"HAlabelerreurvoiture");
	HAcomboboxmarquevoiture=lookup_widget(objet, "HAcomboboxmarquevoiture");
	HAcomboboxprixvoiture=lookup_widget(objet, "HAcomboboxprixvoiture");
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxmarquevoiture))!=-1)
{
strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxmarquevoiture)));
y=HAFillPrixvoiture(PRIX,Marque);
for(i=0;i<=y;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxprixvoiture),0);
for(i=0;i<y;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxprixvoiture),_(PRIX[i]));

}
else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}
}

/*****************************************************************/


void
on_HAbuttonRemplirmarque_clicked       (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxmarquevoiture;
char Marque[50][50];
int x,i;

HAcomboboxmarquevoiture=lookup_widget(objet, "HAcomboboxmarquevoiture");

x=HAFillmarque(Marque);
for(i=0;i<=x;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxmarquevoiture),0);
for(i=0;i<x;i++)
{ gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxmarquevoiture),_(Marque[i]));}

}


/*****************************************************************/

void
on_Habuttonajoutervoiture_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *input1, *input2, *input3,*output;
GtkWidget *HAFenetreReservationvoiture;

GtkWidget *HAspinbuttonjvoiture;
GtkWidget *HAspinbuttonmvoiture;
GtkWidget *HAspinbuttonavoiture;
GtkWidget *HAspinbuttonNombredujour;

GtkWidget *HAcomboboxmarquevoiture;
GtkWidget *HAcomboboxprixvoiture;


HAvoiture v;


HAFenetreReservationvoiture=lookup_widget(objet,"HAFenetreReservationvoiture");

input1=lookup_widget(objet,"HAentrynomvoiture");
input2=lookup_widget(objet,"Haentryprenomvoiture");
input3=lookup_widget(objet,"HAentrycinvoiture");


strcpy(v.HANomv,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.HAPrenomv,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.HACinv,gtk_entry_get_text(GTK_ENTRY(input3)));

	HAspinbuttonjvoiture=lookup_widget(objet, "HAspinbuttonjvoiture");
	HAspinbuttonmvoiture=lookup_widget(objet, "HAspinbuttonmvoiture");
	HAspinbuttonavoiture=lookup_widget(objet, "HAspinbuttonavoiture");
	HAspinbuttonNombredujour=lookup_widget(objet, "HAspinbuttonNombredujour");

	HAcomboboxmarquevoiture=lookup_widget(objet, "HAcomboboxmarquevoiture");
	HAcomboboxprixvoiture=lookup_widget(objet, "HAcomboboxprixvoiture");


	v.HAdateresrv.HAjour= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonjvoiture));
	v.HAdateresrv.HAmois= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonmvoiture));
	v.HAdateresrv.HAannee= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonavoiture));
	v.HAnombredujourv= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonNombredujour));

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxmarquevoiture))!=-1)
	{strcpy(v.HAmarquev,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxmarquevoiture)));}
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxprixvoiture))!=-1)
	{strcpy(v.HAprixv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxprixvoiture)));}


	v.HAprixtv=HAcalculprixv(v);

output =lookup_widget(objet,"HAlabelerreurvoiture");
if ( (strlen(v.HANomv)==0) || (strlen(v.HAPrenomv)==0) || (strlen(v.HACinv)==0) )  
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}
else 
{
HAajouter_voiture(v);
}


}


/*****************************************************************/

void
on_HAbuttonAffichervoiture_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreReservationvoiture;
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAtreeviewvoiture;

HAFenetreReservationvoiture=lookup_widget(objet,"HAFenetreReservationvoiture");

gtk_widget_destroy(HAFenetreReservationvoiture);
HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
HAFenetreAffichagevoiture=create_HAFenetreAffichagevoiture();

gtk_widget_show(HAFenetreAffichagevoiture);

HAtreeviewvoiture=lookup_widget(HAFenetreAffichagevoiture,"HAtreeviewvoiture");

HAafficher_voiture(HAtreeviewvoiture);
}


/*****************************************************************/



void
on_HAbuttonmodifiervoiture_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAFenetreModificationVoiture;


HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
gtk_widget_destroy(HAFenetreAffichagevoiture);

HAFenetreModificationVoiture=lookup_widget(objet,"HAFenetreModificationVoiture");
HAFenetreModificationVoiture=create_HAFenetreModificationVoiture();

gtk_widget_show(HAFenetreModificationVoiture);
}


/*****************************************************************/


void
on_HAbuttonSupprimervoiture_clicked    (GtkWidget       *objet, gpointer         selection)
{
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAtreeviewvoiture;
HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
HAtreeviewvoiture=lookup_widget(HAFenetreAffichagevoiture,"HAtreeviewvoiture");
HAsupprimervoiture(HAtreeviewvoiture);
}


/*****************************************************************/


void
on_HAbuttonRecherchevoiture_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAFenetreRechercheVoiture;


HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
gtk_widget_destroy(HAFenetreAffichagevoiture);

HAFenetreRechercheVoiture=lookup_widget(objet,"HAFenetreRechercheVoiture");
HAFenetreRechercheVoiture=create_HAFenetreRechercheVoiture();

gtk_widget_show(HAFenetreRechercheVoiture);
}


/*****************************************************************/



void
on_HAbuttonconfirmmodmarque_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxmodMarquevoiture;
GtkWidget *HAcomboboxmodPrixvoiture;
GtkWidget *output;	
char PRIX[100][100];
char Marque[100];
int i,y;

	output=lookup_widget(objet,"HAlabelerreurMod");
	HAcomboboxmodMarquevoiture=lookup_widget(objet, "HAcomboboxmodMarquevoiture");
	HAcomboboxmodPrixvoiture=lookup_widget(objet, "HAcomboboxmodPrixvoiture");
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxmodMarquevoiture))!=-1)
{
strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxmodMarquevoiture)));
y=HAFillPrixvoiture(PRIX,Marque);
for(i=0;i<=y;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxmodPrixvoiture),0);
for(i=0;i<y;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxmodPrixvoiture),_(PRIX[i]));
}
else 
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}

}

/*****************************************************************/



void
on_HAbuttonConfirmmodCin_clicked      (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxmodMarquevoiture;

char Marque[50][50];
int x,i;


HAcomboboxmodMarquevoiture=lookup_widget(objet, "HAcomboboxmodMarquevoiture");

x=HAFillmarque(Marque);
for(i=0;i<=x;i++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (HAcomboboxmodMarquevoiture),0);
for(i=0;i<x;i++)
{ gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxmodMarquevoiture),_(Marque[i]));}

}

/*****************************************************************/



void
on_HAbuttonApplymodvoiture_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *input1, *input2, *input3,*input6,*output;
GtkWidget *HAFenetreModificationVoiture;

GtkWidget *HAspinbuttonmodjvoiture;
GtkWidget *HAspinbuttonmodmvoiture;
GtkWidget *HAspinbuttonmodavoiture;
GtkWidget *HAspinbuttonmodnombrevoiture;

GtkWidget *HAcomboboxmodMarquevoiture;
GtkWidget *HAcomboboxmodPrixvoiture;


HAvoiture v;
char cin[20];
int x=0;


HAFenetreModificationVoiture=lookup_widget(objet,"HAFenetreModificationVoiture");

input1=lookup_widget(objet,"HAentryNommodvoiture");
input2=lookup_widget(objet,"HAentryPrenommodvoiture");
input3=lookup_widget(objet,"HAentryCinmodvoiture1");


strcpy(v.HANomv,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.HAPrenomv,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.HACinv,gtk_entry_get_text(GTK_ENTRY(input3)));

	HAspinbuttonmodjvoiture=lookup_widget(objet, "HAspinbuttonmodjvoiture");
	HAspinbuttonmodmvoiture=lookup_widget(objet, "HAspinbuttonmodmvoiture");
	HAspinbuttonmodavoiture=lookup_widget(objet, "HAspinbuttonmodavoiture");
	HAspinbuttonmodnombrevoiture=lookup_widget(objet, "HAspinbuttonmodnombrevoiture");

	HAcomboboxmodMarquevoiture=lookup_widget(objet, "HAcomboboxmodMarquevoiture");
	HAcomboboxmodPrixvoiture=lookup_widget(objet, "HAcomboboxmodPrixvoiture");


	v.HAdateresrv.HAjour= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonmodjvoiture));
	v.HAdateresrv.HAmois= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonmodmvoiture));
	v.HAdateresrv.HAannee= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonmodavoiture));
	v.HAnombredujourv= gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(HAspinbuttonmodnombrevoiture));

	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxmodMarquevoiture))!=-1)
	{strcpy(v.HAmarquev,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxmodMarquevoiture)));}
	if (gtk_combo_box_get_active (GTK_COMBO_BOX(HAcomboboxmodPrixvoiture))!=-1)
	{strcpy(v.HAprixv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxmodPrixvoiture)));}


	v.HAprixtv=HAcalculprixv(v);


input6=lookup_widget(objet,"HAentryCinmodvoiture");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input6)));

output=lookup_widget(objet,"HAlabelerreurMod");

if ( (strlen(v.HANomv)==0) || (strlen(v.HAPrenomv)==0) || (strlen(v.HACinv)==0) )  
{
gtk_label_set_text(GTK_LABEL(output),"Verifier les champs vides !!");
}
else 
{
x= HAmodifiervoiture(cin, v);


if (x!=1)
{
gtk_label_set_text(GTK_LABEL(output),"Verifier votre numero de CIN !!");
}
else if (x==1)
{


gtk_label_set_text(GTK_LABEL(output),"Modification a eu lieu avec succes!");
}
}
}





/*****************************************************************/


void
on_HAbuttonretourmodvoiture_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAFenetreModificationVoiture;
GtkWidget *HAtreeviewvoiture;

HAFenetreModificationVoiture=lookup_widget(objet,"HAFenetreModificationVoiture");
gtk_widget_destroy(HAFenetreModificationVoiture);

HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
HAFenetreAffichagevoiture=create_HAFenetreAffichagevoiture();

gtk_widget_show(HAFenetreAffichagevoiture);
HAtreeviewvoiture=lookup_widget(HAFenetreAffichagevoiture,"HAtreeviewvoiture");

HAafficher_voiture(HAtreeviewvoiture);
}

/*****************************************************************/


void
on_HAbuttonrecherchevoiture_clicked    (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *input1,*output;
GtkWidget *HAtreeviewrecherchevoiture;

int x;
char cin[100];


input1=lookup_widget(objet,"HAentryRecherchevoiture");

output=lookup_widget(objet,"HAlabelErreurRecherchevoiture");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));

HAtreeviewrecherchevoiture=lookup_widget(objet,"HAtreeviewrecherchevoiture");

x=HARajouter_voiture(cin);
if (x==1)
{
HARafficher_voiture(HAtreeviewrecherchevoiture);
gtk_label_set_text(GTK_LABEL(output),"Reservation trouve !!");
}
else if (x!=1)
{
gtk_label_set_text(GTK_LABEL(output),"Aucune reservation trouve, Verifier le numero de votre CIN !! ");
}
}

/*****************************************************************/


void
on_HAbuttonRetourRecherchevoiture_clicked (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAFenetreRechercheVoiture;
GtkWidget *HAtreeviewvoiture;

HAFenetreRechercheVoiture=lookup_widget(objet,"HAFenetreRechercheVoiture");
gtk_widget_destroy(HAFenetreRechercheVoiture);

HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
HAFenetreAffichagevoiture=create_HAFenetreAffichagevoiture();
gtk_widget_show(HAFenetreAffichagevoiture);

HAtreeviewvoiture=lookup_widget(HAFenetreAffichagevoiture,"HAtreeviewvoiture");

HAafficher_voiture(HAtreeviewvoiture);
}

/***********************************************************************************/

void
on_HAbuttonRetourResvoiture_clicked    (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAFenetreAffichagevoiture;
GtkWidget *HAFenetreReservationvoiture;

HAFenetreAffichagevoiture=lookup_widget(objet,"HAFenetreAffichagevoiture");
gtk_widget_destroy(HAFenetreAffichagevoiture);

HAFenetreReservationvoiture=lookup_widget(objet,"HAFenetreReservationvoiture");
HAFenetreReservationvoiture=create_HAFenetreReservationvoiture();
gtk_widget_show(HAFenetreReservationvoiture);

}



/******************************************************************/



void on_HAbuttonRetourMenu1_clicked         (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAFenetreReservation;
GtkWidget *HAMenuAgent;


HAFenetreReservation=lookup_widget(objet,"HAFenetreReservation");
gtk_widget_destroy(HAFenetreReservation);

HAMenuAgent=lookup_widget(objet,"HAMenuAgent");
HAMenuAgent=create_HAMenuAgent();
gtk_widget_show(HAMenuAgent);

}

/************************************************************************************/


void
on_HAbuttonRetourMenu2_clicked         (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAFenetreReservationvoiture;
GtkWidget *HAMenuAgent;


HAFenetreReservationvoiture=lookup_widget(objet,"HAFenetreReservationvoiture");
gtk_widget_destroy(HAFenetreReservationvoiture);

HAMenuAgent=lookup_widget(objet,"HAMenuAgent");
HAMenuAgent=create_HAMenuAgent();
gtk_widget_show(HAMenuAgent);

}



/********************************************************************************/



void
on_HAbuttonAjouterPres_clicked  (GtkWidget       *objet, gpointer         user_data)
{

/*
GtkWidget *window1;
Gtkwidget *window2;


window1=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(window1);

window2=lookup_widget(objet,"SALMEN HSAIRI");
gtk_widget_show(window2);



*/
}


/********************************************************************************/




void
on_HAbuttonConsulterRec_clicked      (GtkWidget       *objet, gpointer         user_data)
{
/*
GtkWidget *window1;
Gtkwidget *window2;


window1=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(window1);

window2=lookup_widget(objet,"YOSRI KANZARI");
gtk_widget_show(window2);



*/
}



/********************************************************************************/



void
on_HAbuttonDeconnexion_clicked (GtkWidget       *objet, gpointer         user_data)
{
/*
GtkWidget *window1;
Gtkwidget *window2;


window1=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(window1);

window2=lookup_widget(objet,"ANwindowAuthentification");
gtk_widget_show(window2);



*/

}


/***********************************************************************************/


void
on_HAbuttonFenetrevoitureTakwa_clicked (GtkWidget       *objet, gpointer         user_data)
{
/*
GtkWidget *window1;
Gtkwidget *window2;


window1=lookup_widget(objet,"HAMenuAgent");
gtk_widget_destroy(window1);

window2=lookup_widget(objet," Takwa ******");
gtk_widget_show(window2);



*/
}


/***********************************************************************************/



/******************** FIN TRAVAIL DE HEDI AROUA **********************************/



/********************************************************************************/








/***********************************************************************************/



/******************** Debut travail Arbi Nouri **********************************/



/********************************************************************************/









#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reservation.h"


/*******************************************************************/ 



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


GtkWidget *input1, *input2, *input3;
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

	strcpy(v.HAdepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));
	strcpy(v.HAdestination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination)));
	strcpy(v.HAdatedepart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDatedepart)));
	strcpy(v.HAdateretour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDatearrive)));
	strcpy(v.HAcompagnie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxCompagnie)));
	strcpy(v.HAprix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxPrix)));

HAajouter_vol(v);
}



/*******************************************************************/ 



void on_HAbuttonModifier_clicked     (GtkWidget       *objet, gpointer         user_data)
{

}


/*******************************************************************/ 




void on_HAbuttonSupprimer_clicked     (GtkWidget       *objet, gpointer         user_data)
{

}



/*******************************************************************/ 



void on_HAbuttonRetour_clicked     (GtkWidget       *objet, gpointer         user_data)
{

}


/*******************************************************************/ 




void on_HAbuttonRemplir_clicked     (GtkWidget       *objet, gpointer         user_data)
{

GtkWidget *HAcomboboxDepart;
char depart[50][50];
int x,i;

HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");

x=HAFillDepart(depart);
for(i=0;i<x;i++)
{ gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDepart),_(depart[i]));}
}

/*********************************************************************/


void on_HAbuttonConfirmerp_clicked     (GtkWidget       *objet, gpointer         user_data)
{
GtkWidget *HAcomboboxDepart;
GtkWidget *HAcomboboxDestination;
char destination[100][100];
char depart[100];
int i,x;
	HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");
	HAcomboboxDestination=lookup_widget(objet, "HAcomboboxDestination");
strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));
x=HAFillDestination(destination,depart);
for(i=0;i<x;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDestination),_(destination[i]));
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


char datedepart[100][100];
char datearrive[100][100];
char compagnie[100][100];
char PRIX[100][100];
char depart[100];
char destination[100];
int i,d,r,c,p;

	HAcomboboxDepart=lookup_widget(objet, "HAcomboboxDepart");
	HAcomboboxDestination=lookup_widget(objet, "HAcomboboxDestination");
	HAcomboboxDatedepart=lookup_widget(objet, "HAcomboboxDatedepart");
	HAcomboboxDatearrive=lookup_widget(objet, "HAcomboboxDatearrive");
	HAcomboboxCompagnie=lookup_widget(objet, "HAcomboboxCompagnie");
	HAcomboboxPrix=lookup_widget(objet, "HAcomboboxPrix");
	


strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDepart)));
strcpy(destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(HAcomboboxDestination)));

d=HAFillDatedepart(datedepart,destination,depart);
r=HAFillDatearrive(datearrive,destination,depart);
c=HAFillCompagnie(compagnie,destination,depart);
p=HAFillPrix(PRIX,destination,depart);

for(i=0;i<d;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDatedepart),_(datedepart[i]));

for(i=0;i<r;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxDatearrive),_(datearrive[i]));

for(i=0;i<c;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxCompagnie),_(compagnie[i]));

for(i=0;i<p;i++)
gtk_combo_box_append_text (GTK_COMBO_BOX (HAcomboboxPrix),_(PRIX[i]));

}


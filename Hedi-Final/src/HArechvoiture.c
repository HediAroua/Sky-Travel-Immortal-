#include <stdio.h>
#include <string.h>
#include "HAreservation.h"
#include "HARecherchevol.h"
#include <gtk/gtk.h>


enum
{
	NOM,
	PRENOM,
	CIN,
	DATERESR,
	MARQUE,
	PRIX,
	NOMBRE,
	PRIXT,


	COLUMNS
};

/******************** 	AJOUT HEDI ************************************/



int HARajouter_voiture( char cin[100])
{
 HAvoiture v;
 int s;
 FILE *f,*f1;
 f=fopen("resv.txt","r");
 f1=fopen("HArechv.txt","w");

while(fscanf(f,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,&v.HAdateresrv.HAjour,&v.HAdateresrv.HAmois,&v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,&v.HAnombredujourv,&v.HAprixtv)!=EOF);
{ if (strcmp(cin,v.HACinv)==0)
{
  fprintf(f1,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,v.HAdateresrv.HAjour,v.HAdateresrv.HAmois,v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,v.HAnombredujourv, v.HAprixtv);
s=1;
}
else 
{
s=0;
}
 fclose(f);
 fclose(f1);
 }
return s;
}


/******************** 	AFFICHAGE HEDI ************************************/

void HARafficher_voiture(GtkWidget *liste)
{

 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

char Nom[100];
char Prenom[100];
char Cin[100];
char dateresr[100];
char marque[100];
char prix[100];
int nombre;
int prixt;


 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);
 if(store==NULL)
 {
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom", renderer, "text",NOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" Prenom", renderer, "text", PRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" CIN", renderer, "text", CIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de reservation", renderer, "text",DATERESR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Marque", renderer, "text",MARQUE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prix du jour", renderer, "text",PRIX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nombre de jour", renderer, "text",NOMBRE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prix totale", renderer, "text",PRIXT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



 store= gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);

 f= fopen("HArechv.txt","r");

 if(f==NULL)
 {
	return;
 }

 else

 { f = fopen("HArechv.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %d %d\n", Nom,Prenom,Cin,dateresr,marque,prix,&nombre,&prixt)!=EOF)
	{
          gtk_list_store_append (store,&iter);
          gtk_list_store_set (store, &iter, NOM, Nom, PRENOM, Prenom, CIN, Cin, DATERESR, dateresr,MARQUE,marque,PRIX,prix,NOMBRE,nombre,PRIXT,prixt, -1);
	}
  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  g_object_unref (store);
 }

}
}



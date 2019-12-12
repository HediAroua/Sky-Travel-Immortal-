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
	DEPART,
	DESTINATION,
	DATEDEPART,
	DATERETOUR,
	COMPAGNIE,
	PRIX,
	NOMBRESIEGE,
	PRIXT,


	COLUMNS
};


/******************** 	AJOUT HEDI ************************************/



int HARajouter_vol( char cin[100])
{
 HAvol v;
 int s;
 FILE *f,*f1;
 f=fopen("res.txt","r");
 f1=fopen("HArech.txt","w");

while(fscanf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,&v.HAdateresr.HAjour,&v.HAdateresr.HAmois,&v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,&v.HAnombre,&v.HAprixt)!=EOF);
{ if (strcmp(cin,v.HACin)==0)
{
 fprintf(f1,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre, v.HAprixt);
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

void HARafficher_vol(GtkWidget *liste)
{

 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

char Nom[100];
char Prenom[100];
char Cin[100];
char dateresr[100];
char depart[100];
char destination[100];
char datedepart[100];
char dateretour[100];
char compagnie[100];
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
	column = gtk_tree_view_column_new_with_attributes(" Depart", renderer, "text",DEPART, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Destination", renderer, "text",DESTINATION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de depart", renderer, "text",DATEDEPART, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de retour", renderer, "text",DATERETOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Compagnie", renderer, "text",COMPAGNIE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prix unitaire", renderer, "text",PRIX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nombre de siege", renderer, "text",NOMBRESIEGE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prix totale", renderer, "text",PRIXT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



 store= gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT);

 f= fopen("HArech.txt","r");

 if(f==NULL)
 {
	return;
 }

 else

 { f = fopen("HArech.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d %d\n", Nom,Prenom,Cin,dateresr,depart,destination,datedepart,dateretour,compagnie,prix,&nombre,&prixt)!=EOF)
	{
          gtk_list_store_append (store,&iter);
          gtk_list_store_set (store, &iter, NOM, Nom, PRENOM, Prenom, CIN, Cin, DATERESR, dateresr,DEPART,depart, DESTINATION, destination ,DATEDEPART,datedepart, DATERETOUR,dateretour,COMPAGNIE,compagnie,PRIX,prix,NOMBRESIEGE,nombre,PRIXT,prixt, -1);
	}
  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  g_object_unref (store);
 }


}

}



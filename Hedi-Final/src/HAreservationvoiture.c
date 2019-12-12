#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HAreservation.h"
#include "HAreservationvoiture.h"
#include "HArechvoiture.h"
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


void HAajouter_voiture(HAvoiture v)
{
 FILE *f;
 f=fopen("resv.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,v.HAdateresrv.HAjour,v.HAdateresrv.HAmois,v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,v.HAnombredujourv, v.HAprixtv);
 fclose(f);
 }

}


/******************** 	AFFICHAGE HEDI ************************************/



void HAafficher_voiture(GtkWidget *liste)
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

 f= fopen("resv.txt","r");

 if(f==NULL)
 {
	return;
 }

 else

 { f = fopen("resv.txt","a+");
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



/**********************  Depart HEDI *************************************/


int HAFillmarque(char Marque[50][50])
{FILE *f;
int x=0;
char mar[50];
char pr[50];
f= fopen("location.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s \n",mar,pr)!=EOF)
{ 
strcpy(Marque[x],mar);
x++;
}
fclose(f);
}
return x;
}



/**********************  Prix HEDI *************************************/


int HAFillPrixvoiture(char PRIX [100][100], char Marque[])

{FILE *f;
int p=0;
char mar[50];
char pr[50];
f= fopen("location.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s\n",mar,pr)!=EOF)

{if (strcmp(mar,Marque)==0) 
{strcpy(PRIX[p],pr);
p++;
}
}
fclose(f);
}
return p;
}


/********************* Supprimer Vol *************************************/

void HAsupprimervoiture(GtkWidget *liste)
{
GtkTreeSelection *selection; 
 GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  gchar *cin;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter))
		{
    
    gtk_tree_model_get(model,&iter,CIN,&cin,-1);
    gtk_list_store_remove(store, &iter);

		}
int s=0;
FILE *f,*a;
    HAvoiture v;
    f=fopen("resv.txt","r");
    a=fopen("tmphedi1.txt","w");
  if ((f!=NULL) && (a!=NULL))
{
    while(!feof(f))
        {
fscanf(f,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,&v.HAdateresrv.HAjour,&v.HAdateresrv.HAmois,&v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,&v.HAnombredujourv,&v.HAprixtv);
            if(strcmp(cin,v.HACinv)!=0)
		{
fprintf(a,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,v.HAdateresrv.HAjour,v.HAdateresrv.HAmois,v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,v.HAnombredujourv,v.HAprixtv);
		}
	}
        fclose(a);
        fclose(f);
	remove("resv.txt");
	rename("tmphedi1.txt","resv.txt");

}
}

/****************************************************/

int HAmodifiervoiture(char cin[20], HAvoiture v)
{


int s=0;
FILE *f,*z;
    HAvoiture v1;
    f=fopen("resv.txt","r");
    z=fopen("tmphedi1.txt","w");
    while(!feof(f))
        {
fscanf(f,"%s %s %s %d/%d/%d %s %s %d %d\n", v1.HANomv,v1.HAPrenomv,v1.HACinv,&v1.HAdateresrv.HAjour,&v1.HAdateresrv.HAmois,&v1.HAdateresrv.HAannee,v1.HAmarquev,v1.HAprixv,&v1.HAnombredujourv,&v1.HAprixtv);
            if(strcmp(cin,v1.HACinv)==0)
            {
fprintf(z,"%s %s %s %d/%d/%d %s %s %d %d\n", v.HANomv,v.HAPrenomv,v.HACinv,v.HAdateresrv.HAjour,v.HAdateresrv.HAmois,v.HAdateresrv.HAannee,v.HAmarquev,v.HAprixv,v.HAnombredujourv,v.HAprixtv);
s=1;
            }
else {
fprintf(z,"%s %s %s %d/%d/%d %s %s %d %d\n", v1.HANomv,v1.HAPrenomv,v1.HACinv,v1.HAdateresrv.HAjour,v1.HAdateresrv.HAmois,v1.HAdateresrv.HAannee,v1.HAmarquev,v1.HAprixv,v1.HAnombredujourv,v1.HAprixtv);
s=0;

} 
        }
        fclose(z);
        fclose(f);
	remove("resv.txt");
	rename("tmphedi1.txt","resv.txt");

return s;

}

/***************************** calcul de prixtotale *********************************/

int HAcalculprixv(HAvoiture v)
{
int p=0;
int t=0;
p = atoi(v.HAprixv);
t= p * v.HAnombredujourv;
return t;
}






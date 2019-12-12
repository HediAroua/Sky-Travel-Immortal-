#include <stdio.h>
#include <string.h>
#include "reservation.h"
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


	COLUMNS
};


/******************** 	AJOUT HEDI ************************************/


void HAajouter_vol(HAvol v)
{
 
 FILE *f;
 f=fopen("res.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre);
 fclose(f);
 }

}

/******************** 	AFFICHAGE HEDI ************************************/



void HAafficher_vol(GtkWidget *liste)
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
	column = gtk_tree_view_column_new_with_attributes(" Cin", renderer, "text", CIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" dateresr", renderer, "text",DATERESR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" depart", renderer, "text",DEPART, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" destination", renderer, "text",DESTINATION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" datedepart", renderer, "text",DATEDEPART, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" dateretour", renderer, "text",DATERETOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" compagnie", renderer, "text",COMPAGNIE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nombre", renderer, "text",NOMBRESIEGE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



 store= gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);

 f= fopen("res.txt","r");

 if(f==NULL)
 {
	return;
 }

 else

 { f = fopen("res.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d \n", Nom,Prenom,Cin,dateresr,depart,destination,datedepart,dateretour,compagnie,prix,&nombre)!=EOF)
	{
          gtk_list_store_append (store,&iter);
          gtk_list_store_set (store, &iter, NOM, Nom, PRENOM, Prenom, CIN, Cin, DATERESR, dateresr,DEPART,depart, DESTINATION, destination ,DATEDEPART,datedepart, DATERETOUR,dateretour,COMPAGNIE,compagnie,PRIX,prix,NOMBRESIEGE,nombre, -1);
	}
  fclose(f);
  gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
  g_object_unref (store);
 }

}
}



/**********************  Depart HEDI *************************************/



int HAFillDepart(char depart[50][50])
{FILE *f;
int x=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{ 
strcpy(depart[x],de);
x++;
}
fclose(f);
}
return x;
}


/**********************  Destination HEDI *************************************/
int HAFillDestination(char destination[50][50],char depart[])

{FILE *f;
int x=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{if (strcmp(de,depart)==0)
{strcpy(destination[x],a);
x++;
}
}
fclose(f);
}
return x;
}

/**********************  Datedepart HEDI *************************************/
int HAFillDatedepart(char datedepart [50][50], char destination[],char depart[])

{FILE *f;
int d=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{if ((strcmp(de,depart)==0) && (strcmp(a,destination)==0))
{strcpy(datedepart[d],dateallez);
d++;
}
}
fclose(f);
}
return d;
}

/**********************  Datearrive HEDI *************************************/

int HAFillDatearrive(char datearrive [50][50], char destination[],char depart[])

{FILE *f;
int r=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{if ((strcmp(de,depart)==0) && (strcmp(a,destination)==0))
{strcpy(datearrive[r],dateretour);
r++;
}
}
fclose(f);
}
return r;
}

/**********************  Compagnie HEDI *************************************/
int HAFillCompagnie(char compagnie [50][50], char destination[],char depart[])

{FILE *f;
int c=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{if ((strcmp(de,depart)==0) && (strcmp(a,destination)==0))
{strcpy(compagnie[c],compagnieaerienne);
c++;
}
}
fclose(f);
}
return c;
}


/**********************  Prix HEDI *************************************/

int HAFillPrix(char PRIX [50][50], char destination[],char depart[])

{FILE *f;
int p=0;
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
char prix[50];
f= fopen("vol.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %d %s \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,prix)!=EOF)
{if ((strcmp(de,depart)==0) && (strcmp(a,destination)==0))
{strcpy(PRIX[p],prix);
p++;
}
}
fclose(f);
}
return p;
}













#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HAreservation.h"
#include "HAreservationvoiture.h"
#include <gtk/gtk.h>

int HAancien=0;
int HAancien1=0;
char HAanciendepart[100];
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


int HAajouter_vol(HAvol v)
{


FILE *f1,*f2;
int x=0;
int r=0; 
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f1= fopen("vol.txt","r");
f2= fopen("tmpvol.txt","w");
if ((f1!=NULL) && (f2!=NULL))
{
while (fscanf(f1,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{ if (nbsiege >= v.HAnombre)
{ if (strcmp(de,v.HAdepart)==0)
{
HAancien=v.HAnombre;
strcpy(HAanciendepart,de);
r= nbsiege - v.HAnombre;
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,r,prix);
}
else
{
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,nbsiege,prix);
}
}
else 
{
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,nbsiege,prix);
}
}
}

 
 FILE *f;
 f=fopen("res.txt","a+");
 if(f!=NULL)
 { if (r >= v.HAnombre)
{  
 fprintf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre,v.HAprixt);
x=1;
}
else {
x=0;
}
}

 fclose(f);
 fclose(f1);
 fclose(f2);
	remove("vol.txt");
	rename("tmpvol.txt","vol.txt");

 return x;


}
/*
void HAajouter_vol(HAvol v)
{
 
 FILE *f;
 f=fopen("res.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre, v.HAprixt);
 fclose(f);
 }

}
*/

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

 f= fopen("res.txt","r");

 if(f==NULL)
 {
	return;
 }

 else

 { f = fopen("res.txt","a+");
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
int y=0;
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
if (strcmp(de,depart)==0)
{strcpy(destination[y],a);
y++;
}
}
fclose(f);
}
return y;
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


/********************* Supprimer Vol *************************************/

void HAsupprimervol(GtkWidget *liste)
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
    HAvol v,v1;
    f=fopen("res.txt","r");
    a=fopen("tmphedi.txt","w");
  if ((f!=NULL) && (a!=NULL))
{
    while(!feof(f))
        {
fscanf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,&v.HAdateresr.HAjour,&v.HAdateresr.HAmois,&v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,&v.HAnombre,&v.HAprixt);
            if(strcmp(cin,v.HACin)!=0)
		{
fprintf(a,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre,v.HAprixt);
		} 
        }
}
        fclose(a);
        fclose(f);
	remove("res.txt");
	rename("tmphedi.txt","res.txt");

}

/****************************************************/

int HAmodifiervol(char cin[20], HAvol v)
{


FILE *f1,*f2;
int x=0;
int r=0; 
char ref[50];
char de[50];
char a[50];
char dateallez[50];
char dateretour[50];
char compagnieaerienne[50];
int nbsiege;
int prix;
f1= fopen("vol.txt","r");
f2= fopen("tmpvol.txt","w");
if ((f1!=NULL) && (f2!=NULL))
{
while (fscanf(f1,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,&nbsiege,&prix)!=EOF)
{ if (nbsiege >= v.HAnombre)
{
if (strcmp(HAanciendepart,de)==0)
{ nbsiege = nbsiege + HAancien;}


if (strcmp(de,v.HAdepart)==0)
{

r= nbsiege - v.HAnombre ;
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,r,prix);
}
else
{
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,nbsiege,prix);
}
}
else 
{
fprintf(f2,"%s %s %s %s %s %s %d %d \n",ref,de,a,dateallez,dateretour,compagnieaerienne,nbsiege,prix);
}
}
}



int s=0;
FILE *f,*z;
    HAvol v1;
    f=fopen("res.txt","r");
    z=fopen("tmphedi.txt","w");
    while(!feof(f))
        {
fscanf(f,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v1.HANom,v1.HAPrenom,v1.HACin,&v1.HAdateresr.HAjour,&v1.HAdateresr.HAmois,&v1.HAdateresr.HAannee,v1.HAdepart,v1.HAdestination,v1.HAdatedepart,v1.HAdateretour,v1.HAcompagnie,v1.HAprix,&v1.HAnombre,&v1.HAprixt);
            if(strcmp(cin,v1.HACin)==0)
            {
fprintf(z,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v.HANom,v.HAPrenom,v.HACin,v.HAdateresr.HAjour,v.HAdateresr.HAmois,v.HAdateresr.HAannee,v.HAdepart,v.HAdestination,v.HAdatedepart,v.HAdateretour,v.HAcompagnie,v.HAprix,v.HAnombre,v.HAprixt);
s=1;
            }
else {
fprintf(z,"%s %s %s %d/%d/%d %s %s %s %s %s %s %d %d\n", v1.HANom,v1.HAPrenom,v1.HACin,v1.HAdateresr.HAjour,v1.HAdateresr.HAmois,v1.HAdateresr.HAannee,v1.HAdepart,v1.HAdestination,v1.HAdatedepart,v1.HAdateretour,v1.HAcompagnie,v1.HAprix,v1.HAnombre,v1.HAprixt);
s=0;

} 
        }
        fclose(z);
        fclose(f);
	remove("res.txt");
	rename("tmphedi.txt","res.txt");

	fclose(f1);
 	fclose(f2);
	remove("vol.txt");
	rename("tmpvol.txt","vol.txt");
return s;

}

/***************************** calcul de prixtotale *********************************/

int HAcalculprix(HAvol v)
{
int p=0;
int t=0;
p = atoi(v.HAprix);
t= p * v.HAnombre;
return t;
}






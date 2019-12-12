#include <gtk/gtk.h>

typedef struct
{
int HAjour;
int HAmois;
int HAannee;
}HAdate;

typedef struct
{
char HANom[100];
char HAPrenom[100];
char HACin[100];
HAdate HAdateresr;
char HAdepart[100];
char HAdestination[100];
char HAdatedepart[100];
char HAdateretour[100];
char HAcompagnie[100];
char HAprix[100];
int HAnombre;


}HAvol;



void HAajouter_vol(HAvol v);
void HAafficher_vol(GtkWidget *liste);
int HAFillDepart(char depart[50][50]);
int HAFillDestination(char destination[50][50],char depart[]);
int HAFillDatedepart(char datedepart [50][50], char destination[],char depart[]);
int HAFillDatearrive(char datearrive [50][50], char destination[],char depart[]);
int HAFillCompagnie(char compagnie [50][50], char destination[],char depart[]);
int HAFillPrix(char PRIX[50][50], char destination[],char depart[]);

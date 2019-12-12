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
int HAprixt;


}HAvol;

typedef struct
{
char HANomv[100];
char HAPrenomv[100];
char HACinv[100];
HAdate HAdateresrv;
char HAmarquev[100];
char HAprixv[100];
int HAnombredujourv;
int HAprixtv;


}HAvoiture;



int HAajouter_vol(HAvol v);
void HAafficher_vol(GtkWidget *liste);
int HAFillDepart(char depart[50][50]);
int HAFillDestination(char destination[50][50],char depart[]);
int HAFillDatedepart(char datedepart [50][50], char destination[],char depart[]);
int HAFillDatearrive(char datearrive [50][50], char destination[],char depart[]);
int HAFillCompagnie(char compagnie [50][50], char destination[],char depart[]);
int HAFillPrix(char PRIX[50][50], char destination[],char depart[]);
void HAsupprimervol(GtkWidget *liste);
int HAmodifiervol(char cin[20], HAvol v);
int HAcalculprix(HAvol v);





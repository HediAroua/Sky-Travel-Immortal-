#include <gtk/gtk.h>

void HAajouter_voiture(HAvoiture v);
void HAafficher_voiture(GtkWidget *liste);
int HAcalculprixv(HAvoiture v);
int HAFillmarque(char Marque[50][50]);
int HAFillPrixvoiture(char PRIX [100][100], char Marque[]);
void HAsupprimervoiture(GtkWidget *liste);
int HAmodifiervoiture(char cin[20], HAvoiture v);

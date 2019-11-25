#ifndef FCTS_h_included
#define FCTS_h_included
typedef struct
{Vol vol;
Hotel hotel;
Voiture voiture;
Excursion excursion;
}Prestation;
typedef struct
{char Nom[10];
char De[20];
char A[20];
Date date_allez[20];
Date date_retour[20];
char Compagnie_aérienne[20];
char Prix[10];
int Nombre_de_siege
}Vol;
typedef struct
{char Nom[10];
char Description[20];
Date date_arrive[20];
Date date_depart[20];
char Prix[10];
char Description;
int Nombre_de_personne;
}Hotel;
typedef struct
{char Nom[10];
char Description[20];
Date date_prise_en_charge[20];
Date date_restitution[20];
char Prix[10];
char Description;
}Voiture;
typedef struct
{char Nom[10];
char Description[20];
Date date_sortie[20];
char Prix[10];
char Description;
int Nombre_de_personne
}Excursion;
typedef struct
int jour;
int mois;
int annee;
}Date;
void AfficherPrestation(Prestation tab[],int n);
void AjouterPrestation(Prestation tab[],int *n);
void AfficherVol(Vol tab[],int n,char donnee[]);
void AfficherHotel(Hotel tab[],int n,char donnee[]);
void AfficherVoiture(Voiture tab[],int n,char donnee[]);
void afficherExcursion(Excursion tab[],int n);
#endif// FCTS_h_included

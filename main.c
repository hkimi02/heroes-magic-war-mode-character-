#include <stdio.h>
#include <stdlib.h>

#define NB_LIGNES_CARTE 10
#define NB_COLONNES_CARTE 10
#define NB_LIGNES_HEROS 5
#define NB_COLONNES_HEROS 7
#define NB_LIGNES_JOUEURS 5
#define NB_COLONNES_JOUEURS 16
#define NB_LIGNES_UNITES 12
#define NB_COLONNES_UNITES 8
#define NB_LIGNES_UNITESJOUEURS 60
#define NB_COLONNES_UNITESJOUEURS 11
#define NB_LIGNES_HEROSJOUEURS 25
#define NB_COLONNES_HEROSJOUEURS 11
#define NB_EMPLACEMENTS 6
#define NB_LIGNES_UNITESBATAILLE 12
#define NB_COLONNES_UNITESBATAILLE 13
#define NB_LIGNES_PLATEAUBATAILLE 12
#define NB_COLONNES_PLATEAUBATAILLE 12


typedef enum {NUM_JOUEUR_J, LIGNE_J, COLONNE_J, OR, BOIS, PIERRE, FER, SOUFFRE,
SULFURE, GEMME_ROUGE, GEMME_BLEU, GEMME_JAUNE, NB_UNITES_TUEES,
NB_BATAILLE_GAGNES, NB_UNITES_PERDUES, NB_BATAILLE_PERDUES} E_JOUEURS;

typedef enum { NUM_HERO_H, BONUS_ATTAQUE_H, BONUS_DEFENSE_H,
CHANCE_CRITIQUE_H, MORAL_H, POINTS_ATTAQUE_SPECIALE_H, PRIX_H } E_HEROS;

typedef enum { NUM_UNITE_U, TYPE_U, SANTE_U, ATTAQUE_U, DEFENSE_U, DEGATS_U,
MOUVEMENTS_U, PRIX_U } E_UNITES;

typedef enum { NUM_JOUEUR_HJ, NUM_HERO_HJ, HERO_PRINCIPAL, POINTS_EXPERIENCE,
NIVEAU_HJ, POINTS_COMPETENCE_HJ, BONUS_ATTAQUE_HJ, BONUS_DEFENSE_HJ,
CHANCE_CRITIQUE_HJ, MORAL_HJ, POINTS_ATTAQUE_SPECIALE_HJ } E_HEROSJOUEURS;

typedef enum { NUM_JOUEUR_UJ, NUM_UNITE_UJ, TYPE_UJ, SANTE_UJ, ATTAQUE_UJ,
DEFENSE_UJ, DEGATS_UJ, MOUVEMENTS_UJ, NOMBRE_UJ, NIVEAU_UJ, UNITE_ACTIVE }
E_UNITESJOUEURS;

typedef enum { NUM_JOUEUR_UB, NUM_UNITE_UB, TYPE_UB, SANTE_RESTANTE_UB,
ATTAQUE_UB, DEFENSE_UB, DEGATS_UB, MOUVEMENTS_UB, NOMBRE_UNITES_UB,
LIGNE_UB, COLONNE_UB, FINTOUR_UB, SANTE_UNITAIRE_UB} E_UNITESBATAILLE;



void chargerFichierVersTableau (int nb_lignes,int nb_colonnes,int tab[nb_lignes][nb_colonnes],char* nomFichier){
    int i,j;
        FILE *fic=fopen(nomFichier,"r");
if (fic == NULL)
    exit(1);
      for(i=0;i<nb_lignes;i++){
      for(j=0;j<nb_colonnes;j++){
fscanf(fic,"%d",&tab[i][j]);
}
}
fclose(fic);
}

void sauvegarderTableauDansFichier (int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes],char* nomFichier ){
int i,j;
 FILE *fic=fopen(nomFichier,"w");
   if(fic==NULL){
     exit(1);}
for(i=0;i<nb_lignes;i++){
    for(j=0;j<nb_colonnes;j++){
            if(j==nb_colonnes-1){
                fprintf(fic,"%d",tab[i][j]);
            }
            else{
    fprintf(fic,"%d ",tab[i][j]);
      }}
       if(i<nb_lignes-1){
 fprintf(fic,"\n");
            }

}
fclose(fic);
}
void sauvegarderJeuComplet(
int  carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int  joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int  heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int  herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int  unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int  unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS])
{
sauvegarderTableauDansFichier(NB_LIGNES_CARTE,NB_COLONNES_CARTE,carte,"carte_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_JOUEURS,  NB_COLONNES_JOUEURS ,  joueurs,"joueurs_sauvgarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_HEROS, NB_COLONNES_HEROS, heros,"heros_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_HEROSJOUEURS,  NB_COLONNES_HEROSJOUEURS,herosJoueurs ,"herosJoueurs_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_UNITES,  NB_COLONNES_UNITES,unites ,"unites_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,  unitesJoueurs,"unitesJoueurs_sauvegarde.txt" );
}
void chargerJeuComplet (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int Joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] ){
chargerFichierVersTableau( NB_LIGNES_CARTE, NB_COLONNES_CARTE,  carte,"carte_sauvegarde.txt");
chargerFichierVersTableau( NB_LIGNES_HEROS, NB_COLONNES_HEROS, heros ,"heros_sauvegarde.txt");
chargerFichierVersTableau( NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS, Joueurs,"joueurs_sauvgarde.txt");
chargerFichierVersTableau( NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,  unitesJoueurs,"unitesJoueurs_sauvegarde.txt");
chargerFichierVersTableau( NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs ,"herosJoueurs_sauvegarde.txt");
chargerFichierVersTableau( NB_LIGNES_UNITES, NB_COLONNES_UNITES,  unites,"unites_sauvegarde.txt");

}
void initialiserNouveauJeu (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int Joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS])
{
chargerFichierVersTableau( NB_LIGNES_CARTE, NB_COLONNES_CARTE,carte,"carte_original.txt");
chargerFichierVersTableau( NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS, Joueurs,"joueurs_original.txt");
chargerFichierVersTableau( NB_LIGNES_HEROS,NB_COLONNES_HEROS , heros,"heros_original.txt");
chargerFichierVersTableau( NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_original.txt");
chargerFichierVersTableau( NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_original.txt");
chargerFichierVersTableau( NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS, unitesJoueurs,"unitesJoueurs_original.txt");}



void afficherTableau ( int nb_lignes,int nb_colonnes, int tab[nb_lignes][nb_colonnes], char* nomFichierEntete){
int i, largeur_fictive_de_champs_donnes,champ_information, nb_espace,largeur_reel_de_champs_donnes,v,n,largeur_de_laffichage_de_tableau;

     largeur_fictive_de_champs_donnes = (151-1)/nb_colonnes;
if (largeur_fictive_de_champs_donnes > 9){
    champ_information = 7;
    nb_espace =(largeur_fictive_de_champs_donnes - champ_information-1)/2;
    largeur_reel_de_champs_donnes = 1+ (nb_espace*2) +champ_information;
    }
    else{
        nb_espace = 0;
        champ_information=largeur_fictive_de_champs_donnes-2;
        largeur_reel_de_champs_donnes = 2+ (nb_espace*2) +champ_information;
}
     largeur_de_laffichage_de_tableau=(largeur_reel_de_champs_donnes*nb_colonnes)+1;
   for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
    if(i==largeur_de_laffichage_de_tableau)
        {printf("\n");}}
FILE *fic=fopen(nomFichierEntete,"r");
char ligne[256];
      if(fic==NULL)
    exit(1);
    else{ fgets(ligne,256,fic);
     printf("%s",ligne);
     fclose(fic);}
     printf("\n");
for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}
for(v=0;v<=nb_lignes-1;v++)
{
    for(n=0;n<=nb_colonnes-1;n++)
    {  printf("| ");
      for(i=1;i<=nb_espace;i++)
      {printf(" ");}
      printf("%*d",champ_information,tab[v][n]);
       for(i=1;i<nb_espace;i++)
      {printf(" ");}
    }
       {printf("|");}
        printf("\n");


    for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}


}}

void afficherTableauxJeu(
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS ][NB_COLONNES_HEROSJOUEURS ],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS]){
     afficherTableau( NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
     afficherTableau( NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_entete.txt");
     afficherTableau( NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt" );
     afficherTableau( NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_entete.txt");
     afficherTableau( NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
}
void afficherTableauUneCondition (int colonne, int valeur, int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes], char* nomFichierEntete){
  int i, largeur_fictive_de_champs_donnes,champ_information, nb_espace,largeur_reel_de_champs_donnes,largeur_de_laffichage_de_tableau,v,n;
  largeur_fictive_de_champs_donnes = (151-1)/nb_colonnes;
if (largeur_fictive_de_champs_donnes > 9){
    champ_information = 7;
    nb_espace =(largeur_fictive_de_champs_donnes - champ_information-1)/2;
    largeur_reel_de_champs_donnes = 1+ (nb_espace*2) +champ_information; }
    else{
        nb_espace = 0;
        champ_information=largeur_fictive_de_champs_donnes-1;
        largeur_reel_de_champs_donnes = 1+ (nb_espace*2) +champ_information;
}
     largeur_de_laffichage_de_tableau=(largeur_reel_de_champs_donnes*nb_colonnes)+1;
   for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
    if(i==largeur_de_laffichage_de_tableau)
        printf("\n");}

FILE *fic=fopen(nomFichierEntete,"r");
char ligne[256];
if(fic==NULL)
    exit(1);
  else{ fgets(ligne,256,fic);
     printf("%s",ligne);
     fclose(fic);}
     printf("\n");
for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}
for(v=0;v<=nb_lignes-1;v++)
{ if(tab[v][colonne]==valeur){
    for(n=0;n<=nb_colonnes-1;n++)
    {  printf("|");
      for(i=1;i<=nb_espace;i++)
      {printf(" ");}
      printf("%*d",champ_information,tab[v][n]);
       for(i=1;i<=nb_espace;i++)
      {printf(" ");}
    }
       {printf("|");}
        printf("\n");


    for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}

}}}



void afficherTableauDeuxConditions ( int colonne1, int valeur1, int colonne2, int valeur2, int nb_lignes,int nb_colonnes, int tab[nb_lignes][nb_colonnes], char* nomFichierEntete){
     int i , largeur_fictive_de_champs_donnes,champ_information, nb_espace,largeur_reel_de_champs_donnes,largeur_de_laffichage_de_tableau,v,n;
   largeur_fictive_de_champs_donnes = (151-1)/nb_colonnes;
if (largeur_fictive_de_champs_donnes > 9)
    {
    champ_information = 7;
    nb_espace =(largeur_fictive_de_champs_donnes - champ_information-1)/2;
    largeur_reel_de_champs_donnes = 1+ (nb_espace*2) +champ_information; }
   else{
        nb_espace = 0;
        champ_information=largeur_fictive_de_champs_donnes-1;
        largeur_reel_de_champs_donnes = 1+ (nb_espace*2) +champ_information;
}
     largeur_de_laffichage_de_tableau=(largeur_reel_de_champs_donnes*nb_colonnes)+1;
   for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
    if(i==largeur_de_laffichage_de_tableau)
        printf("\n");}

FILE *fic=fopen(nomFichierEntete,"r");
char ligne[256];
if(fic==NULL)
    exit(1);
  else{ fgets(ligne,256,fic);
     printf("%s",ligne);
     fclose(fic);}
     printf("\n");
for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}
for(v=0;v<=nb_lignes-1;v++)
{ if(tab[v][colonne1]==valeur1 && tab[v][colonne2]==valeur2){
    for(n=0;n<=nb_colonnes-1;n++)
    {  printf("|");
      for(i=1;i<=nb_espace;i++)
      {printf(" ");}
      printf("%*d",champ_information,tab[v][n]);
       for(i=1;i<=nb_espace;i++)
      {printf(" ");}
    }
       {printf("|");}
        printf("\n");


    for (i=1;i<=largeur_de_laffichage_de_tableau;i++)
    {printf("-");
     if (i==largeur_de_laffichage_de_tableau)
        printf("\n");}

    printf("\n");
}}}


void degagerNuages (int lig, int col, int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE]){

    int i,j,ligne_min,ligne_max,colonne_min,colonne_max,uni;
    ligne_max=lig+2;
    ligne_min=lig-2;
    colonne_max=col+2;
    colonne_min=col-2;


if(ligne_min<0){
 ligne_min=0;
}
if(ligne_max>=9){
    ligne_max=9;
}
if(colonne_min<=0){
    colonne_min=0;

}
if(colonne_max>=9){
    colonne_max=9;

}
for(i=ligne_min;i<=ligne_max;i++)
{for(j=colonne_min;j<=colonne_max;j++){
      uni=carte[i][j]%10;
    if(uni==1){
        carte[i][j]=carte[i][j]-1;
    }
}
}
}
void afficherCarte (int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE] ){
int i,j,v;
        for(v=0;v<10;v++){

        if(v==9){
            printf("  %d  ", v);
        }
        else{
            printf("  %d ", v);
        }}


for(i=0;i<NB_LIGNES_CARTE;i++){


    printf("|\n");
    for(v=0;v<42;v++){
        printf("-");}
        printf("\n");
printf("%d", i);

    for(j=0;j<NB_COLONNES_CARTE;j++){
        if(carte[i][j]==2)
             {printf("| J ");}
        else
        if(carte[i][j]==0)
            {printf("|   ");}
        else
        if(carte[i][j]==1)
            {printf("| ??");}
        else
            if(carte[i][j]%100%10==1)
            {printf("| ??");}
         else
         if(carte[i][j]%10==2){
                switch(carte[i][j]%100/10){
            case 1:{
                switch(carte[i][j]/100){
                    case 1:printf("|JE1");break;
                    case 2:printf("|JE2");break;
                    case 3:printf("|JE3");break;
                    case 4:printf("|JE4");break;
                }}break;
            case 2:
                    printf("|J T");break;
            case 3:printf("|J X");break;
                }
         }

        else
            if(carte[i][j]%100/10==3)
           {printf("| X ");}
        else if(carte[i][j]%100/10==2)
           {printf("| T ");}
        else
         if(carte[i][j]%100/10==1){
            if(carte[i][j]/100==1)
            printf("| E%d", carte[i][j]/100);
            else if(carte[i][j]/100==2)
            printf("| E%d", carte[i][j]/100);
            else if(carte[i][j]/100==3)
            printf("| E%d", carte[i][j]/100);
            else if(carte[i][j]/100==4)
            printf("| E%d", carte[i][j]/100);
        }

        }
    }
printf("|\n");
    for(v=0;v<42;v++){
        printf("-");}
        printf("\n");
}




void avancer (char action,int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS])
{int anc_lignes,anc_colonnes;
int new_ligne,new_colonne;
anc_lignes=joueurs[0][LIGNE_J];
anc_colonnes=joueurs[0][COLONNE_J];
if(action=='h')
{if(anc_lignes==0){
    joueurs[0][LIGNE_J]=joueurs[0][LIGNE_J];
  }
  else{
        joueurs[0][LIGNE_J]-=1;
       carte[anc_lignes][anc_colonnes]-=2;
}
}
else if(action=='b')
{if(anc_lignes+1>9){
    joueurs[0][LIGNE_J]=joueurs[0][LIGNE_J];
}
  else{
        joueurs[0][LIGNE_J]+=1;
       carte[anc_lignes][anc_colonnes]-=2;
}}
else
    if(action=='d')
{if(anc_colonnes+1>9)
  {  joueurs[0][COLONNE_J]=joueurs[0][COLONNE_J];
}
  else {
    joueurs[0][COLONNE_J]+=1;
    carte[anc_lignes][anc_colonnes]-=2;
  }}
else
    if(action=='g')

 {if(anc_colonnes-1<0)
  {  joueurs[0][COLONNE_J]=joueurs[0][COLONNE_J];
  }else {
    joueurs[0][COLONNE_J]-=1;
    carte[anc_lignes][anc_colonnes]-=2;
  }}
  new_ligne=joueurs[0][LIGNE_J];
  new_colonne=joueurs[0][COLONNE_J];
  if(carte[new_ligne][new_colonne]==0){
    carte[new_ligne][new_colonne]+=2;}
  else if(carte[new_ligne][new_colonne]==1){
    carte[new_ligne][new_colonne]+=1;}
  else if(carte[new_ligne][new_colonne]%10==0){
    carte[new_ligne][new_colonne]+=2;}
   else if (carte[new_ligne][new_colonne]%10==1){
    carte[new_ligne][new_colonne]+=1;}
   degagerNuages(new_ligne,new_colonne,carte);

sauvegarderTableauDansFichier(NB_LIGNES_CARTE,NB_COLONNES_CARTE,carte,"carte_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_JOUEURS,  NB_COLONNES_JOUEURS ,  joueurs,"joueurs_sauvgarde.txt");
}

int chercherIndiceAvecUneCondition ( int colonneConcernee, int valeur, int nb_lignes, int
nb_colonnes, int tab[nb_lignes][nb_colonnes]){
    int i,indice,existe;
    i=0;
    indice=-1;
     existe=0;
    while(i<nb_lignes && existe==0){
           if( valeur==tab[i][colonneConcernee]){
            indice=i;
            existe=1;
            }
            else{
                i++;
            }
    }

return indice;
}
 int chercherIndiceAvecDeuxConditions(int colonneConcernee1, int valeur1, int colonneConcernee2,
int valeur2, int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes]){
      int i,indice,existe;
     i=0;
     indice=-1;
     existe=0;
    while(i<nb_lignes && existe==0){
           if(( valeur1==tab[i][colonneConcernee1])&&(valeur2==tab[i][colonneConcernee2])){
            indice=i;
            existe=1;
            }
            else{
                i++;
            }
    }
return indice;
}

void lancerMenuAchatHeros ( int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS]){
int choix1,choix2,choix3,solde,prix,deja_achete,lig_h,new_lig,old_lig,lig_j;
    do{

        printf("\n                                                      Informations sur le joueur humain\n\n");
afficherTableauUneCondition(NUM_JOUEUR_J,0,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
            printf("                                                    Liste des heros disponible pour achat : \n");
afficherTableau( NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_entete.txt");
printf("*************************************\n");
printf("**   Menu achat heros              **\n");
printf("*************************************\n");
printf("** 1-Acheter un nouveau hero       **\n");
printf("** 0-Revenir au menu precedent     **\n");
printf("*************************************\n");
do{
   printf("Entrez votre choix (0-1) : ");
    scanf("%d", &choix1);
}while(choix1!=1 && choix1!=0);
              if(choix1==1){
                    do{
                printf("Entrer le numero d'hero que vous voulez acheter : ");
                scanf("%d", &choix2);
                }while(choix2>5 || choix2<1);
                   lig_h=chercherIndiceAvecUneCondition(NUM_HERO_H,choix2,NB_LIGNES_HEROS,NB_COLONNES_HEROS,heros);

                  do{
                    printf("Confirmer l'achat (1-oui;0-non) : ");
                    scanf("%d", &choix3);
                    }while(choix3!=1 && choix3!=0);
                    if(choix3==1){
                old_lig=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,numJoueur,NUM_HERO_HJ,choix2,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
                lig_j=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,numJoueur,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
                deja_achete=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,numJoueur,NUM_HERO_HJ,choix2,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
                new_lig=chercherIndiceAvecUneCondition(NUM_JOUEUR_HJ,-1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
                  prix=heros[lig_h][PRIX_H];
                  solde=joueurs[lig_j][OR];
                  if(prix>solde){
                    printf("Votre solde d'or ne vous permet pas d'acheter l'hero %d\n", choix2);
                  }else
                    if(deja_achete!=-1){
                        printf("Vous avez deja acheter ce hero \n");
                    }
                   else
                        if(new_lig==-1){
                        printf("Vous ne pouvez pas acheter des autres heros car vous avez atteint le nombe maximum des heros \n\n");
                    }
                    else {

                            herosJoueurs[new_lig][NUM_JOUEUR_HJ]=0;
                            herosJoueurs[new_lig][NUM_HERO_HJ]=choix2;
                            herosJoueurs[new_lig][HERO_PRINCIPAL]=0;
                            herosJoueurs[new_lig][NIVEAU_HJ]=0;
                            herosJoueurs[new_lig][POINTS_EXPERIENCE]=herosJoueurs[old_lig][POINTS_EXPERIENCE];
                            herosJoueurs[new_lig][POINTS_COMPETENCE_HJ]=herosJoueurs[old_lig][POINTS_COMPETENCE_HJ];
                            herosJoueurs[new_lig][BONUS_ATTAQUE_HJ]=heros[lig_h][BONUS_ATTAQUE_H];
                            herosJoueurs[new_lig][BONUS_DEFENSE_HJ]=heros[lig_h][BONUS_DEFENSE_H];
                            herosJoueurs[new_lig][CHANCE_CRITIQUE_HJ]=heros[lig_h][CHANCE_CRITIQUE_H];
                            herosJoueurs[new_lig][MORAL_HJ]=heros[lig_h][MORAL_H];
                            herosJoueurs[new_lig][POINTS_ATTAQUE_SPECIALE_HJ]=heros[lig_h][POINTS_ATTAQUE_SPECIALE_H];
                            joueurs[lig_j][OR]-=prix;
                            printf("                                 Achat effectue avec succes\n\n");
                            afficherTableauUneCondition(NUM_JOUEUR_HJ,numJoueur,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
                    }



              }}
sauvegarderTableauDansFichier(NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_sauvgarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_sauvegarde.txt");
}while(choix1!=0);
}
void lancerMenuAchatUnites ( int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS]){
int choix1,choix2,choix3,choix4,solde,prix,lig_vid,pres_u,lig_u;
    do{
            do{
        printf("\n                                                   Informations sur le joueur humain\n\n");
afficherTableauUneCondition(NUM_JOUEUR_J,0,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
            printf("                                                 Liste des unites disponible pour achat : \n");
afficherTableau( NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_entete.txt");
solde=joueurs[0][OR];
printf("*************************************\n");
printf("**   Menu achat unites             **\n");
printf("*************************************\n");
printf("** 1-Acheter des nouveaux unites  **\n");
printf("** 0-Revenir au menu precedent     **\n");
printf("*************************************\n");
   printf("Entrez votre choix (0-1) : ");
    scanf("%d", &choix1);
}while(choix1!=1 && choix1!=0);
if(choix1==1){
    printf("Entrer le numero d'unites que vous voulez acheter : ");
    scanf("%d", &choix2);
    lig_u=chercherIndiceAvecUneCondition(NUM_UNITE_U,choix2,NB_LIGNES_UNITES,NB_COLONNES_UNITES,unites);
    if(lig_u==-1){
    printf("\ncet unite ne se trouve pas dans le tableau");
    }
    else{
    printf("Entrer le nombre de soldats que vous voulez acheter de l'unite type %d : ", choix2);
    scanf("%d", &choix3);
                    do{
                    printf("Confirmer l'achat (1-oui;0-non) : ");
                    scanf("%d", &choix4);
                    }while(choix4!=1 && choix4!=0);
        if(choix4==1){
    lig_u=chercherIndiceAvecUneCondition(NUM_UNITE_U,choix2,NB_LIGNES_UNITES,NB_COLONNES_UNITES,unites);
    prix=unites[lig_u][PRIX_U]*choix3;

    if(prix>solde){
        printf("                                                                               Achat annule ! solde insuffisant\n");
    }
    else{
         pres_u=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,choix2,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs);
        if(pres_u!=-1){
                        unitesJoueurs[pres_u][NOMBRE_UJ]+=choix3;
                        afficherTableauDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,choix2,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
                        joueurs[0][OR]-=prix;

        }
                else{
                    lig_vid=chercherIndiceAvecUneCondition(NUM_JOUEUR_UJ,-1,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs);
                    unitesJoueurs[lig_vid][NUM_JOUEUR_UJ]=0;
                    unitesJoueurs[lig_vid][NUM_UNITE_UJ]=choix2;
                    unitesJoueurs[lig_vid][TYPE_UJ]=unites[lig_u][TYPE_U];
                    unitesJoueurs[lig_vid][SANTE_UJ]=unites[lig_u][SANTE_U];
                    unitesJoueurs[lig_vid][ATTAQUE_UJ]=unites[lig_u][ATTAQUE_U];
                    unitesJoueurs[lig_vid][DEFENSE_UJ]=unites[lig_u][DEFENSE_U];
                    unitesJoueurs[lig_vid][DEGATS_UJ]=unites[lig_u][DEGATS_U];
                    unitesJoueurs[lig_vid][MOUVEMENTS_UJ]=unites[lig_u][MOUVEMENTS_U];
                    unitesJoueurs[lig_vid][NOMBRE_UJ]=choix3;
                    unitesJoueurs[lig_vid][NIVEAU_UJ]=0;
                    unitesJoueurs[lig_vid][UNITE_ACTIVE]=0;
                    joueurs[0][OR]-=prix;
                    printf("                                                                     Achat effectue avec succes!\n");
                    afficherTableauUneCondition(NUM_JOUEUR_UJ,numJoueur,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");

                }
        }




    }
}}
sauvegarderTableauDansFichier(NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_sauvgarde.txt");
}while(choix1!=0);
}


void lancerMenuMagasin (
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS]){
    int mag;
    printf("\n");
do{
printf("*************************************\n");
printf("**    Menu Magasin                 **\n");
printf("*************************************\n");
printf("** 1-Acheter des heros             **\n");
printf("** 2-Acheter des unites            **\n");
printf("** 0-Retour au menu principal      **\n");
printf("*************************************\n");
printf("Entrer votre choix : ");
scanf("%d", &mag);
if(mag==1)
lancerMenuAchatHeros(0,joueurs,heros,herosJoueurs);
else if (mag==2)
lancerMenuAchatUnites(0,joueurs,unites,unitesJoueurs);
}while(mag!=0);
}
void lancerMenuConfigurationHeros (int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS]){
    int choix1,choix2,hero_principal,lig_h;
do{
        do{
printf("\n                                Informations sur les heros du joueur humain\n\n");
afficherTableauUneCondition(NUM_JOUEUR_HJ,numJoueur,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
printf("*********************************************\n");
printf("**         Menu configuration heros        **\n");
printf("*********************************************\n");
printf("** 1-Mettre un nouveau hero comme principal**\n");
printf("** 0-Revenir au menu precedent             **\n");
printf("*********************************************\n");
printf("Entrez votre choix (0-1) : ");
scanf("%d", &choix1);
}while(choix1!=1 && choix1!=0);
if(choix1==1){
    printf("Entrer le numero de votre nouveau hero principal : ");
    scanf("%d", &choix2);
   lig_h=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,NUM_HERO_HJ,choix2,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
if(lig_h==-1){
    printf("Vous n'avez pas de hero avec ce numero\n");
}
else{
    hero_principal=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
if(hero_principal!=-1){
    herosJoueurs[hero_principal][HERO_PRINCIPAL]=0;
}
herosJoueurs[lig_h][HERO_PRINCIPAL]=1;
printf("                                                    Hero %d est le nouveau hero principal\n\n", choix2);
afficherTableauDeuxConditions(NUM_JOUEUR_HJ,0,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
}
}
}while(choix1!=0);
sauvegarderTableauDansFichier(NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_sauvegarde.txt");
}
void lancerMenuConfigurationUnites ( int numJoueur,
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS]){
int choix1,choix2,i,lig_j,choix3,nb_emplacements,lig_uj;

do{
do{
printf("\n                                                    Informations sur les unites du joueur humain\n");
afficherTableauUneCondition(NUM_JOUEUR_UJ,numJoueur,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
printf("*********************************************\n");
printf("**         Menu configuration unites       **\n");
printf("*********************************************\n");
printf("** 1-Mettre un unite comme principale      **\n");
printf("** 2-Mettre un unite comme reserve         **\n");
printf("** 0-Revenir au menu precedent             **\n");
printf("*********************************************\n");
printf("Entrez votre choix (0-1) : ");
scanf("%d", &choix1);
}while(choix1!=1 && choix1!=0 && choix1!=2);
if(choix1==1){
    printf("Entrer le numero de votre nouveau unite principal : ");
    scanf("%d", &choix2);
    lig_uj=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,choix2,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs);
     if(lig_uj==-1){
        printf("Vous n'avez pas acheter cet unites ");
     }
     else
     {   nb_emplacements=0;
         for(i=0;i<NB_LIGNES_UNITESJOUEURS;i++){
                if(unitesJoueurs[i][NUM_JOUEUR_UJ]==0)
                nb_emplacements+=unitesJoueurs[i][UNITE_ACTIVE];
         }
        if(nb_emplacements==NB_EMPLACEMENTS){
            printf("Vous avez atteint le nombre maximum des unites active\n");
        }
        else{
         unitesJoueurs[lig_uj][UNITE_ACTIVE]=1;
         printf("Unites active avec succes !\n");

         afficherTableauDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,choix2,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
        }
    }}
else if(choix1==2){
       printf("Entrer le numero de l'unite que vous voulez mettre en reserve : ");
       scanf("%d", &choix3);
       lig_j=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,choix3,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs);
       if(lig_j==-1){
        printf("Vous n'avez pas acheter cet unites .");
        }
        else{
        unitesJoueurs[lig_j][UNITE_ACTIVE]=0;
        printf("Unites mise en reserve avec succes!\n");
        afficherTableauUneCondition(NUM_JOUEUR_UJ,0,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
}
}
}while(choix1!=0);
sauvegarderTableauDansFichier(NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_sauvegarde.txt");
}
void lancerMenuCampement (
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS])
{
    int c;
do{
printf("\n**************************************");
printf("\n**    Menu campement                **\n");
printf("** 1-Configuration heros            **\n");
printf("** 2-Configuration unites           **\n");
printf("** 0-Retour au menu precedent       **\n");
printf("**************************************\n");
printf("Entrer votre choix (0-2) : ");
        scanf("%d", &c);
        if(c==1)
    lancerMenuConfigurationHeros(0,joueurs,herosJoueurs);
    else if(c==2)
     lancerMenuConfigurationUnites(0,unitesJoueurs);
}while(c!=0);
}
void afficherContenuCaseCarte ( int valeurcase,
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS]){

 if(valeurcase%100/10==1){
afficherTableauDeuxConditions(NUM_JOUEUR_HJ,valeurcase/100,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
}
else if(valeurcase%100/10==2){
printf("-----------------------------------------\n");
printf("|  caisse a tresor :  %d pieces          |\n", valeurcase/100);
printf("-----------------------------------------\n");
}
else if(valeurcase%100/10==3){
printf("----------------------------------------------------------------------\n");
printf("|coffre points experiences :  %d ponits d'experiences                |\n", valeurcase/100);
printf("----------------------------------------------------------------------\n");
}
else{
printf("-----------------------------\n");
printf("|        case vide!         |\n");
printf("-----------------------------\n");
}
}
void afficherPlateauBataille ( int numJoueur, int numJoueurEnnemi,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] ){

int i,j,v,longeur_champ=7;
printf("\n                                           Unites de joueur enemi num : %d\n", numJoueurEnnemi);
afficherTableauUneCondition(NUM_JOUEUR_UB,numJoueurEnnemi,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille,"unitesBataille_entete.txt");
printf("\n                                           Plateau de bataille : \n");
       for(v=0;v<NB_COLONNES_PLATEAUBATAILLE*longeur_champ+3;v++)
        {
                printf("-");
       }
       printf("\n  ");
        for(v=0;v<NB_COLONNES_PLATEAUBATAILLE;v++){
        if(v>=10){
            printf("|   %d ", v);
        }
        else {
             printf("|    %d ", v);
        }}
for(i=0;i<NB_LIGNES_PLATEAUBATAILLE;i++){
    printf("|\n");
    for(v=0;v<NB_COLONNES_PLATEAUBATAILLE*longeur_champ+3;v++){
        printf("-");}
        printf("\n");
        if(i<10){
printf(" %d", i);}
else{
    printf("%d", i);
}
    for(j=0;j<NB_COLONNES_PLATEAUBATAILLE;j++){
            if(plateauBataille[i][j]==0){
                printf("|      ");
            }
            else if(plateauBataille[i][j]==1){
                printf("|++++++");
            }
            else if(plateauBataille[i][j]%100==10){
                    if(plateauBataille[i][j]/1000>=10){
                    printf("|J%dU%d ",plateauBataille[i][j]/100%10,plateauBataille[i][j]/1000);
                    }
                    else{
                    printf("|J%dU%d  ",plateauBataille[i][j]/100%10,plateauBataille[i][j]/1000);
                    }
            }
 }}
   printf("|\n");
    for(v=0;v<NB_COLONNES_PLATEAUBATAILLE*longeur_champ+3;v++){
        printf("-");}
        printf("\n");
    printf("\nUnites de joueur humain : \n");
     afficherTableauUneCondition(NUM_JOUEUR_UB,0,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille,"unitesBataille_entete.txt");
}
void marquerDeplacementsPossibles (
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int ligneCourante, int colonneCourante, int mouvements ){
   int i,j,nb_deplace;
   for(i=0;i<ligneCourante+mouvements+1;i++){
       if(i<NB_LIGNES_PLATEAUBATAILLE){
        for(j=0;j<colonneCourante+mouvements;j++){
                if(j<NB_COLONNES_PLATEAUBATAILLE){
                nb_deplace=abs(ligneCourante-i);
                nb_deplace+=abs(colonneCourante-j);

            if(nb_deplace<=mouvements && plateauBataille[i][j]==0){
                plateauBataille[i][j]=1;
                }
                }
                }
        }
    }
}
void effacerDeplacementsPossibles (
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE] ){
   int i,j;
   for(i=0;i<NB_LIGNES_PLATEAUBATAILLE;i++){
    for(j=0;j<NB_COLONNES_PLATEAUBATAILLE;j++){
        if(plateauBataille[i][j]==1){
            plateauBataille[i][j]=0;
        }
    }
   }
}
void attaque ( int indiceDansUniteEnBataille, int indiceEnnemiDansUnitesBataille,
int numJoueur, int numEnnemi, int ligne, int colonne,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS] ){
int nb_soldat_attaque=unitesBataille[indiceDansUniteEnBataille][NOMBRE_UNITES_UB];
int defense_uni=unitesBataille[indiceEnnemiDansUnitesBataille][DEFENSE_UB];
int degats_uni=unitesBataille[indiceDansUniteEnBataille][DEGATS_UB];
int attaque_uni=unitesBataille[indiceDansUniteEnBataille][ATTAQUE_UB];
int sante_totale=(unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB])*(unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]);
int perte_totale_sante,degats_infligi_totale;
float bonus_attaque;
   bonus_attaque=(attaque_uni-defense_uni)/200.0;
   perte_totale_sante=nb_soldat_attaque*(degats_uni*(1+bonus_attaque));
   degats_infligi_totale=sante_totale-perte_totale_sante;

   if(degats_infligi_totale<0){
        plateauBataille[unitesBataille[indiceEnnemiDansUnitesBataille][LIGNE_UB]][unitesBataille[indiceEnnemiDansUnitesBataille][COLONNE_UB]]=0;
        int ligne_enemi_tab_joueur=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,numEnnemi,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
         int ligne_joueurHumain_tab_joueur=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,numJoueur,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
        joueurs[ligne_enemi_tab_joueur][NB_UNITES_PERDUES]+=1;
         joueurs[ligne_joueurHumain_tab_joueur][NB_UNITES_TUEES]+=1;
          printf("\nUnite %d de joueur %d attaque l unite %d de joueur enemi %d !\n", unitesBataille[indiceDansUniteEnBataille][NUM_UNITE_UB],numJoueur,unitesBataille[indiceEnnemiDansUnitesBataille][NUM_UNITE_UB],numEnnemi);
          printf("\n<<Sante totale de l'unite attaque %d  -  degats inflegi %d = sante totale restante %d>>\n", sante_totale,perte_totale_sante,degats_infligi_totale);
       for(int i=0;i<NB_COLONNES_UNITESBATAILLE;i++){
            unitesBataille[indiceEnnemiDansUnitesBataille][i]=-1;
       }

   }
   else{
        int nb_unite_defectieux=perte_totale_sante/unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB];
        if(nb_unite_defectieux<unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]){
                if((perte_totale_sante%unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB])>unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]){
                    unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]-=nb_unite_defectieux;
                    unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]-=1;
                    unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]=unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB];
                     unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]-=(perte_totale_sante%unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB]);
               }else if((perte_totale_sante%unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB])<unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]){
                 unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]-=nb_unite_defectieux;
                unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]-=(perte_totale_sante%unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB]);
                }else{
                 unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]-=nb_unite_defectieux;
                 unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]=unitesBataille[indiceDansUniteEnBataille][SANTE_UNITAIRE_UB];

                }
                }

            else if(nb_unite_defectieux==unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]){
                unitesBataille[indiceEnnemiDansUnitesBataille][NOMBRE_UNITES_UB]=1;
                unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]=unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB];
                unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_RESTANTE_UB]-=(perte_totale_sante%unitesBataille[indiceEnnemiDansUnitesBataille][SANTE_UNITAIRE_UB]);
            }
   printf("\nUnite %d de joueur %d attaque l unite %d de joueur enemi %d !\n", unitesBataille[indiceDansUniteEnBataille][NUM_UNITE_UB],numJoueur,unitesBataille[indiceEnnemiDansUnitesBataille][NUM_UNITE_UB],numEnnemi);
   printf("\n<<Sante totale de l'unite attaque %d  -  degats inflegi %d = sante totale restante %d >>\n", sante_totale,perte_totale_sante,degats_infligi_totale);
  }
}

void reinitialiserToursBataille (
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] ){
int i;
for(i=0;i<NB_LIGNES_UNITESBATAILLE;i++){
    unitesBataille[i][FINTOUR_UB]=0;
}
}
int verificationFinTours ( int numJoueur,int
unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
    int i,nb_fin_tour=0;
for(i=0;i<NB_LIGNES_UNITESBATAILLE;i++){
    if(unitesBataille[i][NUM_JOUEUR_UB]== numJoueur && unitesBataille[i][FINTOUR_UB]==0){
    nb_fin_tour++;
    }
}
if(nb_fin_tour!=0){
    return 0;
}
else{
    return 1;
}
}

int verificationGagnant ( int numJoueur, int numJoueurEnnemi, int
unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
int i,nb_ligne_joueur,nb_ligne_enemi;
nb_ligne_enemi=0;
nb_ligne_joueur=0;
for(i=0;i<NB_LIGNES_UNITESBATAILLE;i++){
    if(unitesBataille[i][NUM_JOUEUR_UB]== numJoueur){
    nb_ligne_joueur++;
    }
      if(unitesBataille[i][NUM_JOUEUR_UB]== numJoueurEnnemi){
    nb_ligne_enemi++;
    }
}
if(nb_ligne_joueur==0){
    return numJoueurEnnemi;
}
else if(nb_ligne_enemi==0){
    return numJoueur;
}
else{
    return -1;
}
}

void deplacerUnite ( int numJoueur, int indiceDansUniteEnBataille,
int numUnite, int ligne_courante, int colonne_courante, int nouvelle_ligne, int nouvelle_colonne,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] ){
if(nouvelle_ligne<=NB_LIGNES_PLATEAUBATAILLE && nouvelle_colonne<=NB_COLONNES_PLATEAUBATAILLE){
if(plateauBataille[nouvelle_ligne][nouvelle_colonne]==1){
    plateauBataille[nouvelle_ligne][nouvelle_colonne]= plateauBataille[ligne_courante][colonne_courante];
    plateauBataille[ligne_courante][colonne_courante]=0;
    unitesBataille[indiceDansUniteEnBataille][LIGNE_UB]=nouvelle_ligne;
    unitesBataille[indiceDansUniteEnBataille][COLONNE_UB]=nouvelle_colonne;
}
}}
int codeAttaqueSansDeplacement ( int numJoueur, int typeUnite,
int ligne_courante, int colonne_courante,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE]){
int existance_droit=0;
int existance_gauche=0;
int existance_bas=0;
int existance_haut=0;
int code_attaque=0;
if(typeUnite==1){
    return 1;
}
else{
     if(plateauBataille[ligne_courante][colonne_courante+1]>1 && (plateauBataille[ligne_courante][colonne_courante+1]/100%10!=numJoueur && colonne_courante+1<NB_COLONNES_PLATEAUBATAILLE && colonne_courante+1>=0)){
          existance_droit=10;
     }
     if(plateauBataille[ligne_courante][colonne_courante-1]>1 && (plateauBataille[ligne_courante][colonne_courante-1]/100%10!=numJoueur) && (colonne_courante-1>=0) && (colonne_courante-1<NB_COLONNES_PLATEAUBATAILLE)){
        existance_gauche=100;
     }
     if(plateauBataille[ligne_courante+1][colonne_courante]>1 && (plateauBataille[ligne_courante+1][colonne_courante]/100%10!=numJoueur)  && ligne_courante+1<NB_LIGNES_PLATEAUBATAILLE && ligne_courante+1>=0){
        existance_bas=1000;
     }
     if(plateauBataille[ligne_courante-1][colonne_courante]>1 && (plateauBataille[ligne_courante-1][colonne_courante]/100%10!=numJoueur) && ligne_courante-1<NB_LIGNES_PLATEAUBATAILLE && ligne_courante-1>=0){
        existance_haut=10000;
     }
    if(existance_bas!=0 || existance_droit!=0 || existance_haut!=0 || existance_gauche!=0){
    code_attaque=existance_haut+existance_bas+existance_gauche+existance_droit+2;
    return code_attaque;
}
else{
    return 0;
}
}
}
int uniteAttaquable ( int codeAttaque, int ligne_courante, int colonne_courante,
int ligne_ennemie, int colonne_ennemie){
   int differnce_ligne=ligne_courante-ligne_ennemie;
   int differnce_colonne=colonne_courante-colonne_ennemie;
   int droite,gauche,haut,bas;
   haut=codeAttaque/10000;
   bas=codeAttaque%10000/1000;
   gauche=codeAttaque%10000%1000/100;
   droite=codeAttaque%10000%1000%100/10;
   if(codeAttaque==1){
    return 1;
   }
   else if(codeAttaque==0){
           return 0;
   }
   else{
        if(differnce_ligne==1 && haut==1){
            return 1;
        }
        if(differnce_ligne==-1 && bas==1){
            return 1;
        }
        else if(differnce_colonne== 1 && droite == 1){
            return 1;
        }
        else if(differnce_colonne==-1 && gauche==1){
            return 1;
        }
        return 0;
   }
}
void initialiserBataille ( int numJoueurHumain, int numJoueurEnnemi,
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
int i,j,ligne_vide;
int colonne_unite=0;
int colonne_unite_enemi=0;
    for(i=0;i<NB_LIGNES_UNITESBATAILLE;i++){
        for(j=0;j<NB_COLONNES_UNITESBATAILLE;j++){
            unitesBataille[i][j]=-1;
        }
    }
      for(i=0;i<NB_LIGNES_PLATEAUBATAILLE;i++){
        for(j=0;j<NB_COLONNES_PLATEAUBATAILLE;j++){
            plateauBataille[i][j]=0;
        }
    }
    for(i=0;i<NB_LIGNES_UNITESJOUEURS;i++){
        if(unitesJoueurs[i][NUM_JOUEUR_UJ]==numJoueurHumain && unitesJoueurs[i][UNITE_ACTIVE]==1){
            ligne_vide=chercherIndiceAvecUneCondition(NUM_JOUEUR_UB,-1,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
            if(ligne_vide!=-1){
               unitesBataille[ligne_vide][NUM_JOUEUR_UB]=unitesJoueurs[i][NUM_JOUEUR_J];
               unitesBataille[ligne_vide][NUM_UNITE_UB]=unitesJoueurs[i][NUM_UNITE_UJ];
               unitesBataille[ligne_vide][TYPE_UB]=unitesJoueurs[i][TYPE_UJ];
               unitesBataille[ligne_vide][SANTE_RESTANTE_UB]=unitesJoueurs[i][SANTE_UJ];
               unitesBataille[ligne_vide][ATTAQUE_UB]=unitesJoueurs[i][ATTAQUE_UJ];
               unitesBataille[ligne_vide][DEFENSE_UB]=unitesJoueurs[i][DEFENSE_UJ];
               unitesBataille[ligne_vide][DEGATS_UB]=unitesJoueurs[i][DEGATS_UJ];
               unitesBataille[ligne_vide][MOUVEMENTS_UB]=unitesJoueurs[i][MOUVEMENTS_UJ];
               unitesBataille[ligne_vide][NOMBRE_UNITES_UB]=unitesJoueurs[i][NOMBRE_UJ];
               unitesBataille[ligne_vide][SANTE_UNITAIRE_UB]=unitesJoueurs[i][SANTE_UJ];
               unitesBataille[ligne_vide][LIGNE_UB]=NB_LIGNES_UNITESBATAILLE-1;
               unitesBataille[ligne_vide][COLONNE_UB]=colonne_unite;
               unitesBataille[ligne_vide][FINTOUR_UB]=0;
               plateauBataille[NB_LIGNES_UNITESBATAILLE-1][colonne_unite]=unitesBataille[ligne_vide][NUM_UNITE_UB]*1000+numJoueurHumain*100+10;
               colonne_unite+=2;

            }
        }

          if(unitesJoueurs[i][NUM_JOUEUR_UJ]==numJoueurEnnemi && unitesJoueurs[i][UNITE_ACTIVE]==1){
            ligne_vide=chercherIndiceAvecUneCondition(NUM_JOUEUR_UB,-1,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
            if(ligne_vide!=-1){
               unitesBataille[ligne_vide][NUM_JOUEUR_UB]=unitesJoueurs[i][NUM_JOUEUR_J];
               unitesBataille[ligne_vide][NUM_UNITE_UB]=unitesJoueurs[i][NUM_UNITE_UJ];
               unitesBataille[ligne_vide][TYPE_UB]=unitesJoueurs[i][TYPE_UJ];
               unitesBataille[ligne_vide][SANTE_RESTANTE_UB]=unitesJoueurs[i][SANTE_UJ];
               unitesBataille[ligne_vide][ATTAQUE_UB]=unitesJoueurs[i][ATTAQUE_UJ];
               unitesBataille[ligne_vide][DEFENSE_UB]=unitesJoueurs[i][DEFENSE_UJ];
               unitesBataille[ligne_vide][DEGATS_UB]=unitesJoueurs[i][DEGATS_UJ];
               unitesBataille[ligne_vide][MOUVEMENTS_UB]=unitesJoueurs[i][MOUVEMENTS_UJ];
               unitesBataille[ligne_vide][NOMBRE_UNITES_UB]=unitesJoueurs[i][NOMBRE_UJ];
               unitesBataille[ligne_vide][SANTE_UNITAIRE_UB]=unitesJoueurs[i][SANTE_UJ];
               unitesBataille[ligne_vide][LIGNE_UB]=0;
               unitesBataille[ligne_vide][COLONNE_UB]= colonne_unite_enemi;
               unitesBataille[ligne_vide][FINTOUR_UB]=0;
                colonne_unite_enemi+=2;
               plateauBataille[unitesBataille[ligne_vide][LIGNE_UB]][unitesBataille[ligne_vide][COLONNE_UB]]=unitesBataille[ligne_vide][NUM_UNITE_UB]*1000+numJoueurEnnemi*100+10;
            }
        }
    }
}
int jouerTourHumainBataille ( int numJoueur, int numJoueurEnnemi,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] )
{   int indice_joueur_humain_unitebataille,indice_joueur_enemi_unitebataille;
    int num_unite_joueurhumain;
    int type_unite_jhumain;
    int ligne_corr_jhumain,colonne_corr_jhumain;
    int num_unite_enemi;
    int nb_mouvement_joueurh;
    int deplacer_oui_non;
    int ligne_deplacer;
    int colonne_deplacer;
    int code_attaque_adjacent;
    int ligne_enemi_attaquer,colonne_enemi_attaquer;
    int unite_attaque_adjacent;
    int attque_oui_non;
    int ligne_coraante_enemi;
    int colonne_corrante_enemi;
    int code_attaque_contre;
    do{
            afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);

    do{
     printf("Donner le numero d unite a jouer ou -1 si vous voulez forcer la fin du tour : ");
     scanf("%d", &num_unite_joueurhumain);
     indice_joueur_humain_unitebataille=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueur,NUM_UNITE_UB,num_unite_joueurhumain,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
     if(unitesBataille[indice_joueur_humain_unitebataille][FINTOUR_UB]==1){
        indice_joueur_humain_unitebataille=-1;
     }
     }while(num_unite_joueurhumain!=-1 && indice_joueur_humain_unitebataille==-1);
     indice_joueur_humain_unitebataille=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueur,NUM_UNITE_UB,num_unite_joueurhumain,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
    if(indice_joueur_humain_unitebataille!=-1){
    type_unite_jhumain=unitesBataille[indice_joueur_humain_unitebataille][TYPE_UB];
    ligne_corr_jhumain=unitesBataille[indice_joueur_humain_unitebataille][LIGNE_UB];
    colonne_corr_jhumain=unitesBataille[indice_joueur_humain_unitebataille][COLONNE_UB];



        nb_mouvement_joueurh=unitesBataille[indice_joueur_humain_unitebataille][MOUVEMENTS_UB];
        marquerDeplacementsPossibles(plateauBataille,ligne_corr_jhumain,colonne_corr_jhumain,nb_mouvement_joueurh);
        afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
            printf("                                                                      Les cases marque de +++ sont les cases ou l'hero peut deplacer\n");
            do{
            printf("Voulez vous deplacer cet unite (1:oui,0:non) : ");
            scanf("%d", &deplacer_oui_non);
            }while(deplacer_oui_non!=0 && deplacer_oui_non!=1);
            if(deplacer_oui_non==1){
                    do{
                            do{
                    printf("Donner la ligne de la case a jouer (depuis les cases marque en +++)");
                    scanf("%d", &ligne_deplacer);
                            }while(ligne_deplacer<0 || ligne_deplacer>NB_LIGNES_PLATEAUBATAILLE-1);
                            do{
                    printf("Donner la colonne de la case a jouer (depuis les cases marque en +++)");
                    scanf("%d", &colonne_deplacer);
                    }while(colonne_deplacer<0 || colonne_deplacer>NB_COLONNES_UNITESBATAILLE-1);
                    }while(plateauBataille[ligne_deplacer][colonne_deplacer]!=1);
                    printf("                                                               ---Deplacement de l'unite %d du joueur humain de la case(%d,%d) a la case (%d,%d)---\n", num_unite_joueurhumain,ligne_corr_jhumain,colonne_corr_jhumain,ligne_deplacer,colonne_deplacer);
                    deplacerUnite(numJoueur,indice_joueur_humain_unitebataille,num_unite_joueurhumain,ligne_corr_jhumain,colonne_corr_jhumain,ligne_deplacer,colonne_deplacer,plateauBataille,unitesBataille);
                    effacerDeplacementsPossibles(plateauBataille);
                    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
                    }
                    else{
                        effacerDeplacementsPossibles(plateauBataille);
                    }
                    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
                    ligne_corr_jhumain=unitesBataille[indice_joueur_humain_unitebataille][LIGNE_UB];
                    colonne_corr_jhumain=unitesBataille[indice_joueur_humain_unitebataille][COLONNE_UB];
                    code_attaque_adjacent=codeAttaqueSansDeplacement(numJoueur,type_unite_jhumain,ligne_corr_jhumain,colonne_corr_jhumain,plateauBataille);
        if(code_attaque_adjacent>=1){
        printf("cet unite a la posibilite d'attaquer\n");
        printf("Voulez vous attaquer une unite enemi (1-oui,0-non) : ");
        scanf("%d", &attque_oui_non);
        if(attque_oui_non==1){
        do{
        do{
        printf("Entrer la ligne de joueur enemi attaquer : ");
        scanf("%d", &ligne_enemi_attaquer);
        }while(ligne_enemi_attaquer<0 || ligne_enemi_attaquer>NB_LIGNES_PLATEAUBATAILLE-1);
        do{
        printf("Entrer la colonne de joueur enemi a attaquer : ");
        scanf("%d", &colonne_enemi_attaquer);
        }while(colonne_enemi_attaquer<0 || colonne_enemi_attaquer>NB_COLONNES_PLATEAUBATAILLE-1);
        }while(plateauBataille[ligne_enemi_attaquer][colonne_enemi_attaquer]/100%10!=numJoueurEnnemi);
        num_unite_enemi=plateauBataille[ligne_enemi_attaquer][colonne_enemi_attaquer]/1000;
        indice_joueur_enemi_unitebataille=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueurEnnemi,NUM_UNITE_UB,num_unite_enemi,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
        unite_attaque_adjacent=uniteAttaquable(code_attaque_adjacent,ligne_corr_jhumain,colonne_corr_jhumain,ligne_enemi_attaquer,colonne_enemi_attaquer);
        if(unite_attaque_adjacent==1){
        attaque(indice_joueur_humain_unitebataille,indice_joueur_enemi_unitebataille,numJoueur,numJoueurEnnemi,ligne_corr_jhumain,colonne_corr_jhumain,plateauBataille,unitesBataille,joueurs);
        }
        afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);


        //contre attaque de joueur enemi
        indice_joueur_enemi_unitebataille=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueurEnnemi,NUM_UNITE_UB,num_unite_enemi,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
        if(indice_joueur_enemi_unitebataille!=-1){
        ligne_coraante_enemi=unitesBataille[indice_joueur_enemi_unitebataille][LIGNE_UB];
        colonne_corrante_enemi=unitesBataille[indice_joueur_enemi_unitebataille][COLONNE_UB];
            code_attaque_contre=codeAttaqueSansDeplacement(numJoueurEnnemi,numJoueur,ligne_coraante_enemi,colonne_corrante_enemi,plateauBataille);

        if(code_attaque_contre>=1){
                printf("<<contre attaque de joueur enemi %d>>\n", numJoueurEnnemi);
                 attaque(indice_joueur_enemi_unitebataille,indice_joueur_humain_unitebataille,numJoueurEnnemi,numJoueur,ligne_coraante_enemi,colonne_corrante_enemi,plateauBataille,unitesBataille,joueurs);
        }
        }
}
}
}
if(num_unite_joueurhumain !=-1){
     unitesBataille[indice_joueur_humain_unitebataille][FINTOUR_UB]=1;
}
if(verificationGagnant(numJoueur,numJoueurEnnemi,unitesBataille)!=-1){
    return verificationGagnant(numJoueur,numJoueurEnnemi,unitesBataille);
}
}while(num_unite_joueurhumain!=-1 && verificationFinTours(numJoueur,unitesBataille)==0);
return verificationGagnant(numJoueur,numJoueurEnnemi,unitesBataille);
}



void deplacementAutomatiqueUnite( int numJoueur, int typeUnite,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int ligne_courante, int colonne_courante,
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE],
int indiceUnite ){
int i,j,nouvelle_ligne,nouvelle_colonne,code_attaque;
int num_unite=unitesBataille[indiceUnite][NUM_UNITE_UB];
i=0;j=0;nouvelle_ligne=0;nouvelle_colonne=0;
code_attaque=0;
while(i<NB_LIGNES_PLATEAUBATAILLE && code_attaque<1){
        j=0;
    while(j<NB_COLONNES_PLATEAUBATAILLE && code_attaque<1){
        if(plateauBataille[i][j]==1){
            nouvelle_ligne=i;
            nouvelle_colonne=j;
            code_attaque=codeAttaqueSansDeplacement(numJoueur,typeUnite,nouvelle_ligne,nouvelle_colonne,plateauBataille);
        }
        j=j+1;
    }
    i++;
}
deplacerUnite(numJoueur,indiceUnite,num_unite,ligne_courante,colonne_courante,nouvelle_ligne,nouvelle_colonne,plateauBataille,unitesBataille);
}
int choixAutomatiqueUniteEnnemie ( int numJoueurEnnemi, int codeAttaque,
int ligne_courante, int colonne_courante,
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] )
{  int droite,gauche,haut,bas;
   int unite_a_attaquer=0;
    int i=0;
    if(codeAttaque==1){
        while(unite_a_attaquer==0){
            if(unitesBataille[i][NUM_JOUEUR_UB]==numJoueurEnnemi){
                return unitesBataille[i][NUM_UNITE_UB];
            }
            i++;
        }
    }
    else if(codeAttaque>1){

   haut=codeAttaque/10000;
   bas=(codeAttaque%10000)/1000;
   gauche=((codeAttaque%10000)%1000)/100;
   droite=(((codeAttaque%10000)%1000)%100)/10;
   if(droite==1)
{
    return plateauBataille[ligne_courante][colonne_courante+1]/1000;
}
   if(gauche==1)
{
    return plateauBataille[ligne_courante][colonne_courante-1]/1000;
}
   if(haut==1)
{
    return plateauBataille[ligne_courante-1][colonne_courante]/1000;
}
  if(bas==1)
{
    return plateauBataille[ligne_courante+1][colonne_courante]/1000;
}}
return 0;
}
int jouerTourEnnemiBataille ( int numJoueur, int numJoueurEnnemi,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE] ){
int indice_unite_a_jouer=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueurEnnemi,FINTOUR_UB,0,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);;
//int num_unite_a_jouer=unitesBataille[indice_unite_a_jouer][NUM_UNITE_UB];
int ligne_corrante=unitesBataille[indice_unite_a_jouer][LIGNE_UB];
int colonne_corrante=unitesBataille[indice_unite_a_jouer][COLONNE_UB];
int type_unite=unitesBataille[indice_unite_a_jouer][TYPE_UB];
int mouvement_unite=unitesBataille[indice_unite_a_jouer][MOUVEMENTS_UB];
int unite_enemi_a_attaquer;
int indice_unite_a_attaquer;
int ligne_corrante_humain,colonne_corrante_humain;
int verif_fin_tours,verif_gagnant;
int code_attaque=codeAttaqueSansDeplacement(numJoueurEnnemi,type_unite,ligne_corrante,colonne_corrante,plateauBataille);
int code_attaque_contre;
do{
afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
indice_unite_a_jouer=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueurEnnemi,FINTOUR_UB,0,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
ligne_corrante=unitesBataille[indice_unite_a_jouer][LIGNE_UB];
colonne_corrante=unitesBataille[indice_unite_a_jouer][COLONNE_UB];
type_unite=unitesBataille[indice_unite_a_jouer][TYPE_UB];
mouvement_unite=unitesBataille[indice_unite_a_jouer][MOUVEMENTS_UB];
code_attaque=codeAttaqueSansDeplacement(numJoueurEnnemi,type_unite,ligne_corrante,colonne_corrante,plateauBataille);
if(code_attaque==1){
    unite_enemi_a_attaquer=choixAutomatiqueUniteEnnemie(numJoueur,code_attaque,ligne_corrante,colonne_corrante,plateauBataille,unitesBataille);
    indice_unite_a_attaquer=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueur,NUM_UNITE_UB,unite_enemi_a_attaquer,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
    ligne_corrante_humain=unitesBataille[indice_unite_a_attaquer][LIGNE_UB];
    colonne_corrante_humain=unitesBataille[indice_unite_a_attaquer][COLONNE_UB];
    if(uniteAttaquable(code_attaque,ligne_corrante,colonne_corrante,ligne_corrante_humain,colonne_corrante_humain)==1){
        attaque(indice_unite_a_jouer,indice_unite_a_attaquer,numJoueurEnnemi,numJoueur,ligne_corrante,colonne_corrante,plateauBataille,unitesBataille,joueurs);
    }
    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
    code_attaque_contre=codeAttaqueSansDeplacement(numJoueur,unitesBataille[indice_unite_a_attaquer][TYPE_UB],ligne_corrante_humain,colonne_corrante_humain,plateauBataille);
    if(code_attaque_contre>1){
        attaque(indice_unite_a_attaquer,indice_unite_a_jouer,numJoueur,numJoueurEnnemi,ligne_corrante_humain,colonne_corrante_humain,plateauBataille,unitesBataille,joueurs);
    }

}
else{
    marquerDeplacementsPossibles(plateauBataille,ligne_corrante,colonne_corrante,mouvement_unite);
    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
    deplacementAutomatiqueUnite(numJoueurEnnemi,type_unite,plateauBataille,ligne_corrante,colonne_corrante,unitesBataille,indice_unite_a_jouer);
    effacerDeplacementsPossibles(plateauBataille);
    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);
    ligne_corrante=unitesBataille[indice_unite_a_jouer][LIGNE_UB];
    colonne_corrante=unitesBataille[indice_unite_a_jouer][COLONNE_UB];
    code_attaque=codeAttaqueSansDeplacement(numJoueurEnnemi,type_unite,ligne_corrante,colonne_corrante,plateauBataille);
    if(code_attaque>1){
    unite_enemi_a_attaquer=choixAutomatiqueUniteEnnemie(numJoueur,code_attaque,ligne_corrante,colonne_corrante,plateauBataille,unitesBataille);
    indice_unite_a_attaquer=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UB,numJoueur,NUM_UNITE_UB,unite_enemi_a_attaquer,NB_LIGNES_UNITESBATAILLE,NB_COLONNES_UNITESBATAILLE,unitesBataille);
    ligne_corrante_humain=unitesBataille[indice_unite_a_attaquer][LIGNE_UB];
    colonne_corrante_humain=unitesBataille[indice_unite_a_attaquer][COLONNE_UB];
    if(uniteAttaquable(code_attaque,ligne_corrante,colonne_corrante,ligne_corrante_humain,colonne_corrante_humain)==1){
        attaque(indice_unite_a_jouer,indice_unite_a_attaquer,numJoueurEnnemi,numJoueur,ligne_corrante,colonne_corrante,plateauBataille,unitesBataille,joueurs);
    }
    printf("<<contre attaque de joueur %d>>\n", numJoueur);
    code_attaque_contre=codeAttaqueSansDeplacement(numJoueur,unitesBataille[indice_unite_a_attaquer][TYPE_UB],ligne_corrante_humain,colonne_corrante_humain,plateauBataille);
    if(code_attaque_contre>1){
        attaque(indice_unite_a_attaquer,indice_unite_a_jouer,numJoueur,numJoueurEnnemi,ligne_corrante_humain,colonne_corrante_humain,plateauBataille,unitesBataille,joueurs);
    }
    afficherPlateauBataille(numJoueur,numJoueurEnnemi,plateauBataille,unitesBataille);

    }
}

unitesBataille[indice_unite_a_jouer][FINTOUR_UB]=1;
verif_fin_tours=verificationFinTours(numJoueurEnnemi,unitesBataille);
verif_gagnant=verificationGagnant(numJoueur,numJoueurEnnemi,unitesBataille);
if(verif_gagnant!=-1){
    return verif_gagnant;
}
}while(verif_fin_tours==0);
 return verif_gagnant;
}

void deroulerBataille ( int numJoueur, int numJoueurEnnemi,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] ){
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE];
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE];
int nombre_tour=0;
int joueur_gagnant,joueur_perdant;
int verif_gagnant_tourhumain;
int verif_gagnant_tourenemi;
int indice_joueur_gagnant_joueurs,indice_joueur_perdant_joueurs;
int i;
initialiserBataille(numJoueur,numJoueurEnnemi,herosJoueurs,unitesJoueurs,plateauBataille,unitesBataille);
    do{
            reinitialiserToursBataille(unitesBataille);
    nombre_tour++;
             printf("\n                    ------------------- tour numero %d : -------------------\n", nombre_tour);
            printf("\n                    ------------------- tour de joueur humain-------------------\n");
        verif_gagnant_tourhumain=jouerTourHumainBataille(numJoueur,numJoueurEnnemi,joueurs,herosJoueurs,plateauBataille,unitesBataille);
            printf("\n                    ------------------- tour de joueur enemi-------------------\n");
        verif_gagnant_tourenemi=jouerTourEnnemiBataille(numJoueur,numJoueurEnnemi,joueurs,herosJoueurs,plateauBataille,unitesBataille);
}while(verif_gagnant_tourenemi==-1 && verif_gagnant_tourhumain==-1);
    if(verif_gagnant_tourhumain==numJoueur || verif_gagnant_tourenemi==numJoueur){
       joueur_gagnant=numJoueur;
       joueur_perdant=numJoueurEnnemi;
       indice_joueur_gagnant_joueurs=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,joueur_gagnant,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
       indice_joueur_perdant_joueurs=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,joueur_perdant,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
       joueurs[indice_joueur_gagnant_joueurs][NB_BATAILLE_GAGNES]+=1;
       joueurs[indice_joueur_perdant_joueurs][NB_BATAILLE_PERDUES]+=1;
       for(i=OR;i<=GEMME_JAUNE;i++){
        joueurs[indice_joueur_gagnant_joueurs][i]+=joueurs[indice_joueur_perdant_joueurs][i];
        joueurs[indice_joueur_perdant_joueurs][i]=0;
       }
       printf("\n                               ---------------------------Fin bataille---------------------\n");
       printf("\n                                                 le joueur humain est le joueur gagant \n");
    }
    if(verif_gagnant_tourenemi == numJoueurEnnemi || verif_gagnant_tourhumain == numJoueurEnnemi){
        joueur_gagnant=numJoueurEnnemi;
        joueur_perdant=numJoueur;
        indice_joueur_gagnant_joueurs=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,numJoueurEnnemi,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
        indice_joueur_perdant_joueurs=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,numJoueur,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
        joueurs[indice_joueur_gagnant_joueurs][NB_BATAILLE_GAGNES]+=1;
        joueurs[indice_joueur_perdant_joueurs][NB_BATAILLE_PERDUES]+=1;
        printf("\n                               ---------------------------Fin bataille---------------------\n");
       printf("\n                                                 le joueur numero %d est le joueur gagant \n", joueur_gagnant);
        }

sauvegarderTableauDansFichier( NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS, joueurs,"joueurs_sauvgarde.txt");
sauvegarderTableauDansFichier( NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,  unitesJoueurs,"unitesJoueurs_sauvegarde.txt");
sauvegarderTableauDansFichier( NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs ,"herosJoueurs_sauvegarde.txt");
}
 void executerAction(
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
    int choix,ligne_joueur,position_joueur_ligne,position_joueur__colonne,lig_hero_principale,num_enemi;
ligne_joueur=chercherIndiceAvecUneCondition(NUM_JOUEUR_J,0,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs);
position_joueur_ligne=joueurs[ligne_joueur][LIGNE_J];
position_joueur__colonne=joueurs[ligne_joueur][COLONNE_J];
num_enemi=carte[position_joueur_ligne][position_joueur__colonne]/100;

if(carte[position_joueur_ligne][position_joueur__colonne]%100/10==1){
        do{
 printf("Confirmer vous l'entree en bataille avec l'enemie %d(non=0,oui=1)", num_enemi);
 scanf("%d", &choix);
 }while(choix!=0 && choix!=1);
  if(choix==1){
    deroulerBataille(0,num_enemi,joueurs,herosJoueurs,unitesJoueurs);
  }
}
if(carte[position_joueur_ligne][position_joueur__colonne]%100/10==2){
        if(carte[position_joueur_ligne][position_joueur__colonne]/100==0){
            printf("Cette caisse a ete deja ouvert\n");
        }
        else {
        do{
    printf("Voulez vous ajouter  %d piece d'or a votre fortune (non=0,oui=1)", carte[position_joueur_ligne][position_joueur__colonne]/100);
 scanf("%d", &choix);
}while(choix!=0 && choix!=1);
   if(choix==1){
   joueurs[ligne_joueur][OR]=joueurs[ligne_joueur][OR]+carte[position_joueur_ligne][position_joueur__colonne]/100;
   carte[position_joueur_ligne][position_joueur__colonne]=carte[position_joueur_ligne][position_joueur__colonne]%100;
}
}
}

if(carte[position_joueur_ligne][position_joueur__colonne]%100/10==3){
        if(carte[position_joueur_ligne][position_joueur__colonne]/100==0){
                printf("Ce coffre a ete deja ouvert");}
        else{
    printf("Voulez vous ajouter %d points experience a votre hero (non=0,oui=1)", carte[position_joueur_ligne][position_joueur__colonne]/100);
    scanf("%d", &choix);
    if(choix==1){
           lig_hero_principale=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);
            if(lig_hero_principale==-1){
                printf("\nVous n'avez pas un hero principale\n");
            }
            else{
    herosJoueurs[lig_hero_principale][POINTS_EXPERIENCE]+=carte[position_joueur_ligne][position_joueur__colonne]/100;
    carte[position_joueur_ligne][position_joueur__colonne]=carte[position_joueur_ligne][position_joueur__colonne]%100;
    afficherTableauDeuxConditions(NUM_JOUEUR_HJ,0,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");}
    }
}
}
}
void deroulerJeu(
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
char choix;
int valeurcase,i,j;
do{
printf("\n<<<<<  joueur humain  >>>>>\n");
afficherTableauUneCondition(NUM_JOUEUR_J,0,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
printf("<<<<<  carte de jeu  >>>>>\n");
 afficherCarte(carte);
printf("<<<<<  contenu de la case du joueur >>>>>\n");
for(i=0;i<NB_LIGNES_CARTE;i++){
    for(j=0;j<NB_COLONNES_CARTE;j++){
        if(carte[i][j]%10==2){
            valeurcase=carte[i][j];
        }
    }
}
afficherContenuCaseCarte(valeurcase,herosJoueurs);
printf("Entrer votre choix (h=haut , b=bas, g=gauche, d=droite, a=action, 0=menu principal) : ");
scanf(" %c", &choix);
if(choix=='a'){
executerAction(carte,joueurs,herosJoueurs,unitesJoueurs,plateauBataille,unitesBataille);
}
else if (choix=='h' || choix=='b' || choix=='g' || choix=='d'){
    avancer(choix,carte,joueurs);}
}while(choix!='0');
printf("\n");
sauvegarderTableauDansFichier(NB_LIGNES_CARTE,NB_COLONNES_CARTE,carte,"carte_sauvegarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_sauvgarde.txt");
sauvegarderTableauDansFichier(NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs ,"herosJoueurs_sauvegarde.txt");
}
void lancerMenuPrincipal (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS],
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE],
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE]){
int ch;
     do{
printf("\n*************************************\n");
printf("**    Menu principal               **\n");
printf("** 1-Magasin                       **\n");
printf("** 2-Campement                     **\n");
printf("** 3-Reprendre le jeu en cours     **\n");
printf("** 4-Nouvelle partie               **\n");
printf("** 5-Quitter                       **\n");
printf("*************************************\n");
printf("Entrer votre choix (1-5) : ");
scanf("%d", &ch);
switch (ch){
    case 1 : {
    lancerMenuMagasin(joueurs,heros,herosJoueurs,unites,unitesJoueurs);
}break;
  case  2 : {
     lancerMenuCampement(joueurs,herosJoueurs,unitesJoueurs);
   }break;
    case  3 : {
    deroulerJeu(carte,joueurs,heros,herosJoueurs,unites,unitesJoueurs,plateauBataille,unitesBataille);
    }break;
     case  4 :{
    initialiserNouveauJeu(carte,joueurs,heros,herosJoueurs,unites,unitesJoueurs);
        }break;
}}while(ch!=5);
}



int main()
{ int choix;
 int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE];
 int Joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS];
 int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS];
 int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS];
 int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES];
 int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS];
int plateauBataille[NB_LIGNES_PLATEAUBATAILLE][NB_COLONNES_PLATEAUBATAILLE];
int unitesBataille[NB_LIGNES_UNITESBATAILLE][NB_COLONNES_UNITESBATAILLE];
  while((choix!=1) && (choix!=2))
   {
    printf("*************************************\n");
    printf("**Heroes magic war - character mode**\n");
    printf("*************************************\n");
    printf("** 1 - Nouvelle partie             **\n");
    printf("** 2 - Charger partie              **\n");
    printf("*************************************\n");
    printf("Entrer votre choix (1-2) : \n");
    scanf("%d", &choix);}
   if (choix == 1){
    initialiserNouveauJeu(carte,Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
    afficherTableauxJeu(Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
    sauvegarderJeuComplet(carte,Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
   }
    else{
        {
         chargerJeuComplet(carte,Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
         afficherTableauxJeu(Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
         sauvegarderJeuComplet(carte,Joueurs,heros,herosJoueurs,unites,unitesJoueurs);
         }

}
         lancerMenuPrincipal(carte,Joueurs,heros,herosJoueurs,unites,unitesJoueurs,plateauBataille,unitesBataille);

      return 0;


}


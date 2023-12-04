/*
    Nom du fichier : gestion.c
    Auteur         : Level MBANGO , Fanck TAKAM , Zachee NJILA 
    Date           : 20/04/2023
    Role           : contient les fonctions qui gèrent le tableau "grille" après le début d'une partie ainsi que les bots

*/


#include <stdlib.h>
#include <stdio.h>

#include "jeu.h"
#include "constantes.h"
#include "gestion.h"

void initialiser_grille(int grille[][8]) //initialiser la grille
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            grille[i][j]=VIDE;
 }
    }
    grille[3][d]=BLANC;
    grille[3][e]=NOIR;
    grille[4][d]=NOIR;
    grille[4][e]=BLANC;
}
int case_existe (int ligne,int colonne) //vérifier si les coordonnées sont dans la grille
{
    return ((colonne >= 0) && (colonne < 8) && (ligne >= 0) && (ligne < 8));
}
int coup_valide(int grille[8][8],int ligne,int colonne,int joueur) //vérifier si le coup est valide ou non
{
    int i, j, trouver;
    int caractere_joueur, caractere_adversaire;

    if (joueur == BLANC)
    {
        caractere_joueur = BLANC;
        caractere_adversaire = NOIR;
    }
    else
    {
        caractere_joueur = NOIR;
        caractere_adversaire = BLANC;
    }
    if (!case_existe(ligne, colonne) || grille[ligne][colonne] !=VIDE)
        return 0;

    i = ligne-1;
    trouver = 0;
    while (case_existe(i, colonne) && grille[i][colonne] == caractere_adversaire)
    {
        i--;
        trouver = 1;
    }
    if (case_existe(i, colonne) && grille[i][colonne] == caractere_joueur && trouver == 1)
        return 1;

    i = ligne + 1;
    trouver = 0;
    while (case_existe(i, colonne) && grille[i][colonne] == caractere_adversaire)
    {
        i++;
        trouver = 1;
    }
    if (case_existe(i, colonne) && grille[i][colonne] == caractere_joueur && trouver == 1)
        return 1;

    j = colonne-1;
    trouver = 0;
    while (case_existe(ligne, j) && grille[ligne][j] == caractere_adversaire)
    {
        j--;
        trouver = 1;
    }
    if (case_existe(ligne, j) && grille[ligne][j] == caractere_joueur && trouver == 1)
        return 1;


    j = colonne + 1;
    trouver = 0;
    while (case_existe(ligne, j) && grille[ligne][j] == caractere_adversaire)
    {
        j++;
        trouver = 1;
    }
    if (case_existe(ligne, j) && grille[ligne][j] == caractere_joueur && trouver == 1)
        return 1;

    i = ligne - 1;
    j = colonne - 1;
    trouver = 0;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i--;
        j--;
        trouver = 1;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur && trouver == 1)
        return 1;

    i = ligne + 1;
    j = colonne + 1;
    trouver = 0;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i++;
        j++;
        trouver = 1;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur && trouver == 1)
        return 1;

    i = ligne - 1;
    j = colonne + 1;
    trouver = 0;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i--;
        j++;
        trouver = 1;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur && trouver == 1)
        return 1;


    i = ligne + 1;
    j = colonne - 1;
    trouver = 0;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i++;
        j--;
        trouver = 1;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur && trouver == 1)
        return 1;
    return 0;
}
void jouez_coup(int grille[][8],int ligne,int colonne,int joueur)
{
    int i, j;
    int caractere_joueur, caractere_adversaire;

    if (joueur == BLANC)
    {
        caractere_joueur = BLANC;
        caractere_adversaire = NOIR;
    }
    else if(joueur==NOIR)
    {
        caractere_joueur =NOIR;
        caractere_adversaire = BLANC;
    }
    grille[ligne][colonne] = caractere_joueur;

    i = ligne - 1;
    while (case_existe(i, colonne) && grille[i][colonne] == caractere_adversaire)
        i--;
    if (case_existe(i, colonne) && grille[i][colonne] == caractere_joueur)
    {
        i = ligne - 1;
        while (grille[i][colonne] == caractere_adversaire)
        {
            grille[i][colonne] = caractere_joueur;
            i--;
        }
    }

    /* Vertical vers le bas */
    i = ligne + 1;
    while (case_existe(i, colonne) && grille[i][colonne] == caractere_adversaire)
        i++;
    if (case_existe(i, colonne) && grille[i][colonne] == caractere_joueur)
    {
        i = ligne + 1;
        while (grille[i][colonne] == caractere_adversaire)
        {
            grille[i][colonne] = caractere_joueur;
            i++;
        }
    }

    /* Horizontal vers la gauche */
    j = colonne - 1;
    while (case_existe(ligne, j) && grille[ligne][j] == caractere_adversaire)
        j--;
    if (case_existe(ligne, j) && grille[ligne][j] == caractere_joueur)
    {
        j = colonne - 1;
        while (grille[ligne][j] == caractere_adversaire)
        {
            grille[ligne][j] = caractere_joueur;
            j--;
        }
    }

    /* Horizontal vers la droite */
    j = colonne + 1;
    while (case_existe(ligne, j) && grille[ligne][j] == caractere_adversaire)
        j++;
    if (case_existe(ligne, j) && grille[ligne][j] == caractere_joueur)
    {
        j = colonne + 1;
        while (grille[ligne][j] == caractere_adversaire)
        {
            grille[ligne][j] = caractere_joueur;
            j++;
        }
    }

    /* Diagonal \ vers le haut */
    i = ligne - 1;
    j = colonne - 1;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i--;
        j--;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur)
    {
        i = ligne - 1;
        j = colonne - 1;
        while (grille[i][j] == caractere_adversaire)
        {
            grille[i][j] = caractere_joueur;
            i--;
            j--;
        }
    }

    /* Diagonal \ vers le bas */
    i = ligne + 1;
    j = colonne + 1;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i++;
        j++;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur)
    {
        i = ligne + 1;
        j = colonne + 1;
        while (grille[i][j] == caractere_adversaire)
        {
            grille[i][j] = caractere_joueur;
            i++;
            j++;
        }
    }

    /* Diagonal / vers le haut */
    i = ligne - 1;
    j = colonne + 1;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i--;
        j++;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur)
    {
        i = ligne - 1;
        j = colonne + 1;
        while (grille[i][j] == caractere_adversaire)
        {
            grille[i][j] = caractere_joueur;
            i--;
            j++;
        }
    }

    /* Diagonal \ vers le bas */
    i = ligne + 1;
    j = colonne - 1;
    while (case_existe(i, j) && grille[i][j] == caractere_adversaire)
    {
        i++;
        j--;
    }
    if (case_existe(i, j) && grille[i][j] == caractere_joueur)
    {
        i = ligne + 1;
        j = colonne - 1;
        while (grille[i][j] == caractere_adversaire)
        {
            grille[i][j] = caractere_joueur;
            i++;
            j--;
        }
    }
}
void proposer_coup(int grille[][8],int joueur)
{
    int caractere_joueur=(joueur==BLANC) ? BLANC_PROPOSE:NOIR_PROPOSE;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(coup_valide(grille,i,j,joueur))
                grille[i][j]=caractere_joueur;
        }
    }
}
void nettoyer_grille(int grille[][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(grille[i][j]==BLANC_PROPOSE || grille[i][j]==NOIR_PROPOSE)
            {
                grille[i][j]=VIDE;
            }
        }
    }
}

int Partie_terminee(int grille[8][8]) // s'il y a encore de coup valide à jouer cette fonction envoit 1 sinon elle envoit 0
{
    int valide=1;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(coup_valide(grille,i,j,BLANC) || coup_valide(grille,i,j,NOIR))
            {
                valide=0;
                break;
            }
        }
        if(!valide)
            break;
    }
    return valide;
}

int nb_poin_noir(int grille[8][8]) // cette fonction calcule le nombre de pion noir dans la grille
{
    int noir=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(grille[i][j]==NOIR)
                noir++;
        }
    }
    return noir;
}

int nb_poin_blanc(int grille[8][8])  // cette fonction calcule le nombre de pion blanc dans la grille
{
    int blanc=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(grille[i][j]==BLANC)
                blanc++;
        }
    }
    return blanc;
}
coup get_coup(int a,int b)
{
    coup position;
    for(int i=0; i<8; i++)
    {
        if(a>i*90+280 && a<(i+1)*90+280)
            position.x=i;
        if(b>i*90 && b<(i+1)*90)
            position.y=i;
    }
    return position;
}
int encore_coup(int grille[8][8],int joueur) // s'il y a encore de coup valide pour un joueur
{
    int valide=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(coup_valide(grille,i,j,joueur))
            {
                valide=1;
                break;
            }
        }
        if(valide)
            break;
    }
    return valide;
}
coup bot(int grille[][8],int couleur,int difficulte)
{
    switch(difficulte)
    {
        case FACILE:
            return bot_facile(grille,couleur);
            break;
        case MOYEN:
            return bot_moyen(grille,couleur);
            break;
        case DIFFICILE:
            return bot_Difficile(grille, couleur);
            break;        
    }
}
coup bot_facile(int grille[][8],int couleur) // ce bot cherche de jouer un coup à l'interieur de la grille(il ne capture pas les extrémités: les lignes et les colonnes extérieures) sinon il cherche un coup possible
{
    coup bot;
    for(int i=1; i<=6; i++) //chercher de jouer un coup à l'interieur de la grille
    {
        for(int j=b; j<g; j++)
        {
            if(coup_valide(grille,i,j,couleur))
            {
                bot.x=i;
                bot.y=j;
                return bot;
            }
        }
    }
    // s'il ne trouve pas un coup possible à l'interieur
    for(int j=a; j<=h; j++)
    {
        if(coup_valide(grille,0,j,couleur))
        {
            bot.x=0;
            bot.y=j;
            return bot;
        }
        if(coup_valide(grille,7,j,couleur))
        {
            bot.x=7;
            bot.y=j;
            return bot;
        }
    }
    for(int i=1;i<7;i++)
    {
        if(coup_valide(grille,i,a,couleur))
        {
            bot.x=i;
            bot.y=a;
            return bot;
        }
        if(coup_valide(grille,i,h,couleur))
        {
            bot.x=i;
            bot.y=h;
            return bot;
        }
    }
}

coup bot_moyen(int grille[][8],int couleur) //ce bot cherche de capturer les extrémités et de ne pas jouer si possible un coup qui vous aidera de les capturer
{
    coup bot;
    //vérifier s'il est possible de jouer un coup en (1,a) , (1,h) , (8,a) , (8,h)
    if(coup_valide(grille,0,a,couleur))
    {
         bot.x=0;
         bot.y=a;
         return bot;
    }
    if(coup_valide(grille,0,h,couleur))
    {
         bot.x=0;
         bot.y=h;
         return bot;
    }
    if(coup_valide(grille,7,a,couleur))
    {
         bot.x=7;
         bot.y=a;
         return bot;
    }
    if(coup_valide(grille,7,h,couleur))
    {
         bot.x=7;
         bot.y=h;
         return bot;
    }

    //sinon chercher à jouer un coup en extrémités
    for(int j=b; j<h; j++)
    {
        if(coup_valide(grille,0,j,couleur))
        {
            bot.x=0;
            bot.y=j;
            return bot;
        }
        if(coup_valide(grille,7,j,couleur))
        {
            bot.x=7;
            bot.y=j;
            return bot;
        }
    }
    for(int i=1;i<7;i++)
    {
        if(coup_valide(grille,i,a,couleur))
        {
            bot.x=i;
            bot.y=a;
            return bot;
        }
        if(coup_valide(grille,i,h,couleur))
        {
            bot.x=i;
            bot.y=h;
            return bot;
        }
    }
    //sinon jouer un coup à l'intérieur(la colonne c,f et la ligne 3,6)
    for(int j=c;j<=f;j++)
    {
        if(coup_valide(grille,2,j,couleur))
        {
            bot.x=2;
            bot.y=j;
            return bot;
        }
        if(coup_valide(grille,5,j,couleur))
        {
            bot.x=5;
            bot.y=j;
            return bot;
        }
    }
    for(int i=3;i<=4;i++)
    {
        if(coup_valide(grille,i,c,couleur))
        {
            bot.x=i;
            bot.y=c;
            return bot;
        }
        if(coup_valide(grille,i,f,couleur))
        {
            bot.x=i;
            bot.y=f;
            return bot;
        }
    }
    //sinon jouer un coup dans les cases qui restent
    for(int j=c;j<g;j++)
    {
        if(coup_valide(grille,1,j,couleur))
        {
            bot.x=1;
            bot.y=j;
            return bot;
        }
        if(coup_valide(grille,6,j,couleur))
        {
            bot.x=6;
            bot.y=j;
            return bot;
        }
    }
    for(int i=2;i<6;i++)
    {
        if(coup_valide(grille,i,b,couleur))
        {
            bot.x=i;
            bot.y=b;
            return bot;
        }
        if(coup_valide(grille,i,g,couleur))
        {
            bot.x=i;
            bot.y=g;
            return bot;
        }
    }
    if(coup_valide(grille,1,b,couleur))
    {
         bot.x=1;
         bot.y=b;
         return bot;
    }
    if(coup_valide(grille,6,b,couleur))
    {
         bot.x=6;
         bot.y=b;
         return bot;
    }
    if(coup_valide(grille,1,g,couleur))
    {
         bot.x=1;
         bot.y=g;
         return bot;
    }
    if(coup_valide(grille,6,g,couleur))
    {
         bot.x=6;
         bot.y=g;
         return bot;
    }
}

/////////////////////////////////////////////
int evaluer_gain(int grille[8][8], int ligne, int colonne, int joueur)
{
    int gain = 0;

    // Déterminer le caractère du joueur et de l'adversaire
    int caractere_joueur, caractere_adversaire;
    if (joueur == BLANC)
    {
        caractere_joueur = BLANC;
        caractere_adversaire = NOIR;
    }
    else
    {
        caractere_joueur = NOIR;
        caractere_adversaire = BLANC;
    }

    // Évaluer le gain potentiel pour chaque direction
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int dx = directions[i][0];
        int dy = directions[i][1];

        int ligne_actuelle = ligne + dx;
        int colonne_actuelle = colonne + dy;

        int gain_direction = 0;
        int adversaire_trouve = 0;

        while (case_existe(ligne_actuelle, colonne_actuelle))
        {
            if (grille[ligne_actuelle][colonne_actuelle] == caractere_adversaire)
            {
                adversaire_trouve = 1;
            }
            else if (grille[ligne_actuelle][colonne_actuelle] == caractere_joueur)
            {
                if (adversaire_trouve)
                {
                    gain_direction++;
                }
                break;
            }
            else
            {
                break;
            }

            ligne_actuelle += dx;
            colonne_actuelle += dy;
        }

        gain += gain_direction;
    }

    return gain;
}

coup bot_Difficile(int grille[8][8], int couleur)
{
    // Chercher les coups valides
    coup coups_valides[64];
    int nb_coups_valides = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (coup_valide(grille, i, j, couleur))
            {
                coups_valides[nb_coups_valides].x = i;
                coups_valides[nb_coups_valides].y = j;
                nb_coups_valides++;
            }
        }
    }

    // Si aucun coup valide, retourner un coup "passer"
    if (nb_coups_valides == 0)
    {
        coup passer;
        passer.x = -1;
        passer.y = -1;
        return passer;
    }

    // Évaluer les gains potentiels pour chaque coup valide
    int gains_potentiels[64];

    for (int k = 0; k < nb_coups_valides; k++)
    {
        int gain = evaluer_gain(grille, coups_valides[k].x, coups_valides[k].y, couleur);
        gains_potentiels[k] = gain;
    }

    // Trouver le coup avec le gain maximal
    int gain_max = -1;
    int index_coup_max = -1;

    for (int k = 0; k < nb_coups_valides; k++)
    {
        if (gains_potentiels[k] > gain_max)
        {
            gain_max = gains_potentiels[k];
            index_coup_max = k;
        }
    }

    // Retourner le coup avec le gain maximal
    return coups_valides[index_coup_max];
}


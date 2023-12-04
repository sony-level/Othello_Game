/*
    Nom du fichier : gestion.h
    Auteur         : Level MBANGO , Fanck TAKAM , Zachee NJILA 
    Date           : 20/04/2023
    Role           : contient les prototypes des fonctions du fichier gestion.h

*/

#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

	void initialiser_grille(int grille[][8]);
	
	int case_existe (int ligne,int colonne);
	
	int coup_valide(int grille[][8],int ligne,int colonne,int joueur);
	
	int evaluer_gain(int grille[8][8], int ligne, int colonne, int joueur);
	
	void jouez_coup(int grille[][8],int ligne,int colonne,int joueur);
	
	void proposer_coup(int grille[][8],int joueur);
	
	void nettoyer_grille(int grille[][8]);
	
	int Partie_terminee(int grille[][8]);
	
	int nb_poin_noir(int grille[][8]);
	
	int nb_poin_blanc(int grille[][8]);
	
	int encore_coup(int grille[][8],int joueur);
	
	coup bot_facile(int grille[][8],int couleur);
	
	coup bot_moyen(int grille[][8],int couleur);
	
	coup bot_Difficile(int grille[8][8], int couleur);

#endif // GESTION_H_INCLUDED

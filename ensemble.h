#include<iostream>
using namespace std;
/***************************************/
/*fonction de recherche retournant 
l'indice si e est dans le tableau et
 -1 sinon*/
int recherche(int t[], int e, int n);

/**************************************/
/*
Un ensemble est représenté par un tableau
dynamique dont la taille varie selon qu'un
élément ait été ajouté ou retiré*/

class Ensemble{
	private :
		/*un ensemble d'entiers*/
		int *ens;
		/*Cardinal d'un ensemble*/
		int card;
	public :
		/*Constructeur par défaut*/
		Ensemble();
		/*constructeur par recopie*/
		Ensemble(const Ensemble &A);
		/*Destructeur*/
		~Ensemble();
		/*Retire l'élément d'indice i et
		 le retourne*/
		int remove(int i);
		/*Ajoute un nouvel élément à ens*/
		void add(int e);
		/*Ajoute un élément première position*/
		void addFirst(int e);
		/*Ajoute un élément à la dernière position*/
		void addLast(int e);
		/*Retourne l'élément situé à la position i*/
		int get(int i);
		/*Retourne la réunion des ensembles
		this et A*/
		Ensemble reunion(Ensemble &A);
		/*Retourne la différence de this par A*/
		Ensemble difference(Ensemble &A);
		/*Retourne l'intersection de this et A*/
		Ensemble intersection(Ensemble &A);
		/*Retourne la taille de ens*/
		int size();
		/*Affiche un ensemble*/
		void affiche();
		/*Comme on a modifié le constructeur par
		 recopie par défaut, on surcharge =*/
		Ensemble& operator=(Ensemble const &);
};


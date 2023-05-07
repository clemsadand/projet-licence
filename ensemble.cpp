#include"ensemble.h"

/**********************************/

int recherche(int t[], int e, int n){
	for(int i=0; i<n; i++){
		if(t[i]==e)
			return i;
	}
	
	return -1;
}

/*********************************/

Ensemble::Ensemble(){
	ens = new int;//allocation dynamique de T place
	card = 0;
}

/*********************************/

Ensemble::Ensemble(const Ensemble &A){
	card = A.card;
	if(card==0)
		ens = new int;
	if(card>0){
		for(int i=0; i<card; i++)
			*(ens+i) = *(A.ens+i);
	}
}

/***********************************/

Ensemble::~Ensemble(){
	delete [] ens;
}

/**********************************/

void Ensemble::add(int e){
	/*Si ens est vide, on lui ajoute e*/
	if(card==0){
		*ens = e;
		card = 1;
	}
	/*Si ens contient plus d'un élément,
	alors*/
	if(card>0){
	/*Si e n'est pas déjà dans ens,
	 on l'ajoute à ens*/
		if(recherche(ens, e, card)==-1){
			/*Tableau tampon*/
			int T[card];
			//Copie des éléments de ens
   			for(int i=0;i<card;i++)
        			T[i] = *(ens+i);
			/*On libère la mémoire occupée
			 par ens*/
			delete ens;
     		/*Retourne augmente d'un
     		 la taille de ens*/
			ens = new int[++card];
			//On redéfinie ens 
   	 		for(int i=0;i<card-1;i++)
        		 *(ens+i) = T[i];
	 		*(ens+card-1) = e;
		}
	}
}

/**********************************/

void Ensemble::addFirst(int e){
	/*ajoute le premier élément*/
	if(card==0){
		*ens = e;
		card = 1;
	}
	if(card>0){
	/*on vérifie si e n'est pas déjà dans ens*/
		if(recherche(ens, e, card)==-1){
			/*Tablleau tampon*/
  	       int T[card];
    	     /*opie des éléments de ens*/
        	 for(int i=0;i<card;i++)
        	     T[i] = *(ens+i);
 			/*on libère la mémoire occupée par ens*/
        	 delete ens;
 			/*On augmente d'un la taille de ens*/
        	 ens = new int[++card];
        	 /*on redéfinie ens*/
			 *ens = e; 
        	 for(int i=1;i<card;i++)
            	  *(ens+i) = T[i-1];
		}
     }
}

/********************************/

void Ensemble::addLast(int e){
	/*Ajoute e à la dernière position*/
	add(e);
	int r = recherche(ens, e, card);
	/*Tel que la fonction add est définie
	 aucun élément ne se repète dans ens
	  donc il est nécessaire de s'assurer
	   que e est bien à la dernière 
	   position dans le cas où e est
	    déjà dans ens*/
	 /*Si e n'est pas sa borne place,
	  on effectue une permutation */
	if(r!=card-1){
		*(ens+r) = *(ens+card-1);
		*(ens+card-1) = e;
	}
}

/*******************************/

int Ensemble::get(int i){
	/*Retourne l'élément situé 
	à la position i*/
	return *(ens+i-1);
}

/************************************************************************/

int Ensemble::remove(int i){
	
	if(card==1)
		if(i==1){
			int v =*ens;
			delete ens;
			ens = new int;
			card =0;
		}
	if(card>1){
		if(i>=1 && i<=card){
			int v = *(ens+i-1), k =0;
			int A[card];
			for(int j=0; j<card ;j++)
				A[j] = *(ens+j);
			delete ens;
			card = 0;
			ens = new int;
			//ens = new int[--card];
			for(int j=0; j < sizeof(A)/sizeof(int) ; j++)
				if(j!=i-1)
					add(A[j]);
			return v;
		}
	}
}

/***************************************/

Ensemble Ensemble::intersection(Ensemble &A){
	Ensemble I;
	int ind;
	//On prend un élément de A, s'il est dans ens
	// on l'ajoute à inter, sinon on le laisse
	for(int i=0; i<A.card; i++){
		ind = recherche(ens, *(A.ens+i) , card);
		if(ind != -1)
			I.add(*(ens+ind));
	}
	return I;
}

/**************************************/

Ensemble Ensemble::difference(Ensemble &A){
	Ensemble dif;//difference de ens par A
	int ind, T[card], k=0;
	/*On prend un élément de ens, s'il  n'est pas dans A, alors on l'ajoute à dif
	 * sinon on le laisse */
	for(int i=0; i<card ; i++){
		ind = recherche(A.ens, *(ens+i), A.card);
		if(ind==-1)
			dif.add(*(ens+i));
	}
	/*for(int i=0;i<k; i++)
		dif.add(T[i]);
	cout<<dif.card<<endl;*/
	return dif;
}

/*************************************/

Ensemble Ensemble::reunion(Ensemble &A){
	Ensemble U;
	int max, min;
	/*cardinale de ens*/
	min = card;
	/*cardinale de ens union A*/
	max = min + A.card;
	//U est la réunion de I et A
	for(int i=0; i<max ; i++){
		if(i<min)
			U.add(*(ens+i));
		else
			U.add(*(A.ens+i-min));
	}
	return U;
}

/************************************/

int Ensemble::size(){ return card; }

/***********************************/
void Ensemble::affiche(){
	for(int i=0; i<card ; i++)
		cout<<*(ens+i)<<" ";
	cout<<endl;
}

/***********************************/

Ensemble& Ensemble::operator=(Ensemble const &A){
	
	for(int i=0; i<A.card ; i++)
		add(*(A.ens+i));
	return *this;
}

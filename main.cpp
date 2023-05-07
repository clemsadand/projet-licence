#include"ensemble.h"

int main(){
	Ensemble A, B, I;
	int v;	
	A.add(2);
	A.add(3);
	A.add(4);
	A.addFirst(-6);
	A.addLast(2);
	
	B.add(1);
	B.add(2);
	B.add(3);
	B.add(6);
	v = B.remove(2);
	A.affiche();
	B.affiche();
	//I = A.intersection(B);
	//I.affiche();

	I = B.reunion(A);
	I.affiche();
	//cout<<A.get(3)<<endl;
	//cout<<I.size()<<endl;
	return 0;
}

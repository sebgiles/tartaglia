//stampa il triangolo di tartaglia
#include <iostream>
using namespace std;
#define CELLA_DEFAULT 6
#define RIGHE_DEFAULT 12
void incrementa(int* &sopra){
	int l=0;
	while(sopra[l++]!=0);
	int* sotto=new int[l+1];
	sotto[0]=1;
	sotto[l]=0;
	for (int i=1; i<l; i++) sotto[i]=sopra[i-1]+sopra[i];
	delete [] sopra;
	sopra = sotto;
}
//prende array dei numeri, la dimensione di una cella e il numero di righe che
//dovrà disegnare dopo questa
void stampa(int* riga, int cella, int n){
	n*=(cella/2);
	while(n--) cout << ' '; //ogni riga è mezza cella più a sinistra
	static int nmax=1;
	if(nmax==1) for(int i=0; i<cella; i++) nmax*=10; //cella+1 cifre non entrano
	int x, i=0;
	while((x=riga[i++])!=0){
		cout << x;
		while((x*=10)<nmax) cout << ' '; //per ogni cifra in meno lascia uno spazio
	}
	cout << endl;
}
//argomenti: numero di righe, dimensione di una cella (hanno rispettivi DEFAULT)
int main(int argc, char* argv[]){
	int* riga=new int[1];
	riga[0]=0;
	int nrighe=(argc<2)?(RIGHE_DEFAULT):(atoi(argv[1]));
	int dimcella=(argc<3)?(CELLA_DEFAULT):(atoi(argv[2]));
	while(nrighe--){
		incrementa(riga);
		stampa(riga, dimcella, nrighe);
	}
}

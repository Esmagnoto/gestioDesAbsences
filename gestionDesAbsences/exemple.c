/*
#include <string.h> // pour strcmp
#include <stdlib.h> // pour qsort
#include <stdio.h> // pour printf

// une constante
enum { MAX_NOM = 31 };
// un type
typedef struct {
	char nom[MAX_NOM];
	int age;
} Personne;

/*
* Fonction comparant 2 personnes. Son prototype est bizarre. Elle est cod�e et expliqu�e 
* apr�s le programme principal.
#1#
int compare(const void* a, const void* b);

int main() {
	// un tableau de personnes
	Personne tab[] = { {"Noah", 10}, {"Moha", 15}, {"Lisa", 10}, {"Anna", 15} };
	// le nombre de personnes calcul� � partir de la taille du tableau et de la taille d'un de ses �l�ments
	int nbPersonnes = (int)(sizeof(tab) / sizeof(tab[0]));
	// on affiche le tableau, une personne par ligne
	printf("les personnes :\n");
	for (int i = 0; i < nbPersonnes; ++i)
		printf("- %s (%d ans)\n", tab[i].nom, tab[i].age);
	// on trie le tableau en passant en param�tre � qsort :
	// - le tableau
	// - sa taille (ici le nombre de personnes)
	// - le nombre d'octets qu'occupe chaque case du tableau
	// - (l'adresse de) la fonction sachant comparer 2 �l�ments du tableau
	qsort(tab, nbPersonnes, sizeof(tab[0]), compare);
	// on affiche � nouveau le tableau, une personne par ligne
	printf("les personnes apres le tri:\n");
	for (int i = 0; i < nbPersonnes; ++i)
		printf("- %s (%d ans)\n", tab[i].nom, tab[i].age);
}

/*
* Le r�le de la fonction qui suit est d'indiquer si la personne point�e par p1 est plus petite,
* �gale ou plus grande que celle point�e par p2.
* Si *p1 < *p2 alors la fonction doit retourner un entier strictement inf�rieur � 0
* Si *p1 == *p2 alors la fonction doit retourner 0
* Si *p1 > *p2 alors la fonction doit retourner un entier strictement sup�rieur � 0
*
* Les adresses p1 et p2 des personnes sont re�ues sous la forme de pointeur vers n'importe quoi
* (le type void*). Les premi�res instructions de la fonction visent � convertir ces pointeurs
* en des pointeurs de personne pour pouvoir acc�der facilement aux champs age et nom.
*
* Pour cet exemple, une personne *p1 est consid�r�e comme �tant plus petite qu'une personne *p2
* si l'age de *p1 est plus petit que celui de *p2 ou, � age �gal, si le nom de *p1 est devant
* celui de *p2 dans l'ordre alphab�tique.
#1#
int compare(const void* a, const void* b) {
	// conversion
	const Personne* p1 = (const Personne*)a;
	const Personne* p2 = (const Personne*)b;
	// d�cision (p1 plus petit que p2 ou �gal ou plus grand ?)
	if (p1->age < p2->age)
		return -1; // p1 est plus petit (jeune) que p2
	if (p1->age > p2->age)
		return 1; // p1 est plus grand (vieux) que p2
	// ici on sait que p1->age == p2->age (ils ont le m�me age)
	return strcmp(p1->nom, p2->nom); // on compare les 2 noms
}
*/

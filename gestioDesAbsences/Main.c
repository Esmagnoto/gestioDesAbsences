#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#pragma warning(disable : 6031)


enum { MAX_CARACTERES = 31, MAX_ETUDIANTS = 15, DEMI_JOURNEE = 2, LIMIT_ABSENCES = 5 };
typedef enum {ETUDIANT_NON_TROUVE, ETUDIANT_TROUVE} EtudiantStatus;

typedef struct {
	int jour;
	int periode;
	int etudiantId;
} Absence;

typedef struct {
	char nomEtudiant[MAX_CARACTERES];
	int numeroGroupe;
	int nombreAbsences;
} Etudiant;

// verifie si un etudiant est ou n'est pas déjà inscrit dans la table.
EtudiantStatus verifierInscription(Etudiant tableEtudiants[MAX_ETUDIANTS], char nomEtudiant[]) {
	assert(tableEtudiants != NULL && nomEtudiant != NULL);

	EtudiantStatus status = ETUDIANT_NON_TROUVE;
	for (int i = 0; i < MAX_ETUDIANTS; i++) {
		if (strcmp(tableEtudiants[i].nomEtudiant, nomEtudiant) == 0) {
			status =  ETUDIANT_TROUVE;
		}
	}
	return status;
}

// faire une inscription table etudiants declaré dans main().
void inscrireEtudiant(Etudiant tableEtudiants[MAX_ETUDIANTS], int cmpEtudiants,char nomEtudiant[MAX_CARACTERES], int numeroGroupe) {
	assert(nomEtudiant != NULL && strlen(nomEtudiant) > 0);
	assert(numeroGroupe > 0);
	assert(cmpEtudiants >= 0 && cmpEtudiants < MAX_ETUDIANTS);
	assert(tableEtudiants != NULL);

	strcpy(tableEtudiants[cmpEtudiants].nomEtudiant, nomEtudiant);
	tableEtudiants[cmpEtudiants].numeroGroupe = numeroGroupe;
	tableEtudiants[cmpEtudiants].nombreAbsences = 0;
	
}

int main() {
	char entree[MAX_CARACTERES] = {0};
	Etudiant etudiants[MAX_ETUDIANTS]= {0} ;
	int cmpEtudiants = 0;
	
	while (1) {

		printf("ecrire une commande: ");
		scanf("%30s", entree);

		if (strcmp(entree, "exit") == 0){return 0;}
		else if (strcmp(entree, "inscription") == 0)
		{
			char nomEtudiant[MAX_CARACTERES];
			unsigned int numeroGroupe;
			scanf("%30s", nomEtudiant);
			if (scanf("%u", &numeroGroupe) == 1 && verifierInscription(etudiants, nomEtudiant) == ETUDIANT_NON_TROUVE && numeroGroupe > 0) 
			{
				inscrireEtudiant(etudiants, cmpEtudiants, nomEtudiant, numeroGroupe);
				printf("Inscription enregistree (%d)\n", cmpEtudiants + 1);
				++cmpEtudiants;
			}
			else
			{
				printf("Nom Incorrect\n");
			}

		}
		else if (strcmp(entree, "absence") == 0) 
		{
			
		}
		else
		{
			// Attrape les erreurs de commande, nettoie le buffer et continue le programme.
			printf("Comande invalide\n");
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}

}

/*int etudiantId;
			int jour;
			char periode[DEMI_JOURNEE];
			scanf("%d",&etudiantId);
			scanf("%d",&jour);
			scanf("%s",periode);

			if (verifierEtudiants(etudiants, periode) == 1) {

				if(0 < jour < 41) {
					if(strcmp(periode, "am") == 0 || strcmp(periode, "pm") == 0){
						etudiants[etudiantId].absences[jour].jour = jour;
						strcpy(etudiants[etudiantId].absences[jour].periode, periode);
						etudiants[etudiantId].nombreAbsences += 1;
						printf("Absence enregistree [%d]", etudiants[etudiantId].nombreAbsences);
					}
				}
			}*/



/*
* 
    The user types "inscription caio 108" and presses enter.
    The fgets function reads the entire line of input, including the newline character (\n), into the inputLine buffer.
    The sscanf function parses the input string, extracting the name "caio" and the number 108.
    The program checks if the name is already registered using the verifier function. If it's not registered, the program proceeds to register the student using the inscrireEtudiant function.
    The program increments the cmpEtudiants counter and continues to the next iteration of the main loop.


else if (strcmp(entree, "inscription") == 0) {
    char inputLine[MAX_CARACTERES];
    printf("Enter name and number: ");
    fgets(inputLine, MAX_CARACTERES, stdin);

    char nomEtudiant[MAX_CARACTERES];
    int numeroGroupe;
    if (sscanf(inputLine, "inscription %s %d", nomEtudiant, &numeroGroupe) == 2) {
        if (verifier(etudiants, nomEtudiant) == ETUDIANT_NON_TROUVE) {
            inscrireEtudiant(etudiants, cmpEtudiants, nomEtudiant, numeroGroupe);
            ++cmpEtudiants;
        } else {
            printf("Nom Incorrect\n");
        }
    } else {
        printf("Invalid input format. Please enter 'inscription <name> <number>'.\n");
    }
}*/
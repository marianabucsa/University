# include <stdio.h>


void afisare_meniu()
{
	// functia afiseaza un meniu
	// date de intrare: -
	// date de iesire: -
	printf("Meniu:\n");
	printf("1.Genereaza nr prime mai mici decat nr.\n");
	printf("2.Genereaza primele n numere prime. \n");
	printf("3.Exit");
}

int citire_comanda()
{
	// functia citeste un numar de la tastatura si determina daca este o comanda valida caz in care il returneaza
	// functia continua sa citeasca comenzi pana cand una corecta este introdusa
	// date de intrare: -
	// date de iesire: returneaza un intreg reprezentand o comanda, intregul este valoarea 1 sau 2
	int comanda=0;
	while (comanda == 0)
	{
		printf("\nDati comanda: ");
		scanf("%d", &comanda);
		if (comanda != 1 && comanda != 2 && comanda != 3)
		{
			printf("Comanda invalida!\n");
			comanda = 0;
		}
	}
	return comanda;
}
int prim(int nr)
{
	// functia returneaza valoarea 1 daca numarul dat ca parametru este prim si 0 in caz contrar
	// date de intrare: nr - intreg, nr>0
	// date de iesire: 1- daca nr prim
	//				   0- daca nr nu este prim
	int d;
	for (d = 2; d <= nr / 2; d++)
		if (nr % d == 0)
			return 0;
	return 1;
}
void afisare_prime(int nr)
{
	// functia afiseaza numerele prime mai mici decat numarul dat ca parametru
	// date de intrare: nr -intreg , nr>0
	// date de iesire: -
	int i;
	for (i = 2;i < nr; i++)
	{
		if (prim(i) == 1)
			printf(" %d", i);
	}
	printf("\n");
}

void generare_prime(int n)
{
	// functia afiseaza primele n numere prime
	// date de intrare: n -intreg , n>0
	// date de iesire: -
	int i = 0,nr=2;
	while (i < n)
	{
		if (prim(nr) == 1)
		{
			printf("%d ", nr);
			i++;
		}
		nr++;
	}
}

int main()
{
	// decide ce functie se apeleaza in functie de comanda citita
	int nr, continuare = 1,comanda;
	while (continuare== 1)
	{
		afisare_meniu();
		comanda=citire_comanda();
		if (comanda == 1)
		{
			printf("Dati numarul: ");
			scanf("%d", &nr);
			afisare_prime(nr);
		}
		else
			if (comanda == 2)
			{
			printf("Dati numarul: ");
			scanf("%d", &nr);
			generare_prime(nr);
			}
		else continuare = 0;

	}

	return 0;

}
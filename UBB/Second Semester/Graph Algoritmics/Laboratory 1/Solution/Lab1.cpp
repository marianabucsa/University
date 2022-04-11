#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void inmultire_m(int m1[101][101], int m2[101][101], int n) {
	int i, j, k, rez[10][10];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			rez[i][j] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
			{
				rez[i][j] += m1[i][k] * m2[k][j];
			}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			m1[i][j] = rez[i][j];
}

int verificare_m_d(int mat[101][101], int n) {
	int i, j, k, ok = 1, r;
	int suma = 0, s = 0, noduri_iz[10];
	k = 0;
	for (i = 0; i < n; i++)
	{
		suma = 0;
		for (j = 0; j < n; j++)
			if (mat[i][j] != 0)
				suma++;
		if (suma == 0)
		{
			noduri_iz[k] = i + 1;
			k++;
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j && mat[i][j] == 0) {
				if (k == 0)
					return 0;
				else
					for (r = 0; r < k; r++)
						if (noduri_iz[r] - 1 != i && noduri_iz[r] - 1 != j)
							return 0;
			}
	if (ok == 1)
		return 1;
}

int main() {
	int n, m_adiacenta[101][101], m_incidenta[101][101], l_adiacenta[101][101], m_distanta[101][101], i, j, x, y, m, k;
	ifstream in("test_12.in");
	in >> n >> m;
	// formam o matrice cu valoarea 0 pe fiecare pozitie
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			m_adiacenta[i][j] = 0;
			l_adiacenta[i][j] = 0;
			m_distanta[i][j] = 0;
		}

	for (i = 0; i < n; i++)
		for (j = 0; j < n * (n - 1) / 2; j++) {
			m_incidenta[i][j] = 0;
		}

	// formam matricea de adiacenta
	while (in >> x >> y)
		m_adiacenta[x][y] = m_adiacenta[y][x] = 1;
	in.close();
	// afisam matricea de adiacenta
	cout << "Matricea de adiacenta:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << m_adiacenta[i][j] << ", ";
		cout << endl;
	}
	// formam lista de adiacenta din matricea de adiacenta
	for (i = 0; i < n; i++) {
		int k = 1;
		l_adiacenta[i][0] = i + 1;
		for (j = 0; j < n; j++)
			if (m_adiacenta[i][j] == 1) {
				l_adiacenta[i][k] = j + 1;
				k++;
			}
	}
	// afisam lista de adiacenta
	cout << "Lista de adiacenta:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << l_adiacenta[i][0] << ": ";
		for (j = 1; j < n; j++)
			if (l_adiacenta[i][j] != 0)
				cout << l_adiacenta[i][j] << " ";
		cout << endl;
	}

	// formam matricea de incidenta din lista de adiacenta
	m = 0;  // nr de coloane
	for (i = 0; i < n - 1; i++) {
		j = 1;
		while (l_adiacenta[i][j] != 0 && j < n) {
			if (l_adiacenta[i][j] > i) {
				m_incidenta[i][m] = m_incidenta[l_adiacenta[i][j] - 1][m] = 1;
				m++;
			}
			j++;
		}
	}
	m--;
	// afisam matricea de incidenta
	cout << "Matricea de incidenta:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
			cout << m_incidenta[i][j] << " ";
		cout << endl;
	}

	// lista de adiacenta din matrice de incidenta
	for (i = 0; i < n; i++) {
		int r = 1;
		l_adiacenta[i][0] = i + 1;
		for (j = 0; j <= m; j++) {
			if (m_incidenta[i][j] == 1)
				for (k = 0; k < n; k++)
					if (m_incidenta[k][j] == 1 && k != i) {
						l_adiacenta[i][r] = k + 1;
						r++;
					}
		}
	}


	// afisam lista de adiacenta
	cout << "Lista de adiacenta:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << l_adiacenta[i][0] << ": ";
		for (j = 1; j < n; j++)
			if (l_adiacenta[i][j] != 0)
				cout << l_adiacenta[i][j] << " ";
		cout << endl;
	}
	// matricea de adiacenta din lista de adiacenta
	for (i = 0; i < n; i++)
		for (j = 1; j < n; j++)
			if (l_adiacenta[i][j] != 0)
				m_adiacenta[i][l_adiacenta[i][j] - 1] = m_adiacenta[l_adiacenta[i][j] - 1][i] = 1;
	// afisam matricea de adiacenta
	cout << "Matricea de adiacenta:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << m_adiacenta[i][j] << " ";
		cout << endl;
	}

	// determinarea noduri izolate
	int suma = 0, s = 0, noduri_iz[10];
	k = 0;
	for (i = 0; i < n; i++)
	{
		suma = 0;
		for (j = 0; j < n; j++)
			if (m_adiacenta[i][j] != 0)
				suma++;
		if (suma == 0)
		{
			noduri_iz[k] = i + 1;
			k++;
		}
	}
	// afisam nodurile izolate
	cout << "Noduri izolate: ";
	for (i = 0; i < k; i++)
		cout << noduri_iz[i] << " ";
	//determinarea graf regulat
	int ok = 1;
	for (i = 0; i < n; i++)
	{
		suma = 0;
		for (j = 0; j < n; j++)
			if (m_adiacenta[i][j] != 0)
				suma++;
		if (i != 0 && suma != s)
			ok = 0;
		s = suma;
	}
	// afisare graf regulat
	if (ok == 0)
		cout << "\nGraful nu este regulat!\n";
	else cout << "\nGraful este regulat!\n";

	// matricea distantelor
	int m_aux[101][101];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			m_distanta[i][j] = m_adiacenta[i][j];
			m_aux[i][j] = m_adiacenta[i][j];
		}
	int pow = 1;
	while (verificare_m_d(m_distanta, n) == 0) {
		inmultire_m(m_aux, m_adiacenta, n);
		pow++;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (m_distanta[i][j] == 0 && i != j && m_aux[i][j] != 0)
					m_distanta[i][j] = pow;

	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (i != j && m_distanta[i][j] == 0)
				m_distanta[i][j] = 0;
			m_distanta[i][i] = 0;
		}

	// afisare matricea distantelor
	cout << "\nMatricea distantelor: \n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << " " << m_distanta[i][j];
		cout << endl;
	}
	cout << endl;

	// graf conex
	int noduri_parcurse[10], noduri[10];
	for (i = 0; i < n; i++)
		noduri_parcurse[i] = 0;
	int curent = 0, nod = 0;
	noduri_parcurse[curent] = 1;
	while (curent > -1) {
		curent--;
		for (j = 0; j < n; j++)
			if (m_adiacenta[nod][j] == 1)
				if (noduri_parcurse[j] == 0) {
					noduri_parcurse[j] = 1;
					curent++;
					nod = j;
				}
	}

	// afisare graf conex
	ok = 1;
	for (i = 1; i <= n; i++)
		if (noduri_parcurse[i] == 0)
		{
			cout << "Graful nu este conex";
			ok = 0;
			break;
		}
	if (ok)
		cout << "Graful este conex";
	cout << endl;
	return 0;
}


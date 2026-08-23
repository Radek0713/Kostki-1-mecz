#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int N = 2, ile_meczy=1000000;

struct jeden
{
	string nazwa{};
	//int ranking{};
	int poziom{};
};
jeden druzyny[N];

int funkcja(int x, int y, int z)
{
	int wyniki[6]{};
	int i, gole = 0, poziomy_roznica = y - x;
	for (i = 0; i < 4; i++)
	{
		wyniki[rand() % 6]++;
	}
	for (i = 0; i + 1 < 0.5 * poziomy_roznica + 4.5 + 0.5 * (abs(poziomy_roznica + 1) % 2); i++)
	{
		if (wyniki[i] == 1 || (wyniki[i] == 3 && z > 0))
		{
			gole++;
		}
	}
	/*for (i = 0; i < 6; i++)
	{
		for (j = 0; j < wyniki[i]; j++)
		{
			cout << " " << i + 1;
		}
	}
	cout << " [" << 0.5 * poziomy_roznica + 4.5 + 0.5 * (abs(poziomy_roznica + 1) % 2) << "] " << endl;
	*/
	return gole;
}

int i, wynik[2], dokladnosc=3;
float btts, win, draw, lose;

int main()
{
	srand(time(NULL));

	cout << "Podaj nazwe 1 druzyny: ";
	cin >> druzyny[0].nazwa;
	cout << "Podaj poziom 1 druzyny: ";
	cin >> druzyny[0].poziom;

	cout << "Podaj nazwe 2 druzyny: ";
	cin >> druzyny[1].nazwa;
	cout << "Podaj poziom 2 druzyny: ";
	cin >> druzyny[1].poziom;

	//cout << endl << druzyny[0].nazwa<< " "<< funkcja(druzyny[0].poziom, druzyny[1].poziom, 0) << ":";
	//cout << funkcja(druzyny[1].poziom, druzyny[0].poziom, 0) << " "<<druzyny[1].nazwa << endl;
	
	for (int i = 0; i < ile_meczy; i++)
	{
		wynik[0] = funkcja(druzyny[0].poziom, druzyny[1].poziom, 1);
		wynik[1] = funkcja(druzyny[1].poziom, druzyny[0].poziom, 1);
		if (wynik[0] > wynik[1])
		{
			win++;
		}
		else if (wynik[0]==wynik[1])
		{
			draw++;
		}
		else if (wynik[0] < wynik[1])
		{
			lose++;
		}
		if (wynik[0] > 0 && wynik[1] > 0)
		{
			btts++;
		}
	}
	cout << endl << druzyny[0].nazwa << " ";
	cout << funkcja(druzyny[0].poziom, druzyny[1].poziom, 0) << ":";
	cout << funkcja(druzyny[1].poziom, druzyny[0].poziom, 0) << " "<<druzyny[1].nazwa << endl;
	cout << endl;
	cout << setprecision(dokladnosc) << ile_meczy / win << " ";
	cout << setprecision(dokladnosc) << ile_meczy/draw << " ";
	cout << setprecision(dokladnosc) << ile_meczy/lose  << " " << endl;
	cout << setprecision(dokladnosc) << ile_meczy/(win + draw)  << " ";
	cout << setprecision(dokladnosc) << ile_meczy/(win + lose)   << " ";
	cout << setprecision(dokladnosc) << ile_meczy/(draw + lose)  << " " << endl;
	cout << setprecision(dokladnosc) << ile_meczy/btts  << " ";
	cout << setprecision(dokladnosc) << ile_meczy / (ile_meczy - btts) << " " << endl;
	system("pause");
}
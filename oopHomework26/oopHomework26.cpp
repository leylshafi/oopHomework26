#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include <numeric>
#include <sstream>
#include<string>
using namespace std;
#include"Debtor.h"

//Predicate

bool debtorDebtASC(const Debtor& d1, const Debtor& d2) {
	return d1.getDebt() > d2.getDebt();
}

void IfDomen(const Debtor& d)
{
	if (d.getEmail().find("rhyta.com") != string::npos || d.getEmail().find("dayrep.com") != string::npos)
		cout << d << endl;
}

void ifHas8(const Debtor& d)
{
	if (d.getPhone().find("8") == string::npos)
	{
		int a = d.getFullName().find('.');
		for (size_t i = a + 2; i < d.getFullName().size(); i++)
		{
			cout << d.getFullName()[i];
		}
		cout << endl;
		cout << "Age: " << 2022 - (d.getBirthday().year) << endl;
		cout << "Total debt: " << d.getDebt() << endl;
		cout << endl << endl;
	}
}


//Functor
class IfDomenFunctor
{
	string domen;
public:
	IfDomenFunctor(string domen)
	{
		this->domen = domen;
	}

	void operator()(const Debtor& d)
	{
		if (d.getEmail().find(domen) != string::npos )
			cout << d << endl;
	}
};

class ifHas8Functor
{
	string number;
public:
	ifHas8Functor(string number)
	{
		this->number = number;
	}

	void operator()(const Debtor& d)
	{
		if (d.getPhone().find(number) == string::npos)
		{
			int a = d.getFullName().find('.');
			for (size_t i = a + 2; i < d.getFullName().size(); i++)
			{
				cout << d.getFullName()[i];
			}
			cout << endl;
			cout << "Age: " << 2022 - (d.getBirthday().year) << endl;
			cout << "Total debt: " << d.getDebt() << endl;
			cout << endl << endl;
		}
	}

};

int main()
{
	stringstream ss;

	vector<Debtor>debtors;
	debtors.push_back(Debtor("Shirley T. Qualls", DateTime{ 12,3,1992 }, "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414));
	debtors.push_back(Debtor("Danielle W. Grier", DateTime(10, 18, 1953), "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599));
	debtors.push_back(Debtor("Connie W. Lemire", DateTime(6, 18, 1963), "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219));
	debtors.push_back(Debtor("Coy K. Adams", DateTime(3, 1, 1976), "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784));
	debtors.push_back(Debtor("Bernice J. Miles", DateTime(6, 1, 1988), "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060));
	debtors.push_back(Debtor("Bob L. Zambrano", DateTime(2, 28, 1990), "706-446-1649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628));
	debtors.push_back(Debtor("Adam D. Bartlett", DateTime(5, 6, 1950), "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412));
	debtors.push_back(Debtor("Pablo M. Skinner", DateTime(8, 26, 1936), "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097));
	debtors.push_back(Debtor("Dorothy J. Brown", DateTime(7, 9, 1971), "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956));
	debtors.push_back(Debtor("Larry A. Miracle", DateTime(5, 22, 1998), "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150));
	debtors.push_back(Debtor("Jessica J. Stoops", DateTime(4, 22, 1989), "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805));
	debtors.push_back(Debtor("Audry M. Styles", DateTime(2, 7, 1937), "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001));
	debtors.push_back(Debtor("Violet R. Anguiano", DateTime(11, 4, 1958), "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128));
	debtors.push_back(Debtor("Charles P. Segundo", DateTime(10, 21, 1970), "4157-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648));
	debtors.push_back(Debtor("Paul H. Sturtz", DateTime(9, 15, 1944), "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437));
	debtors.push_back(Debtor("Doris B. King", DateTime(10, 10, 1978), "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230));
	debtors.push_back(Debtor("Deanna J. Donofrio", DateTime(4, 16, 1944), "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515));
	debtors.push_back(Debtor("Martin S. Malinowski", DateTime(1, 17, 1992), "7657-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816));
	debtors.push_back(Debtor("Melissa R. Arner", DateTime(5, 24, 1974), "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037));
	debtors.push_back(Debtor("Kelly G. Hoffman", DateTime(9, 22, 1969), "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755));
	debtors.push_back(Debtor("Doyle B. Short", DateTime(6, 15, 1986), "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657));
	debtors.push_back(Debtor("Lorrie R. Gilmore", DateTime(12, 23, 1960), "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693));
	debtors.push_back(Debtor("Lionel A. Cook", DateTime(4, 16, 1972), "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712));
	debtors.push_back(Debtor("Charlene C. Burke", DateTime(1, 18, 1990), "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016));
	debtors.push_back(Debtor("Tommy M. Patton", DateTime(6, 30, 1981), "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349));
	debtors.push_back(Debtor("Kristin S. Bloomer", DateTime(6, 16, 1944), "4437-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824));
	debtors.push_back(Debtor("Daniel K. James", DateTime(11, 10, 1997), "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215));
	debtors.push_back(Debtor("Paula D. Henry", DateTime(9, 6, 1976), "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766));
	debtors.push_back(Debtor("Donna C. Sandoval", DateTime(12, 13, 1947), "540-482-5463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363));
	debtors.push_back(Debtor("Robert T. Taylor", DateTime(8, 17, 1932), "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785));

	//11,18
	//2 rhyta.com ve ya dayrep.com domenlerinde emaili olan borclulari cixartmag
	for_each(debtors.begin(), debtors.end(), [](const Debtor& d)
		{
			if (d.getEmail().find("rhyta.com") !=string::npos || d.getEmail().find("dayrep.com") != string::npos)
				cout << d << endl;
		});

	// for_each(debtors.begin(), debtors.end(), IfDomen); //Predicate 

	//for_each(debtors.begin(), debtors.end(), IfDomenFunctor("rhyta.com")); //Functor


	//9 Telefon nomresinde 8 olmayan borclularin yalniz familyasin,yashin ve umumi borcun meblegin cixarmaq

	/*for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			if (d.getPhone().find("8") == string::npos)
			{
				int a = d.getFullName().find('.');
				for (size_t i = a+2; i < d.getFullName().size(); i++)
				{
					cout << d.getFullName()[i];
				}
				cout << endl;
				cout << "Age: " << 2022 - (d.getBirthday().year) << endl;
				cout << "Total debt: " << d.getDebt() << endl;
				cout << endl<< endl;
			}	
		});*/

	// for_each(debtors.begin(), debtors.end(), ifHas8); //Predicate 

	// for_each(debtors.begin(), debtors.end(), ifHas8Functor("8")); //Functor

	
	//11 Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek
	/*for_each(debtors.begin(), debtors.end(), [](const Debtor& d)
		{
			
			
		});*/



	//13 borclulardan en coxu hansi ilde dogulubsa hemin ili cixartmaq
	/*vector<int>years;
	for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			years.push_back(d.getBirthday().year);
		});
	sort(years.begin(), years.end());
	int counter = 0;
	int element = 0;
	for (auto i : years)
	{
		int tempElement = i;
		int tempCount = 0;
		for (auto j : years)
		{
			if (j == tempElement)
			{
				tempCount++;
				if (tempCount >= counter)
				{
					element = tempElement;
					counter = tempCount;
				}
			}
		}
	}

	cout << "The number " << element << " is the most frequent (occurs " << counter << " times).\n";*/


	//14 Borcu en boyuk olan 5 borclunun siyahisini cixartmaq
	sort(debtors.begin(), debtors.end(), debtorDebtASC);
	int count = 0;
	for_each(debtors.begin(), debtors.end(), [&](const Debtor&d)
		{
			if (count < 5)
				cout << d << endl;
			count++;
		});




	//18 Nomresinde tekrar reqemler olmayan borclularin ve onlarin borcunun meblegin cixartmaq ?
	//int counter = 0;
	//int element = 0;
	/*vector<char>number;
	for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			for (size_t i = 0; i < d.getPhone().size(); i++)
			{
				number.push_back(d.getPhone()[i]);
			}
			sort(number.begin(), number.end());
			
		}); */






	//19 Tesevvur edek ki,butun borclari olanlar bugunden etibaren her ay 500 azn pul odeyecekler.
	//Oz ad gunune kimi borcun oduyub qurtara bilenlerin siyahisin cixartmaq
	
	int numberOfMonths = 0;

	for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			if (d.getBirthday().month > 7 && d.getBirthday().month < 12)
				numberOfMonths = d.getBirthday().month - 7;
			else
				numberOfMonths = 5 + d.getBirthday().month;

			if (numberOfMonths * 500 - d.getDebt() <= 0)
				cout << d << endl;
		
		});
	





	//20 Adindaki ve familyasindaki herflerden "smile" sozunu yaza bileceyimiz borclularin siyahisini cixartmaq
	/*for_each(debtors.begin(), debtors.end(), [&](const Debtor& d)
		{
			if (d.getFullName().find('s') != string::npos && d.getFullName().find('m') != string::npos &&
				d.getFullName().find('i') != string::npos && d.getFullName().find('l') != string::npos
				&& d.getFullName().find('e') != string::npos)
				cout << d << endl;

		});*/





}
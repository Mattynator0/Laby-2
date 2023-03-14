#include "Library.h"

int main()
{
	// Book
	std::string a = "Mickiewicz", t = "Dziady";

	Book be;
	std::cout << "be: " << be << std::endl;

	Book b1 = { a, t };
	std::cout << "b1: " << b1 << std::endl;

	Book b2 = { "Tez Mickiewicz", "Tan Padeusz" };
	std::cout << "b2: " << b2 << std::endl;

	Book b3 = b1;
	std::cout << "b3: " << b3 << " b1: " << b1 << std::endl;

	be = std::move(b2);
	std::cout << "be: " << be << " b2:" << b2 << std::endl;

	be.SetAuthor("Slowacki");
	std::cout << "be: " << be << std::endl;
	be.SetTitle("Balladyna");
	std::cout << "be: " << be << std::endl;

	// Library
	std::cout << "-----------------------------\n\n";
	Library le;
	std::cout << "le: " << le << std::endl;
	//3-5 książek
	std::cout << "-----------------------------\n\n";
	Library l1 = {	{"Ksiazka A", "Autor A"},
					{"Ksiazka B", "Autor B"},
					{"Ksiazka C", "Autor C"} };
	std::cout << "l1: " << l1 << std::endl;
	std::cout << "-----------------------------\n\n";
	Library l2(2);
	std::cout << "l2: " << l2 << std::endl;
	std::cout << "-----------------------------\n\n";
	l2[0] = { "Ksiazka X", "Autor X" };
	l2[1] = { "Ksiazka Y", "Autor Y" };
	std::cout << "l2: " << l2 << std::endl;
	std::cout << "-----------------------------\n\n";
	le = std::move(l2);
	std::cout << "le: " << le << " l2: " << l2 << std::endl;
	std::cout << "-----------------------------\n\n";

	l1[0] = std::move(le[1]);
	std::cout << "l1: " << l1 << " le: " << le << std::endl;
}
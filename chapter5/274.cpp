#include <iostream>
#include <sstream>		//istringstream

using namespace std;

int main(void)
{
	istringstream is("WINDY WOOD");
	string x, y, z;

	is >> x;
	cout << x << endl;
	auto pos = is.tellg();

	is >> y;
	is.seekg(6, ios_base::beg);
	is >> z;

	cout << "x:" << x << " y:" << y << " z:" << z << endl;

	getchar();
	return 0;
}

/*
#include <iostream>
#include <sstream>

int main() {
	std::istringstream is("ABC");
	char x;

	is >> x;
	std::cout << x << std::endl;

	is.seekg(0, std::ios_base::beg);
	is >> x;
	std::cout << x << std::endl;
}
*/
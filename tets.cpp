#include <iostream>
int main ( )
{
// Utilisation de fmtflags comme type de constantes publiques, membres de la classe ios_base
std::cout.setf ( std::ios_base::hex, std::ios_base::basefield );
std::cout.setf ( std::ios_base::showbase );
std::cout << 123 << std::endl;
// Utilisation de fmtflags comme type de constantes publiques, membres hérités de la classe ios
std::cout.setf ( std::ios::hex, std::ios::basefield );
std::cout.setf ( std::ios::showbase );
std::cout << 123 << std::endl;
// Utilisation de fmtflags comme type de constantes publiques manipulées par l’objet cout
std::cout.setf ( std::cout.hex, std::cout.basefield );
std::cout.setf ( std::cout.showbase );
std::cout << 123 << std::endl;

return 0;
}

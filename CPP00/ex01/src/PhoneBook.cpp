#include "../Includes/PhoneBook.hpp"

// needs the part where it waits for the contact info that the user puts like first name

/*void PhoneBook::contactInfo()
{

}*/

// _index can only be accessed inside member functions of PhoneBook
PhoneBook::PhoneBook()
{
    _index = 0; // initialize the index
}

void PhoneBook::addContact() // member function of the PhoneBook class
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    _contacts[_index].setFirstName(input);
    std::cout << "\n";

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    _contacts[_index].setLastName(input);
    std::cout << "\n";

    std::cout << "Enter nick name: ";
    std::getline(std::cin, input);
    _contacts[_index].setNickName(input);
    std::cout << "\n";

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    _contacts[_index].setPhoneNumber(input);
    std::cout << "\n";

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    _contacts[_index].setSecret(input);
    std::cout << "\n";

     _index = (_index + 1) % 8;
}
#include "../Includes/PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void)
{
	_index = 0; // might delete
}
// Destructor
PhoneBook::~PhoneBook(void)
{
	return ;
}

bool PhoneBook::isValidPhoneNumber(const std::string &number)
{
    if (number.empty())
        return false;
    for (size_t i = 0; i < number.length(); ++i) {
        char c = number[i];
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            if (c == '+') {
                if (i != 0) // + is only allowed at the start
                    return false;
            }
            else
                return false;
        }
    }
    return true;
}

// this stops adding a contact if a field is empty
void PhoneBook::clearContact(int index)
{
    _contacts[index].setFirstName("");
    _contacts[index].setLastName("");
    _contacts[index].setNickName("");
    _contacts[index].setPhoneNumber("");
    _contacts[index].setSecret("");
}

void PhoneBook::addContact(void) // member function of the PhoneBook class
{
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	_contacts[_index].setFirstName(input);
    if (_contacts[_index].getFirstName().empty()) {
        std::cout << "❌ Contact not added (first name cannot be empty).\n\n";
        clearContact(_index);
        return;
    }
	std::cout << "\n";

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	_contacts[_index].setLastName(input);
    if (_contacts[_index].getLastName().empty()) {
        std::cout << "❌ Contact not added (last name cannot be empty).\n\n";
        clearContact(_index);
        return;
    }
	std::cout << "\n";

	std::cout << "Enter nick name: ";
	std::getline(std::cin, input);
	_contacts[_index].setNickName(input);
    if (_contacts[_index].getNickName().empty()) {
        std::cout << "❌ Contact not added (nick name cannot be empty).\n\n";
        clearContact(_index);
        return;
    }
	std::cout << "\n";

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	while (!isValidPhoneNumber(input)) {
		std::cout << "Invalid phone number. Try again\n> ";
	    std::getline(std::cin, input);
    }
	_contacts[_index].setPhoneNumber(input);
    if (_contacts[_index].getPhoneNumber().empty()) {
        std::cout << "❌ Contact not added (phone number cannot be empty).\n\n";
        clearContact(_index);
        return;
    }
	std::cout << "\n";

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	_contacts[_index].setSecret(input);
    if (_contacts[_index].getSecret().empty()) {
        std::cout << "❌ Contact not added (dark secret cannot be empty).\n\n";
        clearContact(_index);
        return;
    }
	std::cout << "\n";

	_index = (_index + 1) % 8;
}

std::string PhoneBook::formatField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void PhoneBook::searchContact(void)
{
    // Print header
    std::cout << "|" << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "FirstName"
              << "|" << std::setw(10) << std::right << "LastName"
              << "|" << std::setw(10) << std::right << "Nickname"
              << "|" << std::setw(10) << std::right << "PhoneNum"
              << "|" << std::endl;

    // Print separator under header
    std::cout << std::setfill('-') << std::setw(56) << "-" << std::setfill(' ') << std::endl;

    // Print contacts
    for (int i = 0; i < 8; i++) {
        // if I remove this, it will print the entire 8 contact table, even if I only add 1 contact
        if (_contacts[i].getFirstName().empty())
            continue;
        std::cout << "|" << std::setw(10) << std::right << (i + 1)
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getLastName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getNickName())
                  << "|" << std::setw(10) << std::right << formatField(_contacts[i].getPhoneNumber())
                  << "|" << std::endl << std::endl;
    }
}

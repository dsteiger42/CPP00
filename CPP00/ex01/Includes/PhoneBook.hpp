#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8]; // I want the contacts to have acess to the Contact class
        int _index; // track the index of the contact list. _index can only be accessed inside member functions of PhoneBook

        bool isValidPhoneNumber(const std::string &number);
        std::string formatField(const std::string &field);
        void clearContact(int index);

    public:
        PhoneBook(); // constructor to initialize index
        ~PhoneBook();
        void addContact();
        void searchContact();

};

#endif
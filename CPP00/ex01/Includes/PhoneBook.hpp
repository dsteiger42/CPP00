#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8]; // I want the contacts to have acess to the Contact class
        int _index; // track the index of the contact list. _index can only be accessed inside member functions of PhoneBook

    public:
        PhoneBook(); // constructor to initialize index
        void addContact();

};

#endif
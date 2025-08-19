#include "../Includes/PhoneBook.hpp"

std::string display_prompt()
{
	std::string command;
	std::cout << "Enter one of these commands: ADD | SEARCH | EXIT\n> ";
	if (!std::getline(std::cin, command))
	{
		std::cout << "\nEOF pressed.\n";
		return ("");
	}
	return (command);
}

int	main(void)
{
	PhoneBook phone1; // Phonebook object
	Contact contact1;
	std::string userInput;

	while (true)
	{
		userInput = display_prompt();
		if (userInput.empty() && std::cin.eof())
			// makes sure the program doesnt leave the loop just because the user typed nothing
		{
			std::cout << "\nEOF pressed.\n";
			break ;
		}
		if (userInput == "ADD")
		{
			phone1.addContact();
		}
		else if (userInput == "SEARCH")
		{
		}
		else if (userInput == "EXIT")
		{
		}
		else
			std::cout << "Invalid command. Please choose a valid option.\n\n";
	}
}
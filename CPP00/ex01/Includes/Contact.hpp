#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
#include <iomanip>

class Contact
{
  private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _darkest_secret;

  public:
	void setFirstName(const std::string &first);
	void setLastName(const std::string &last);
	void setNickName(const std::string &nick);
	void setPhoneNumber(const std::string &phone);
	void setSecret(const std::string &secret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;
};

#endif
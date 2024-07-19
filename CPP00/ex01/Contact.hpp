#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

class Contact
{
	public:
    	Contact();
    	~Contact();

   		void setFName(const std::string& fName);
    	void setLName(const std::string& lName);
   		void setNickn(const std::string& nickn);
    	void setPhoneNumber(const std::string& phoneNumber);
    	void setDarkestSecret(const std::string& darkestSecret);

    	std::string getFName() const;
    	std::string getLName() const;
    	std::string getNickn() const;
    	std::string getPhoneNumber() const;
    	std::string getDarkestSecret() const;

	private:
    	std::string fName;
    	std::string lName;
    	std::string nickn;
    	std::string phoneNumber;
    	std::string darkestSecret;
};

#endif

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact { 
    public:
    // setters
	bool	setFirstName(std::string);
	bool	setLastName(std::string);
	bool	setNickname(std::string);
	bool	setPhoneNumber(std::string);
	bool	setDarkestSecret(std::string);

    // getters
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

    private:
    std::string	first_name;
    std::string	last_name;
    std::string	nickname;
    std::string	phone_number;
    std::string	darkest_secret;
};

#endif

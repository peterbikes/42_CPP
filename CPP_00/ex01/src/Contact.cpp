#include "../include/the_phonebook.hpp"

// SETTERS

bool Contact::setFirstName(std::string str) {
	if(str.length() == 0)
		return false;
	this->first_name = str;
		return true;
}

bool Contact::setLastName(std::string str) {
	if(str.length() == 0)
		return false;
	this->last_name = str;
		return true;
}

bool Contact::setNickname(std::string str) {
	if(str.length() == 0)
		return false;
	this->nickname = str;
		return true;
}

bool Contact::setPhoneNumber(std::string str) {
	if(str.length() == 0)
		return false;
	this->phone_number = str;
		return true;
}

bool Contact::setDarkestSecret(std::string str) {
	if(str.length() == 0)
		return false;
	this->darkest_secret = str;
		return true;
}


// GETTERS

std::string Contact::getFirstName() {
    return first_name;
}

std::string Contact::getLastName() {
    return last_name;
}

std::string Contact::getNickname() {
    return nickname;
}

std::string Contact::getPhoneNumber() {
    return phone_number;
}

std::string Contact::getDarkestSecret() {
    return darkest_secret;
}

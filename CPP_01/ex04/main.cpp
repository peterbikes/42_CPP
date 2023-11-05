#include <fstream>
#include <string>
#include <iostream>

bool 		ac_control(int ac);

std::string	makeshift_sed(std::string subj, std::string find, std::string replace)
{
	int control;
	int laps = 0;
	std::string exclude = subj;

	while(exclude.find(find) <= exclude.length())
	{
		control = exclude.find(find);
		exclude.erase(control, find.length());
		subj.erase(control+(replace.length()*laps), find.length());
		subj.insert(control+(replace.length()*laps), replace);
		laps++;
	}
	return subj;
}

int main (int ac, char **av)
{
	if(!ac_control(ac))
		return 0;
	
	std::ifstream	file(av[1]);

	if(!file.is_open())
	{
		std::cout << 
		"error opening file, maybe it does not exist?"
		<< std::endl;
		return 0;
	}

	std::ofstream	out_file;
	std::string 	filename(av[1]);
	filename.append(".replace");

	std::string content_read;
	char	control;

	while(file.good())
	{
		control = file.get();
		if(control != -1)
			content_read.push_back(control);	
	}

	out_file.open(filename.c_str());
	out_file << makeshift_sed(content_read, av[2], av[3]);

	file.close();
	out_file.close();
	return 0;
}

bool ac_control(int ac)
{
	if(ac != 4)
	{
		std::cout << 
		"wrong nbr of arguments, run me like: <filename> <to_replace> <by_me>"
		<< std::endl;
		return false;
	}	
	return true;
}

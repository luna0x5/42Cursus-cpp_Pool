/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:46:35 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 18:52:49 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceLine(std::string &line, std::string &search, std::string &replace)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(search, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += replace;
		pos = found + search.length();
	}
	result += line.substr(pos);
	return (result);
}

int openFiles(const std::string& filename, std::fstream& in, std::ofstream& out)
{
    in.open(filename.c_str());
    if (!in.is_open())
    {
        std::cout << "Error: Cannot open input file \"" << filename << "\"" << std::endl;
        return (0);
    }
    out.open((filename + ".replace").c_str());
	if (!out.is_open())
    {
        std::cout << "Error: Cannot create output file \"" << filename + ".replace" << "\"" << std::endl;
        in.close();
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
	std::string filename;
	std::string search;
	std::string replace;
	
	if (ac != 4)
	{
		std::cout << "ERROR: Wrong number of arguments" << std::endl;
		return (1);
	}
	filename = av[1];
	search = av[2];
	replace = av[3];
	if (search.empty())
	{
		std::cout << "ERROR: Search string can not be empty" << std::endl;
		return (1);
	}
	std::fstream infile;
	std::ofstream outfile;
	if (!openFiles(filename, infile, outfile))
		return (1);
	std::string line;
	while (std::getline(infile, line))
	{
		std::string newline = replaceLine(line, search, replace);
		outfile << newline;
		if (!infile.eof())
		{
			if (search == "\n")
				outfile << replace;
			else
				outfile << '\n';
		}
	}	
	infile.close();
	outfile.close();
	return (0);
}

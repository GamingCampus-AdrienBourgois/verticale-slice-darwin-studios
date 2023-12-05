#include "Components/Capacity.h"
#include <fstream>
#include <iostream>

//void Capacity::Data()
//{
//	std::string filename = "Capacity.txt";
//	std::ifstream ifstrm(filename);
//
//	if (ifstrm.is_open())
//	{
//		std::string ligne;
//		std::string delimiter = " ";
//
//		while (std::getline(ifstrm,ligne))
//		{
//			size_t position = 0;
//			while ((position = ligne.find(delimiter) != std::string::npos))
//			{
//				std::string mot = ligne.substr(0, position);
//				capacity.push_back(mot);
//				ligne.erase(0, position + delimiter.length());
//			}
//			capacity.push_back(ligne);
//		}
//		ifstrm.close();
//	}
//	else
//	{
//		std::cout << "failed to open the file"<< std::endl;
//	}
//}

void Capacity::SetName(std::string new_name)
{
	name = new_name;
}

void Capacity::SetDescription(std::string new_description)
{
	description = new_description;
}

void Capacity::SetEffect(float new_effect)
{
	effect = new_effect;
}
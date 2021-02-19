#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

void
reverse_order (std::string date1, std::string date2)
{
  std::string date;
  std::string num1 = date1;
  std::string num2 = date2;
  int days = 0;
  int index = 0;
  std::string amount[365];

  std::string eastSt;
  std::string eastEl;
  std::string westSt;
  std::string westEl;

  std::ifstream fin ("Current_Reservoir_Levels.tsv");
  if (fin.fail ())
    {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit (1);
    }

  std::string junk;
  getline (fin, junk);

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
      fin.ignore (INT_MAX, '\n');
      if (date == num1 or index == 1)
	{
	  amount[days] =
	  {
	  date + "" + westEl};
	  days = days + 1;
	  index = 1;
	}
      else if (date == num2)
	{
	  index = 0;
	}
      else if (index == 0)
	{
	  days = days + 0;
	}
    }
  days = days - 1;

  std::cout << "Day 1: " << num1 << std::endl;
  std::cout << "Day 2: " << num2 << std::endl;

  while (days != -1)
    {
      std::cout << amount[days] << "ft" << std::endl;
      days = days - 1;
    }
  fin.close ();
}

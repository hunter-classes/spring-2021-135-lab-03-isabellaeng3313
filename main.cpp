// add your code as appropriate 
#include <iostream>
#include <fstream>
#include "reservoir.h"
int main(){
    //PART A
    std::cout << "East basin storage: " << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
    std::cout << "East basin storage: " << get_east_storage("03/03/2018") << " billion gallons" << std::endl;
    std::cout << "East basin storage: " << get_east_storage("09/26/2018") << " billion gallons" << std::endl;
  
    //PART B
    std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
    std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;

    //PART C
    std::cout << compare_basins("01/01/2018") << std::endl; 
    std::cout << compare_basins("03/03/2018") << std::endl; 
    std::cout << compare_basins("09/26/2018") << std::endl; 
}
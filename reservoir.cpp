// add your code
#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

// PART A
double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open file
    }

    std::string junk;  //new string variable
    getline(fin, junk); //reads one line
    
    double eastSt;
    std::string info;

    while(fin >> info >> eastSt){
        fin.ignore(INT_MAX, '\n');  //skips to the end of line, ignorring the remaining columns
        std::cout << "Entered date: " << info << std::endl;
        if(info == date){    // will stop the while loop
            return eastSt;
            break;
        }
    }
    fin.close();
    return 0;

}

//PART B
double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open file
    }

    std::string junk;  //new string variable
    getline(fin, junk); //reads one line
    
    double lowest = 1150.0;
    double eastSt;
    std::string info;

    while(fin >> info >> eastSt){
        fin.ignore(INT_MAX, '\n');  //skips to the end of line, ignorring the remaining columns
        
        if(eastSt < lowest){    // will stop the while loop
            lowest = eastSt;
        }
    }
    return lowest;
    return 0;
}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open file
    }

    std::string junk;  //new string variable
    getline(fin, junk); //reads one line
    
    double highest = 0.0;
    double eastSt;
    std::string info;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

    while(fin >> info >> eastSt){
        fin.ignore(INT_MAX, '\n');  //skips to the end of line, ignorring the remaining columns
        
        if(eastSt > highest){    // will stop the while loop
            highest = eastSt;
        }
    }
    return highest;
    return 0;
}

//PART C
std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open file
    }

    std::string junk;  //new string variable
    getline(fin, junk); //reads one line
    
    double eastEl;
    double westEl;
    double none;
    std::string info;

    while(fin >> info >> none >>eastEl >> none >> westEl){
        fin.ignore(INT_MAX, '\n');  //skips to the end of line, ignorring the remaining columns
        if(date == info){    // will stop the while loop
            if (eastEl > westEl){
                return "East";
            }
            else if(eastEl < westEl){
                return "West";
            }
            else{
                return "Equal";
            }
        }
    }
    fin.close();
    return 0;

}

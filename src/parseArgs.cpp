/**
    parseArgs.cpp
    Purpose: Parse input arguments

    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

#include <getopt.h>
#include <cstring>
#include <iostream>

#include "util.h"
#include "parseArgs.h"


bool parseArgs (int argc, char **argv){
    opterr = 0;
    static int verbose_flag;
    static int print_rule_matrix;
    while (1)
    {
        static struct option long_options[] =
        {
            {"stMatrix",     no_argument,      &print_rule_matrix, 1},
            {"help",      no_argument,      0, 'h'},
            {"version",      no_argument,      0, 'v'},

            {NULL, 0, NULL, 0}
        };
        int option_index = 0;

        int c = getopt_long (argc, argv, "hv",
                        long_options, &option_index);

        if (c == -1)
        break;
        
        switch (c)
        {
        case 0:
            if (long_options[option_index].flag != 0)
            break;
            printf ("option %s", long_options[option_index].name);

            if (optarg)
            printf (" with arg %s", optarg);
            printf ("\n");
            break;

        case 'h':
            std::cout << std::endl << "-----------------------------------------------------------------------------" << std::endl;
            std::cout << "Turing Machine Recreator" << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl<<std::endl;

            std::cout << "Arguments to set flags:" << std::endl<<std::endl;
            std::cout << "--stMatrix" << "\t"  << "Indicates programs to print the StateMatrix of a given TMs" 
            << std::endl<< std::endl;

            std::cout << " Optional Arguments:" << std::endl<< std::endl;
            std::cout << "-v" << ", " << "--version" << "\t" << "Outputs the version of the program." << std::endl <<std::endl;
            std::cout << "-h" << ", " << "--help" << "\t" << "Describes program." <<std::endl<<std::endl;

            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            std::cout << "Examples:" << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            std::cout <<"Recreate specific tm and print tape after x iterations" << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            std::cout << "echo String | ./rtm" << std::endl;
            std::cout << "echo String | ./rtm" << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            std::cout <<"Print stMatrix of the tm" << std::endl;
            std::cout << "echo String | ./rtm --stMatrix"<< std::endl << std::endl;
            exit (0);

        case 'v':
            std::cout << "Relative Turing Machine Version 0.1" << std::endl<<std::endl;
            exit (0);

        case '?':
            break;

        default:
            abort ();
        }
    }

    if (verbose_flag) {
        std::cerr << "verbose flag is set" << std::endl;
    }
    if (print_rule_matrix==1) {
        return true;
    }

    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
        printf ("%s ", argv[optind++]);
        putchar ('\n');
    }
    return false;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>

/*
 * author: Hanna Ekholdt
 * date: 8/28/20
 * pledge: this is my own work, unless otherwise noted
 *
 * this is a template. file in author and date above and modify
 *
 * template last change: 8 oct 2019
 *
 */

#define USAGE_MESSAGE "usage: mytee [-av] _filename_"

/* globals and externs go here */


int main(int argc, char * argv[]) {
        int ch ;
        int ch1 ;
        int is_verbose = 0 ;
        int is_append = 0 ;
        char * mode_s = NULL ;
        char * filename ;
        FILE * f ;


        while ((ch = getopt(argc, argv, "va")) != -1) {
        //"va" = list of characters
//if argv has a 'v' or 'a' then those variable will change --> going through each character of the argument array               

                switch(ch) {
                /*
                 * modify or add to these case statements
                 */
                case 'v':
                        is_verbose = 1 ;
                        break ;
                case 'a':
                        is_append = 1 ;
                        break ;
                default:
                        printf("%s\n", USAGE_MESSAGE) ;
                        break;
                }
        }
        argc -= optind; // these are globals defined in the getopt code
        argv += optind;

        if (argc!=1) {
                printf("%s\n", USAGE_MESSAGE) ;
                return 0 ;
        }

        filename = argv[0] ; // access to data protected by an assertion that data is in fact there... first argument is the file to write into

        if (is_append){
                mode_s = "a";
}
        else {
                mode_s = "w";
        }

        if (is_verbose) { // example of using verbose 
                printf("%s:%d: openning file %s in mode %s\n",
                                __FILE__, __LINE__, filename, mode_s) ;
        }

        f = fopen(filename,mode_s); //first argument and writing/append mode
        assert(f) ; // example of  using assert's for DEBUGGING PURPOSES, to weed out errors

        while ((ch1 = getchar()) != EOF) {
                if(fputc(ch1,f)==EOF){
			assert(0);
		}
                fputc(ch1,stdout);
        }

        fclose(f);
        return 0;
}

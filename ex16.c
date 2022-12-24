/***************************************************************************
 *   ex16.c                                   Version 20220503.230956      *
 *                                                                         *
 *   Erros                                                                 *
 *   Copyright (C) 2022         by Matheus Henrique De Arruda              *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Matheus Henrique De Arruda                                            *
 *   Email: mha1@poli.br                                                   *
 *   Webpage: http://beco.poli.br/mha1@poli.br                             *
 *   Phone: (81) 99232-9583                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex16.c -o ex16.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <error.h>
#include <errno.h>
#include <string.h> 
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex16.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20220503.230956" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* ---------------------------------------------------------------------- */
/* prototypes */
int strerror_test(void);
int perror_test(void);
FILE *open_sesame (char *name);

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

/* ---------------------------------------------------------------------- */
/* This function does ...
 * 
 * It receives as input ... 
 *
 * It returns ...
 */
int main(void)
{
    const char *teste_error = NULL;
    char *program_invocation_name = NULL;

    perror_test();

    strerror_test();

    open_sesame(program_invocation_name);

    for(int i=1; i<256; i++)
    {
       error(1, i,  teste_error);
    }
    help();
    copyr();
  
    /* ...and we are done */
    return EXIT_SUCCESS;
}

/* add more functions here */

/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex16", "");
    printf("\nUsage: %s\n\n", "ex16");
    printf("This program does...\n");
    /* add more stuff here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Matheus Henrique De Arruda", "mha1@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information 
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex16", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2022, "Matheus Henrique De Arruda", "mha1@poli.br");
    return;
}
int strerror_test(void)
{
    FILE *fp;

   fp = fopen("file.txt","r");
   if( fp == NULL ) {
      printf("Error: %s\n", strerror(errno));
   }

   return 0;
}
int perror_test(void)
{
    FILE* arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL) {
        perror("Erro ao abrir o arquivo.txt");
        return 1;
    }

    fclose(arquivo);

    return 0;
}
FILE *open_sesame (char *name)
{
    extern char *program_invocation_short_name;
    FILE *stream;

    errno = 0;
    stream = fopen (name, "r");
    if (stream == NULL)
    {
        fprintf (stderr, "%s: Couldn't open file %s; %s\n",
                 program_invocation_short_name, name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    else

    return stream;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */


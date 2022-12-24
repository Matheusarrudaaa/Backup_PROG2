/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 2022 by Matheus Henrique De Arruda                      *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Matheus Henrique De Arruda <mha1@poli.br>                         *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 99232-9583                                                  *
 * ************************************************************************ *
 *
 */

#include "libmhda.h"

int main()
{   //variaveis
    float result;
    //chamado da funcao em libmhda.c e declarada me libmhda.h
    result = norm_var(norm.Numero, norm.Xmax, norm.Xmin);
	if(result  != 1)
	printf("%f\n", result);
    return 0;
}

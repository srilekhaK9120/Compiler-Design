/*Definition Section*/
%{
#include<stdio.h>
%}
/*Rule Section*/

%%

"(type)"|"sizeof" {printf("%s\tOPERATOR\n",yytext);}

"#include"|"#define" {printf("%s\tKEYWORD\n",yytext);}

"void"|"short"|"unsigned short"|"unsigned int"|"int"|"long"|"unsigned long"|"float"|"double"|"long double"|"char"|"unsigned char"|"(global)"|"static" {printf("%s\tKEYWORD\n",yytext);}

"__global__" {printf("%s\tKEYWORD\n",yytext);}

"Array"|"struct"|"union" {printf("%s\tDERIVED DATATYPE\n",yytext);}

"printf"|"scanf" {printf("%s\tKEYWORD\n",yytext);}

"break"|"return"|"default" {printf("%s\tKEYWORD\n",yytext);}
 						
"if"|"else"|"else if"|"do"|"while"|"for"|"switch"|"case"|"while" {printf("%s\tKEYWORD\n",yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {printf("%s\tIDENTIFIER\n",yytext);}  

[+-]?[0-9]+ {printf("%s\tCONSTANT\n",yytext);}

[+-]?[0-9]+[.][0-9]+ {printf("%s\tCONSTANT\n",yytext);}

[+-]?[0-9]+([.][0-9]+)?(E[+-]?[0-9]+) {printf("%s\tCONSTANT\n",yytext);}

\'.\'|\'\\.*\' {printf("%s\tCONSTANT\n",yytext);}

\"[^"]+\" {printf("%s\tSTRING\n",yytext);}

"+"|"-"|"/"|"*"|"%"|"="|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"!"|"&"|"^"|"\|"|"&&"|"\|\|"|"?:"|"+="|"-="|"="|"/="|"%="|"&="|"++"|"--"|"["|"]"|"("|")"|"~"|">>="|"<<="|"&="|"^="|"\|="|"." {printf("%s\tOPERATOR\n",yytext);}

"//".*"\n" {printf("%s\tSINGLE LINE COMMENT\n", yytext);}

"/*".*[\n]*.*"*/" {printf("%s\tMULTI LINE COMMENT\n", yytext);}

"{"|"}"|","|";"|":" {printf("%s\tSEPARATOR\n",yytext);}

"#"|"$" {printf("%s\tSPECIAL SYMBOL\n",yytext);}

.|\n; 												

%%

/*call the yywrap function*/
int yywrap()								
{
return 1;
}
/*Auxiliary function*/
/*Driver function*/

int main(void)
{
/*call the yylex function*/
printf("Enter String \n");
yylex();
return 0;
}




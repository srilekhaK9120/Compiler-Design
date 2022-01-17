

#include "codegen.h"
#include "backpatch.cpp"
#include "stable.cpp"
extern Quadruple quadruple[5000];

char* newTemp(){
	char *temp= new char[10];
	snprintf(temp,10,"__t%d__",tempGenerated);
	tempGenerated++;
	return temp;
}

void printCode(){
    FILE * file = fopen("output.txt","w");
	for(int i=0;i<nextInstr-1;i++){
	     printf("\n");
	     fprintf(file,"\n");
        if(!strcmp(quadruple[i].result,"if")){
            printf("%.4d : %s\t%s\t%s\t%s\t%s\t%.4d",i,quadruple[i].result,quadruple[i].addr1,quadruple[i].op,quadruple[i].addr2,quadruple[i].addr3,quadruple[i].label);
            fprintf(file,"%.4d : %s\t%s\t%s\t%s\t%s\t%.4d",i,quadruple[i].result,quadruple[i].addr1,quadruple[i].op,quadruple[i].addr2,quadruple[i].addr3,quadruple[i].label);
            continue;
        }
        if(!strcmp("goto",quadruple[i].result)){
             printf("%.4d : %s\t%.4d",i,quadruple[i].result,quadruple[i].label);
             fprintf(file,"%.4d : %s\t%.4d",i,quadruple[i].result,quadruple[i].label);
        }
	    else{
            printf("%.4d : %s\t=\t%s",i,quadruple[i].result,quadruple[i].addr1);
            fprintf(file,"%.4d : %s\t=\t%s",i,quadruple[i].result,quadruple[i].addr1);
            if(quadruple[i].op!=NULL){
                printf("\t%s",quadruple[i].op);
                fprintf(file,"\t%s",quadruple[i].op);
            }
            else continue;
            if(quadruple[i].addr2!=NULL){
                printf("\t%s",quadruple[i].addr2);
                fprintf(file,"\t%s",quadruple[i].addr2);
            }
            else continue;
            if(quadruple[i].addr3!=NULL){
                printf("\t%s",quadruple[i].addr3);
                fprintf(file,"\t%s",quadruple[i].addr3);
            }
            else continue;
            if(quadruple[i].label!=0){
                printf("\t%d",quadruple[i].label);
                fprintf(file,"\t%d",quadruple[i].label);
            }
	    }
	}
	 printf("\n%.4d : %s\n",nextInstr-1,quadruple[nextInstr-1].result);
	 fprintf(file,"\n%.4d : %s\n",nextInstr-1,quadruple[nextInstr-1].result);
	 fclose(file);
	
}

void genCode(const char *result,const char*addr1,const char *op,const char *addr2){
        quadruple[nextInstr].result=(char*)result;
		quadruple[nextInstr].addr1=(char*)addr1;
        quadruple[nextInstr].op=(char*)op;
		quadruple[nextInstr].addr2=(char*)addr2;
		quadruple[nextInstr].addr3=NULL;
		quadruple[nextInstr].label=0;
		nextInstr++;
}

void genCode(const char *result,const char *unop,const char*addr1){
        quadruple[nextInstr].result=(char*)result;
		quadruple[nextInstr].addr1=NULL;
        quadruple[nextInstr].op=(char*)unop;
		quadruple[nextInstr].addr2=(char*)addr1;
		quadruple[nextInstr].addr3=NULL;
		quadruple[nextInstr].label=0;
		nextInstr++;
}

void genCode(const char*result,const char *addr1,const char *op,const char *addr2,const char *addr3,int label){

		quadruple[nextInstr].result=(char*)result;
		quadruple[nextInstr].addr1=(char*)addr1;
		quadruple[nextInstr].op=(char*)op;
		quadruple[nextInstr].addr2=(char*)addr2;
		quadruple[nextInstr].addr3=(char*)addr3;
		quadruple[nextInstr].label=label;
		nextInstr++;
}

void genCode(const char *result,const char *addr1){
		quadruple[nextInstr].result = (char*)result;
		quadruple[nextInstr].addr1 = (char*)addr1;
		quadruple[nextInstr].addr2 = NULL;
		quadruple[nextInstr].addr3 = NULL;
		quadruple[nextInstr].label =0;
		nextInstr++;
}

void genCode(const char *result,int label){
		quadruple[nextInstr].result = (char*)result;
		quadruple[nextInstr].addr1 = NULL;
		quadruple[nextInstr].addr2 = NULL;
		quadruple[nextInstr].addr3 = NULL;
		quadruple[nextInstr].label = label;
		nextInstr++;
}

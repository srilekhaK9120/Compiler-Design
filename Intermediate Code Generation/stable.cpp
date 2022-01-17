#include<bits/stdc++.h>
#include "stable.h"
using namespace std;

short hashCode(char *str){
    short h = 0;
    for(u_int8_t i = 0 ; str[i]!='\0' ; i++){
        h = ((h<<5) + short(str[i]))%MOD;
    }
    return h;
}


SymbolTable *newTable(char *id ,int lineno,int type ){
    SymbolTable * temp = new SymbolTable;
    temp->Identifier = new char[strlen(id)];
    temp->attr = new Attributes;
    temp->attr->lineno = lineno;
    temp->attr->type = type;
    strcpy(temp->Identifier,id);
    temp->next = NULL;
    return temp;
}

void InsertId(char *id,int lineno,int type){
    short k;
    char *temp;
    if( IsPresent(id) ){
        k = getType(id);
        temp = new char[256];
        if(k==type){

            strcpy(temp,"redeclaration of '");
            getType(temp,type);
            strcat(temp,id);
            strcat(temp,"' ");
            AddError(temp,lineno,ERROR);

            temp[0]='\'';
            temp[1]='\0';
            getType(temp,type);
            strcat(temp,id);
            strcat(temp,"' previously declared here");
        }
        else{
            strcpy(temp,"Conflicting declaration  '");
            getType(temp,type);
            strcat(temp,id);
            strcat(temp,"' ");
            AddError(temp,lineno,ERROR);

            strcpy(temp,"previously declaration as '");
            getType(temp,getType(id));
            strcat(temp,id);
            strcat(temp,"' ");
        }
        AddError(temp,getLine(id),NOTE);
        delete temp;
        return;
    }

    k = hashCode(id);
   
    if(Table[k].Identifier==NULL){
        Table[k].Identifier = new char[strlen(id)];
        Table[k].attr = new Attributes;

        Table[k].attr->lineno = lineno;
        Table[k].attr->type = type;
        strcpy(Table[k].Identifier,id);
    }
    else{
        
        if(Table[k].next==NULL){
            Table[k].next = newTable(id,lineno,type);
        }
        SymbolTable *temp = Table[k].next;
        while(temp->next!=NULL)temp = temp->next;
        temp->next = newTable(id,lineno,type);
    }
}


void InitializeSymbolTable(){
    for(size_t i=0;i<MOD;i++){
       Table[i].Identifier =NULL;
       Table[i].attr=NULL;
       Table[i].next=NULL;
    }
}

void DeleteSymbolTable(){
    SymbolTable *temp;
    SymbolTable *temp2;
    for(size_t i=0;i<MOD;i++){
       if(Table[i].Identifier!=NULL){
            delete Table[i].Identifier;
            delete Table[i].attr;
            temp = Table[i].next;
            while(temp!=NULL){
               temp2=temp;
               temp=temp->next;
               delete temp2->attr;
               delete temp2;
            }
        }
    }
}


bool IsPresent(char *id){
    short k = hashCode(id);
    
    if(Table[k].Identifier==NULL){
        return false;
    }
    else{
        if(!strcmp(id,Table[k].Identifier))return true;
        SymbolTable *temp = Table[k].next;
        while(temp!=NULL){
            if(!strcmp(id,temp->Identifier))return true;
            temp = temp->next;
        }
        return false;
    }
}



int getLine(char *id){
    short k = hashCode(id);
    if(!strcmp(id,Table[k].Identifier))return Table[k].attr->lineno;
    SymbolTable *temp = Table[k].next;
    while(temp!=NULL){
        if(!strcmp(id,temp->Identifier))return temp->attr->lineno;
        temp = temp->next;
    }
    return -1;
}


short getType(char *id){
    short k = hashCode(id);
    if(!strcmp(id,Table[k].Identifier))return Table[k].attr->type;
    SymbolTable *temp = Table[k].next;
    while(temp!=NULL){
        if(!strcmp(id,temp->Identifier))return temp->attr->type;
        temp = temp->next;
    }
    return -1;
}

void getType(char *errmsg,int type){
    switch(type){
        case 1:
            strcat(errmsg,"int ");
            break;
        case 2:
            strcat(errmsg,"signed");
            break;
        case 3:
            strcat(errmsg,"signed int");
            break;
        case 4:
              strcat(errmsg,"unsigned");
              break;
        case 5:
           strcat(errmsg,"unsigned int ");
            break;
        case 6:
             strcat(errmsg,"float");
             break;
        case 7:
            strcat(errmsg,"signed float");
            break;
        case 8:
            strcat(errmsg,"unsigned float");
            break;
        case 9:
            strcat(errmsg,"bool");
            break;
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>

using namespace std;

char* reverse( char* str){
    if(str==NULL){return NULL;}
    char* str_ptr;
    char* rev_str,*rev_ptr;
    int len=strlen(str);
    rev_str = new char[len+1];
    rev_ptr=rev_str;
    str_ptr=str+len-1;
    
    for(;str_ptr!=str-1;str_ptr--){
        *rev_ptr=*str_ptr;
        rev_ptr++;
    }
    *rev_ptr='\0';
    return rev_str;
}

int atoi(char *str){
    int num=0;
    if(str==NULL){return num;}
    char* str_tmp;
    char sign=str[0];
    if(sign == '-'){      //+-
        str_tmp= str+1;
    }
    else{
        str_tmp= str;
    }
    for(;*str_tmp!='\0';str_tmp++){
        if(*str_tmp<'0' || *str_tmp>'9'){return 0;}
        num = num*10 + (int)(*str_tmp-'0');
    }
    return (sign=='-')? num*(-1) : num;
}
char* itoa(int value,char* buf){
    char* num = new char[12];
    unsigned int val;
    for(int i=0;i<12;i++){num[i]='\0';}
    char *c_ptr=num;
    bool sign=true;
    if(value<0){
        sign=false;
        val=(unsigned) (value*(-1));    
    }
    else{
        val=(unsigned) (value);
    }
    
    while(val!=0){
        *c_ptr=(val%10)+'0';
        val=val/10;
        c_ptr++;
    }
    if(sign==false){
        *c_ptr='-';
    }
    buf=reverse(num);  
    return buf;
}


int main()
{
    char *buf=new char[1024];
    int testInt [] = {1,-1,23,-23,INT_MAX,INT_MIN,0};
    const char* testStr [] = {"Hello World!",""};

    for( int i = 0 ; i <2; ++i) {
        strcpy(buf /*dest*/, testStr[i]/*src*/);
        // test reverse string
        reverse(buf);
        printf( "reverse(%s)", buf);        
        printf( "-> %s\n", reverse(buf));            
    }    
    free(buf);
    for( int i = 0;  i < 7; ++i) {
        // test itoa , atoi
        printf( "%d == %d\n", atoi( itoa(testInt[i],buf )) ,testInt[i]);
        // test reverse string
        printf( "reverse(%s)", buf);
        printf( "-> %s\n", reverse(buf));            
    }

    return 0;
}

////////////////////////////////////
///                              ///
///        ALEX OLHOVSKIY        ///
///                              ///
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void description(){
    printf("This program simulates data transfer from a portable device\n");
    printf("flags:\n");
    printf("-s <tableName> -p <password>");
}

void interprogramFunc(char*table,char*pass){
    int h=0,m=0,Y=0,M=0,d=0,t=0,error=255,num=0;
    char res[256]={0};
    char str[]="{\"table\": \"";
    char str_p[]="\", \"password\": \"";
    char str2[]="\", \"x\": ";
    char str3[]="}";
    char numBuf[20]={0};
    while(1){
        num=-30+rand()%60;
        itoa(num,numBuf,10);

        strcat(res,str);
        strcat(res,table);
        strcat(res,str_p);
        strcat(res,pass);
        strcat(res,str2);
        strcat(res,numBuf);
        strcat(res,str3);

        //printf("%s\n",res);
        //printf("%d\n",num);

        FILE*lfd=fopen("url.txt","w");
        if(lfd!=NULL){
            fprintf(lfd,"%s",res);
        }
        else{
            printf("Error in url formation");
        }
        fclose(lfd);

        system("python requestForTheServer4.py");
        res[0]='\0';

        sleep(5);
    }
}


int main(int argc,char*argv[])
{
    srand(time(NULL));
    char*fileName;
    char*tableName;
    char*password;
    int rez=0,key=0;
	// opterr=0;
	while ( (rez = getopt(argc,argv,"hs:p:")) != -1){
		switch (rez){
			case 'h':
                key=0;
                break;
            case 's':
                tableName=optarg;
                key++;
                break;
            case 'p':
                password=optarg;
                key++;
                break;
		};
	};

    switch(key){
        case 0:description();
            break;
        case 1:
            break;
        case 2:
            interprogramFunc(tableName,password);
            break;
        default:;
    }



    return 0;
}

#include "menuclick.h"
FILE *fin=NULL,*fin2=NULL;
int u=0;
void judgeprefig(int x,int y){
   if(x<=520&&x>=390&&y<=490&&y>=440){
       fin = fopen("prefigspeed.txt","w");
       fprintf (fin,"%f\n",0);
       fclose(fin);
       fin=NULL;
       for(int i=0;i<3;i++){
        if(i==0) menu_recthickdif[i]=10;
        else menu_recthickdif[i]=0;
       }
   }//easy
   else if(x<=720&&x>=540&&y<=490&&y>=440){
        fin = fopen("prefigspeed.txt","w");
        fprintf (fin,"%f\n",0.7);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<3;i++){
        if(i==1) menu_recthickdif[i]=10;
        else menu_recthickdif[i]=0;
       }

   }//medium
   else if(x<=950&&x>=740&&y<=490&&y>=440){
        fin = fopen("prefigspeed.txt","w");
        fprintf (fin,"%f\n",1.4);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<3;i++){
        if(i==2) menu_recthickdif[i]=10;
        else menu_recthickdif[i]=0;
       }

   }//diff
   else if(x<=420&&x>=380&&y<=635&&y>=595){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",1);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==0) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//1
   else if(x<=470&&x>=430&&y<=635&&y>=595){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",2);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==1) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//2
   else if(x<=525&&x>=485&&y<=635&&y>=595){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",3);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==2) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//3
   else if(x<=580&&x>=540&&y<=635&&y>=595){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",4);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==3) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//4
   else if(x<=630&&x>=590&&y<=635&&y>=595){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",5);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==4) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//5
   else if(x<=410&&x>=370&&y<=685&&y>=645){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",6);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==5) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//6
   else if(x<=470&&x>=430&&y<=685&&y>=645){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",7);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==6) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//7
   else if(x<=525&&x>=485&&y<=685&&y>=645){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",8);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==7) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//8
   else if(x<=580&&x>=540&&y<=685&&y>=645){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",9);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==8) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//9
   else if(x<=645&&x>=600&&y<=685&&y>=645){
        fin = fopen("prefiglevel.txt","w");
        fprintf (fin,"%d",10);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<10;i++){
        if(i==9) menu_recthicklev[i]=10;
        else menu_recthicklev[i]=0;
       }
   }//10
      else if(x<=420&&x>=380&&y<=390&&y>=350){
        fin = fopen("prefigvolume.txt","w");
        fprintf (fin,"%d",1);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<5;i++){
        if(i==0) menu_recthickvol[i]=10;
        else menu_recthickvol[i]=0;
       }
   }//1
      else if(x<=470&&x>=430&&y<=390&&y>=350){
        fin = fopen("prefigvolume.txt","w");
        fprintf (fin,"%d",2);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<5;i++){
        if(i==1) menu_recthickvol[i]=10;
        else menu_recthickvol[i]=0;
       }
   }//2
      else if(x<=525&&x>=485&&y<=390&&y>=350){
        fin = fopen("prefigvolume.txt","w");
        fprintf (fin,"%d",3);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<5;i++){
        if(i==2) menu_recthickvol[i]=10;
        else menu_recthickvol[i]=0;
       }
   }//3
      else if(x<=580&&x>=540&&y<=390&&y>=350){
        fin = fopen("prefigvolume.txt","w");
        fprintf (fin,"%d",4);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<5;i++){
        if(i==3) menu_recthickvol[i]=10;
        else menu_recthickvol[i]=0;
       }
   }//4
      else if(x<=630&&x>=590&&y<=390&&y>=350){
        fin = fopen("prefigvolume.txt","w");
        fprintf (fin,"%d",5);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<5;i++){
        if(i==4) menu_recthickvol[i]=10;
        else menu_recthickvol[i]=0;
       }
   }//5
         else if(x<=555&&x>=365&&y<=775&&y>=735){
        fin = fopen("prefigmode.txt","w");
        fprintf (fin,"%d",0);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<2;i++){
        if(i==0) menu_recthickintor[i]=10;
        else menu_recthickintor[i]=0;
       }
   }//nor
         else if(x<=805&&x>=580&&y<=775&&y>=735){
        fin = fopen("prefigmode.txt","w");
        fprintf (fin,"%d",1);
        fclose(fin);
        fin=NULL;
        for(int i=0;i<2;i++){
        if(i==1) menu_recthickintor[i]=10;
        else menu_recthickintor[i]=0;
       }
   }//in
   fin = fopen("prefigspeed.txt","r");
   fscanf(fin, "%f",&speedprefig);
   fclose(fin);
   fin=NULL;
   fin2 = fopen("prefiglevel.txt","r");
   fscanf(fin2, "%d",&level);
   fclose(fin2);
   fin2=NULL;
   fin = fopen("prefigvolume.txt","r");
   fscanf(fin, "%d",&music_volume);
   fclose(fin);
   fin=NULL;
   fin = fopen("prefigmode.txt","r");
   fscanf(fin, "%d",&modeinm);
   fclose(fin);
   fin=NULL;
   printf("%d %d music\n",music_volume,modeinm);
}






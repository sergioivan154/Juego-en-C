#include<stdio.h>
#include<conio.h>
#include<windows.h>
int bandera=0;
int trabar=0;
int listo[3];
int nivel;
int vidas_arreglo[3][3];//tres vidas y tres puntos
int perder=0;
int vidas=5;
int tipo_trampa=1;
void movimiento ();
void escena(int i,int j);
void trampas(int i, int j, int tipo_trampa);
void fondo();
main()
{
int i,j;

inicio:
clrscr();
i=5;
 j=20;
 trabar=0;
bandera=0;

perder=0;

   gotoxy(17,3);
         printf("Vidas : %d",vidas);
 gotoxy(i,j);
   textcolor(0xb);
	cprintf("%c",2);
   fondo();

escena(i,j);
 movimiento();
	if((vidas>=1)&&(listo[nivel]==0))
  goto inicio;
    clrscr();
    if(listo[nivel]==1){
    printf("Felicidades");
    getch();           }
    else               {
    printf("Gracias por participar");
    getch();            }
    

getch();
}



//Movimiento
void movimiento()
{


 int k;
 int i,j;
 int op,paso;
 i=5;
 j=20;
 paso=0;
 bandera=0;

 perder=0;


  do{




 if   (((((i<=47)|(i>59)&&(bandera==0))|((bandera==1)&&(((i<23)|(i>=31)) )) ))&&(trabar==0)){

 if(i>1){
  op=getch();

 switch(op){
case 77:
	//adelante


 i+=1;
   clrscr();

   fondo();

   escena(i,j);
	gotoxy(i,j);
   if(((i>=58)&&(i<=63))&&(bandera==0)){
 }
 else{
   textcolor(0xb);
	cprintf("%c",2);
      }
    	break;
case 75:
     //atras



 i-=1;
   clrscr();


        fondo();
   escena(i,j);

	gotoxy(i,j);

   if(((i>=58)&&(i<=63))&&(bandera==0)){
 }
 else{
   textcolor(0xb);
	cprintf("%c",2);
   }
   break;
 case 13: case' ':
//Salto

for(k=10;k<=14;k++)
	{
   Sleep(50);

   j=j-1;

   clrscr();
   fondo();
   escena(i,j);
   gotoxy(i,j);
   textcolor(0xb);
	cprintf("%c",2);
   }

   if(bandera==0){
   if((i>=2)&&(i<=6))
   bandera=1;
   Sleep(10);
   printf("\a");
   }
   else if(bandera==1){
        if((i>=2)&&(i<=6))
        bandera=0;
        }
for(k=14;k>=10;k--)
		{
   Sleep(70);

   j=j+1;
   clrscr();
   fondo();
    escena(i,j);
   gotoxy(i,j);
   textcolor(0xb);

   cprintf("%c",2);
		}


        break;

   case 'q':case 'Q':
   
   fondo();
//Salto  hacia atras
for(k=10;k<=14;k++)
{

   Sleep(70);

   j=j-1;

   clrscr();
   fondo();
     if(i>1){
    i=i-1;
    }
   escena(i,j);
   gotoxy(i,j);

   textcolor(0xb);
	cprintf("%c",2);


}
for(k=14;k>=10;k--)
{

fondo();
   Sleep(70);

   j=j+1;

   clrscr();
  fondo();
   if(i>1)
   i=i-1;
    escena(i,j);
    gotoxy(i,j);
   textcolor(0xb);
	cprintf("%c",2);

}

     break;
case 'E':case 'e':

fondo();
//Salto hacia adelante
for(k=10;k<=14;k++)
	{
   Sleep(70);

   j=j-1;

   clrscr();
   fondo();
   i=i+1;
    escena(i,j);
   	gotoxy(i,j);

   textcolor(0xb);
	cprintf("%c",2);

   }
for(k=14;k>=10;k--)
		{
   Sleep(70);

   j=j+1;

   clrscr();
    fondo();
    i=i+1;
    escena(i,j);

   	gotoxy(i,j);

   textcolor(0xb);
	cprintf("%c",2);
   	}

   break;
   }


 }
 else{

      i=2;
  		}

 }
 else
 {
 gotoxy(65,12);
printf("JAJA quedaste");
gotoxy(65,13);
tipo_trampa=2;
printf("atrapado");
gotoxy(65,14);
printf("liberate");
  getch();
  getch();
  tipo_trampa=2;
  perder=1;
 }
  if(((i>31)&&(i<41))){
  perder=1;   tipo_trampa=1;
                       }
  }while((perder==0)&&(trabar==0)&&listo[nivel]==0) ;  //posicion del agujero
  if(listo[nivel]==0){
  trampas(i,j,tipo_trampa);
  vidas-=1;          }



}





void trampas(int i, int j, int tipo_trampa)
{
  int x=i,y;
//caida
recucibidad:
  if(tipo_trampa==1){
  for(j=21;j<=24;j++)
	{
   Sleep(90);

   clrscr();
   fondo();
   escena(i,j);
   gotoxy(i,j);

   textcolor(0xb);
	cprintf("%c",2);
   }
   clrscr();
   fondo();
   escena(i,j);

   getch();
                     }
   else if(tipo_trampa==2)
   {
  //levitaR
  for(y=20;y>=1;y--)
	{
   Sleep(90);

   clrscr();
   fondo();
   escena(i,j);

   gotoxy(x,y);
   x=x+1;
   textcolor(0xb);
	cprintf("%c",2);
   }
   clrscr();
   fondo();
   escena(i,j);


   }
   else if(tipo_trampa==3)
   {
   //retroceder sin control

      textcolor(0xb);
   for(x=i;x<=70;x++){

   Sleep(100);
   clrscr();
   fondo(); escena(i,j);
   gotoxy(x,20);
   cprintf("%c",2);


          }


   Sleep(200);
   clrscr();
   gotoxy(x-1,20);

   fondo();
   escena(i,j);
	cprintf("%c",2);

   for(i=70;i>=40;i--)
   {

   Sleep(40);
  clrscr();
   fondo();
   escena(i,j);

   gotoxy(i,20);
	cprintf("%c",2);
   }
   tipo_trampa=1;
   goto recucibidad;
          }
printf("Muerte");
  getch();

}




//Funcuion punto clave de la pantalla
void escena(int i,int j)
{
int linea_horizotal,x,y,color,color2;
   nivel=1;
    gotoxy(17,3);
         printf("Vidas : %d",vidas);


   for(linea_horizotal=1;linea_horizotal<=30;linea_horizotal++)//Limite es una variable que indica hasta que punto se dibuja el agujero y hasta que punto se continua limite + 9
	{
   gotoxy(linea_horizotal,21);
      printf("*");

   }

   for(y=21;y<=24;y++)
  	{
       gotoxy(linea_horizotal,y);
       printf("*");
  	}
	for(linea_horizotal=41;linea_horizotal<80;linea_horizotal++) //agujero entre x=11 y x=20     intervalo de 9 puntos
	{
     gotoxy(linea_horizotal,21);
       printf("*");

   }
   for(y=21;y<=24;y++)
  	{
       gotoxy(41,y);
       printf("*");
  	}
   randomize();
    do{
    color=random(16);
    }while((color==6)|(color==0)|(color==8));
   textcolor(color);
     ////////////////Cuadro///////////////////////////////////////////////
   gotoxy(2,12);cprintf("%c",218);//marco superior izq
     gotoxy(6,12);cprintf("%c",191);//marco superior der
     gotoxy(2,15);cprintf("%c",192);// marco inferior izq
     gotoxy(6,15);cprintf("%c",217);//marco inferior der
    for(x=3;x<=5;x++){
    gotoxy(x,12); cprintf("%c",196);//------------
    gotoxy(x,15); cprintf("%c",196);//------------
                     }
     for(y=13;y<15;y++){
     	gotoxy(2,y);cprintf("%c",179);//  |
   	gotoxy(6,y);cprintf("%c",179);//  |
   	                }




   if (bandera==0){

    gotoxy(3,14);
    printf("OFF");

    for(y=20;y>=10;y--){
    gotoxy(48,y);
    do{

    color2=random(16);
    }while((color2==6)|(color2==0)|(color2==8)|(color2==16)|(color2==9)|(color2==4)|(color2==1)|(color==color2));
    textcolor(color2);
    cprintf("***************");


    						}

    if(i>=63)
    {
    gotoxy(75,16);
    printf("Salida");

    for(y=20;y>=17;y--){
    gotoxy(78,y);
    do{

    color2=random(16);
    }while((color2==6)|(color2==0)|(color2==8)|(color2==16)|(color2==9)|(color2==4)|(color2==1)|(color==color2));
    textcolor(color2);
    cprintf("**");

    }
    if(i==78)
   listo[nivel]=1;

     }

       }

   else{
   randomize();
   do{

    color2=random(16);
    }while((color2==6)|(color2==0)|(color2==8)|(color2==16)|(color2==9)|(color2==4)|(color2==1)|(color==color2));
    textcolor(color2);
   gotoxy(4,14);
    cprintf("ON");






    textcolor(3);
    gotoxy(19,17);
    cprintf("        *    ");
    gotoxy(19,18);
    cprintf("       ***   ");
    gotoxy(19,19);
    cprintf("      *****  ");
    gotoxy(19,20);
    cprintf("    ******** ");
    gotoxy(19,22);
    cprintf("To ame"); //tocame la c de clor distinto muestra el punto exacto para saltar
    textcolor(0xf);
    gotoxy(21,22);
    cprintf("c");
    gotoxy(24,19);
    textcolor(0xc);

    cprintf("%c",3);
     gotoxy(25,18);
     cprintf("%c",3);
     gotoxy(26,17);
     cprintf("%c",3);

               textcolor(0xe);
        gotoxy(70,14); cprintf("  ...    ");
        gotoxy(70,15); cprintf(".......  ");
        gotoxy(70,16); cprintf("... .....");
        gotoxy(70,17); cprintf(" ... ....");


        if(i<=40)
        {
        textcolor(0xc);
        gotoxy(74,16); cprintf("-");

        gotoxy(73,15); cprintf("'");
        }

        else
        {
        if(i%2==1)
        {
        textcolor(0xc);
        gotoxy(74,16); cprintf("O");
        gotoxy(73,15); cprintf("/");
        }
        else
        {
        textcolor(0xc);
        gotoxy(74,16); cprintf("-");

        gotoxy(73,15); cprintf("/");
        }

        }

        textcolor(0xf);

        gotoxy(70,16); cprintf("*");
        textcolor(0xe);
        gotoxy(70,17); cprintf("     ....");
        gotoxy(70,18); cprintf("     ....");
        gotoxy(70,19); cprintf("........");
        gotoxy(70,20); cprintf(".....");
             if(vidas_arreglo[0][1]==0){
        gotoxy(12,16);
     cprintf("%c",3);


     if((i==12)&&(j==16)){

     vidas_arreglo[0][1]=1;
     vidas+=1;
     							  				}
                		   }
       if(vidas_arreglo[0][2]==0){
        gotoxy(15,18);
     cprintf("%c",3);

     if((i==15)&&(j==18)){

     vidas_arreglo[0][2]=1;
     vidas+=1;

             	}
                		   }
     textcolor(0xe);
      if(vidas_arreglo[0][0]==0){
        gotoxy(18,17);

     cprintf("%c",3);

     if((i==18)&&(j==17)){

     vidas_arreglo[0][0]=1;
     vidas-=3;
              if(vidas<1){
              perder=1;

                          }
     			  							}
                		   }

         if(vidas<1){
         textcolor(0xb);
         gotoxy(17,3);
         printf("Vidas : ");
         cprintf("%d",vidas);
         gotoxy(17,4);
         printf("Hasta crees...");


         				}
                     else{
     		gotoxy(17,3);
         printf("Vidas : %d",vidas);
             }

              if((i==65)){

        textcolor(0xc);     //boton
        for(y=14;y>=10;y--){
        gotoxy(79,y);
        cprintf("**");
        							}
        textcolor(9);
        for(x=65;x<69;x++){ //zona de disparo
        gotoxy(x,21);
        cprintf("**");              //allegro.h
        							}


        textcolor(0xb);
        if (trabar==0){
        gotoxy(54,22);
        cprintf("Zona de disparo");
        gotoxy(54,23);
        cprintf("Presiona D");
        }
        else{
          gotoxy(54,22);
        cprintf("JAJA");
        gotoxy(54,23);
        cprintf("Ten mas cuidado");
        gotoxy(54,24);
        cprintf("Presiona cualquier tecla");
        }
        gotoxy(i,j);
   		textcolor(0xb);
			cprintf("%c",2);
        char op;
        op=getch();
        if((op=='d')|(op=='D'))
           {

           x=65;
           for(y=19;y>=10;y--){
           Sleep(70);
           x=x+2;
           gotoxy(x,y);
           cprintf("/");
        							}
           bandera=0;
        gotoxy(65,10);

           goto salida;
           }

             }

         else{
         if(i>=65){
         perder=2;
         trabar=1;
         }
                  }
        bandera=1;
        }

if(((i>=58)&&(i<=63))&&(bandera==0)){
    gotoxy(65,10);
printf("Truco activado");
gotoxy(65,11);
printf("Bonus de retroceso");

gotoxy(65,11);
printf("precione");

gotoxy(65,12);
printf("cualquier");
gotoxy(65,13);
tipo_trampa=2;
printf("Jajaja");
gotoxy(65,14);
printf("para accionarlo");
randomize();
    do{
    color=random(16);
    }while((color==6)|(color==0)|(color==8));
   textcolor(color);
   gotoxy(i,j);
   cprintf("%c",2);
}

else{
tipo_trampa=3;
}
        salida:
}
void fondo()
{

textcolor(0Xf);
gotoxy(8,1);
            cprintf("* **");
gotoxy(6,2);
          cprintf("*     **");
gotoxy(5,3);
         cprintf("*  | |  **");
gotoxy(3,4);
       cprintf("***        ***");
gotoxy(2,5);
      cprintf("*          ******");
gotoxy(1,6);
     cprintf("**      **  ******");
gotoxy(2,7);
		cprintf("****  ***   ****");

/*

                           * **
                         *     **
                        *  | |  **
                      ***        ***
                     *			  ******
                    **		 **  ******
                     ****  ***   ****
*/
textcolor(2);
gotoxy(15,10);
cprintf("     ***      ***");
gotoxy(15,11);
cprintf("    *****    ***** **");
gotoxy(15,12);
cprintf("   *******************");
gotoxy(15,13);
cprintf("  *********************");
gotoxy(1,14);
textcolor(6);                                             //********************
cprintf("_______________                      __________________________________________");
textcolor(2);
gotoxy(15,14);
cprintf(" ***********************");

gotoxy(15,15);
cprintf("*************************");

/*

                       ***      ***
                      *****    ***** **
                     *******************
                    *********************
___________________***********************____________________________
                  *************************

*/
textcolor(0xf);
gotoxy(38,1);
            cprintf("* **     *  **");
gotoxy(36,2);
          cprintf("*     **  *     **");
gotoxy(35,3);
         cprintf("*  | |  ***  | |  ***        **");
gotoxy(33,4);
       cprintf("***        **        ***     *    **");
gotoxy(32,5);
      cprintf("*           ***         **** *   ||  ***");
gotoxy(31,6);
     cprintf("**     **   ****    **   *****        ***");
gotoxy(32,7);
		cprintf("****  ***    ****  * ** **** **    ****");
}

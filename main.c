#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "MINI_PROJET.h"

//declaratino de fichier
FILE *p=NULL;

 void main()
{
   info t[1000];
   int j=0,i=0,choix,c1,c,k=0,ch,l;
   float max=0,s;

  p=fopen("fichier.txt","a");

    do
    {
      l=MENU1(i);

        switch(l)
        {
            case 7:{//saisir
                       system("cls");
                      if(i==0)
                      {
                          printf("\n\n   Combien d'etudiant voulez-vous saisir ?   ");
                                do{
                                      scanf("%d",&i);
                                  }while(i<1||i>1000);
                          do
                          {
                              system("cls");
                              saisir(t,j);
                              j++;
                          }while(j<i);
                      }
                      else
                      {
                           saisir(t,i);
                           i++;
                      }
                   };break;
            case 8:{ //recherche
                      system("cls");
                      printf("\n      Recherche d'un %ctudiant\n\n",130);
                      c1=MENU2();
                      switch(c1)
                      {
                           case 1:{system("cls");recherche1(t,i);getch();
                                  };break;
                           case 2:{system("cls");recherche2(t,i);getch();
                                  };break;
                      }
                   };break;
            case 9:{  //affichage
                      system("cls");
                      printf("\n      Afficher des %ctudiants\n\n",130);
                      c1=MENU3();
                      switch(c1)
                      {
                           case 1:{ system("cls"); afficher1(t,i); getch();
                                  };break;
                           case 2:{ system("cls"); afficher2(t,i); getch();
                                  };break;
                      }
                   };break;
            case 10:{  //la moyenne generale
                      system("cls");
                      printf("\n      La moyenne g%cn%crale\n\n",130,130);
                      c1=MENU2();
                      switch(c1)
                      {
                           case 1:{system("cls");moyenne1(t,i);getch();
                                  };break;
                           case 2:{system("cls");moyenne2(t,i);getch();
                                  };break;
                      }

                   };break;
            case 11:{ //major de promotion
                   system("cls");
                   if(i!=0)
                   {
                    max=t[0].moyenne;k=0;
                    for(j=0;j<i;j++)
                    {
                        if(t[j].moyenne>max)
                        {
                            max=t[j].moyenne;
                            k=j;
                        }
                    }
                    schema(t,k);getch();
                   }
                   else
                   {printf("\n*******Aucun etudiant afficher*******");getch();}
                   };break;
            case 12:{ //suprimer
                      system("cls");
                      printf("\n      Supprimer un %ctudiant\n\n",130);
                      c1=MENU2();
                      switch(c1)
                      {
                           case 1:{system("cls");i=supprimer1(t,i);getch();
                                  };break;
                           case 2:{system("cls");i=supprimer2(t,i);getch();
                                  };break;
                      }
                   };break;
            case 13:{ //le trie
                     system("cls");
                     printf("\n      Trier les %ctudiants\n\n",130);
                      c1=MENU4();
                      switch(c1)
                      {
                           case 1:{system("cls");triparnote(t,i);afficher1(t,i);getch();
                                  };break;
                           case 2:{system("cls");triparmat(t,i);afficher1(t,i);getch();
                                  };break;
                      }

                   };break;
            case 14:{ //les fichier
                        system("cls");
                        for(c=0;c<i;c++)
                        {
                            fprintf(p,"       \n  Etudiant:\n");
                            fprintf(p,"  \n Nom    : %s",t[c].nom);
                            fprintf(p,"  \n Prenom : %s",t[c].prenom);
                            fprintf(p,"  \n Matricule : %ld",t[c].mat);
                            fprintf(p,"  \n Date de naissance :   ") ;
                            fprintf(p,"   \n    jour :%d",t[c].jour);
                            fprintf(p,"   \n    mois :%d",t[c].mois);
                            fprintf(p,"   \n    annee:%d",t[c].annee);
                            fprintf(p,"  \n Les notes est:");
                               for(j=0;j<t[c].h;j++)
                               {
                                   fprintf(p,"  \n    Notes %d : %.2f",j+1,t[c].notes[j]);
                               }
                            fprintf(p,"\n\n\n");
                        }
                                     fclose(p);
                   };break;
        }
       system("cls");
    }while(l!=14);

      textcolor(12);gotoxy(20,5);cprintf("       MERCI POUR VOTRE PARTICIPATION ");
      
}

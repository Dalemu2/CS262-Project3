#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"itemList_dalemu2_207.h"

/* main funcion 
 * ask the user wishes to create a new delivery order. 
 * read the location and restaurant 
 * call  insertOrderList,printOrderItems and freeOrderItems functions
 */ 

int main ()
{

  char buffer[SIZE]={'\0'};
  char location[SIZE] ={'\0'};
  char restaurant[SIZE]={'\0'};
  char option;

  ordernode *hhead = NULL;   // declear and initialize hhead variable


  printf ("\t\t\tCampus Food Delivery\n\n");	

  while (1)
    {
      printf ("New delivery order? (y/n) : ");	/* ask the user if they wishes to creat new delivery order*/
      fgets (buffer, SIZE, stdin);
      sscanf (buffer, "%c", &option);		

      switch (option)
	{

	case 'y':
	  {

	    printf ("\nDelivery Address for new delivery order : "); /* Read location*/
	    fgets (location, SIZE, stdin);
	    location[strlen (location) - 1] = '\0';

	    printf ("Restaurant from which to pick up food : ");  /* read restaurant */
	    fgets (restaurant, SIZE, stdin);
	    restaurant[strlen (restaurant) - 1] = '\0';

	    insertOrderList(&hhead,location,restaurant);     /*call insertOrderList funcion // pass the location,restaurant and head to this funcion*/
	    printf ("\n");
	  }
	  break;

	case 'n':
	  {

	    printOrderItems (hhead);	/*call printOrderItems function to print the delivery orders*/
	    freeOrderItems(&hhead);	/*call freeOrderItems to free the allocated memories*/
	    exit (0);
	  }
	  break;

	default:
	  printf ("Invalid Input. Try again\n");   // if the user enters other than 'n' and 'y' characters*/
	}

    }
}

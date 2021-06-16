#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"itemList_dalemu2_207.h"
/* createOrderNode function creats an instance of ordernode
 * allocate memory,initializes ordernode struct field and 
 * return a pointer to the newly allocated struct
 */
ordernode *createOrderNode ()
{
  ordernode *newOrderNode = dmalloc (SIZE *sizeof (ordernode));
  
  newOrderNode->data = NULL;
  newOrderNode->deliverTo = "";
  newOrderNode->restaurant = "";
  newOrderNode->next = NULL;
  return newOrderNode;
  
}
/* insertOrderList funcion inserts the user delivery order lists
 * accept head,location and restaurant values from the main function
 * read the food items from the user and pass the value to insert function
 */ 
void insertOrderList (ordernode ** hhead, char *location, char *restaurant)
{
  char foodItem[SIZE];
  int signal;
  size_t str1 = strlen (location);
  size_t str2 = strlen (restaurant);

  itemList *s;
  s = createItem (); 	/* assign the initialized itemList struct fields to pointer variable*/
  ordernode *newOrderNode;
  newOrderNode = createOrderNode ();  


  newOrderNode->deliverTo = dmalloc (sizeof(str1));  /* allocate memory with str1  string size */
  memcpy (newOrderNode->deliverTo, location, str1);

  newOrderNode->restaurant = dmalloc (sizeof(str2)); /* allocate memory with str2  string size*/
  memcpy (newOrderNode->restaurant, restaurant, str2);

/* read food items until the user response is blank */
  do
    {

      printf ("food Item :");
      fgets (foodItem, SIZE, stdin);
      foodItem[strlen (foodItem) - 1] = '\0';

      signal = insert (foodItem, s);      /* pass the instance of itemList struct and foodItem list*/

      if (signal == 0)  /* increment count if the insertion is successful*/
	{
	  s->count++;
	}
	
    }
  while (foodItem[0] != '\0');

  newOrderNode->data = dmalloc (sizeof (itemList));
  newOrderNode->data = s;

  newOrderNode -> next =NULL;
 
   newOrderNode->next = *hhead;		/* add the new node to the head of the delivery list*/
  *hhead = newOrderNode;
}

/* print the delivery list */

void printOrderItems (ordernode * hhead)
{

  ordernode *tempNode = hhead;
  printf ("\nList of Deliveries: \n");

  while (tempNode != NULL)
    {
      printf ("\n");

      printf ("Delivery order from %s has %d food Items \n ",tempNode->restaurant, tempNode->data->count);

      printItems (tempNode->data);
      printf ("Deliver to : %s\n", tempNode->deliverTo);

      tempNode = tempNode->next;
    }
	//freeOrderItems(&hhead);
  printf ("\n");
}

/* free all memory allocated on insertOrderNode function*/
void freeOrderItems(ordernode **head)
{
	ordernode *tempNode;
	tempNode=*head;
	ordernode *nextNode;
        
	while(tempNode!=NULL)
	{
	   nextNode=tempNode -> next;
           free(tempNode -> deliverTo);
	   free(tempNode -> restaurant);
	   
	   freeItem(tempNode->data);  
	   free(tempNode -> data);
	   free(tempNode);
	  tempNode = nextNode; 
	}

}



#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"itemList_dalemu2_207.h"
/* createItem function, is an instance of itemList struct
 * allocate memory,initializes its fields(head and count) and returns 
 * a pointer to the newly allocated struct
 */
itemList * createItem ()
{

  itemList *newNode = dmalloc (sizeof (itemList)); /*allocate memory with itemList size*/
 
  newNode->head = NULL;
  newNode->count = 0;


  return newNode;	

}
/* insert function inserts food items in alphabetical order,
 * ignore duplicate strings finally returns 0 if the insertion
 * is successful otherwise return 1
 */

int insert (char *str, itemList * s)
{

  ordernode *newOrderNode = dmalloc (sizeof (ordernode));  /* allocate memory for newOrderNode variable */
 
  newOrderNode->data = s; 

  node *newNode = dmalloc (sizeof (node));
  
  int flag = 0;		
  size_t stringL = strlen (str);	

  newNode->data = dmalloc (sizeof(stringL)); /*allocate memory for node struct field( node -> data) with size of new string*/ 
  memcpy (newNode->data, str, stringL);   /*copy the string to node*/
  newNode->next = NULL;

  if (str[0] != '\0') 	/* check the string is different from blank */
    {

      if (newOrderNode->data->head == NULL)	/*insert the first node*/
	{

	  newOrderNode->data->head = newNode;
	  flag = 0;        
	}
	
/*compare the new node data and head data( if strcmpi returns 0 ignore insertion*/
      else if (strcmpi (newNode->data, newOrderNode->data->head->data) == 0)  

	{

	   flag = 1;
	}

/*compare the new node data and head data( if strcmpi returns < 0 insert new node*/
      else if (strcmpi (newNode->data, newOrderNode->data->head->data) < 0)
	{

	  newNode->next = newOrderNode->data->head;
	  newOrderNode->data->head = newNode;
	  flag = 0;
	}

      else
	{

	  node *tempNode;
	  tempNode = newOrderNode->data->head;
	/*compare each node data with the new node data until the end of the list*/
	  while ((tempNode->next != NULL)
		 && (strcmpi (newNode->data, tempNode->next->data)>= 0))
	    {
		/* if the newnode data alrady inserted, then ignore the insertion*/
	      if (strcmpi (newNode->data, tempNode->next->data) == 0)
		{

		  flag = 1;
		  tempNode = tempNode->next;
		}

	      else
		{

		  tempNode = tempNode->next;
		}
	    }
	if(flag==0)
	 {
	  newNode->next = tempNode->next;
	  tempNode->next = newNode;
	 }
	}
    }
  else
    {

      flag = 1;
    }
  return flag;
}
/* Displays the elements of the itemList with each string on a new line.*/
void printItems (itemList * s)
{

  node *tempNode = s->head;

  while (tempNode != NULL)
    {

      printf ("   => %s\n", tempNode->data);
      tempNode = tempNode->next;
    }

}
/* deallocate the allocated memory*/
void freeItem(itemList *s)
{
	node *tempNode;
	tempNode=s -> head;
	node *nextNode;
	while(tempNode!=NULL)
	{
	   nextNode=tempNode -> next;
	   
           
	   free(tempNode -> data);
	   free(tempNode);
	   tempNode=nextNode;
	}
	s =NULL;;
}


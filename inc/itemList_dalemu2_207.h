#ifndef itemList_dalemu2_207

#define itemList_dalemu2_207

typedef struct _node
{
   char *data;  // Food Item Name
   struct _node *next;
} node;

typedef struct _itemList
{
   node *head;  // Pointer to first food item for the order (alphabetical)
   int count;   // Number of food items in the order
} itemList;
typedef struct _ordernode
{
   itemList *data;
   char *deliverTo;
   char *restaurant;
   struct _ordernode *next;
} ordernode;

#define SIZE 100
/* prototypes for functons located at 
 * itemList_dalemu2_207.c
 * project3_dalemu2_207.c and
 * helperfunction.c
 */

itemList *createItem();
int insert(char *str, itemList *s);
void printItems(itemList *s);
int strcmpi(char *s, char *t);
void *dmalloc(size_t size);
void freeItem(itemList *s);
void freeOrderItems(ordernode **s);
void printOrderItems(ordernode *hhead);
void insertOrderList(ordernode **head,char *location,char *restaurant);
ordernode *createOrderNode();
#endif 

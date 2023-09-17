#include "shell.h"

/**
 * 
 * 
 * 
*/

void free_list(list* head) 
{

	while (head != NULL) 
	{
	      	 list* temp = head;
      	  	 head = head->next;
       	  	 free(temp->dir);
       	 	 free(temp);
        }

}
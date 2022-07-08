#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

 typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0 || *begin_list == 0)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

 void print_list(t_list **begin_list)
 {
  t_list *cur = *begin_list;
  while (cur != 0)
  {
      printf("%s\n", cur->data);
      cur = cur->next;
  }
 }
 int cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return (0);
	return (1);
}

 int main(void)
{
	t_list *lst;
	int a = 1;
	int b = 2;
    int c = 3;
    int d = 4;
    int f = 1;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &a;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &b;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &c;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &d;
	lst->next->next->next->next =  NULL;

	ft_list_remove_if(&lst, &f, cmp);

	while (lst != NULL)
	{
		printf("%d\n", *(int*)lst->data);
		lst = lst->next;
	}

	return (0);
}

//  int      main(void)
//  {
//   char straa[] = "9";
//   t_list *aa = malloc(sizeof(t_list));
//   aa->next = 0;
//   aa->data = straa;
 
//   char strbb[] = "9";
//   t_list *bb = malloc(sizeof(t_list));
//   bb->next = 0;
//   bb->data = strbb;
 
//   char strcc[] = "1";
//   t_list *cc = malloc(sizeof(t_list));
//   cc->next = 0;
//   cc->data = strcc;
 
//   char strdd[] = "9";
//   t_list *dd = malloc(sizeof(t_list));
//   dd->next = 0;
//   dd->data = strdd;
 
//   aa->next = bb;
//   bb->next = cc;
//   cc->next = dd;
 
//   t_list **begin_list = &aa;
 
//   print_list(begin_list);
//   printf("----------\n");
//   ft_list_remove_if(begin_list, strbb, strcmp);
//   print_list(begin_list);
//  }

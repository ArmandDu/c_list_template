#ifndef TEMPLATE_C_H_
# define TEMPLATE_C_H_

# include <stdlib.h>

# define template_list(type)						\
									\
  struct s_list_##type;							\
									\
  typedef struct							\
  {									\
    long	(*add)(struct s_list_##type *list, type *elem);		\
    type	*(*pop)(struct s_list_##type *list);			\
    size_t	(*size)(struct s_list_##type *list);			\
    void	(*free)(struct s_list_##type *list, void (*free_f)());	\
  }		t_list_functions_##type;				\
									\
  typedef struct		s_node_##type				\
  {									\
    type			*data;					\
    struct s_node_##type	*next;					\
  }				t_node_##type;				\
									\
  typedef struct		s_iterator_##type			\
  {									\
    t_node_##type		*nodes;					\
    type			*(*get_next)(struct s_iterator_##type *); \
    char			(*has_next)(struct s_iterator_##type *); \
    void			(*free)(struct s_iterator_##type *);	\
  }				t_iterator_##type;			\
									\
  typedef struct s_list_##type						\
  {									\
    size_t			size;					\
    t_node_##type		*nodes;					\
    t_list_functions_##type	*funcs;					\
    t_iterator_##type		*(*iterator)(struct s_list_##type *);	\
  }				t_list_##type;				\
									\
  long list_add_##type(t_list_##type *list, type *elem);		\
  size_t list_size_##type(t_list_##type *list);				\
  type *list_pop_##type(t_list_##type *list);				\
  void list_free_##type(t_list_##type *, void (*free_f)());		\
									\
inline  type		*get_next_##type(struct s_iterator_##type *it)	\
  {									\
    type *elem;								\
									\
    if (it->nodes)							\
      {									\
	elem = it->nodes->data;						\
	it->nodes = it->nodes->next;					\
      }									\
    return (elem);							\
  }									\
  inline char		has_next_##type(struct s_iterator_##type *it)	\
  {									\
    return (it->nodes != NULL);						\
  }									\
  inline void		free_iterator_##type(struct s_iterator_##type *it) \
  {									\
    free(it);								\
  }									\
									\
inline t_list_functions_##type	*get_list_functions_##type(void)	\
{									\
  t_list_functions_##type *list_f;					\
									\
    if (!(list_f = malloc(sizeof(*list_f))))				\
      return (NULL);							\
    list_f->add = list_add_##type;					\
    list_f->pop = list_pop_##type;					\
    list_f->size = list_size_##type;					\
    list_f->free = list_free_##type;					\
 return (list_f);							\
}									\
									\
 t_iterator_##type *new_iterator_##type(struct s_list_##type *list)	\
  {									\
    t_iterator_##type *iterator;					\
									\
    if (!(iterator = malloc(sizeof(*iterator))))			\
      return (NULL);							\
    iterator->nodes = list->nodes;					\
    iterator->has_next = has_next_##type;				\
    iterator->get_next = get_next_##type;				\
    iterator->free = free_iterator_##type;				\
    return (iterator);							\
  }									\
									\
 t_list_##type		*new_list_##type()				\
  {									\
    t_list_##type  *ptr;						\
    if (!(ptr = malloc(sizeof(*ptr))))					\
      return (NULL);							\
    ptr->nodes = NULL;							\
    ptr->size = 0;							\
    ptr->funcs = get_list_functions_##type();				\
    ptr->iterator = new_iterator_##type;				\
    return (ptr);							\
  }									\
									\
 inline long		list_add_##type(t_list_##type *list, type *elem) \
  {									\
    t_node_##type *node;						\
    t_node_##type *ptr = list->nodes;					\
									\
    if (!(node = malloc(sizeof(*node))))				\
      return (-1);							\
    node->data = elem;							\
    node->next = NULL;							\
    if (list->size > 0)							\
      {									\
	while (ptr->next)						\
	  ptr = ptr->next;						\
	ptr->next = node;						\
      }									\
    else								\
      list->nodes = node;						\
    return (++(list->size));						\
  }									\
									\
 inline type		*list_pop_##type(t_list_##type *list)		\
  {									\
    t_node_##type *ptr;							\
    t_node_##type *last;						\
    type *elem;								\
    									\
    ptr = list->nodes;							\
    elem = NULL;							\
    if (list->size > 1)							\
      {									\
	while (ptr->next)						\
	  {								\
	    if (!(ptr->next->next))					\
	      last = ptr;						\
	    ptr = ptr->next;						\
	  }								\
	elem = ptr->data;						\
	free(ptr);							\
	last->next = NULL;						\
	--(list->size);							\
      }									\
    else if (list->size == 1)						\
      {									\
	elem = ptr->data;						\
	free(ptr);							\
	list->nodes = NULL;						\
	list->size = 0;							\
      }									\
    return (elem);							\
  }									\
									\
  inline size_t			 list_size_##type(t_list_##type *list)	\
  {									\
    return (list->size);						\
  }									\
  									\
  inline void			 list_free_##type(t_list_##type *list,	\
						  void (*free_f)(void*)) \
  {									\
    type *elem;								\
									\
    while (list->size > 0)						\
      {									\
	elem = list->funcs->pop(list);					\
	if (free_f)							\
	  free_f(elem);							\
      }									\
    free(list->funcs);							\
    free(list);								\
  }									\
								

# define push_list(list, data)	list->funcs->add(list, (data))
# define list_size(list)	list->funcs->size(list)
# define pop_list(list)		list->funcs->pop(list)
# define has_next(iterator)	iterator->has_next(iterator)
# define get_next(iterator)	iterator->get_next(iterator)

# define List(type)		t_list_##type	*
# define Iterator(type)		t_iterator_##type *

# define new_list(type)		new_list_##type()
# define new_iterator(list)	(list->iterator(list))

# define delete_list(list, f)	(list->funcs->free(list, f))
# define delete_iterator(it)	(list->delete_iterator(it))

#endif /* !TEMPLATE_C_H_ */

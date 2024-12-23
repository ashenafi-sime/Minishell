/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	ft_fork(int *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];

	ft_pipe(fd);
	ft_fork(&pid);

	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "Hello parent!", 13);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 13);
		close(fd[0]);
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
	return 0;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:24 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/08 18:28:00 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push(t_stack **head, char *var)
{
	t_stack	*new_st;

	new_st = malloc(sizeof(t_stack));
	new_st->var = ft_strdup(var);
	new_st->next = NULL;
	if (is_empty(*head))
		new_st->prev = NULL;
	else
	{
		new_st->prev = *head;
		(*head)->next = new_st;
	}
	*head = new_st;
	if (!is_empty((*head)->prev))
	{
		(*head)->id = (*head)->prev->id + 1;
	}
	else
		(*head)->id = 0;
}


t_stack	*end_stack(t_stack **st)
{
	if (is_empty((*st)->next))
		return (*st);
	while (!is_empty((*st)->next))
		*st = (*st)->next;
	return (*st);
}


void	remove_stack(t_stack **head)
{
	t_stack	*cur;

	cur = *head;
	ft_printf("remove\n");
	if (!is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur-> next;
		(*head)->prev = cur-> prev;
		free(cur->var);
		free(cur);
	}
	else if (is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur->next;
		(*head)->prev = NULL;
		free (cur->var);
		free (cur);
	}
	else if (!is_empty(cur->prev) && is_empty(cur->next))
	{
		(*head) = cur->prev;
		(*head)->next = NULL;
		free (cur->var);
		free (cur);
	}
}

void	find_n_remove(t_stack **st, char *key)
{
	char	*temp;

	if (is_empty(*st))
		return ;
	while (1)
	{
		temp = ft_strkey((*st)->var, '=');
		if (!ft_strcmp(key, temp))
		{
			free(temp);
			remove_stack(st);
			end_stack(st);
			return ;
		}
		free(temp);
		if (!is_empty((*st)->prev))
			break ;
		*st = (*st)->prev;
	}
	end_stack(st);
}


/*
void	pop(t_stack **head, char *key)
{
	t_stack	*cur;

	if (is_empty(*head))
		return ;
	cur = find_in_stack(head, key);
	if (is_empty(cur))
	{
		printf("Stack.c : No Match found ===next - %i====\n",is_empty((cur->next)));
		return ;
	}
	printf("1 = Stack.c : %s, ====prev stack= %i===\n \n", cur->var, !is_empty(cur->prev));
	
	printf("Stack.c : %s \n====next stack= %i===\n \n", cur->var, !is_empty(cur->next));
}
*/

int	is_empty(t_stack *check)
{
	return (check == NULL);
}

int	st_len(t_stack *st)
{
	if (is_empty(st))
		return (0);
	return (1 + st_len(st->next));
}

int	not_sorted(t_stack **st)
{
	t_stack	*cur;

	cur = *st;
	while (!is_empty((cur)))
	{
		if (!is_empty(cur->next))
		{
			if (ft_strcmp(cur->var, (cur->next)->var) > 0)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}


*/

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    char *rl;
	while (1){
	rl = readline("ourMiniShell > ");
    printf("%s\n", rl);
	free(rl);
	}
    
    return (0);
}

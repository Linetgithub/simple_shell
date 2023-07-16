#include "shell.h"

/**
 * _myhistory - the history list is displayed, one command on each line,
 * preceded with line numbers, starting at 0.
 * @info: potential arguments are contained in this structure
 * it is used to maintain a constant function prototype.
 * Return: it will always return 0
 */

int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - alias is set to string
 * @info: it is a parameter structure
 * @str: this is the string alias
 * Return: it will always return 0 on success,
 * 1 when there is an error
 */

int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');

if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias - alias is set to string
 * @info:it is a parameter structure
 * @str:it is the string alias
 * Return: it will always return 0 on success,
 * 1 when there is an error
 */

int set_alias(info_t *info, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - an alias string is printed
 * @node:this is the alias node *
 * Return: it will always 0 on success, 1 when there is an error
 */

int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');

for (a = node->str; a <= p; a++)

_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - it imitates the alias builtin (man alias)
 * @info: potential arguments are contained in this structure
 * it is used to maintain a constant function prototype.
 * Return: Always 0
 */

int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next; }
return (0); }
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
return (0);
}

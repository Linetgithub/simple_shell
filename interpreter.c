#include "shell.h"
/**
* _myexit - used to exit the shell
* @info:contains arguments
* Return: 0 exit if info.argv[0] !=
*/
int _myexit(info_t *info)
{
int exit;
if (info->argv[1])/* an exit argument */
{
exit = _erratoi(info->argv[1]);
if (exit == -1)
{
info->status = 2;
print_error(info, "unwanted number:");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
* _mycd - current directory has changed
* @info: maintains a constant function prototype
* Return:0
*/
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO:>>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /*TODO:what is it suppose to be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what is it suppose to be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "cannot cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 *  _myhelp -the current directory of the process is changed
 *  @info: potential arguments are contained in this structure
 *  it is used to maintain a constant function prototype.
 *  Return: it will always return
 */
int _myhelp(info_t *info)
{
char **arg_array;
_setenv(info, "OLDPWD", _getenv(info, "PWD="));

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}

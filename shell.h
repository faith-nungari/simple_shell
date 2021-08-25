#ifndef _ALX_MAIN_H
#define _ALX_MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <wait.h>

/**
 * struct list - linked list for environmenta variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
char *var;
struct list *next;
} list_t;

/* function prototypes */

ssize_t _prompt(char **argv, int *flag, char **env);
int _exitt(char *av, int num);
int _print_env(char *av, char **env);
void _path(char **av, char *env, char *av_0, int av_l, int *p_find);
void fill(char *str, char *p);
char **_strtok(char *str);
void __cd_error(info_t *info, char *dir);
void __cd_success(info_t *info);
int __cd(info_t *info);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *str);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
int built_in(char **token, list_t *env, int num, char **command);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
int _env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
char *int_to_string(int num);




#include <dirent.h>
#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifdef MAX_EXIT_CODE
#undef MAX_EXIT_CODE
#endif
/* The maximum value of an exit code */
#define MAX_EXIT_CODE 256
#ifdef HISTORY_FILE
#undef HISTORY_FILE
#endif
/* The file name used to store this shell's history */
#define HISTORY_FILE "/.simple_shell_history"
/* The string representation of INT32_MAX */
#ifndef MAX_INT_STR
#define MAX_INT_STR "2147483647"
#endif

#include "main_types.h"

/* ******** Program (simple_shell.c) ******** */

void init_shell(int ac, char *av[], char *envp[]);
void print_node(cmd_t *node);
void handle_signal(int sig_num);
void *get_shell_prop(char prop_id);
void clean_up_shell(void);
/* ******** ---------------- ******** */

/* ******** Alias Manager (alias_manager.c) ******** */

void manage_aliases(char op);
void add_alias(char *name, char *value);
char *get_alias_value(char *str);
alias_t **get_aliases(int *len);
/* ******** ---------------- ******** */

/* ******** History Manager (history_manager.c) ******** */

void manage_history(int op);
void add_to_history(char *str);
void save_history(void);
char **get_history(int *size);
int get_line_num(void);
/* ******** ---------------- ******** */

/* ******** Environment Variable Helpers (env_var_helpers.c) ******** */

char *get_env_var(char *str);
void set_env_var(char *var, char *val);
void add_env_var(char *var, char *val);
void remove_env_var(char *var);
/* ******** ---------------- ******** */

/* ******** Line Reader (line_reader.c) ******** */

char *get_cmd_line(void);
void check_chars(char *quote, char *quote_o, char current_char);
void set_error(char *error, char quote_o, int n, char *str, int pos);
void print_prompt(void);
/* ******** ---------------- ******** */
/* ******** CLI Helpers (cli_helpers_#.c) ******** */

cmd_t *get_next_command(cmd_t *cur, int exit_code);
void handle_ctrl_d(int len);
char check_args(int ac, char *av[]);
char is_blank(char *str);
/* ******** ---------------- ******** */

/* ******** CLI Parser (cli_parser.c) ******** */

cmd_t *parse_cmd_line(char *line);
void init_processing_table(proc_tbl_t **proc_tbl,
	token_t **tokens, cmd_t **cmd_list);
void process_commands_separator(proc_tbl_t *proc_tbl);
void process_operator(proc_tbl_t *proc_tbl);
void process_word(proc_tbl_t *proc_tbl);

char *read_variable(char *str, int pos);

token_t *tokenize_command_string(char *str);
void skip_comment(char *str, int o, int *len_out);
char *read_operator(char *str, int o, int *len_out, char *error);
char *read_word(char *str, int o, int *len_out);

void adjust_block(char **blk, size_t new_sz, size_t *old_sz, char incr);
char *dissolve_tokens(char *str, char can_free);
void dissolve_cmd_parts(cmd_t *node);
void expand_tilde(char *str, size_t *i, char **res, size_t *j, size_t *size);
void expand_variable(char *str, size_t *i,
	char **res, size_t *j, size_t *size);

char is_valid_prev_char(char c);
token_t *get_token_tail(token_t **head);
token_t *process_alias_expansion(token_t **tokens);
void process_tokens(token_t **tokens);
/* ******** ---------------- ******** */

/* ******** Cmd_t Helpers (cmd_t_helpers.c) ******** */

cmd_t *new_cmd_node(void);
void free_cmd_t(cmd_t **head);
void add_node_to_end(cmd_t **head, cmd_t **node);
cmd_t *get_cmd_t_tail(cmd_t *head);

void add_token_to_end(token_t **head, token_t *tkn);
token_t *create_token(char *value, char type);
void free_token_t(token_t **head);
token_t *get_token_at_index(int idx, token_t **head);
/* ******** ---------------- ******** */

/* ******** IO Helpers (io_helpers_#.c) ******** */

char **read_all_lines(int fd, int *lines_out);
void print_text(int fd, char *text[], int n);
/* ******** ---------------- ******** */

/* ******** Memory Helpers (mem_helpers.c) ******** */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_array(char **list, int length);
/* ******** ---------------- ******** */

/* ******** Executors (executor.c) ******** */

void execute_cmds_list(cmd_t **cmds_list, uchar_t *exit_code);
int exec_built_in_cmd(cmd_t *node);
int exec_program(cmd_t *node, char *program_path);
char **copy_environment(char **env, int env_count);
char **copy_arguments(cmd_t *node);
/* ******** ---------------- ******** */

/* ******** Built-In Commands (shell_cmds_#.c) ******** */

int sc_alias(int ac, char *av[]);
void print_alias(char *name, char *value);
int sc_cd(int ac, char *av[]);
int sc_env(int ac, char *av[]);
int sc_exit(int ac, char *av[]);
int sc_help(int ac, char *av[]);
int sc_history(int ac, char *av[]);
int sc_setenv(int ac, char *av[]);
int sc_unsetenv(int ac, char *av[]);
/* ******** ---------------- ******** */

/* ******** Built-In Commands Help (shell_cmds_help_#.c) ******** */

void help_program(void);
void help_alias(void);
void help_cd(void);
void help_env(void);
void help_exit(void);
void help_help(void);
void help_history(void);
void help_setenv(void);
void help_unsetenv(void);
/* ******** ---------------- ******** */

/* ******** String Utilities (utils_str_#.c) ******** */

int str_to_int(const char *num);
void mem_set(char *str, int n, char c);
char *trim_start(char *str, char c, char can_free);
char *trim_end(char *str, char c, char can_free);
int str_len(const char *str);
char str_eql(char *left, char *right);
char *str_copy(const char *str);
char *str_cat(char *left, char *right, char can_free);
char *copy_range(char *str, int a, int b);
char **str_split(char *str, char c, int *len_out, char can_free);
char *str_replace(char *str, char *sub_str, char *rep_str, char can_free);
char *long_to_str(long num);
char *rep_range(char *str, char *val, int a, int b);
char *strs_join(char **arr, int n, char c, char can_free);
void print_error(char *command_name, char *userinput, char *error_message);
void swap(char *x, char *y);
char *reverse(char *buffer, int i, int j);
char *_itoa(int value, char *buffer, int base);
char str_in_arr(char **arr, int n, char *str);
/* ******** ---------------- ******** */

/* ******** Validator Utilities (utils_validator_#.c) ******** */

char is_digit(char c);
char is_whitespace(char c);
char is_letter(char c);
char is_quote(char c);
char is_variable_expandible(char *str, int pos, char quote, char quote_o);
char is_tilde_expansion_char(char c);
char is_built_in_cmd(cmd_t *cmd);
char str_is_num(char *str);
char is_binary_file(char *fn);
char is_variable(char *str);
char is_exec_file(char *fp);
char is_alias(char *str);
char is_alias_name(char *str);
char is_alias_assignment(char *str, char **name_out, char **value_out);
int is_regular_file(const char *path);
char is_binary_file(char *fn);
char is_normal_program(cmd_t *node, char **path_out);
char is_system_command(char *command, char **abs_path);
char is_valid_uint(char *str);
/* ******** ---------------- ******** */

/* ******** DATA Validator (data_validators_#.c) ******** */

char *check_path(char *str);
char *search_path(char *command);
/* ******** ---------------- ******** */

/**
 * enum Shell_Prop_Ids - Consists of the shell's property ids
 * @ENVP_ID: The prop id for the shell's environment variables
 * @ENVP_COUNT_ID: The prop id for the shell's environment variables count
 * @EXEC_NAME_ID: The prop id for the shell's given executale file name
 * @SHELL_PID_ID: The prop id for the shell's process identifier
 * @NODE_EXIT_CODE_ID: The prop id for the last executed command's exit code
 * @IS_INTERACTIVE_ID: The prop id for the interactive status of the shell
 */
enum Shell_Prop_Ids
{
	/* The prop id for the shell's environment variables */
	ENVP_ID = 0,
	/* The prop id for the shell's environment variables count */
	ENVP_COUNT_ID = 1,
	/* The prop id for the shell's given executale file name */
	EXEC_NAME_ID = 6,
	/* The prop id for the shell's process identifier */
	SHELL_PID_ID = 7,
	/* The prop id for the last executed command's exit code */
	NODE_EXIT_CODE_ID = 8,
	/* The prop id for the interactive status of the shell */
	IS_INTERACTIVE_ID
};

/**
 * enum Operator_Types - The operator codes for this shell program.
 * @OP_NONE: The operator code for no operator
 * @OP_AND: The operator code for a logical AND character
 * @OP_OR: The operator code for a logical OR character
 * @OP_SEP: The operator code for a command separator character
 */
enum Operator_Types
{
	/* The operator code for no operator */
	OP_NONE = 0,
	/* The operator code for a logical AND character (&&) */
	OP_AND = 1,
	/* The operator code for a logical OR character (||) */
	OP_OR = 2,
	/* The operator code for a command separator character (;) */
	OP_SEP = 3
};

/**
 * enum Token_Types - Types of tokens in a command line
 * @TKN_BEG: The beginning of the command line
 * @TKN_WORD: A word in the command line
 * @TKN_SPACE: An open space in the command line
 * @TKN_OP: An open operator in the command line
 * @TKN_SEP_OP: An open separator in the command line
 */
enum Token_Types
{
	/* The beginning of the command line */
	TKN_BEG = 0,
	/* A word in the command line */
	TKN_WORD = 1,
	/* An open (not enclosed in quotes) space in the command line */
	TKN_SPACE = 2,
	/* An open (not enclosed in quotes) operator in the command line */
	TKN_OP = 3,
	/* An open (not enclosed in quotes) separator in the command line */
	TKN_SEP_OP = 4
};

/**
 * enum Management_Operations - Operation codes for managing some resources
 * @MO_INIT: Initialize the resources
 * @MO_FREE: Free the resources
 */
enum Management_Operations
{
	/* Initialize the resources */
	MO_INIT = 0,
	/* Free the resources */
	MO_FREE = 1
};

/**
 * enum Exit_Codes - Exit codes for this shell program
 * @EC_SUCCESS: The command executed successfully
 * @EC_GENERAL_ERROR: Catchall for general errors
 * @EC_INVALID_ARGS: Misuse of shell built-ins
 * @EC_CANNOT_EXECUTE: Command invoked cannot execute
 * @EC_COMMAND_NOT_FOUND: Command not found
 * @EC_INVALID_EXIT_ARGS: Invalid argument to exit
 * @EC_FATAL_ERROR_SIGNAL: Fatal error signal "n"
 * @EC_CONTROL_C_TERMINATION: Script terminated by Control-C
 * @EC_EXIT_STATUS_OUT_OF_RANGE: Exit status out of range
 */
enum Exit_Codes
{
	/* The command executed successfully */
	EC_SUCCESS = 0,
	/* Catchall for general errors */
	/* E.g.; Miscellaneous errors, such as "divide by zero" and other */
	/* impermissible operations */
	EC_GENERAL_ERROR = 1,
	/* Misuse of shell built-ins */
	EC_INVALID_ARGS = 2,
	/* Command invoked cannot execute */
	/* Permission problem or command is not an executable */
	EC_CANNOT_EXECUTE = 126,
	/* Command not found */
	/* Possible problem with $PATH or a typo */
	EC_COMMAND_NOT_FOUND = 127,
	/* Invalid argument to exit */
	EC_INVALID_EXIT_ARGS = 128,
	/* Fatal error signal "n" */
	/* Ranges from 128 to 255; 0 <= n <= 127 */
	EC_FATAL_ERROR_SIGNAL = 128,
	/* Script terminated by Control-C */
	EC_CONTROL_C_TERMINATION = 130,
	/* Exit status out of range */
	/* exit takes only integer args in the range 0 - 255 */
	EC_EXIT_STATUS_OUT_OF_RANGE = 255
};

/**
 * struct token - Represents a word or operator on the command line
 * @value: The value of the token
 * @type: The type of the token
 * @next: The next token on the command line
 */
struct token
{
	/* The value of the token */
	char *value;
	/* The type of the token */
	char type;
	/* The next token on the command line */
	struct token *next;
};

/**
 * struct command_node - Represent a command and its arguments.
 * @command: The name of the command
 * @args_count: The number of arguments provided
 * @args: The arguments provided
 * @next_cond: The condition for executing the next command
 * @next: The next command that can be executed
 */
struct command_node
{
	/* The name of the command */
	char *command;
	/* The number of arguments provided */
	int args_count;
	/* The arguments provided */
	char **args;
	/* The condition for executing the next command */
	char next_cond;
	/* The next command that can be executed */
	struct command_node *next;
};

/**
 * struct processing_table - Represents the parameters used in \
 * parsing a list of tokens
 * @tokens_list: The pointer to the list of tokens being processed
 * @cur_token: The current token being processed
 * @cur_cmd_node: The current command node being built
 * @cmds_list_head: The pointer to the head of the commands list being built
 * @error: The error flag that represents a processing error
 * @pos: The current index in the list of tokens being processed
 */
struct processing_table
{
	/* The pointer to the list of tokens being processed */
	struct token **tokens_list;
	/* The current token being processed */
	struct token *cur_token;
	/* The current command node being built */
	struct command_node *cur_cmd_node;
	/* The pointer to the head of the commands list being built */
	struct command_node **cmds_list_head;
	/* The error flag that represents a processing error */
	char error;
	/* The current index in the list of tokens being processed */
	int pos;
};

/**
 * struct built_in_cmd - Represents a built-in command node
 * @cmd_name: The name of the built-in command
 * @run: The handler for the built-in command
 */
struct built_in_cmd
{
	/* The name of the built-in command */
	char *cmd_name;
	/* The handler for the built-in command */
	int (*run)(int, char**);
};

/**
 * struct alias - Represents an alias command
 * @name: The name of the alias
 * @value: The value of the alias
 */
struct alias
{
	/* The name of the alias */
	char *name;
	/* The value of the alias */
	char *value;
};

/**
 * struct cmd_help - Represents this shell's help pages
 * @cmd_name: The name of the built-in command
 * @run: The handler for the built-in command's help
 */
struct cmd_help
{
	/* The name of the built-in command */
	char *cmd_name;
	/* The handler for the built-in command's help */
	void (*run)(void);
};

typedef unsigned char uchar_t;
typedef struct token token_t;
typedef struct command_node cmd_t;
typedef struct cmd_help cmd_help_t;
typedef struct built_in_cmd built_in_cmd_t;
typedef struct alias alias_t;
typedef struct processing_table proc_tbl_t;


#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <argp.h>


const char *argp_program_version = "cronx-0.0";
const char *argp_program_bug_address = "github.com/montagist/cronx/issues";

static char doc[] = "cronx -- a simple timer program used to add delays or countdowns to other scripts or command line uses";
static char args_doc[] = "timer_length [timer_name]";

static struct argp_option options[] = {

	{ "len",	'l', 0, 0, "Get current running time for timer(s)" },
	{ "time",	't', 0, 0, "Create new timer." },
	{ "name",	'n', 0,	0, "Name of new, targeted, or Regex matching sought-after timers." },
	{ "id",		'i', 0, 0, "Alternative match timers by id or id-matching Regex instead." },
	{ "db",		'd', "FILE", 0, "Specify alternative location of timer database." },
	{ "pause",	'p', 0, 0, "Pause timer(s)." },
	{ "resume",	'r', 0, 0, "Resume timer(s)." },
	{ "kill",	'k', 0, 0, "Kill timer(s)." }, 
	{ 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments {
	char *args[2];
	char * database;
	long timer_length;
	char * timer_name;
	char * timer_id;
};

static int parse_opt( int key, char *arg, struct argp_state *state ) {

	struct arguments *the_args = (struct arguments*) state->input; 

	switch( key ) {

		case 'l':
			printf( "Should print out timers here \n" ); 
		break;

		case 'n':
			the_args->timer_name = arg;
		break;
	}

	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

int main( int argc, char **argv ) {

	struct arguments arguments;

	// Defaults
	arguments.database = NULL;
	arguments.timer_length = 0;
	arguments.timer_name = NULL;
	arguments.timer_id = NULL;

	argp_parse ( &argp, argc, argv, 0, 0, &arguments );

	printf( "testing. \n" );
	return 0;
}

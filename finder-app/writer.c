#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

	if (argc != 3) {
		syslog(LOG_ERR, "Not enough input arguments. Expecting 2");
	}
	
	const char *path = argv[1];
	const char *content = argv[2];

	FILE *file = fopen(path, "w");
	if (!file) {
		syslog(LOG_ERR, "Error opening file");
		return EXIT_FAILURE;
	}

	if (fputs(content, file) == EOF) {
		syslog(LOG_ERR, "Error writing file");
		fclose(file);
		return EXIT_FAILURE;
	}
	
	if (fclose(file) != 0) {
		syslog(LOG_ERR, "Error writing file");
		return EXIT_FAILURE;
	}
	syslog(LOG_INFO, "File wrtten successfully");
	closelog();
  return 0;
}

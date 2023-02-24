#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "util.c"
#include "list.c"
#include "queue.c"
#include "parse.c"
// #include "xml_token.c"
#include "xml_parse.c"
// #include "xml_tree.c"


int main(int argc, char **argv) {
if (argc != 2) {
fprintf(stderr, "Usage: %s <XML file>\n", argv[0]);
return 1;
}

// Read input XML file
FILE *f = fopen(argv[1], "r");
if (!f) {
perror("fopen");
return 1;
}
fseek(f, 0, SEEK_END);
long fsize = ftell(f);
fseek(f, 0, SEEK_SET);
char *data = malloc(fsize + 1);
if (!data) {
perror("malloc");
fclose(f);
return 1;
}
fread(data, fsize, 1, f);
fclose(f);
data[fsize] = 0;

// Initialize parser
Parser p;
parse_init(&p, NULL, data);

// Parse XML file
int res = parse_text(&p);



// Clean up
free(data);

return res ? 0 : 1;
}

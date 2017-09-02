#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "definitions.h"

int main(int argc, char const *argv[]) {
  /* code */

  /* Create a new tree */
  node_t* new_tree = NULL;

  /* Declare and initialise variables needed  */
  char prefix[MAX_NUM_CHAR + 1];

  char buffer_str[WEIGHT_PLUS_KEY + 2];
  int weight;

  FILE* infile;
  FILE* outfile;

  infile = fopen(argv[1], "r");
  while (fscanf(infile, "%d;%s", weight, prefix)) {
    prefix[strlen(prefix) - 1] = '\0';
    new_tree = insert(new_tree, prefix, weight);
  }
  fclose(infile);

  outfile = fopen(argv[2], "w");

  if (argv[3] == "<" && argv[4] != NULL) {
    FILE* datafile;
    datafile = fopen(argv[4], "r");
    
  }



  new_tree = insert(new_tree, "cut", 3);
  new_tree = insert(new_tree, "at", 2);
  new_tree = insert(new_tree, "cute", 4);
  new_tree = insert(new_tree, "cure", 4);
  new_tree = insert(new_tree, "cat", 3);
  new_tree = insert(new_tree, "car", 3);
  new_tree = insert(new_tree, "pet", 3);



  /* prefix is an array prepared to store a string
    find_and_traverse is a function that finds the prefix in my tree and prints
    stuffs basically
    I want to be prompted with "Prefix: " again and again when I input whatever
    string I want and press enter.
    That works before but right now if you see my inner while loop, I want to be able
    to enter not only one word, but multiple words in a single execution
    (e.g. when prompted by the terminal, I can type "first_word second_word third_word etc."
    and have my loop process all the words typed in, AND THEN prompt me with
    "Prefix: " again). What my current code below does, is that it DOES NOT
    prompt me with "Prefix: " once I type in however many words I want in the
    stdin (even though it still accepts input and processes them fine), and
    if I hit Ctrl-D in the terminal, it runs an infinite loop(probably cos of
    the while(TRUE). So what do I do to get it to prompt me properly and work right.
    */
while (TRUE) {
  printf("Prefix: ");
  scanf("%s", prefix);
  find_and_traverse(new_tree, prefix);
  printf("\n");
}








  return 0;
}

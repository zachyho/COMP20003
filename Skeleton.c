#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "definitions.h"

/**
* Given a call like root = insert(root, ”cat”, 3)
* the code below should return the tree containing the new key
*/
node_t* insert(node_t* pNode, char* word, int weight) {
  if (pNode == NULL) {
      /**
      * Create a new pNode, and save a character from word
      */
      pNode = create_node(word);
  }
  if (word[0] < pNode->data) {
    /**
    * Insert the character on the left branch
    */
    pNode->left = insert(pNode->left , word, weight);
  } else if (word[0] == pNode->data) {
    if (word[1] == '\0') {
      /**
      * set pNode end of key flag to true and assign weight
      */
      pNode->end_of_key = TRUE;
      pNode->weight = weight;
    } else {
      /**
      * If the word contains more characters , try to insert them
      * under the equal branch
      */
      pNode->equal = insert(pNode->equal, word + 1, weight);
    }
  } else {
      /**
      * if current char in word is greater than char in pData
      * Insert the character on the right branch
      */
      pNode->right = insert(pNode->right, word, weight) ;
    }
  return pNode;
}


/* Find and print all keys following given prefix */
void find_and_traverse(node_t* pNode, char* prefix) {

  char buffer[MAX_NUM_CHAR];
  /**
  * Find the node in the tree that represents the prefix
  * pNode will point there if we reached the '\0' symbol,
  * if prefix does not exist , then pNode should be NULL
   */

  int index = 0;
  while (prefix[index] != '\0' && pNode != NULL) {
    /**
    * Find tree position for prefix
    */

    // left branch
    if (prefix[index] < pNode->data) {
      /**
      * Go to left branch
      */
      pNode = pNode->left;
      continue ;
    }

      // right branch
    if(prefix[index] > pNode->data) {
      /**
      * Go to right branch
      */
      pNode = pNode->right;
      continue ;
    }

    // equal branch
    if(prefix[index] == pNode->data) {
      /**
      * Go to equal branch, and check next char in prefix
      */
      buffer[index] = prefix[index];

      /* If current character being checked is the last in the prefix, pNode
      stays where it is */
      if (index == strlen(prefix) - 1) {
        break;
      }

      pNode = pNode->equal;
      index++;
      continue;
    }
  }

  /**
  * At this point, pNode should be pointing to
  * the node where the prefix is contained.
  */
  if (pNode == NULL) {
    printf("NOTFOUND\n");
  }
  else {
    /**
    * Include the prefix itself as a candidate
    * if prefix is a key
    */
    if (pNode->end_of_key == TRUE) {
      buffer[strlen(prefix)] = '\0';
      printf("key:  %s --> weight:  %d\n", buffer, pNode->weight);
    }

      /**
      * print all the keys that contain the prefix
      */
    traverse(pNode->equal, buffer, strlen(prefix));
  }
}

/**
* Tree traversal from a given node
*/
void traverse(node_t* pNode, char* buffer, int depth) {

  if (pNode == NULL) {
    return;
  }

  /**
  * Go first to the left most branch */
  traverse(pNode->left, buffer, depth);

  /**
  * If no more left branches , then save the character
  */
  buffer[depth] = pNode->data;
  if (pNode->end_of_key == TRUE) {
    buffer[depth + 1] = '\0';
    printf("key:  %s --> weight:  %d\n", buffer, pNode->weight);
  }

  /**
  * and go to the equal branch, advancing
  * to the next character of the key
  */
  traverse(pNode->equal, buffer, depth + 1);
  /**
  * Finally go to the branches that contain
  * characters greater than the current one in the buffer
  */
  traverse(pNode->right, buffer, depth);
}

/**
* Creates a new node and initialises values for the variables contained
*/
node_t* create_node(char* data) {
  node_t* new_node = (node_t* )malloc(sizeof(node_t));
  assert(new_node);

  /* Initialising variables in created node */
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->equal = NULL;
  new_node->data = data[0];
  new_node->end_of_key = FALSE;
  new_node->weight = DEFAULT_WEIGHT;

  return new_node;
}

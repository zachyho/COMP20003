#define MAX_NUM_CHAR 250
#define DEFAULT_WEIGHT 0
#define TRUE 1
#define FALSE 0
#define WEIGHT_PLUS_KEY sizeof(int) + 250

/* Defining each node of the ternary tree as a struct */
typedef struct node node_t;

struct node {
  char data;
  int weight;
  int end_of_key;
  node_t* left;
  node_t* right;
  node_t* equal;
} ;


/* Function prototypes */
node_t* insert(node_t* pNode, char* word, int weight);
void find_and_traverse(node_t* pNode, char* prefix);
void traverse(node_t* pNode, char* buffer, int depth);
node_t* create_node(char* data);

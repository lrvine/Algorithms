class listnode {
 public:
  char get_data();
  int set_data(char);
  int set_left_node(listnode *);
  int set_right_node(listnode *);
  listnode *get_left_node();
  listnode *get_right_node();
  listnode();

 protected:
  char data;
  listnode *left;
  listnode *right;
};

void handle_node(listnode *);

void preorder_r_dfs(listnode *);
void inorder_r_dfs(listnode *);
void postorder_r_dfs(listnode *);

void preorder_i_dfs(listnode *);
void inorder_i_dfs(listnode *);
void postorder_i_dfs(listnode *);

void bfs(listnode *);
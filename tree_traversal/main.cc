#include <iostream>
#include "traversal.h"


using namespace std;

int main ( int argc , char** argv ){

listnode *a= new listnode;
listnode *b= new listnode;
listnode *c= new listnode;
listnode *d= new listnode;
listnode *e= new listnode;
listnode *f= new listnode;
listnode *g= new listnode;
listnode *h= new listnode;
listnode *i= new listnode;

a->set_data('a');
b->set_data('b');
c->set_data('c');
d->set_data('d');
e->set_data('e');
f->set_data('f');
g->set_data('g');
h->set_data('h');
i->set_data('i');

f->set_left_node(b);
f->set_right_node(g);
b->set_left_node(a);
b->set_right_node(d);
d->set_left_node(c);
d->set_right_node(e);
g->set_right_node(i);
i->set_left_node(h);


preorder_r_dfs(f);
cout<<endl;
preorder_i_dfs(f);
cout<<endl;
cout<<endl;

inorder_r_dfs(f);
cout<<endl;
inorder_i_dfs(f);
cout<<endl;
cout<<endl;

postorder_r_dfs(f);
cout<<endl;
postorder_i_dfs(f);
cout<<endl;
cout<<endl;

bfs(f);
cout<<endl;

return 0;
}

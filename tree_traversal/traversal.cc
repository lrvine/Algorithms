#include "traversal.h"
#include<stack>
#include<queue>
#include<iostream>

using namespace std;

listnode::listnode(){
	right=NULL; 
	left=NULL;
}	

char listnode::get_data(){
	return data;
}

int listnode::set_data(char d){
	data=d;
	return 0;
}

int listnode::set_left_node( listnode* l ){
	left = l;
	return 0;
}
int listnode::set_right_node( listnode* r ){
	right = r;
	return 0;
}

listnode* listnode::get_left_node(){
	return left;
}

listnode* listnode::get_right_node(){
	return right;
}


void handle_node( listnode * node){
	cout<<node->get_data()<<" ";
}

void preorder_r_dfs( listnode * current){
	if( current == NULL)
		return;
	handle_node(current);
	if(current->get_left_node()){
		preorder_r_dfs(current->get_left_node());	
	}
	if(current->get_right_node()){
		preorder_r_dfs(current->get_right_node());
	}
}

void inorder_r_dfs( listnode * current){
	if( current == NULL)
		return;
	if(current->get_left_node()){
		inorder_r_dfs(current->get_left_node());	
	}
	handle_node(current);
	if(current->get_right_node()){
		inorder_r_dfs(current->get_right_node());
	}
}
void postorder_r_dfs( listnode * current){
	if( current == NULL)
		return;
	if(current->get_left_node()){
		postorder_r_dfs(current->get_left_node());	
	}
	if(current->get_right_node()){
		postorder_r_dfs(current->get_right_node());
	}
	handle_node(current);
}

void preorder_i_dfs( listnode * root){ 

	stack<listnode*> ss;
	listnode * current;

	if( root == NULL )
		return;

	ss.push(root);

	while( !ss.empty() ){
		current = ss.top();
		ss.pop();
		handle_node(current);
		if( current->get_right_node()){
			ss.push(current->get_right_node());
		}
		if(current->get_left_node()){
			ss.push(current->get_left_node());
		}
	}
}

void inorder_i_dfs( listnode * root){ 

	stack<listnode*> ss;
	listnode * current;

	if( root == NULL )
		return;

	current = root;
	while( !ss.empty() || (current != NULL) ){
		if(current != NULL){
			ss.push(current);
			current=current->get_left_node();
		}else{
			current=ss.top();
			ss.pop();
			handle_node(current);
			current=current->get_right_node();
		}
	}
}

void postorder_i_dfs( listnode * root){ 

	stack<listnode*> ss;
	listnode * current;
	listnode * lastvisited;

	if( root == NULL )
		return;

	current = root;
	while( !ss.empty() || (current != NULL) ){
		if(current != NULL){
			ss.push(current);
			current=current->get_left_node();
		}else{
			current=ss.top();
			if( (current->get_right_node() != NULL) && ( current->get_right_node() != lastvisited )){
				current=current->get_right_node();
			}else{
				handle_node(current);
				lastvisited = current;
				ss.pop();
				current=NULL;
			}
		}
	}
}

void bfs( listnode * root){
	queue<listnode*> ss;
	listnode* current;
	ss.push(root);
	while( !ss.empty() ){
		current = ss.front();
		handle_node(current);
		ss.pop();
		if( current->get_left_node() ){
			ss.push(current->get_left_node());
		}
		if( current->get_right_node() ){
			ss.push(current->get_right_node());
		}
	}
}


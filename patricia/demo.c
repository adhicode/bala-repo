/*
 * initial version 
 *
 * 
 */

#include "patricia.h"
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */

/*
void func(prefix_t *prefix) {
	char str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, (&(prefix)->add.sin), str, INET_ADDRSTRLEN);	
	// printf("node: %s/%d\n", prefix_toa(prefix), prefix->bitlen);
	printf("node: %s/%d\n", str, prefix->bitlen);
}
*/

void func(prefix_t *prefix, void *data) {
	char str[INET_ADDRSTRLEN];
	char egress_intf[5]="e0/0"; 
	inet_ntop(AF_INET, (&(prefix)->add.sin), str, INET_ADDRSTRLEN);	
	// printf("node: %s/%d\n", prefix_toa(prefix), prefix->bitlen);
	printf("node: %s/%d nexthop %x\n", str, prefix->bitlen, data);
}

#define BALA1 1

patricia_tree_t *tree;

int
main(void)
{
    prefix_t *prefix;
    //patricia_tree_t *tree;
    patricia_node_t *node;

    tree = New_Patricia(32);

    make_and_lookup(tree, "127.0.0.0/8");

#define BALA_TEST100_UC 1
#if BALA_TEST100_UC

    make_and_lookup(tree, "127.1.0.0/16");
    make_and_lookup(tree, "127.2.0.0/16");
    make_and_lookup(tree, "127.3.0.0/16");
    make_and_lookup(tree, "127.4.0.0/16");
    make_and_lookup(tree, "127.5.0.0/16");
    make_and_lookup(tree, "127.6.0.0/16");
    make_and_lookup(tree, "127.7.0.0/16");
    make_and_lookup(tree, "127.8.0.0/16");
    make_and_lookup(tree, "127.9.0.0/16");
    make_and_lookup(tree, "127.10.0.0/16");
    make_and_lookup(tree, "127.11.0.0/16");
    make_and_lookup(tree, "127.12.0.0/16");
    make_and_lookup(tree, "127.13.0.0/16");
    make_and_lookup(tree, "127.14.0.0/16");
    make_and_lookup(tree, "127.15.0.0/16");
    make_and_lookup(tree, "127.16.0.0/16");
    make_and_lookup(tree, "127.17.0.0/16");
    make_and_lookup(tree, "127.18.0.0/16");
    make_and_lookup(tree, "127.19.0.0/16");
    make_and_lookup(tree, "127.20.0.0/16");
#endif

    try_search_best(tree, "127.0.0.1");
    try_search_best(tree, "127.0.0.0");
    try_search_best(tree, "10.0.0.1");

    make_and_lookup(tree, "10.42.42.0/24");
    make_and_lookup(tree, "10.42.69.0/24");
    make_and_lookup(tree, "10.0.0.0/8");
    make_and_lookup(tree, "10.0.0.0/9");

    try_search_best(tree, "10.42.42.0/24");
    try_search_best(tree, "10.10.10.10");
    try_search_best(tree, "10.10.10.1");
    try_search_exact(tree, "10.0.0.0");
    try_search_exact(tree, "10.0.0.0/8");

#if 0
    PATRICIA_WALK(tree->head, node) {
       printf("node: %s/%d\n", 
              prefix_toa(node->prefix), node->prefix->bitlen);
    } PATRICIA_WALK_END;
#else
    printf("%u total nodes.\n", patricia_walk_inorder(tree->head, func));
//Bala
//    printf("%u total nodes.\n", tree->num_active_node);
#endif

    lookup_then_remove(tree, "42.0.0.0/8");
    lookup_then_remove(tree, "10.0.0.0/8");
    try_search_exact(tree, "10.0.0.0");
    try_search_best(tree, "10.0.0.0");
    try_search_best(tree, "127.0.0.0");

#if 0
    PATRICIA_WALK(tree->head, node) {
       printf("node: %s/%d\n", 
              prefix_toa(node->prefix), node->prefix->bitlen);
    } PATRICIA_WALK_END;
#else
    printf("%u total nodes.\n", patricia_walk_inorder(tree->head, func));
//Bala
//   printf("%u total nodes.\n", tree->num_active_node);
#endif

    make_and_lookup(tree, "225.0.0.0/8");
    make_and_lookup(tree, "225.0.0.0/9");
#if 1
    printf("%u total nodes.\n", patricia_walk_inorder(tree->head, func));
//Bala
//    printf("%u total nodes.\n", tree->num_active_node);
#endif

    try_search_best(tree, "225.0.0.0");
    lookup_then_remove(tree, "225.0.0.0/9");
    try_search_exact(tree, "225.0.0.0/9");
    try_search_best(tree, "225.0.0.0");
    try_search_best(tree, "225.0.0.0/9");
    lookup_then_remove(tree, "225.0.0.0/8");
    try_search_best(tree, "225.0.0.0/9");
    try_search_best(tree, "225.0.0.0");
#ifdef BALA1
    printf("Before add/remove %u total nodes.\n", patricia_walk_inorder(tree->head, func));
    printf("%u total nodes.\n", tree->num_active_node);

	add_route ("225.0.0.0/8", NULL);
    try_search_best(tree, "225.0.0.0/8");
	remove_route ("225.0.0.0/8", NULL);
    try_search_best(tree, "225.0.0.0/8");
#endif 

#if 1
    printf("%u total nodes.\n", patricia_walk_inorder(tree->head, func));
//Bala
//    printf("%u total nodes.\n", tree->num_active_node);
#endif

#if BALA2
	update_prefix_aggregate(prefix_list,supernet); 
	
#endif

    Destroy_Patricia(tree, (void *)0);

    exit(0);
}


#ifdef BALA1
int add_route (char *prefix, char *nh)
{
	// check for NULL
	// NH is auto populated for now
    printf("%s prefix: %s\n", __func__, prefix);
	if (prefix)
    	make_and_lookup(tree, prefix);
	else
    	printf("%s invalid prefix",__func__);

	return 1;
}

int remove_route (char *prefix, char *nh)
{
	// check for NULL
	// NH is auto populated for now and hence auto removed.
    printf("%s prefix: %s\n", __func__, prefix);
	if (prefix)
    	lookup_then_remove(tree, prefix);
	else
    	printf("%s invalid prefix",__func__);

	return 1;
}
#endif

#ifdef BALA3
//store with prefix len
char *track_prefix_db[5] = {'\0'};
static unsigned int track_prefix_count = 0;

int init_track_prefix_db();
int register_prefix(char *prefix, char *func_ptr);
int unregister_prefix(char *prefix);
int exist_track_prefix_db(char *prefix);

int init_track_prefix_db()
{
	// free db atexit
	int i =0 ; 

	track_prefix_db = calloc(5, (sizeof(char)*20));
	
	if (!track_prefix_db)
		// error
		return 0;

	// ok
	return 1; 
}

int register_prefix(char *prefix, char *func_ptr)
{
	// if more than 5 entries, cant add prefix
	// else add it for tracking
	if ((prefix) && (track_prefix_count < 5)) {
		
		strcpy(track_prefix_db[track_prefix_count], prefix); 
	}

}

int exist_track_prefix_db(char *prefix)
{
	int i = 0;

	for (; i < 5; i++) {
	if (!strcmp(track_prefix_db[i]), prefix)
		return 1;	
	}
	return 0;
}


void update_prefix(char *aggregate, char *supernet)
{
	int i = 0;

	for (; i<5; i++) {
    lookup_then_remove(tree, aggregate[i]);
	if (exist_track_prefix_db(aggregate[i]))
		printf("call_back_fn \n");	
	}

    make_and_lookup(tree, supernet);

	/*	
	<ip prefix array>
	<extract one and call remove>
	<callback for remove>
	
	<install supernet>
	*/

	return;
}

#endif

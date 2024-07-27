#include <stdio.h>
#include "graphs.h"

int main(int argc, char const *argv[])
{	
	int visited[MAXV];
	int E = 17;	
	int V = 13;
	get_adjList(E,V);
	print_list();
	list_dfs(visited);
	return 0;
}	
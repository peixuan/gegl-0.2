#include <glib-object.h>
#include "gegl.h"
#include "gegl-mock-node.h"
#include "gegl-mock-bfs-visitor.h"
#include "ctest.h"
#include "csuite.h"
#include "testutils.h"
#include <string.h>

static GeglNode *A,*B,*C,*D,*E,*F,*G;
static GeglNode *H,*I,*J,*K,*L,*M,*N;
static GeglNode *O,*P,*Q,*R,*S;

static void
test_bfs_visitor_g_object_new(Test *test)
{
  {
    GeglMockBfsVisitor * mock_bfs_visitor = g_object_new (GEGL_TYPE_MOCK_BFS_VISITOR, NULL);  

    ct_test(test, mock_bfs_visitor != NULL);
    ct_test(test, GEGL_IS_MOCK_BFS_VISITOR(mock_bfs_visitor));
    ct_test(test, g_type_parent(GEGL_TYPE_MOCK_BFS_VISITOR) == GEGL_TYPE_BFS_VISITOR);
    ct_test(test, !strcmp("GeglMockBfsVisitor", g_type_name(GEGL_TYPE_MOCK_BFS_VISITOR)));

    g_object_unref(mock_bfs_visitor);
  }
}

/**
  From node_setup: 

         E 
        / \ 
       D   F 
      /\    \ 
     B  C    G 
     | /
     A 

**/
static void
test_bfs_visitor_traverse(Test *test)
{
  {
    gint i;
    gchar * visit_names [] = { "E", "D", "F", "B", "C", "G", "A" };  
    GeglMockBfsVisitor *mock_bfs_visitor = g_object_new(GEGL_TYPE_MOCK_BFS_VISITOR, NULL);  
    GList * visits_list;

    gegl_bfs_visitor_traverse (GEGL_BFS_VISITOR(mock_bfs_visitor), E); 
    visits_list = gegl_visitor_get_visits_list(GEGL_VISITOR(mock_bfs_visitor));

    for(i = 0; i < g_list_length(visits_list); i++)
      {
        gchar *name = (gchar*)g_list_nth_data(visits_list, i);
        ct_test (test, 0 == strcmp(name, visit_names[i]));
      }

    g_object_unref(mock_bfs_visitor);
  }

  {
    gint i;
    gchar * visit_names[] = { "D", "B", "C", "A" };  
    GeglMockBfsVisitor *mock_bfs_visitor = g_object_new(GEGL_TYPE_MOCK_BFS_VISITOR, NULL);  
    GList * visits_list;

    gegl_bfs_visitor_traverse (GEGL_BFS_VISITOR(mock_bfs_visitor), D); 
    visits_list = gegl_visitor_get_visits_list(GEGL_VISITOR(mock_bfs_visitor));

    for(i = 0; i < g_list_length(visits_list); i++)
      {
        gchar *name = (gchar*)g_list_nth_data(visits_list, i);
        ct_test (test, 0 == strcmp(name, visit_names[i]));
      }

    g_object_unref(mock_bfs_visitor);
  }
}

/**
    O 
    |\
    | P 
    | |
    | Q 
    |/ 
    R 
    |
    S 

**/
static void
test_bfs_visitor_traverse_diamond(Test *test)
{
  {
    gint i;
    gchar * visit_names [] = {"O", "P", "Q", "R", "S"};  
    GeglMockBfsVisitor *mock_bfs_visitor = g_object_new(GEGL_TYPE_MOCK_BFS_VISITOR, NULL);  
    GList * visits_list;

    gegl_bfs_visitor_traverse (GEGL_BFS_VISITOR(mock_bfs_visitor), O); 
    visits_list = gegl_visitor_get_visits_list(GEGL_VISITOR(mock_bfs_visitor));

    for(i = 0; i < g_list_length(visits_list); i++)
      {
        gchar *name = (gchar*)g_list_nth_data(visits_list, i);
        ct_test (test, 0 == strcmp(name, visit_names[i]));
      }

    g_object_unref(mock_bfs_visitor);
  }
}

/**

  From setup: 
                   M     
                 /   \
                /     \ 
           ---------   N 
   graph L |   K   |    
           |  / \  |     
           | I   J |
           | |     |
           |null   | 
           ---------
               |
               H 

**/
static void
test_bfs_visitor_traverse_graph(Test *test)
{
  {
    gchar *name;
    gint i;
    gint length;
    gchar * visit_names[] = {"M", "L", "K", "I", "J", "N", "H"};  
    GeglMockBfsVisitor *mock_bfs_visitor = g_object_new(GEGL_TYPE_MOCK_BFS_VISITOR, NULL);  
    GList * visits_list;

    gegl_bfs_visitor_traverse(GEGL_BFS_VISITOR(mock_bfs_visitor), M); 
    visits_list = gegl_visitor_get_visits_list(GEGL_VISITOR(mock_bfs_visitor));

    length = g_list_length(visits_list);
    for(i = 0; i < g_list_length(visits_list); i++)
      {
        name = (gchar*)g_list_nth_data(visits_list, i);
        ct_test (test, 0 == strcmp(name, visit_names[i]));
      }

    g_object_unref(mock_bfs_visitor);
  }
}

static void
bfs_visitor_setup(Test *test)
{

  /*
         E 
        / \ 
       D   F 
      /\    \ 
     B  C    G 
     | /
     A 

  */

  {
    A = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "A", 
                      "num_outputs", 1, 
                      NULL);  
    B = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "B", 
                      "num_inputs", 1,
                      "num_outputs", 1, 
                      NULL);  
    C = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "C", 
                      "num_inputs", 1,
                      "num_outputs", 1, 
                      NULL);  
    D = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "D", 
                      "num_inputs", 2,
                      "num_outputs", 1, 
                      NULL);  
    E = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "E", 
                      "num_inputs", 2, 
                      NULL);  
    F = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "F", 
                      "num_inputs", 1,
                      "num_outputs", 1, 
                      NULL);  
    G = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "G", 
                      "num_outputs", 1, 
                      NULL);  


    gegl_node_set_nth_input(B, A, 0);
    gegl_node_set_nth_input(C, A, 0);
    gegl_node_set_nth_input(D, B, 0);
    gegl_node_set_nth_input(D, C, 1);
    gegl_node_set_nth_input(E, D, 0);
    gegl_node_set_nth_input(E, F, 1);
    gegl_node_set_nth_input(F, G, 0);

  }

  /*
                   M     
                 /   \
                /     \ 
           ---------   N 
   graph L |   K   |    
           |  / \  |     
           | I   J |
           | |     |
           |null   | 
           ---------
               |
               H 

  */

  {
    H = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "H", 
                      "num_outputs", 1, 
                      NULL);  
    I = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "I", 
                      "num_inputs", 1,
                      "num_outputs", 1, 
                      NULL);  
    J = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "J", 
                      "num_outputs", 1, 
                      NULL);  
    K = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "K", 
                      "num_inputs", 2,
                      "num_outputs", 1, 
                      NULL);  
    M = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "M", 
                      "num_inputs", 2, 
                      NULL);  
    N = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "N", 
                      "num_outputs", 1, 
                      NULL);  

    gegl_node_set_nth_input(K, I, 0);
    gegl_node_set_nth_input(K, J, 1);
    L = g_object_new (GEGL_TYPE_GRAPH, 
                      "name", "L", 
                      "root", K, 
                      NULL);  

    gegl_node_set_nth_input(L, H, 0);
    gegl_node_set_nth_input(M, L, 0);
    gegl_node_set_nth_input(M, N, 1);
  }

/**
    O 
    |\
    | P 
    | |
    | Q 
    |/ 
    R 
    |
    S 

**/
  {
    O = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "O", 
                      "num_inputs", 2, 
                      NULL);  

    P = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "P", 
                      "num_inputs", 1, 
                      "num_outputs", 1, 
                      NULL);  

    Q = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "Q", 
                      "num_inputs", 1, 
                      "num_outputs", 1, 
                      NULL);  

    R = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "R", 
                      "num_inputs", 1, 
                      "num_outputs", 1, 
                      NULL);  

    S = g_object_new (GEGL_TYPE_MOCK_NODE, 
                      "name", "S", 
                      "num_outputs", 1, 
                      NULL);  

    gegl_node_set_nth_input(O, R, 0);
    gegl_node_set_nth_input(O, P, 1);

    gegl_node_set_nth_input(P, Q, 0);
    gegl_node_set_nth_input(Q, R, 0);
    gegl_node_set_nth_input(R, S, 0);
  }
}

static void
bfs_visitor_teardown(Test *test)
{
  g_object_unref(A);
  g_object_unref(B);
  g_object_unref(C);
  g_object_unref(D);
  g_object_unref(E);
  g_object_unref(F);
  g_object_unref(G);
  g_object_unref(H);
  g_object_unref(I);
  g_object_unref(J);
  g_object_unref(K);
  g_object_unref(L);
  g_object_unref(M);
  g_object_unref(N);
  g_object_unref(O);
  g_object_unref(P);
  g_object_unref(Q);
  g_object_unref(R);
  g_object_unref(S);
}

Test *
create_bfs_visitor_test()
{
  Test *t = ct_create("GeglBfsVisitorTest");

  g_assert(ct_addSetUp(t, bfs_visitor_setup));
  g_assert(ct_addTearDown(t, bfs_visitor_teardown));

#if 1 
  g_assert(ct_addTestFun(t, test_bfs_visitor_g_object_new));
  g_assert(ct_addTestFun(t, test_bfs_visitor_traverse));
  g_assert(ct_addTestFun(t, test_bfs_visitor_traverse_diamond));
  g_assert(ct_addTestFun(t, test_bfs_visitor_traverse_graph));
#endif

  return t;
}

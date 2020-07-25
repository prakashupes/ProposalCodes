
#include <iostream>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dominator_tree.hpp>

using namespace std;


using namespace boost;

typedef adjacency_list<
    listS,
    listS,
    bidirectionalS,
    property<vertex_index_t, std::size_t>, no_property> G;

int main(int, char*[])
{
 

  // Tarjan's paper
  typedef pair<int, int> edge;

  int numOfVertices;
  vector<edge> edges;

  numOfVertices = 17;  
  edges.push_back(edge(0, 1));
  edges.push_back(edge(1, 4));
  edges.push_back(edge(2, 5));
  edges.push_back(edge(3, 8));
  edges.push_back(edge(4, 5));
  edges.push_back(edge(4, 9));
  edges.push_back(edge(5, 10));
  edges.push_back(edge(5, 8));
  edges.push_back(edge(6, 7));
  edges.push_back(edge(7, 4));
  edges.push_back(edge(8, 11));
  edges.push_back(edge(9, 14));
  edges.push_back(edge(9, 10));
  edges.push_back(edge(10, 11));
  edges.push_back(edge(13, 14));
  //edges.push_back(edge(14, 12));
  edges.push_back(edge(15, 16));
  /*
 numOfVertices = 8;  
  edges.push_back(edge(0, 1));  
  edges.push_back(edge(1, 2));  
  edges.push_back(edge(1, 3)); 
  edges.push_back(edge(2, 7));  
  edges.push_back(edge(3, 4));  
  edges.push_back(edge(4, 5));
  edges.push_back(edge(4, 6));
  edges.push_back(edge(6, 4));
  edges.push_back(edge(5, 7));         

  */


  
    //const int numOfVertices = numOfVertices;

    G g(edges.begin(),edges.end(),numOfVertices);

    typedef graph_traits<G>::vertex_descriptor Vertex;
   
    vector<Vertex> domTreePredVector, domTreePredVector2;
    auto indexMap(get(vertex_index, g));
    graph_traits<G>::vertex_iterator uItr, uEnd;
    int j = 0;
    for (boost::tie(uItr, uEnd) = vertices(g); uItr != uEnd; ++uItr, ++j)
    {
      put(indexMap, *uItr, j); //instead of j try to put graph[*v].id
    }

    // Lengauer-Tarjan dominator tree algorithm
    
    domTreePredVector =
      vector<Vertex>(num_vertices(g));
    auto domTreePredMap =
      make_iterator_property_map(domTreePredVector.begin(), indexMap);

    lengauer_tarjan_dominator_tree(g, vertex(1, g), domTreePredMap);

    vector<int> idom(num_vertices(g));
    for (boost::tie(uItr, uEnd) = vertices(g); uItr != uEnd; ++uItr)
    {
      if (get(domTreePredMap, *uItr) != graph_traits<G>::null_vertex())
        idom[get(indexMap, *uItr)] =
          get(indexMap, get(domTreePredMap, *uItr));
      else
        idom[get(indexMap, *uItr)] = (numeric_limits<int>::max)();
    }

    ///
    int x=0;
    for(int i: idom)
    {
    	if(i!=(numeric_limits<int>::max)())
    	  cout<<"idom of "<<x+1<<"  is "<<i+1<<endl;
    	else
    	cout<<"idom of "<<x+1<<"  is "<<0<<endl;
    	 x++;
    }
   // copy(idom.begin(), idom.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // dominator tree correctness test
    


  

  return 0;
}

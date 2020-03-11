#include <boost/test/minimal.hpp>
#include <iostream>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dominator_tree.hpp>

using namespace std;

struct DominatorCorrectnessTestSet
{
  typedef pair<int, int> edge;

  int numOfVertices;
  vector<edge> edges;
  vector<int> correctIdoms;
};

using namespace boost;

typedef adjacency_list<
    listS,
    listS,
    bidirectionalS,
    property<vertex_index_t, std::size_t>, no_property> G;

int test_main(int, char*[])
{
  typedef DominatorCorrectnessTestSet::edge edge;

  DominatorCorrectnessTestSet testSet[1];

  // Tarjan's paper
  testSet[0].numOfVertices = 13;
  testSet[0].edges.push_back(edge(0, 1));
  testSet[0].edges.push_back(edge(0, 2));
  testSet[0].edges.push_back(edge(0, 3));
  testSet[0].edges.push_back(edge(1, 4));
  testSet[0].edges.push_back(edge(2, 1));
  testSet[0].edges.push_back(edge(2, 4));
  testSet[0].edges.push_back(edge(2, 5));
  testSet[0].edges.push_back(edge(3, 6));
  testSet[0].edges.push_back(edge(3, 7));
  testSet[0].edges.push_back(edge(4, 12));
  testSet[0].edges.push_back(edge(5, 8));
  testSet[0].edges.push_back(edge(6, 9));
  testSet[0].edges.push_back(edge(7, 9));
  testSet[0].edges.push_back(edge(7, 10));
  testSet[0].edges.push_back(edge(8, 5));
  testSet[0].edges.push_back(edge(8, 11));
  testSet[0].edges.push_back(edge(9, 11));
  testSet[0].edges.push_back(edge(10, 9));
  testSet[0].edges.push_back(edge(11, 0));
  testSet[0].edges.push_back(edge(11, 9));
  testSet[0].edges.push_back(edge(12, 8));
  testSet[0].correctIdoms.push_back((numeric_limits<int>::max)());
  testSet[0].correctIdoms.push_back(0); // correctIdoms.push_back(0); represents that 0 is the idom of vertex 0
  testSet[0].correctIdoms.push_back(0); //// correctIdoms.push_back(0); represents that 0 is the idom of 1
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(3); // correctIdoms.push_back(0); represents that 3 is the idom of 5
  testSet[0].correctIdoms.push_back(3);
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(7);
  testSet[0].correctIdoms.push_back(0);
  testSet[0].correctIdoms.push_back(4);




  for (size_t i = 0; i < sizeof(testSet)/sizeof(testSet[0]); ++i)
  {
    const int numOfVertices = testSet[i].numOfVertices;

    G g(
      testSet[i].edges.begin(), testSet[i].edges.end(),
      numOfVertices);

    typedef graph_traits<G>::vertex_descriptor Vertex;
    typedef property_map<G, vertex_index_t>::type IndexMap;
    typedef
      iterator_property_map<vector<Vertex>::iterator, IndexMap>
      PredMap;

    vector<Vertex> domTreePredVector, domTreePredVector2;
    IndexMap indexMap(get(vertex_index, g));
    graph_traits<G>::vertex_iterator uItr, uEnd;
    int j = 0;
    for (boost::tie(uItr, uEnd) = vertices(g); uItr != uEnd; ++uItr, ++j)
    {
      put(indexMap, *uItr, j);
    }

    // Lengauer-Tarjan dominator tree algorithm
    
    domTreePredVector =
      vector<Vertex>(num_vertices(g), graph_traits<G>::null_vertex());
    PredMap domTreePredMap =
      make_iterator_property_map(domTreePredVector.begin(), indexMap);

    lengauer_tarjan_dominator_tree(g, vertex(0, g), domTreePredMap);

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
    	cout<<"idom of "<<x<<"  is "<<i<<endl;
    	x++;
    }
   // copy(idom.begin(), idom.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // dominator tree correctness test
    cout<<"Checking from previus assumptions: "<<endl;
    BOOST_CHECK(std::equal(idom.begin(), idom.end(), testSet[i].correctIdoms.begin()));


  }

  return 0;
}

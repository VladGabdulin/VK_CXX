#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

std::vector<int> bfs(const std::vector<std::vector<int>>& graph, int main_vertex) {
    std::vector<int> distances(graph.size(), -1);
    distances[main_vertex] = 0;

    std::queue<int> vertex_queue;
    vertex_queue.push(main_vertex);

    while (!vertex_queue.empty()) {
        int current_vertex = vertex_queue.front();
        vertex_queue.pop();

        for (int neighbor : graph[current_vertex]) {
            if (distances[neighbor] == -1) { 
                distances[neighbor] = distances[current_vertex] + 1;
                vertex_queue.push(neighbor);
            }
        }
    }

    return distances;
}

int main() {
    int vertex_count;
    int edge_count;

    std::ifstream input_file("graph.txt");
    input_file >> vertex_count >> edge_count;

    std::vector<std::vector<int>> adjacency_list(vertex_count);
    for (int i = 0; i < edge_count; ++i) {
        int vertex_left, vertex_right;
        input_file >> vertex_left >> vertex_right;
        adjacency_list[vertex_left].push_back(vertex_right);
        adjacency_list[vertex_right].push_back(vertex_left);
    }

    int main_vertex;
    input_file >> main_vertex;

    input_file.close();
    
    std::vector<int> distances = bfs(adjacency_list, main_vertex);

    for (int distance : distances) {
        std::cout << distance << std::endl;
    }

    return 0;
}

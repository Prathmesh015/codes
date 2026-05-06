#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
    int g, h, f;
    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr) {
        this->x = x;
        this->y = y;
        this->g = g;
        this->h = h;
        this->f = g + h;
        this->parent = parent;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int rows, int cols, vector<vector<int>>& maze) {
    return x >= 0 && y >= 0 && x < rows && y < cols && maze[x][y] == 0;
}

void printPath(Node* goal) {
    vector<pair<int, int>> path;
    while (goal != nullptr) {
        path.push_back({goal->x, goal->y});
        goal = goal->parent;
    }

    reverse(path.begin(), path.end());

    cout << "Path found:\n";
    for (auto p : path) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

void aStar(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> goal) {
    int rows = maze.size();
    int cols = maze[0].size();

    priority_queue<Node*, vector<Node*>, Compare> openList;
    vector<vector<bool>> closed(rows, vector<bool>(cols, false));

    Node* startNode = new Node(start.first, start.second, 0,
                               heuristic(start.first, start.second, goal.first, goal.second));

    openList.push(startNode);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        int x = current->x;
        int y = current->y;

        if (closed[x][y])
            continue;

        closed[x][y] = true;

        if (x == goal.first && y == goal.second) {
            printPath(current);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, rows, cols, maze) && !closed[nx][ny]) {
                int gNew = current->g + 1;
                int hNew = heuristic(nx, ny, goal.first, goal.second);

                Node* neighbor = new Node(nx, ny, gNew, hNew, current);
                openList.push(neighbor);
            }
        }
    }

    cout << "No path found\n";
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    aStar(maze, start, goal);

    return 0;
}
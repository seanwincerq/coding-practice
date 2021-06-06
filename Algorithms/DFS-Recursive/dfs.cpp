#include <iostream>

template <typename T>
class DFS
{
    struct node
    {
        int row;
        int col;
    };

public:
    DFS(const int size)
        : m_size(size),
          grid(new T *[size]),
          visited(new bool *[size])
    {
        for (int r = 0; r < m_size; ++r)
        {
            grid[r] = new T[m_size];
            visited[r] = new bool[m_size];
            for (int c = 0; c < m_size; ++c)
            {
                visited[r][c] = false;
                std::cin >> grid[r][c];

                if ('s' == grid[r][c])
                {
                    m_startNode = {r, c};
                }
            }
        }

        // Clockwise: UP, RIGHT, DOWN, LEFT
        directions[0] = {-1, 0};
        directions[1] = {0, 1};
        directions[2] = {1, 0};
        directions[3] = {0, -1};
    }

    ~DFS()
    {
        for (int r = 0; r < m_size; ++r)
        {
            delete[] grid[r];
        }
        delete grid;
    }

    bool dfs(node curr)
    {
        visited[curr.row][curr.col] = true;
        if ('e' == grid[curr.row][curr.col])
        {
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            const node newNode = {curr.row + directions[i].row, curr.col + directions[i].col};
            const int r = newNode.row;
            const int c = newNode.col;

            if (!isInBounds(r, c))
                continue;
            if ('w' == grid[r][c])
                continue;
            if (visited[r][c])
                continue;

            if (dfs(newNode))
            {
                if (m_startNode.row != curr.row || m_startNode.col != curr.col)
                    grid[curr.row][curr.col] = '+';
                return true;
            }
        }

        return false;
    }

    void solve()
    {
        dfs(m_startNode);
    }

    void show()
    {
        for (int r = 0; r < m_size; ++r)
        {
            for (int c = 0; c < m_size; ++c)
            {
                std::cout << grid[r][c] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    bool isInBounds(const int row, const int col)
    {
        const bool isRowOk = row >= 0 && row < m_size;
        const bool isColOk = col >= 0 && col < m_size;

        return isRowOk && isColOk;
    }

    T **grid;
    bool **visited;
    int m_size;
    node m_startNode;
    node directions[4];
};

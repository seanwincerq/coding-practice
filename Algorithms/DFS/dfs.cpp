
#include <iostream>
#include "sizedstack.cpp"

template <typename T>
class DFS
{
public:
    DFS(const int size)
        : m_size(size),
          grid(new T *[size])
    {
        for (int r = 0; r < m_size; ++r)
        {
            grid[r] = new T[m_size];
            for (int c = 0; c < m_size; ++c)
            {
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

    void solve()
    {
        SizedStack<node> stack = SizedStack<node>(m_size * m_size);
        bool visited[m_size][m_size]{};
        node prevNode[m_size][m_size]{};

        stack.push(m_startNode);

        while (!stack.empty())
        {
            node curr = stack.pop();
            visited[curr.row][curr.col] = true;

            if (grid[curr.row][curr.col] == 'e')
            {
                node trace = prevNode[curr.row][curr.col];
                while (trace.row != m_startNode.row || trace.col != m_startNode.col)
                {
                    grid[trace.row][trace.col] = '+';
                    trace = prevNode[trace.row][trace.col];
                }
                break;
            }

            for (int i = 3; i >= 0; --i)
            {
                const node nextNode = {curr.row + directions[i].row, curr.col + directions[i].col};
                const int r = nextNode.row;
                const int c = nextNode.col;

                if (r < 0 || r >= m_size || c < 0 || c >= m_size)
                {
                    continue;
                }

                if ('w' == grid[r][c])
                    continue;
                if (visited[r][c])
                    continue;

                stack.push(nextNode);
                prevNode[r][c] = curr;
            }
        }
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

    struct node
    {
        int row;
        int col;
    };

    T **grid;
    int m_size;
    node m_startNode;
    node directions[4];
};
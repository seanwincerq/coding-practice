#include <iostream>

class NQueens
{
public:
    NQueens(const int size)
        : m_size(size), successCount(0)
    {
        grid = new char *[m_size];
        for (int r = 0; r < m_size; ++r)
        {
            grid[r] = new char[m_size];
            for (int c = 0; c < m_size; ++c)
            {
                grid[r][c] = '.';
            }
        }
    }

    ~NQueens()
    {
        for (int r = 0; r < m_size; ++r)
        {
            delete[] grid[r];
        }
        delete grid;
    }

    bool solveNQueen(const int col)
    {
        if (col == m_size)
        {
            printf("Result #%d \n", ++successCount);
            show();
            printf("----------\n");
            return true;
        }

        bool res = false;

        for (int r = 0; r < m_size; ++r)
        {
            if (isOk(r, col))
            {
                grid[r][col] = 'Q';
                res = solveNQueen(col + 1);
                grid[r][col] = '.';
            }
        }

        return res;
    }

    void solve()
    {
        solveNQueen(0);
    }

    void show()
    {
        for (int r = 0; r < m_size; ++r)
        {
            for (int c = 0; c < m_size; ++c)
            {
                printf("%c ", grid[r][c]);
            }
            printf("\n");
        }
    }

private:
    bool isOk(const int row, const int col)
    {
        // Check row
        for (int c = 0; c < col; ++c)
        {
            if (grid[row][c] == 'Q')
                return false;
        }

        // Check up diag to the left
        for (int r = row, c = col; r >= 0 && c >= 0; --r, --c)
        {
            if (grid[r][c] == 'Q')
                return false;
        }

        // Check down diag to the left
        for (int r = row, c = col; r < m_size && c >= 0; ++r, --c)
        {
            if (grid[r][c] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    char **grid;
    const int m_size;
    int successCount;
};

int main()
{
    auto n = NQueens(4);
    n.solve();
}
#include <iostream>

class Sudoku
{
public:
    Sudoku(const int size)
        : m_size(size)
        , m_sqrtSize(sqrt(size))
    {
        grid = new int*[m_size];
        for (int r = 0; r < m_size; ++r)
        {
            grid[r] = new int[m_size];
            for (int c = 0; c < m_size; ++c)
            {
                std::cin >> grid[r][c];
            }
        }

        boxesArea = new box[size];
        int boxIndex = 0;

        // Initialize Box Area
        for (int r = 0, rowStartIndex = 0; r < m_sqrtSize; ++r, rowStartIndex += m_sqrtSize)
        {
            for (int c = 0, colStartIndex = 0; c < m_sqrtSize; ++c, colStartIndex += m_sqrtSize)
            {
                boxesArea[boxIndex].row = {rowStartIndex, rowStartIndex+m_sqrtSize-1};
                boxesArea[boxIndex].col = {colStartIndex, colStartIndex+m_sqrtSize-1};
                boxIndex++;
            }
        }

    }

    ~Sudoku()
    {
        for (int r = 0; r < m_size; ++r)
        {
            delete[] grid[r];
        }
        delete grid;
        delete[] boxesArea;
    }

    bool solve(const int rowIndex, const int colIndex)
    {
        if (rowIndex >= m_size) return true;
        if (colIndex >= m_size) return solve(rowIndex + 1, 0);
        if (grid[rowIndex][colIndex] != 0)
        {
            return solve(rowIndex, colIndex + 1);
        }

        for (int i = 1; i <= m_size; ++i)
        {
            grid[rowIndex][colIndex] = i;

            const bool isBoxOk = isUniqueInArea(i, rowIndex, colIndex);
            const bool isColOk = isUniqueInCol(i, rowIndex, colIndex);
            const bool isRowOk = isUniqueInRow(i, rowIndex, colIndex);
            bool isUnique = isBoxOk && isColOk && isRowOk;

            if (isUnique)
            {
                bool isValid = solve(rowIndex, colIndex + 1);
                if (isValid) return true;
            }

            grid[rowIndex][colIndex] = 0;
        }

        return false;
    }

    void show()
    {
        for (int r = 0; r < m_size; ++r)
        {
            for (int c = 0; c < m_size; ++c)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }
    }

    

private:
    bool isUniqueInArea(const int num, const int row, const int col)
    {
        int found = 0;
        const box boxArea = boxesArea[getBoxAreaIndex(row, col)];

        for (int r = boxArea.row.from; r <= boxArea.row.to; ++r)
        {
            for (int c = boxArea.col.from; c <= boxArea.col.to; ++c)
            {
                if (grid[r][c] == num) found++;
                if (found > 1) return false;
            }
        }

        return found == 1;
    }

    bool isUniqueInRow(const int num, const int row, const int col)
    {
        int found = 0;
        for (int r = 0; r < m_size; ++r)
        {
            if (grid[r][col] == num) found++;
            if (found > 1) return false;
        }

        return found == 1;
    }

    bool isUniqueInCol(const int num, const int row, const int col)
    {
        int found = 0;
        for (int c = 0; c < m_size; ++c)
        {
            if (grid[row][c] == num) found++;
            if (found > 1) return false;
        }

        return found == 1;
    }


    struct range
    {
        int from;
        int to;
    };

    struct box
    {
        range row;
        range col;

        void show()
        {
            printf("row: %d -> %d\n", row.from, row.to);
            printf("col: %d -> %d\n", col.from, col.to);
        }
    };

    int getBoxAreaIndex(const int row, const int col)
    {
        const int boxRowIndex = row / m_sqrtSize;
        const int boxColIndex = col / m_sqrtSize;
        return boxRowIndex * m_sqrtSize + boxColIndex; 
    }

    int getSqrt()
    {
        return m_sqrtSize;
    }

    int sqrt(const int num)
    {
        for (int i = 1; i*i <= num; ++i)
        {
            if (i*i == num) return i;
        }

        return -1;
    }

    int** grid;
    const int m_size;
    const int m_sqrtSize;
    box* boxesArea;
    
};


int main()
{
    int size;
    std::cin >> size;
    auto s = Sudoku(size);
    s.solve(0, 0);
    s.show();
}
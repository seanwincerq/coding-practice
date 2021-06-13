#include <iostream>

constexpr int maxWeight = 7;
constexpr int maxItems = 6;
const int items[maxItems] = {3, 3, 2, 2, 2, 2};
int basket[] = {0, 0};
int pos[maxItems] = {-1, -1, -1, -1, -1, -1};

bool solve(const int index)
{
    if (index == maxItems)
        return true;

    for (int i = 0; i < 2; ++i)
    {
        basket[i] += items[index];
        pos[index] = i + 1;

        if (basket[i] <= maxWeight)
        {
            if (solve(index + 1))
            {
                return true;
            }
        }

        basket[i] -= items[index];
        pos[index] = -1;
    }

    return false;
}

int main()
{
    solve(0);

    for (const auto &p : pos)
    {
        printf("%d ", p);
    }
    printf("\n");
}
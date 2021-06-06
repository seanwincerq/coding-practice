#include <iostream>
#include "dfs.cpp"

int main()
{
    int size;
    std::cin >> size;
    auto d = DFS<char>(size);
    d.solve();
    d.show();
}

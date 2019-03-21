#include <bits/stdc++.h>

std::unordered_map<char, char> opening_chars = {{'}','{'},{']','['},{')','('}};

// Complete the isBalanced function below.
std::string isBalanced(std::string s)
{
    std::vector<char> stack{};
    for (auto const &c : s)
    {
        if (!stack.empty())
        {
            auto back_char = stack.back();
            const auto closing_char = opening_chars[c];
            if (back_char == closing_char)
            {
                stack.pop_back();
                continue;
            }
        }
        stack.push_back(c);
    }
    if (!stack.empty())
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    std::ifstream in;

    in = std::ifstream{"../input.txt"};
    std::cin.rdbuf(in.rdbuf());

    std::ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        std::string s;
        getline(std::cin, s);

        std::string result = isBalanced(s);

        fout << result << "\n";
        std::cout << result << "\n";
    }

    fout.close();

    return 0;
}

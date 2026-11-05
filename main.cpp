#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <cassert>
#include <cctype>
#include <stdexcept>

class BigNumber
{
    private:
    std::string number;
    std::stack<std::pair<int, char>> history; // Save index and deleted digit

    public:
    BigNumber(const std::string& num) : number(num) {
        if (num.empty()) throw std::invalid_argument("Number must contain digits.");
        for (unsigned char c : num) if (!std::isdigit(c)) throw std::invalid_argument("Number must contain digits only.");
    }
    const std::string& value() const { return number; }

    void print() const {
        std::cout << "Current Number: " << number << std::endl;
    }

void deleteAt(int index)
{
    if (index < 0 || static_cast<std::size_t>(index) >= number.size())
    {
        std::cerr << "Index out of range.\n";
        return;
    }

    char deleted = number[index];
    history.push({ index, deleted});
    number.erase(number.begin() + index);
    std::cout << "Deleted '" << deleted << "' at position " << index << std::endl;
}

void restoreLastDelete()
{
    if (history.empty())
    {
        std::cerr << "Nothing to restore.\n";
        return;
    }

    auto[index, ch] = history.top();
    history.pop();
    number.insert(number.begin() + index, ch);
    std::cout << "Restored '" << ch << "' at position " << index << std::endl;
}
};

int main()
{
    BigNumber bn("9876543210123456789");  // Example big number

    bn.print();

    bn.deleteAt(5);
    bn.print();

    bn.deleteAt(10);
    bn.print();

    bn.restoreLastDelete();
    bn.print();

    bn.restoreLastDelete();
    bn.print();

    assert(bn.value() == "9876543210123456789");
    BigNumber test("001234");
    test.deleteAt(0); assert(test.value() == "01234");
    test.deleteAt(4); assert(test.value() == "0123");
    test.restoreLastDelete(); test.restoreLastDelete();
    assert(test.value() == "001234");
    test.restoreLastDelete(); assert(test.value() == "001234");
    test.deleteAt(-1); test.deleteAt(99); assert(test.value() == "001234");
    BigNumber single("0"); single.deleteAt(0); assert(single.value().empty());
    single.restoreLastDelete(); assert(single.value() == "0");
    bool invalid = false;
    try { BigNumber bad("12x"); } catch (const std::invalid_argument&) { invalid = true; }
    assert(invalid);
    std::cout << "All self-checks passed.\n";
    return 0;
}

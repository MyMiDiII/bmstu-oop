#ifndef LINK_H
#define LINK_H

#include <cstddef>

class Link
{
public:
    Link() = default;
    Link(const std::size_t &dot1_index, const std::size_t &dot2_index);
    Link(const Link &_link) = default;

    ~Link() = default;

    // Getter & setter
    std::size_t get_dot1_index() const;
    std::size_t get_dot2_index() const;

    void set_dot1_index(const std::size_t &first_dot_index);
    void set_dot2_index(const std::size_t &second_dot_index);

private:
    std::size_t _dot1_index;
    std::size_t _dot2_index;
};












#endif //LINK_H

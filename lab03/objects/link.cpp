#include "link.h"


Link::Link(const std::size_t &dot1, const std::size_t &dot2)
{
    set_dot1_index(dot1);
    set_dot2_index(dot2);
}

std::size_t Link::get_dot1_index() const {
    return _dot1_index;
}

std::size_t Link::get_dot2_index() const {
    return _dot2_index;
}

void Link::set_dot1_index(const size_t &first_dot_index)
{
    _dot1_index = first_dot_index;
}

void Link::set_dot2_index(const size_t &second_dot_index)
{
    _dot2_index = second_dot_index;
}

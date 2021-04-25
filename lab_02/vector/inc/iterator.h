#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

template <typename Type>
class Iterator : public std::iterator<std::random_access_iterator_tag, Type>
{
public:
    Iterator();

private:
    std::weak_ptr<Type[]> ptr;
};

#endif // ITERATOR_H

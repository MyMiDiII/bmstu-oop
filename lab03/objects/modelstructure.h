#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include <vector>

#include "vertex.h"
#include "link.h"

class ModelStructure
{
public:
    ModelStructure() = default;
    ModelStructure(std::vector<Dot> &dots, std::vector<Link> &links);
    ModelStructure(std::vector<Dot> &dots, std::vector<Link> &links, Dot center);

    ~ModelStructure() = default;

    const std::vector<Dot> &get_dots() const;
    const std::vector<Link> &get_links() const;
    const Dot &get_center() const;

    void add_dot(const Dot &dot);
    void add_link(const Link &link);

    void transform(const Dot &move, const Dot &scale, const Dot &spin);

private:
    Dot _center;

    std::vector<Dot> _dots;
    std::vector<Link> _links;
};


#endif //MODELSTRUCTURE_H

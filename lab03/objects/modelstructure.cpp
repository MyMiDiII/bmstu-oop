#include "modelstructure.h"

#include <utility>

ModelStructure::ModelStructure(std::vector<Dot> &dots, std::vector<Link> &links) : _center{}, _dots(dots), _links(links) {}


ModelStructure::ModelStructure(std::vector<Dot> &dots, std::vector<Link> &links, Dot center): _center(center), _dots(dots), _links(links) {}

const std::vector<Dot> &ModelStructure::get_dots() const
{
//    std::cout << "Sizing = " << _dots.size() << std::endl;
    return _dots;
}


const std::vector<Link> &ModelStructure::get_links() const
{
    return _links;
}


const Dot &ModelStructure::get_center() const
{
    return _center;
}

void ModelStructure::add_dot(const Dot &dot)
{
    _dots.push_back(dot);
}


void ModelStructure::add_link(const Link &link)
{
    _links.push_back(link);
}

void ModelStructure::transform(const Dot &move, const Dot &scale, const Dot &spin)
{
    _center.move(move.get_x(), move.get_y(), move.get_z());

    for (auto &dot : _dots)
    {
        dot.scale(scale.get_x(), scale.get_y(), scale.get_z());
        dot.spin(spin.get_x(), spin.get_y(), spin.get_z());
    }
}

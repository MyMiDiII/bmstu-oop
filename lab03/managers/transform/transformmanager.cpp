#include "transformmanager.h"


void TransformManager::move_object(const std::shared_ptr <Object> &object,
                                   const double &dx,
                                   const double &dy,
                                   const double &dz)
{
    Dot move(dx, dy,dz);
    Dot scale(1, 1, 1);
    Dot spin(0, 0, 0);

    object->transform(move, scale, spin);
}


void TransformManager::scale_object(const std::shared_ptr <Object> &object,
                                    const double &kx,
                                    const double &ky,
                                    const double &kz)
{
    Dot move(0, 0,0);
    Dot scale(kx, ky, kz);
    Dot spin(0, 0, 0);

    object->transform(move, scale, spin);
}


void TransformManager::spin_object(const std::shared_ptr <Object> &object,
                                   const double &ox,
                                   const double &oy,
                                   const double &oz)
{
    Dot move(0, 0,0);
    Dot scale(1, 1, 1);
    Dot spin(ox, oy, oz);

    object->transform(move, scale, spin);
}


void TransformManager::transform_object(const std::shared_ptr<Object> &object,
                                        const Dot &move,
                                        const Dot &scale,
                                        const Dot &spin)
{
    object->transform(move, scale, spin);
}

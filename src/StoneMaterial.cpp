#include "StoneMaterial.h"

StoneMaterial* StoneMaterial::Instance()
{
    static StoneMaterial material;
    return &material;
}

#include "WoodMaterial.h"

WoodMaterial* WoodMaterial::Instance()
{
    static WoodMaterial material;
    return &material;
}

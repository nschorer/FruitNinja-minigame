#include "GlassMaterial.h"

GlassMaterial* GlassMaterial::Instance()
{
    static GlassMaterial material;
    return &material;
}

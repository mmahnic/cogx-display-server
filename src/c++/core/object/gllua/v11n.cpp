
#include "v11n.h"
#include "../CLuaGlScript.hpp"
#include <QGLContext>

void* v11nGetOpenGlContext()
{
   return (void*) QGLContext::currentContext();
}

void v11nCamera_SetPosition(void* scriptObj, char* name,
      double xEye, double yEye, double zEye,
      double xView, double yView, double zView,
      double xUp, double yUp, double zUp)
{
   // TODO: check if scriptObj is valid
   cogx::display::CLuaGlScript* pScript = (cogx::display::CLuaGlScript*)scriptObj;
   if (! pScript) return;
   pScript->setCamera(name, xEye, yEye, zEye, xView, yView, zView, xUp, yUp, zUp);
}

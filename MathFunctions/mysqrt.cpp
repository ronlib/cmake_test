#include "MathFunctions.h"
#include "../Config.h"

double mysqrt(double value)
{
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    return exp(log (value) * 0.5);
#else
    (void)(value);
    return 1.0;
#endif //defined (HAVE_LOG) && defined (HAVE_EXP)
}

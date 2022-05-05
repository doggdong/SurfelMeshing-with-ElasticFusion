#include <ElasticFusion.h>
#include <opencv2/opencv.hpp>
float confidence, depth, icp, icpErrThresh, covThresh, photoThresh, fernThresh;
int timeDelta, icpCountThresh, start, end;
bool fillIn, openLoop, reloc, frameskip, quiet, fastOdom, so3, iclnuim,
    frameToFrameRGB;
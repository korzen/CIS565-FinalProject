set(SOURCE_FILES
    "rasterize.cu"
    "rasterize.h"
    "Particle.h"
    "RigidBody.h"
    "RigidBody.cpp"
    "particleSampling.h"
    "particleSampling.cu"
    "simulate.h"
    "simulate.cu"
	"rasterizeTools.h"
    "fluid.h"
    "fluid.cu"
    )

cuda_add_library(src
    ${SOURCE_FILES}
    OPTIONS -arch=sm_20
    )

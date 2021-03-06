#ifndef VAST_COMMON_STATE_H
#define VAST_COMMON_STATE_H

//----LIBRARY----
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

//----LOCAL----
#include "common/basictypes.h"

namespace Vast
{
	struct State
	{
		v3 position = v3(0.0, 0.0, 0.0);
		v3 velocity = v3(0.0, 0.0, 0.0);
		v3 scale = v3(1.0, 1.0, 1.0);

		quat orientation = quat();
		quat spin = quat();

		mat4 matrix = mat4(1.0);

		void update();
		void tick();
	};
}

#endif

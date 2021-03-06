#ifndef VAST_RENDER_RESOURCES_SHADER_H
#define VAST_RENDER_RESOURCES_SHADER_H

//----STANDARD----
#include "string"

//----LOCAL----
#include "common/basictypes.h"
#include "resource.h"

namespace Vast
{
	namespace Render
	{
		namespace Resources
		{
			class Shader : public Resource
			{
				private:
					glid gl_id;
				public:
					void enable();
					glid getGLID();
					void loadFromFiles(std::string vertex_file_path, std::string fragment_file_path);
					void loadFromStrings(std::string vertex_shader_code, std::string fragment_shader_code);
			};
		}
	}
}

#endif

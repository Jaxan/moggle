#pragma once

#include "../../core/shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
 * We need to provide specialisations in order to set uniforms.
 * Very alike the original moggle stuff
 */

namespace moggle {
#define X(T,...)                                    \
	template<> class shader_uniform_setter<T> {     \
		GLint id;                                   \
		shader_uniform_setter(GLint id) : id(id) {} \
		friend class shader_program;                \
	public:                                         \
		void set(T const & v) {                     \
			__VA_ARGS__;                            \
		}                                           \
	}

X(glm::vec2, gl::uniform_2fv(id, 1, glm::value_ptr(v)));
X(glm::vec3, gl::uniform_3fv(id, 1, glm::value_ptr(v)));
X(glm::vec4, gl::uniform_4fv(id, 1, glm::value_ptr(v)));
//X(glm::dvec2, gl::uniform_2dv(id, 1, glm::value_ptr(v)));
//X(glm::dvec3, gl::uniform_3dv(id, 1, glm::value_ptr(v)));
//X(glm::dvec4, gl::uniform_4dv(id, 1, glm::value_ptr(v)));
X(glm::ivec2, gl::uniform_2iv(id, 1, glm::value_ptr(v)));
X(glm::ivec3, gl::uniform_3iv(id, 1, glm::value_ptr(v)));
X(glm::ivec4, gl::uniform_4iv(id, 1, glm::value_ptr(v)));
X(glm::uvec2, gl::uniform_2uiv(id, 1, glm::value_ptr(v)));
X(glm::uvec3, gl::uniform_3uiv(id, 1, glm::value_ptr(v)));
X(glm::uvec4, gl::uniform_4uiv(id, 1, glm::value_ptr(v)));

X(glm::mat2, gl::uniform_matrix_2fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat3, gl::uniform_matrix_3fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat4, gl::uniform_matrix_4fv(id, 1, GL_FALSE, glm::value_ptr(v)));

X(glm::mat2x3, gl::uniform_matrix_2x3fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat3x2, gl::uniform_matrix_3x2fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat2x4, gl::uniform_matrix_2x4fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat4x2, gl::uniform_matrix_4x2fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat3x4, gl::uniform_matrix_3x4fv(id, 1, GL_FALSE, glm::value_ptr(v)));
X(glm::mat4x3, gl::uniform_matrix_4x3fv(id, 1, GL_FALSE, glm::value_ptr(v)));

#undef X
}

#pragma once

#include "../../math/matrix.hpp"
#include <glm/glm.hpp>

/*
 * Moggle uses traits for some functionality, for example attributes.
 */

namespace moggle {
	namespace detail {
		// Workaround for the fact that glm::vec*::length is not a static member
		template <typename genType>
		constexpr size_t dimensions();

		template <> constexpr size_t dimensions<glm::vec2>() { return 2; }
		template <> constexpr size_t dimensions<glm::vec3>() { return 3; }
		template <> constexpr size_t dimensions<glm::vec4>() { return 4; }

		// Base case for glm-type vectors
		// We default to non-homogeneous.
		template <typename T, bool Homogeneous = false>
		struct glm_traits_vector {
			static constexpr bool is_matrix = false;
			static constexpr bool is_vector = true;
			static constexpr bool is_homogeneous = Homogeneous;
			static constexpr size_t width = 1;
			static constexpr size_t height = dimensions<T>();
			static constexpr size_t size = width * height;
			using element_type = typename T::value_type;
		};

		// Base case for glm-type matrices
		template <typename T>
		struct glm_traits_matrix {
			static constexpr bool is_matrix = true;
			static constexpr bool is_vector = false;
			static constexpr bool is_homogeneous = false;
			static constexpr size_t width = dimensions<typename T::row_type>();
			static constexpr size_t height = dimensions<typename T::col_type>();
			static constexpr size_t size = width * height;
			using element_type = typename T::value_type;
		};
	}

	// Specific cases for all glm types
#define X(t) \
	template <> \
	struct matrix_traits<t> : detail::glm_traits_vector<t> {};

	X(glm::vec2)
	X(glm::vec3)
	X(glm::vec4)
#undef X

#define X(t) \
	template <> \
	struct matrix_traits<t> : detail::glm_traits_matrix<t> {};

	X(glm::mat2)
	X(glm::mat3)
	X(glm::mat4)
	X(glm::mat2x3)
	X(glm::mat3x2)
	X(glm::mat2x4)
	X(glm::mat4x2)
	X(glm::mat3x4)
	X(glm::mat4x3)
#undef X
}

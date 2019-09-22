#pragma once

#include <glm/glm.hpp>

using SignedType = float;

using Mat4 = glm::mat<4, 4, SignedType, glm::qualifier::defaultp>;
using Mat3 = glm::mat<3, 3, SignedType, glm::qualifier::defaultp>;
using Mat2 = glm::mat<2, 2, SignedType, glm::qualifier::defaultp>;

using Vec4 = glm::vec<4, SignedType, glm::qualifier::defaultp>;
using Vec3 = glm::vec<3, SignedType, glm::qualifier::defaultp>;
using Vec2 = glm::vec<2, SignedType, glm::qualifier::defaultp>;

using Scalar = SignedType;

using Vec3bool = glm::vec<3, bool, glm::qualifier::defaultp>;
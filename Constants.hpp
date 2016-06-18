#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <random>

namespace Window {
  const unsigned WIDTH = 1280;
  const unsigned HEIGHT = 720;
}

namespace Entities {

  const float GRAVITY = 0.015f;

  namespace Tank {
    const float BASE_VELOCITY = 2.f;
    const float BASE_JUMP_VELOCITY = 1.f;
    const float DECEL = 0.8f;
  }

  namespace Bomber {
    const float BASE_VELOCITY = 2.5f;
  }
}

namespace RNG {
  /* code from http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf */

  inline std::default_random_engine& global_urng()
  {
    static std::default_random_engine u{};
    return u;
  };

  inline void randomize()
  {
    static std::random_device rd{};
    global_urng().seed( rd() );
  };

  inline int getRandomNumber(int min, int max)
  {
    static std::uniform_int_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{min, max});
  };

  inline double getRandomNumber(double min, double max)
  {
    static std::uniform_real_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{min, max});
  };
}

#endif

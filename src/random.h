#include <random>

template <class Engine = std::mt19937>
int random(int begin, int end)
{
  static Engine engine = []{
    Engine engine;
    std::random_device device;
    engine.seed(device());
    return engine;
  }();
  
  static std::uniform_int_distribution<int> dist{};
  using param_t = decltype(dist)::param_type;
  
  return dist(engine, param_t(begin, end-1));
}

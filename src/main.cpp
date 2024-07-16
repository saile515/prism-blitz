#include <coral/coral.hpp>

class Player : public coral::Node {
  private:
    coral::Vector3<double> m_position;

  public:
    static Player create() { return Player(); }

    void on_start() { m_position.set(0, 2, 0); };

    void on_update() { m_position.add_x(1); };
};

int main() {
    coral::CoralEngine coral;

    coral.register_node<Player>("Player", Player::create);

    coral.create_window();

    coral.load<coral::Scene>("scenes/main.xml");

    while (true) {
    }
}

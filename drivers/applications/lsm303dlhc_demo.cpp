#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/units.hpp>

#include <lsm303dlhc.hpp>
#include <resource_list.hpp>

using namespace hal::literals;
using namespace std::chrono_literals;
namespace sjsu::drivers {

void application()
{

  auto i2c = resources::i2c();
  auto clock = resources::clock();
  auto console = resources::console();

  auto lsm303dlhc_sensor = lsm303dlhc(i2c);

  while (true) {
    hal::delay(*clock, 3000ms);
    auto acc = lsm303dlhc_sensor.read_accel_data();
    auto mag = lsm303dlhc_sensor.read_mag_data();

    auto x_acc = acc.x_accel;
    auto y_acc = acc.y_accel;
    auto z_acc = acc.z_accel;

    auto x_mag = mag.x_mag;
    auto y_mag = mag.y_mag;
    auto z_mag = mag.z_mag;

    hal::print<64>(*console, "X-Acceleration %d\n", x_acc);
    hal::print<64>(*console, "Y-Acceleration %d\n", y_acc);
    hal::print<64>(*console, "Z-Acceleration %d\n", z_acc);

    hal::print<64>(*console, "X-Magnetic Field %d\n", x_mag);
    hal::print<64>(*console, "Y-Magnetic Field %d\n", y_mag);
    hal::print<64>(*console, "Z-Magnetic Field %d\n", z_mag);
  }
}
}  // namespace sjsu::drivers

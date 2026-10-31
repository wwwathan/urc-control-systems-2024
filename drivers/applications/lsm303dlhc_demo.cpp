#include "lsm303dlhc.hpp"
#include <libhal-util/serial.hpp>
#include <resource_list.hpp>
#include <s

namespace sjsu::drivers {

void application() {
    auto i2c = resources::i2c();
    auto console = resources::i2c();

    auto lsm303dlhc_sensor = lsm303dlhc(i2c);

    auto rd = lsm303dlhc_sensor.read_accel_data();
    auto accel_x = rd.x_accel

    hal::print<64>(*console, const char = "Test: %f]\n", accel_x);
    }
}